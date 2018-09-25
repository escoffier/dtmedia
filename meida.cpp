#include "media.h"
#include "streammanager.h"

Meida *Meida::instance_ = nullptr;

Meida *Meida::getInstance()
{
	if (instance_ == nullptr)
	{
		instance_ = new Meida;
	}

	return instance_;
}

Meida::Meida()
{
}

Meida::~Meida()
{
}

bool Meida::openStream(const dt::OpenRealStreamParam& param, std::shared_ptr<CallBack> cb)
{
	cbmap_.emplace(param.callid, cb);
	StreamManager::getInstance()->addStream(param, cb);
	
}
