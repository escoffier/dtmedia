#include "streammanager.h"
#include "threadpool.h"
#include "mediastream.h"
#include "HCNetSDK.h"
#include "glog/logging.h"
#include "zmd5.h"

StreamManager *StreamManager::instance_ = nullptr;
//template<>  ThreadPool<PSBuffer> * ThreadPool<PSBuffer>::instance_ = nullptr;

StreamManager *StreamManager::getInstance()
{
	if (instance_ == nullptr)
	{
		instance_ = new StreamManager;
	}

	return instance_;
}

StreamManager::StreamManager() : streams_(), msgthread_(), locker_(), /*rtpSender_(new RTPSender),*/ plugins_(new SDKPlugins),
								 avThreadPool_(std::make_shared<ThreadPool>(4))
{
	NET_DVR_Init();
};

std::shared_ptr<MediaStream> StreamManager::getStream(const std::string &id)
{
	auto search = streams_.find(id);
	if (search != streams_.end())
	{
		return search->second;
	}
	return nullptr;
}

// void StreamManager::addStream(Media::RealStreamReqParam &param,
// 							  const std::function<void(bool, const ::Media::RealStreamRespParam &)> iceCB,
// 							  std::function<void(::std::exception_ptr)> ecb)
// {
// 	//std::lock_guard<std::mutex> lockGuard(locker_);

// 	//auto search = streams_.find(id);
// 	//if (search == streams_.end())
// 	//{
// 	//	std::shared_ptr<MediaStream> ms = std::make_shared<RealSteam>(id, name, pwd, ip, port, destIp, destPort, iceCB, ecb);

// 	//    ms->addsubStream(destIp, destPort, ssrc, transmitter_);
// 	//	streams_.emplace(id, ms);
// 	//
// 	//	msgthread_.submit([=]() {
// 	//		openStream(id, callid);
// 	//	});
// 	//}
// 	//else
// 	//{
// 	//	//search->second->addDestHost(destIp, destPort);
// 	//	search->second->addsubStream(destIp, destPort, ssrc, transmitter_);
// 	//}
// }

void StreamManager::addStream(const dt::OpenRealStreamParam &param, std::shared_ptr<CallBack> cb) //std::function<void(bool, const ::Media::RealStreamRespParam &)> iceCB)
{
	std::lock_guard<std::mutex> lockGuard(locker_);

	std::shared_ptr<CamaraController> controller;
	//Media::RealStreamRespParam resp;
	dt::OpenRealStreamResp resp;
	resp.id = param.id;
	auto search = streams_.find(param.id);
	if (search == streams_.end())
	{
		auto search = controllers_.find("hkdevice");

		if (search == controllers_.end())
		{
			controller = loadPlugin("hkdevice");
			if (!controller)
			{
				LOG(ERROR) << "load plugin failed";
				// Media::OpenStreamException ex;
				// ex.reason = "load plugin failed";
				// ex.callid = param.callid;
				//resp.id = param.id;
				resp.succed = false;
				(*cb)(resp);
				//excb(make_exception_ptr(ex));
				return;
			}
		}
		else
		{
			controller = search->second;
		}

		std::shared_ptr<MediaStream> ms = std::make_shared<RealSteam>(param, cb, controller);

		ms->addsubStream(param.callid, param.destip, param.destport,
						 param.ssrc, param.pt);

		std::shared_ptr<Buffer> buf = std::make_shared<Buffer>();
		//create rtp sender
		std::shared_ptr<PaketSender> sender = std::make_shared<RTPSender>(param.destip, param.destport);
		sender->setParam("ssrc", std::to_string(param.ssrc));
		sender->init();
		buf->addSender(param.callid, sender);

		avThreadPool_->attachBuffer(param.id, buf);

		streams_.emplace(param.id, ms);

		//msgthread_.submit([=]() {
		//openStream(param.id, param.callid, iceCB, excb);
		msgthread_.submit([=]() {
			dt::OpenRealStreamResp resp;
			if (!ms->openStream(param.callid))
			{
				LOG(ERROR) << "Cann't find stream: " << param.id << std::endl;
				//cb(false, resp);
				resp.succed = false;
				(*cb)(resp);
				return;
			}
		});
	}
	else //stream from id camera already existed
	{
		std::shared_ptr<PaketSender> sender = std::make_shared<RTPSender>(param.destip, param.destport);
		sender->setParam("ssrc", std::to_string(param.ssrc));
		sender->init();
		//Media::RealStreamRespParam resp;
		resp.id = param.id;
		resp.callid = param.callid;
		resp.sourceip = "192.168.254.233";
		resp.sourceport = 18000;

		auto buf = avThreadPool_->getBuffer(param.id);
		if (buf != nullptr)
		{
			buf->addSender(param.callid, sender);
			search->second->addsubStream(param.callid, param.destip, param.destport, param.ssrc, param.pt);
			//iceCB(true, resp);
			resp.succed = true;
			(*cb)(resp);
		}
		else
		{
			//iceCB(false, resp);
			resp.succed = false;
			(*cb)(resp);
		}
	}
}

