#ifdef WINDOWS
#include <winsock2.h>
#include <windows.h>
#endif
#include "mediastream.h"

#include <functional>
#include "threadpool.h"
#define WIN32_LEAN_AND_MEAN
#include "HCNetSDK.h"
#include "glog/logging.h"
#include "RTPSender.h"
//#include "callback.h"

FILE *streamfile = fopen("stream106", "wb");

void checkerror(int rtperr)
{
	if (rtperr < 0)
	{
		std::cout << "ERROR: " << jrtplib::RTPGetErrorString(rtperr) << std::endl;
		//exit(-1);
	}
}

// MediaStream::MediaStream(const std::string &id, const std::string &name, const std::string &pwd,
// 						 const std::string &ip, int port, const std::string &destIp, int destPort,
// 						 std::function<void(const ::Media::RealStreamRespParam &)> iceCB, std::function<void(::std::exception_ptr)> ecb,
// 						 std::shared_ptr<CamaraController> con) : id_(id), name_(name), pwd_(pwd), ip_(ip), port_(port), destIp_(destIp),
// 																  destPort_(destPort), iceCB_(iceCB), ecb_(ecb), isOpen_(false), isLogin_(false), buffer_(std::make_shared<Buffer>()), controller_(con)
// {
// 	//ThreadPool<PSBuffer>* pool = ThreadPool<PSBuffer>::getInstance();
// 	//pool->push_buffer(id_, buffer_);
// }

MediaStream::MediaStream(const dt::OpenRealStreamParam &req, std::shared_ptr<CallBack> cb, //std::function<void(bool, const ::Media::RealStreamRespParam &)> iceCB,
						 /*std::function<void(::std::exception_ptr)> ecb,*/ std::shared_ptr<CamaraController> con)
{
}

void MediaStream::addDestHost(const std::string &destIp, int destPort)
{
}

std::string MediaStream::addsubStream(const std::string &callid, const std::string &destIp, int destPort,
									  int ssrc, int pt /*, jrtplib::RTPTransmitter* transmitter*/)
{
	std::lock_guard<std::mutex> lockGuard(mutex_);
	auto search = subStreams_.find(callid);
	if (search == subStreams_.end())
	{
		//subStreams_.emplace(std::pair<std::string, subStream>(md5str, ss));
		LOG(INFO) << "add substream : " << destIp << " - " << destPort << std::endl;
		subStream ss(destIp, destPort, "192.168.21.121", 1999, ssrc /*, transmitter_*/);

		std::shared_ptr<PaketSender> sender = std::make_shared<RTPSender>(destIp, destPort);
		sender->setParam("ssrc", "1111");
		sender->init();
		buffer_->addSender(callid, sender);

		//buffer_->addDestination(callid, ss.destipn_, destPort, ssrc, pt/*, transmitter*/);

		subStreams_.emplace(callid, std::move(ss));
	}
	return callid;
}

void MediaStream::removesubStream(const std::string &callid)
{
	{
		std::lock_guard<std::mutex> lockGuard(mutex_);
		subStreams_.erase(callid);
	}
	//buffer_->removeDestination(callid);
	buffer_->removeSender(callid);
}

size_t MediaStream::subStreamCount() const
{
	//std::lock_guard<std::mutex> lockGuard(mutex_);
	return subStreams_.size();
}

bool MediaStream::needClose()
{
	std::lock_guard<std::mutex> lockGuard(mutex_);
	return subStreams_.empty();
}

void MediaStream::processData(char *data, uint32_t len)
{
	LOG(WARNING) << "discard data";
	// std::shared_ptr<PSBuffer::BufferNode> node = buffer_->getFreeNode();
	// if (!node)
	// {
	// 	LOG(WARNING) << "discard data";
	// 	return;
	// }

	// memcpy(node->data_, data, len);
	// node->length_ = len;
	// buffer_->push(node);
}

void MediaStream::getNodeInfo(int &b, int &f)
{
	//buffer_->getNodeInfo(b, f);
}

RealSteam::RealSteam(const dt::OpenRealStreamParam &req, std::shared_ptr<CallBack> cb, 
					 //std::function<void(bool, const ::Media::RealStreamRespParam &)> iceCB,
					 std::shared_ptr<CamaraController> con) : MediaStream(req, cb, con)
{
}

RealSteam::~RealSteam()
{
}

bool RealSteam::openStream(const std::string &callid)
{
	//���������ȡ��Ƶ��

	if (controller_->openRealStream(id_, ip_, port_, name_, pwd_,
									[=](char *data, uint32_t len) { processData(data, len); }))
	{
		Media::RealStreamRespParam resp;
		//respinfo.callid = callid;
		//uint32_t ip = transParams.GetBindIP();
		//char strIp[16] = {0};
		//inet_ntop(AF_INET, (void*)&ip, strIp, 15);
		std::string strIp("192.168.254.233");
		resp.sourceip = strIp;
		resp.callid = callid;
		resp.id = id_;

		iceCB_(resp);
		return true;
	}
	else
	{
		//ecb_();
		return false;
	}
}

void RealSteam::closeStream(const std::string &callid)
{
	//std::lock_guard<std::mutex> lockGuard(mutex_);
	//auto search = subStreams_.find(callid);
	//if (search != subStreams_.end())
	//{
	//	size_t n =  subStreams_.count(callid);
	//	if (n == 0)
	//	{
	//		if (controller_->closeRealStream(search->second.id_))
	//		{
	//			LOG(ERROR) << "Hik sdk close stream failed, error code: " << NET_DVR_GetLastError();
	//		}
	//		else
	//		{
	//			LOG(INFO) << "Close stream: " << callid;
	//		}
	//
	//	}
	//	subStreams_.erase(search);
	//}

	return;
}

void RealSteam::closeStream()
{
	if (!controller_->closeRealStream(id_))
	{
		LOG(ERROR) << "Hik sdk close stream failed, error code: " << NET_DVR_GetLastError();
	}
	else
	{
		LOG(INFO) << "Close stream: " << id_;
	}
}

// VodSteam::VodSteam(const std::string &id, const std::string &name, const std::string &pwd,
// 				   const std::string &ip, int port, const std::string &destIp, int destPort,
// 				   std::function<void(const ::Media::RealStreamRespParam &)> iceCB, std::function<void(::std::exception_ptr)> ecb,
// 				   const std::string &startTime, const std::string &endTime, std::shared_ptr<CamaraController> con) : MediaStream(id, name, pwd, ip, port, destIp, destPort, iceCB, ecb, con), startTime_(startTime), endTime_(endTime)
VodSteam::VodSteam(const dt::OpenRealStreamParam &req, std::shared_ptr<CallBack> cb, 
				   //std::function<void(bool returnValue, const ::Media::RealStreamRespParam &)> iceCB,
				   std::shared_ptr<CamaraController> con) : MediaStream(req, cb, con)
{
}

VodSteam::~VodSteam()
{
}

bool VodSteam::openStream(const std::string &callid)
{
	return false;
}

void VodSteam::closeStream(const std::string &callid)
{
}

void VodSteam::closeStream()
{
}

