#ifdef WINDOWS
#include <winsock2.h>
#include<windows.h>
#endif
#include "streamI.h"
//#define WIN32_LEAN_AND_MEAN
#include "mediastream.h"
#include "message.h"
#include "glog/logging.h"
#include "icecallback.h"
#include "media.h"

StreamI::StreamI()
	//:sm_(new StreamManager())
{
	
}

StreamI::~StreamI()
{
}

void StreamI::openRealStreamAsync(::Media::RealStreamReqParam param, ::std::function<void(bool, const::Media::RealStreamRespParam&)> cb, ::std::function<void(::std::exception_ptr)> ecb, const::Ice::Current &)
{
	LOG(INFO) << param.callid;

	dt::OpenRealStreamParam p;
	p.id = param.id;
	p.callid = param.callid;

	//std::shared_ptr<CallBack> callback = std::make_shared<IceCallBack<std::function<void(bool, const::Media::RealStreamRespParam&)>>>(cb);
    std::shared_ptr<CallBack> callback = std::make_shared<IceCallBack>(cb);
	Meida::getInstance()->openStream(p, callback);
	//StreamManager::getInstance()->addStream(p, cb);
}

void StreamI::closeStreamAsync(::std::string callid, ::std::string id, ::std::function<void()> cb, ::std::function<void(::std::exception_ptr)> excb, const::Ice::Current &)
{
	
	//StreamManager::getInstance()->closeStream(id, callid);
	cb();
}

void StreamI::getStreamStatic(::std::string id, ::Media::StreamStatic & stat, const::Ice::Current &)
{
	//StreamManager::getInstance()->getStreamStatic(id, stat);
}

//void StreamI::openRealStream_async(const Media::AMD_Stream_openRealStreamPtr &cb, const Media::RealStream & ctg, const Ice::Current &)
//{
//	sm_->addStream(ctg.id,ctg.name, ctg.pwd, ctg.ip, ctg.port, ctg.destip, ctg.destport, ctg.ssrc, cb);
//	//Media::StreamInfo stm;
//	//stm.ip = "111111";
//	//cb->ice_response(stm);
//}