// bool StreamManager::openStream(std::string id, std::string callid, std::function<void(const ::Media::RealStreamRespParam &)> iceCB, std::function<void(::std::exception_ptr)> excb)
// {
// 	std::lock_guard<std::mutex> lockGuard(locker_);
// 	auto search = streams_.find(id);
// 	if (search == streams_.end())
// 	{
// 		LOG(ERROR) << "Cann't find stream: " << id << std::endl;
// 		Media::OpenStreamException ex;
// 		ex.reason = "Cann't find stream";
// 		excb(std::make_exception_ptr(ex));
// 		return false;
// 	}
// 	else
// 	{
// 		if (!search->second->openStream(callid))
// 		{
// 			LOG(ERROR) << "Cann't open stream: " << id << std::endl;

// 			//ThreadPool<PSBuffer>::getInstance()->remove_buffer(id);
// 			streams_.erase(id);

// 			Media::OpenStreamException ex;
// 			ex.reason = "Cann't open stream";
// 			excb(std::make_exception_ptr(ex));

// 			return false;
// 		}
// 	}
// 	Media::RealStreamRespParam resp;
// 	resp.id = id;
// 	resp.callid = callid;
// 	resp.sourceip = "192.168.254.233";
// 	resp.sourceport = "18000";
// 	iceCB(resp);
// 	return true;
// }

void StreamManager::closeStream(std::string id, std::string callid)
{
	std::lock_guard<std::mutex> lockGuard(locker_);
	auto search = streams_.find(id);
	if (search == streams_.end())
	{
		LOG(ERROR) << "Cann't find stream: " << id << std::endl;
		return;
	}
	else
	{
		search->second->removesubStream(callid);

		auto buf = avThreadPool_->getBuffer(id);
		if (buf != nullptr)
		{
			buf->removeSender(callid);
		}

		if (search->second->needClose())
		{
			//�����ǰ�������ֻ��һ·��Ƶ���������������streams_ժ��
			search->second->closeStream();
			avThreadPool_->removeBuffer(id);
			//ThreadPool<PSBuffer>::getInstance()->remove_buffer(id);
			//rtpSender_->removeBuffer(id);
			streams_.erase(search);
		}
	}
	return;
}

void StreamManager::getStreamStatic(std::string id, ::Media::StreamStatic &stat)
{
	std::lock_guard<std::mutex> lockGuard(locker_);
	auto search = streams_.find(id);
	if (search == streams_.end())
	{
		LOG(ERROR) << "(getStreamStatic)Cann't find stream: " << id << std::endl;
		return;
	}
	else
	{
		search->second->getNodeInfo(stat.busynode, stat.freenode);
	}
	return;
}

typedef CamaraController *(*CREATE_PTR)();

std::shared_ptr<CamaraController> StreamManager::loadPlugin(const std::string &name)
{
	if (!plugins_->Load("./", name.c_str()))
	{
		LOG(ERROR) << "Load " << name << ".dll failed!";
		return std::shared_ptr<CamaraController>();
	}

	CREATE_PTR func = (CREATE_PTR)plugins_->GetFuncAddr("GetController");
	if (func == nullptr)
	{
		LOG(ERROR) << "GetFuncAddr failed!";
		return std::shared_ptr<CamaraController>();
	}

	std::shared_ptr<CamaraController> controller = std::shared_ptr<CamaraController>(func());
	if (controller == nullptr)
	{
		LOG(ERROR) << "CamaraController is null!";
		return std::shared_ptr<CamaraController>();
	}

	controllers_.emplace(std::make_pair(name, controller));
	LOG(INFO) << "load plugin : " << name << ".dll";

	return controller;
}

std::shared_ptr<CamaraController> StreamManager::getController(const std::string &name)
{
	auto search = controllers_.find(name);
	std::shared_ptr<CamaraController> controller;

	if (search == controllers_.end())
	{
		controller = loadPlugin("hkdevice");
		if (!controller)
		{
			LOG(ERROR) << "load plugin failed";
			//Gateway::DeviceControlException ex;
			//ex.reason = "load plugin failed";
			//excb(make_exception_ptr(ex));
			return std::shared_ptr<CamaraController>();
			;
		}
	}
	else
	{
		controller = search->second;
	}

	return controller;
}

std::string StreamManager::buildCallId(const std::string &ip, int port)
{
	unsigned char buff[128] = {0};
	md5_state_t mdctx;
	md5_byte_t md_value[16];

	snprintf((char *)buff, 127, "%s%d", ip.c_str(), port);
	md5_init(&mdctx);
	md5_append(&mdctx, (const unsigned char *)(buff), strlen((const char *)buff));
	md5_finish(&mdctx, md_value);

	char md5sum[33];
	int i;
	int h, l;
	for (i = 0; i < 16; ++i)
	{
		h = md_value[i] & 0xf0;
		h >>= 4;
		l = md_value[i] & 0x0f;
		md5sum[i * 2] = (char)((h >= 0x0 && h <= 0x9) ? (h + 0x30) : (h + 0x57));
		md5sum[i * 2 + 1] = (char)((l >= 0x0 && l <= 0x9) ? (l + 0x30) : (l + 0x57));
	}
	md5sum[32] = '\0';

	std::string md5str(md5sum);
	return md5str;
}