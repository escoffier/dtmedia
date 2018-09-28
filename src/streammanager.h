#pragma once
#include <functional>
#include <memory>
#include <string>
#include "mediastream.h"
#include "plugins.h"
#include "callback.h"


class StreamManager
{
  public:
    //using RTPTransmitterPtr = std::shared_ptr<jrtplib::RTPTransmitter>;
    using Process = std::function<bool()>;
    static StreamManager *getInstance();
    StreamManager();
    ~StreamManager()
    {
        /*	if (transParams_)
		{
			delete transParams_;
		}*/
    }
    std::shared_ptr<MediaStream> getStream(const std::string &id);

    void addStream(const dt::OpenRealStreamParam &param, std::shared_ptr<CallBack>);
                   //std::function<void(bool, const ::Media::RealStreamRespParam &)> iceCB);

    //bool openStream( std::string id,  std::string callid, std::function<void(const::Media::RealStreamRespParam&)> iceCB, std::function<void(::std::exception_ptr)> ecb);
    void closeStream(std::string callid, std::string id);
    void getStreamStatic(std::string id, ::Media::StreamStatic &stat);

    std::shared_ptr<CamaraController> loadPlugin(const std::string &name);
    std::shared_ptr<CamaraController> getController(const std::string &name);

  private:
    std::string buildCallId(const std::string &ip, int port);
    std::map<std::string, std::shared_ptr<MediaStream>> streams_;
    //RTPTransmitterPtr transmitter_;
    //jrtplib::RTPUDPv4TransmissionParams * transParams_;
    MessageThread msgthread_;
    std::mutex locker_;
    std::map<std::string, std::shared_ptr<CamaraController>> controllers_;
    std::unique_ptr<SDKPlugins> plugins_;
    std::shared_ptr<ThreadPool> avThreadPool_;

    static StreamManager *instance_;
};