// **********************************************************************
//
// Copyright (c) 2003-2018 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************
//
// Ice version 3.7.1
//
// <auto-generated>
//
// Generated from file `stream.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#include <stream.h>
#include <IceUtil/PushDisableWarnings.h>
#include <Ice/LocalException.h>
#include <Ice/ValueFactory.h>
#include <Ice/OutgoingAsync.h>
#include <Ice/InputStream.h>
#include <Ice/OutputStream.h>
#include <Ice/LocalException.h>
#include <IceUtil/PopDisableWarnings.h>

#if defined(_MSC_VER)
#   pragma warning(disable:4458) // declaration of ... hides class member
#elif defined(__clang__)
#   pragma clang diagnostic ignored "-Wshadow"
#elif defined(__GNUC__)
#   pragma GCC diagnostic ignored "-Wshadow"
#endif

#ifndef ICE_IGNORE_VERSION
#   if ICE_INT_VERSION / 100 != 307
#       error Ice version mismatch!
#   endif
#   if ICE_INT_VERSION % 100 > 50
#       error Beta header file detected
#   endif
#   if ICE_INT_VERSION % 100 < 1
#       error Ice patch level mismatch!
#   endif
#endif

#ifdef ICE_CPP11_MAPPING // C++11 mapping

namespace
{

const ::IceInternal::DefaultUserExceptionFactoryInit<::Media::RequestCanceledException> iceC_Media_RequestCanceledException_init("::Media::RequestCanceledException");

const ::IceInternal::DefaultUserExceptionFactoryInit<::Media::OpenStreamException> iceC_Media_OpenStreamException_init("::Media::OpenStreamException");

const ::std::string iceC_Media_Stream_ids[2] =
{
    "::Ice::Object",
    "::Media::Stream"
};
const ::std::string iceC_Media_Stream_ops[] =
{
    "closeStream",
    "closeVodStream",
    "controlVodStream",
    "getRecordFiles",
    "getStreamStatic",
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "openRealStream",
    "openVodStream"
};
const ::std::string iceC_Media_Stream_openRealStream_name = "openRealStream";
const ::std::string iceC_Media_Stream_closeStream_name = "closeStream";
const ::std::string iceC_Media_Stream_getStreamStatic_name = "getStreamStatic";
const ::std::string iceC_Media_Stream_getRecordFiles_name = "getRecordFiles";
const ::std::string iceC_Media_Stream_openVodStream_name = "openVodStream";
const ::std::string iceC_Media_Stream_closeVodStream_name = "closeVodStream";
const ::std::string iceC_Media_Stream_controlVodStream_name = "controlVodStream";

}

Media::RequestCanceledException::~RequestCanceledException()
{
}

const ::std::string&
Media::RequestCanceledException::ice_staticId()
{
    static const ::std::string typeId = "::Media::RequestCanceledException";
    return typeId;
}

Media::OpenStreamException::~OpenStreamException()
{
}

const ::std::string&
Media::OpenStreamException::ice_staticId()
{
    static const ::std::string typeId = "::Media::OpenStreamException";
    return typeId;
}

bool
Media::Stream::ice_isA(::std::string s, const ::Ice::Current&) const
{
    return ::std::binary_search(iceC_Media_Stream_ids, iceC_Media_Stream_ids + 2, s);
}

::std::vector<::std::string>
Media::Stream::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector<::std::string>(&iceC_Media_Stream_ids[0], &iceC_Media_Stream_ids[2]);
}

::std::string
Media::Stream::ice_id(const ::Ice::Current&) const
{
    return ice_staticId();
}

const ::std::string&
Media::Stream::ice_staticId()
{
    static const ::std::string typeId = "::Media::Stream";
    return typeId;
}

/// \cond INTERNAL
bool
Media::Stream::_iceD_openRealStream(::IceInternal::Incoming& inS, const ::Ice::Current& current)
{
    _iceCheckMode(::Ice::OperationMode::Normal, current.mode);
    auto istr = inS.startReadParams();
    RealStreamReqParam iceP_ctg;
    istr->readAll(iceP_ctg);
    inS.endReadParams();
    auto inA = ::IceInternal::IncomingAsync::create(inS);
    auto responseCB = [inA](bool ret, const RealStreamRespParam& iceP_stm)
    {
        auto ostr = inA->startWriteParams();
        ostr->writeAll(iceP_stm, ret);
        inA->endWriteParams();
        inA->completed();
    };
    this->openRealStreamAsync(::std::move(iceP_ctg), responseCB, inA->exception(), current);
    return false;
}
/// \endcond

/// \cond INTERNAL
bool
Media::Stream::_iceD_closeStream(::IceInternal::Incoming& inS, const ::Ice::Current& current)
{
    _iceCheckMode(::Ice::OperationMode::Normal, current.mode);
    auto istr = inS.startReadParams();
    ::std::string iceP_callid;
    ::std::string iceP_id;
    istr->readAll(iceP_callid, iceP_id);
    inS.endReadParams();
    auto inA = ::IceInternal::IncomingAsync::create(inS);
    this->closeStreamAsync(::std::move(iceP_callid), ::std::move(iceP_id), inA->response(), inA->exception(), current);
    return false;
}
/// \endcond

/// \cond INTERNAL
bool
Media::Stream::_iceD_getStreamStatic(::IceInternal::Incoming& inS, const ::Ice::Current& current)
{
    _iceCheckMode(::Ice::OperationMode::Normal, current.mode);
    auto istr = inS.startReadParams();
    ::std::string iceP_id;
    istr->readAll(iceP_id);
    inS.endReadParams();
    StreamStatic iceP_static;
    this->getStreamStatic(::std::move(iceP_id), iceP_static, current);
    auto ostr = inS.startWriteParams();
    ostr->writeAll(iceP_static);
    inS.endWriteParams();
    return true;
}
/// \endcond

/// \cond INTERNAL
bool
Media::Stream::_iceD_getRecordFiles(::IceInternal::Incoming& inS, const ::Ice::Current& current)
{
    _iceCheckMode(::Ice::OperationMode::Normal, current.mode);
    auto istr = inS.startReadParams();
    ::std::string iceP_startTime;
    ::std::string iceP_endtime;
    istr->readAll(iceP_startTime, iceP_endtime);
    inS.endReadParams();
    this->getRecordFiles(::std::move(iceP_startTime), ::std::move(iceP_endtime), current);
    inS.writeEmptyParams();
    return true;
}
/// \endcond

/// \cond INTERNAL
bool
Media::Stream::_iceD_openVodStream(::IceInternal::Incoming& inS, const ::Ice::Current& current)
{
    _iceCheckMode(::Ice::OperationMode::Normal, current.mode);
    auto istr = inS.startReadParams();
    RealStreamReqParam iceP_req;
    istr->readAll(iceP_req);
    inS.endReadParams();
    RealStreamRespParam iceP_resp;
    this->openVodStream(::std::move(iceP_req), iceP_resp, current);
    auto ostr = inS.startWriteParams();
    ostr->writeAll(iceP_resp);
    inS.endWriteParams();
    return true;
}
/// \endcond

/// \cond INTERNAL
bool
Media::Stream::_iceD_closeVodStream(::IceInternal::Incoming& inS, const ::Ice::Current& current)
{
    _iceCheckMode(::Ice::OperationMode::Normal, current.mode);
    auto istr = inS.startReadParams();
    ::std::string iceP_callid;
    ::std::string iceP_id;
    istr->readAll(iceP_callid, iceP_id);
    inS.endReadParams();
    this->closeVodStream(::std::move(iceP_callid), ::std::move(iceP_id), current);
    inS.writeEmptyParams();
    return true;
}
/// \endcond

/// \cond INTERNAL
bool
Media::Stream::_iceD_controlVodStream(::IceInternal::Incoming& inS, const ::Ice::Current& current)
{
    _iceCheckMode(::Ice::OperationMode::Normal, current.mode);
    auto istr = inS.startReadParams();
    ::std::string iceP_cmd;
    ::std::string iceP_callid;
    ::std::string iceP_id;
    istr->readAll(iceP_cmd, iceP_callid, iceP_id);
    inS.endReadParams();
    this->controlVodStream(::std::move(iceP_cmd), ::std::move(iceP_callid), ::std::move(iceP_id), current);
    inS.writeEmptyParams();
    return true;
}
/// \endcond

/// \cond INTERNAL
bool
Media::Stream::_iceDispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair<const ::std::string*, const ::std::string*> r = ::std::equal_range(iceC_Media_Stream_ops, iceC_Media_Stream_ops + 11, current.operation);
    if(r.first == r.second)
    {
        throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
    }

    switch(r.first - iceC_Media_Stream_ops)
    {
        case 0:
        {
            return _iceD_closeStream(in, current);
        }
        case 1:
        {
            return _iceD_closeVodStream(in, current);
        }
        case 2:
        {
            return _iceD_controlVodStream(in, current);
        }
        case 3:
        {
            return _iceD_getRecordFiles(in, current);
        }
        case 4:
        {
            return _iceD_getStreamStatic(in, current);
        }
        case 5:
        {
            return _iceD_ice_id(in, current);
        }
        case 6:
        {
            return _iceD_ice_ids(in, current);
        }
        case 7:
        {
            return _iceD_ice_isA(in, current);
        }
        case 8:
        {
            return _iceD_ice_ping(in, current);
        }
        case 9:
        {
            return _iceD_openRealStream(in, current);
        }
        case 10:
        {
            return _iceD_openVodStream(in, current);
        }
        default:
        {
            assert(false);
            throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
        }
    }
}
/// \endcond

/// \cond INTERNAL
void
Media::StreamPrx::_iceI_openRealStream(const ::std::shared_ptr<::IceInternal::OutgoingAsyncT<Stream::OpenRealStreamResult>>& outAsync, const RealStreamReqParam& iceP_ctg, const ::Ice::Context& context)
{
    _checkTwowayOnly(iceC_Media_Stream_openRealStream_name);
    outAsync->invoke(iceC_Media_Stream_openRealStream_name, ::Ice::OperationMode::Normal, ::Ice::FormatType::DefaultFormat, context,
        [&](::Ice::OutputStream* ostr)
        {
            ostr->writeAll(iceP_ctg);
        },
        nullptr,
        [](::Ice::InputStream* istr)
        {
            Stream::OpenRealStreamResult v;
            istr->readAll(v.stm, v.returnValue);
            return v;
        });
}
/// \endcond

/// \cond INTERNAL
void
Media::StreamPrx::_iceI_closeStream(const ::std::shared_ptr<::IceInternal::OutgoingAsyncT<void>>& outAsync, const ::std::string& iceP_callid, const ::std::string& iceP_id, const ::Ice::Context& context)
{
    outAsync->invoke(iceC_Media_Stream_closeStream_name, ::Ice::OperationMode::Normal, ::Ice::FormatType::DefaultFormat, context,
        [&](::Ice::OutputStream* ostr)
        {
            ostr->writeAll(iceP_callid, iceP_id);
        },
        nullptr);
}
/// \endcond

/// \cond INTERNAL
void
Media::StreamPrx::_iceI_getStreamStatic(const ::std::shared_ptr<::IceInternal::OutgoingAsyncT<StreamStatic>>& outAsync, const ::std::string& iceP_id, const ::Ice::Context& context)
{
    _checkTwowayOnly(iceC_Media_Stream_getStreamStatic_name);
    outAsync->invoke(iceC_Media_Stream_getStreamStatic_name, ::Ice::OperationMode::Normal, ::Ice::FormatType::DefaultFormat, context,
        [&](::Ice::OutputStream* ostr)
        {
            ostr->writeAll(iceP_id);
        },
        nullptr);
}
/// \endcond

/// \cond INTERNAL
void
Media::StreamPrx::_iceI_getRecordFiles(const ::std::shared_ptr<::IceInternal::OutgoingAsyncT<void>>& outAsync, const ::std::string& iceP_startTime, const ::std::string& iceP_endtime, const ::Ice::Context& context)
{
    outAsync->invoke(iceC_Media_Stream_getRecordFiles_name, ::Ice::OperationMode::Normal, ::Ice::FormatType::DefaultFormat, context,
        [&](::Ice::OutputStream* ostr)
        {
            ostr->writeAll(iceP_startTime, iceP_endtime);
        },
        nullptr);
}
/// \endcond

/// \cond INTERNAL
void
Media::StreamPrx::_iceI_openVodStream(const ::std::shared_ptr<::IceInternal::OutgoingAsyncT<RealStreamRespParam>>& outAsync, const RealStreamReqParam& iceP_req, const ::Ice::Context& context)
{
    _checkTwowayOnly(iceC_Media_Stream_openVodStream_name);
    outAsync->invoke(iceC_Media_Stream_openVodStream_name, ::Ice::OperationMode::Normal, ::Ice::FormatType::DefaultFormat, context,
        [&](::Ice::OutputStream* ostr)
        {
            ostr->writeAll(iceP_req);
        },
        nullptr);
}
/// \endcond

/// \cond INTERNAL
void
Media::StreamPrx::_iceI_closeVodStream(const ::std::shared_ptr<::IceInternal::OutgoingAsyncT<void>>& outAsync, const ::std::string& iceP_callid, const ::std::string& iceP_id, const ::Ice::Context& context)
{
    outAsync->invoke(iceC_Media_Stream_closeVodStream_name, ::Ice::OperationMode::Normal, ::Ice::FormatType::DefaultFormat, context,
        [&](::Ice::OutputStream* ostr)
        {
            ostr->writeAll(iceP_callid, iceP_id);
        },
        nullptr);
}
/// \endcond

/// \cond INTERNAL
void
Media::StreamPrx::_iceI_controlVodStream(const ::std::shared_ptr<::IceInternal::OutgoingAsyncT<void>>& outAsync, const ::std::string& iceP_cmd, const ::std::string& iceP_callid, const ::std::string& iceP_id, const ::Ice::Context& context)
{
    outAsync->invoke(iceC_Media_Stream_controlVodStream_name, ::Ice::OperationMode::Normal, ::Ice::FormatType::DefaultFormat, context,
        [&](::Ice::OutputStream* ostr)
        {
            ostr->writeAll(iceP_cmd, iceP_callid, iceP_id);
        },
        nullptr);
}
/// \endcond

/// \cond INTERNAL
::std::shared_ptr<::Ice::ObjectPrx>
Media::StreamPrx::_newInstance() const
{
    return ::IceInternal::createProxy<StreamPrx>();
}
/// \endcond

const ::std::string&
Media::StreamPrx::ice_staticId()
{
    return Stream::ice_staticId();
}

namespace Ice
{
}

#else // C++98 mapping

namespace
{

const ::std::string iceC_Media_Stream_openRealStream_name = "openRealStream";

const ::std::string iceC_Media_Stream_closeStream_name = "closeStream";

const ::std::string iceC_Media_Stream_getStreamStatic_name = "getStreamStatic";

const ::std::string iceC_Media_Stream_getRecordFiles_name = "getRecordFiles";

const ::std::string iceC_Media_Stream_openVodStream_name = "openVodStream";

const ::std::string iceC_Media_Stream_closeVodStream_name = "closeVodStream";

const ::std::string iceC_Media_Stream_controlVodStream_name = "controlVodStream";

}

namespace
{

const ::IceInternal::DefaultUserExceptionFactoryInit< ::Media::RequestCanceledException> iceC_Media_RequestCanceledException_init("::Media::RequestCanceledException");

}

Media::RequestCanceledException::~RequestCanceledException() throw()
{
}

::std::string
Media::RequestCanceledException::ice_id() const
{
    return "::Media::RequestCanceledException";
}

Media::RequestCanceledException*
Media::RequestCanceledException::ice_clone() const
{
    return new RequestCanceledException(*this);
}

void
Media::RequestCanceledException::ice_throw() const
{
    throw *this;
}

/// \cond STREAM
void
Media::RequestCanceledException::_writeImpl(::Ice::OutputStream* ostr) const
{
    ostr->startSlice("::Media::RequestCanceledException", -1, true);
    ::Ice::StreamWriter< RequestCanceledException, ::Ice::OutputStream>::write(ostr, *this);
    ostr->endSlice();
}

void
Media::RequestCanceledException::_readImpl(::Ice::InputStream* istr)
{
    istr->startSlice();
    ::Ice::StreamReader< RequestCanceledException, ::Ice::InputStream>::read(istr, *this);
    istr->endSlice();
}
/// \endcond

namespace
{

const ::IceInternal::DefaultUserExceptionFactoryInit< ::Media::OpenStreamException> iceC_Media_OpenStreamException_init("::Media::OpenStreamException");

}

Media::OpenStreamException::OpenStreamException(const ::std::string& callid, const ::std::string& reason) :
    ::Ice::UserException(),
    callid(callid),
    reason(reason)
{
}

Media::OpenStreamException::~OpenStreamException() throw()
{
}

::std::string
Media::OpenStreamException::ice_id() const
{
    return "::Media::OpenStreamException";
}

Media::OpenStreamException*
Media::OpenStreamException::ice_clone() const
{
    return new OpenStreamException(*this);
}

void
Media::OpenStreamException::ice_throw() const
{
    throw *this;
}

/// \cond STREAM
void
Media::OpenStreamException::_writeImpl(::Ice::OutputStream* ostr) const
{
    ostr->startSlice("::Media::OpenStreamException", -1, true);
    ::Ice::StreamWriter< OpenStreamException, ::Ice::OutputStream>::write(ostr, *this);
    ostr->endSlice();
}

void
Media::OpenStreamException::_readImpl(::Ice::InputStream* istr)
{
    istr->startSlice();
    ::Ice::StreamReader< OpenStreamException, ::Ice::InputStream>::read(istr, *this);
    istr->endSlice();
}
/// \endcond

Media::AMD_Stream_openRealStream::~AMD_Stream_openRealStream()
{
}

Media::AMD_Stream_closeStream::~AMD_Stream_closeStream()
{
}

/// \cond INTERNAL
IceAsync::Media::AMD_Stream_openRealStream::AMD_Stream_openRealStream(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Media::AMD_Stream_openRealStream::ice_response(bool ret, const ::Media::RealStreamRespParam& stm)
{
    ::Ice::OutputStream* ostr = startWriteParams();
    ostr->write(stm);
    ostr->write(ret);
    endWriteParams();
    completed();
}
/// \endcond

/// \cond INTERNAL
IceAsync::Media::AMD_Stream_closeStream::AMD_Stream_closeStream(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::Media::AMD_Stream_closeStream::ice_response()
{
    writeEmptyParams();
    completed();
}
/// \endcond

/// \cond INTERNAL
::IceProxy::Ice::Object* ::IceProxy::Media::upCast(Stream* p) { return p; }

void
::IceProxy::Media::_readProxy(::Ice::InputStream* istr, ::IceInternal::ProxyHandle< Stream>& v)
{
    ::Ice::ObjectPrx proxy;
    istr->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new Stream;
        v->_copyFrom(proxy);
    }
}
/// \endcond

::Ice::AsyncResultPtr
IceProxy::Media::Stream::_iceI_begin_openRealStream(const ::Media::RealStreamReqParam& iceP_ctg, const ::Ice::Context& context, const ::IceInternal::CallbackBasePtr& del, const ::Ice::LocalObjectPtr& cookie, bool sync)
{
    _checkTwowayOnly(iceC_Media_Stream_openRealStream_name, sync);
    ::IceInternal::OutgoingAsyncPtr result = new ::IceInternal::CallbackOutgoing(this, iceC_Media_Stream_openRealStream_name, del, cookie, sync);
    try
    {
        result->prepare(iceC_Media_Stream_openRealStream_name, ::Ice::Normal, context);
        ::Ice::OutputStream* ostr = result->startWriteParams(::Ice::DefaultFormat);
        ostr->write(iceP_ctg);
        result->endWriteParams();
        result->invoke(iceC_Media_Stream_openRealStream_name);
    }
    catch(const ::Ice::Exception& ex)
    {
        result->abort(ex);
    }
    return result;
}

bool
IceProxy::Media::Stream::end_openRealStream(::Media::RealStreamRespParam& iceP_stm, const ::Ice::AsyncResultPtr& result)
{
    ::Ice::AsyncResult::_check(result, this, iceC_Media_Stream_openRealStream_name);
    bool ret;
    if(!result->_waitForResponse())
    {
        try
        {
            result->_throwUserException();
        }
        catch(const ::Ice::UserException& ex)
        {
            throw ::Ice::UnknownUserException(__FILE__, __LINE__, ex.ice_id());
        }
    }
    ::Ice::InputStream* istr = result->_startReadParams();
    istr->read(iceP_stm);
    istr->read(ret);
    result->_endReadParams();
    return ret;
}

void IceProxy::Media::Stream::_iceI_end_openRealStream(::Media::RealStreamRespParam& iceP_stm, bool& ret, const ::Ice::AsyncResultPtr& result)
{
    ::Ice::AsyncResult::_check(result, this, iceC_Media_Stream_openRealStream_name);
    if(!result->_waitForResponse())
    {
        try
        {
            result->_throwUserException();
        }
        catch(const ::Ice::UserException& ex)
        {
            throw ::Ice::UnknownUserException(__FILE__, __LINE__, ex.ice_id());
        }
    }
    ::Ice::InputStream* istr = result->_startReadParams();
    istr->read(iceP_stm);
    istr->read(ret);
    result->_endReadParams();
}

::Ice::AsyncResultPtr
IceProxy::Media::Stream::_iceI_begin_closeStream(const ::std::string& iceP_callid, const ::std::string& iceP_id, const ::Ice::Context& context, const ::IceInternal::CallbackBasePtr& del, const ::Ice::LocalObjectPtr& cookie, bool sync)
{
    ::IceInternal::OutgoingAsyncPtr result = new ::IceInternal::CallbackOutgoing(this, iceC_Media_Stream_closeStream_name, del, cookie, sync);
    try
    {
        result->prepare(iceC_Media_Stream_closeStream_name, ::Ice::Normal, context);
        ::Ice::OutputStream* ostr = result->startWriteParams(::Ice::DefaultFormat);
        ostr->write(iceP_callid);
        ostr->write(iceP_id);
        result->endWriteParams();
        result->invoke(iceC_Media_Stream_closeStream_name);
    }
    catch(const ::Ice::Exception& ex)
    {
        result->abort(ex);
    }
    return result;
}

void
IceProxy::Media::Stream::end_closeStream(const ::Ice::AsyncResultPtr& result)
{
    _end(result, iceC_Media_Stream_closeStream_name);
}

::Ice::AsyncResultPtr
IceProxy::Media::Stream::_iceI_begin_getStreamStatic(const ::std::string& iceP_id, const ::Ice::Context& context, const ::IceInternal::CallbackBasePtr& del, const ::Ice::LocalObjectPtr& cookie, bool sync)
{
    _checkTwowayOnly(iceC_Media_Stream_getStreamStatic_name, sync);
    ::IceInternal::OutgoingAsyncPtr result = new ::IceInternal::CallbackOutgoing(this, iceC_Media_Stream_getStreamStatic_name, del, cookie, sync);
    try
    {
        result->prepare(iceC_Media_Stream_getStreamStatic_name, ::Ice::Normal, context);
        ::Ice::OutputStream* ostr = result->startWriteParams(::Ice::DefaultFormat);
        ostr->write(iceP_id);
        result->endWriteParams();
        result->invoke(iceC_Media_Stream_getStreamStatic_name);
    }
    catch(const ::Ice::Exception& ex)
    {
        result->abort(ex);
    }
    return result;
}

void
IceProxy::Media::Stream::end_getStreamStatic(::Media::StreamStatic& iceP_static, const ::Ice::AsyncResultPtr& result)
{
    ::Ice::AsyncResult::_check(result, this, iceC_Media_Stream_getStreamStatic_name);
    if(!result->_waitForResponse())
    {
        try
        {
            result->_throwUserException();
        }
        catch(const ::Ice::UserException& ex)
        {
            throw ::Ice::UnknownUserException(__FILE__, __LINE__, ex.ice_id());
        }
    }
    ::Ice::InputStream* istr = result->_startReadParams();
    istr->read(iceP_static);
    result->_endReadParams();
}

void IceProxy::Media::Stream::_iceI_end_getStreamStatic(::Media::StreamStatic& iceP_static, const ::Ice::AsyncResultPtr& result)
{
    ::Ice::AsyncResult::_check(result, this, iceC_Media_Stream_getStreamStatic_name);
    if(!result->_waitForResponse())
    {
        try
        {
            result->_throwUserException();
        }
        catch(const ::Ice::UserException& ex)
        {
            throw ::Ice::UnknownUserException(__FILE__, __LINE__, ex.ice_id());
        }
    }
    ::Ice::InputStream* istr = result->_startReadParams();
    istr->read(iceP_static);
    result->_endReadParams();
}

::Ice::AsyncResultPtr
IceProxy::Media::Stream::_iceI_begin_getRecordFiles(const ::std::string& iceP_startTime, const ::std::string& iceP_endtime, const ::Ice::Context& context, const ::IceInternal::CallbackBasePtr& del, const ::Ice::LocalObjectPtr& cookie, bool sync)
{
    ::IceInternal::OutgoingAsyncPtr result = new ::IceInternal::CallbackOutgoing(this, iceC_Media_Stream_getRecordFiles_name, del, cookie, sync);
    try
    {
        result->prepare(iceC_Media_Stream_getRecordFiles_name, ::Ice::Normal, context);
        ::Ice::OutputStream* ostr = result->startWriteParams(::Ice::DefaultFormat);
        ostr->write(iceP_startTime);
        ostr->write(iceP_endtime);
        result->endWriteParams();
        result->invoke(iceC_Media_Stream_getRecordFiles_name);
    }
    catch(const ::Ice::Exception& ex)
    {
        result->abort(ex);
    }
    return result;
}

void
IceProxy::Media::Stream::end_getRecordFiles(const ::Ice::AsyncResultPtr& result)
{
    _end(result, iceC_Media_Stream_getRecordFiles_name);
}

::Ice::AsyncResultPtr
IceProxy::Media::Stream::_iceI_begin_openVodStream(const ::Media::RealStreamReqParam& iceP_req, const ::Ice::Context& context, const ::IceInternal::CallbackBasePtr& del, const ::Ice::LocalObjectPtr& cookie, bool sync)
{
    _checkTwowayOnly(iceC_Media_Stream_openVodStream_name, sync);
    ::IceInternal::OutgoingAsyncPtr result = new ::IceInternal::CallbackOutgoing(this, iceC_Media_Stream_openVodStream_name, del, cookie, sync);
    try
    {
        result->prepare(iceC_Media_Stream_openVodStream_name, ::Ice::Normal, context);
        ::Ice::OutputStream* ostr = result->startWriteParams(::Ice::DefaultFormat);
        ostr->write(iceP_req);
        result->endWriteParams();
        result->invoke(iceC_Media_Stream_openVodStream_name);
    }
    catch(const ::Ice::Exception& ex)
    {
        result->abort(ex);
    }
    return result;
}

void
IceProxy::Media::Stream::end_openVodStream(::Media::RealStreamRespParam& iceP_resp, const ::Ice::AsyncResultPtr& result)
{
    ::Ice::AsyncResult::_check(result, this, iceC_Media_Stream_openVodStream_name);
    if(!result->_waitForResponse())
    {
        try
        {
            result->_throwUserException();
        }
        catch(const ::Ice::UserException& ex)
        {
            throw ::Ice::UnknownUserException(__FILE__, __LINE__, ex.ice_id());
        }
    }
    ::Ice::InputStream* istr = result->_startReadParams();
    istr->read(iceP_resp);
    result->_endReadParams();
}

void IceProxy::Media::Stream::_iceI_end_openVodStream(::Media::RealStreamRespParam& iceP_resp, const ::Ice::AsyncResultPtr& result)
{
    ::Ice::AsyncResult::_check(result, this, iceC_Media_Stream_openVodStream_name);
    if(!result->_waitForResponse())
    {
        try
        {
            result->_throwUserException();
        }
        catch(const ::Ice::UserException& ex)
        {
            throw ::Ice::UnknownUserException(__FILE__, __LINE__, ex.ice_id());
        }
    }
    ::Ice::InputStream* istr = result->_startReadParams();
    istr->read(iceP_resp);
    result->_endReadParams();
}

::Ice::AsyncResultPtr
IceProxy::Media::Stream::_iceI_begin_closeVodStream(const ::std::string& iceP_callid, const ::std::string& iceP_id, const ::Ice::Context& context, const ::IceInternal::CallbackBasePtr& del, const ::Ice::LocalObjectPtr& cookie, bool sync)
{
    ::IceInternal::OutgoingAsyncPtr result = new ::IceInternal::CallbackOutgoing(this, iceC_Media_Stream_closeVodStream_name, del, cookie, sync);
    try
    {
        result->prepare(iceC_Media_Stream_closeVodStream_name, ::Ice::Normal, context);
        ::Ice::OutputStream* ostr = result->startWriteParams(::Ice::DefaultFormat);
        ostr->write(iceP_callid);
        ostr->write(iceP_id);
        result->endWriteParams();
        result->invoke(iceC_Media_Stream_closeVodStream_name);
    }
    catch(const ::Ice::Exception& ex)
    {
        result->abort(ex);
    }
    return result;
}

void
IceProxy::Media::Stream::end_closeVodStream(const ::Ice::AsyncResultPtr& result)
{
    _end(result, iceC_Media_Stream_closeVodStream_name);
}

::Ice::AsyncResultPtr
IceProxy::Media::Stream::_iceI_begin_controlVodStream(const ::std::string& iceP_cmd, const ::std::string& iceP_callid, const ::std::string& iceP_id, const ::Ice::Context& context, const ::IceInternal::CallbackBasePtr& del, const ::Ice::LocalObjectPtr& cookie, bool sync)
{
    ::IceInternal::OutgoingAsyncPtr result = new ::IceInternal::CallbackOutgoing(this, iceC_Media_Stream_controlVodStream_name, del, cookie, sync);
    try
    {
        result->prepare(iceC_Media_Stream_controlVodStream_name, ::Ice::Normal, context);
        ::Ice::OutputStream* ostr = result->startWriteParams(::Ice::DefaultFormat);
        ostr->write(iceP_cmd);
        ostr->write(iceP_callid);
        ostr->write(iceP_id);
        result->endWriteParams();
        result->invoke(iceC_Media_Stream_controlVodStream_name);
    }
    catch(const ::Ice::Exception& ex)
    {
        result->abort(ex);
    }
    return result;
}

void
IceProxy::Media::Stream::end_controlVodStream(const ::Ice::AsyncResultPtr& result)
{
    _end(result, iceC_Media_Stream_controlVodStream_name);
}

/// \cond INTERNAL
::IceProxy::Ice::Object*
IceProxy::Media::Stream::_newInstance() const
{
    return new Stream;
}
/// \endcond

const ::std::string&
IceProxy::Media::Stream::ice_staticId()
{
    return ::Media::Stream::ice_staticId();
}

Media::Stream::~Stream()
{
}

/// \cond INTERNAL
::Ice::Object* Media::upCast(Stream* p) { return p; }

/// \endcond

namespace
{
const ::std::string iceC_Media_Stream_ids[2] =
{
    "::Ice::Object",
    "::Media::Stream"
};

}

bool
Media::Stream::ice_isA(const ::std::string& s, const ::Ice::Current&) const
{
    return ::std::binary_search(iceC_Media_Stream_ids, iceC_Media_Stream_ids + 2, s);
}

::std::vector< ::std::string>
Media::Stream::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&iceC_Media_Stream_ids[0], &iceC_Media_Stream_ids[2]);
}

const ::std::string&
Media::Stream::ice_id(const ::Ice::Current&) const
{
    return ice_staticId();
}

const ::std::string&
Media::Stream::ice_staticId()
{
#ifdef ICE_HAS_THREAD_SAFE_LOCAL_STATIC
    static const ::std::string typeId = "::Media::Stream";
    return typeId;
#else
    return iceC_Media_Stream_ids[1];
#endif
}

/// \cond INTERNAL
bool
Media::Stream::_iceD_openRealStream(::IceInternal::Incoming& inS, const ::Ice::Current& current)
{
    _iceCheckMode(::Ice::Normal, current.mode);
    ::Ice::InputStream* istr = inS.startReadParams();
    RealStreamReqParam iceP_ctg;
    istr->read(iceP_ctg);
    inS.endReadParams();
    this->openRealStream_async(new IceAsync::Media::AMD_Stream_openRealStream(inS), iceP_ctg, current);
    return false;
}
/// \endcond

/// \cond INTERNAL
bool
Media::Stream::_iceD_closeStream(::IceInternal::Incoming& inS, const ::Ice::Current& current)
{
    _iceCheckMode(::Ice::Normal, current.mode);
    ::Ice::InputStream* istr = inS.startReadParams();
    ::std::string iceP_callid;
    ::std::string iceP_id;
    istr->read(iceP_callid);
    istr->read(iceP_id);
    inS.endReadParams();
    this->closeStream_async(new IceAsync::Media::AMD_Stream_closeStream(inS), iceP_callid, iceP_id, current);
    return false;
}
/// \endcond

/// \cond INTERNAL
bool
Media::Stream::_iceD_getStreamStatic(::IceInternal::Incoming& inS, const ::Ice::Current& current)
{
    _iceCheckMode(::Ice::Normal, current.mode);
    ::Ice::InputStream* istr = inS.startReadParams();
    ::std::string iceP_id;
    istr->read(iceP_id);
    inS.endReadParams();
    StreamStatic iceP_static;
    this->getStreamStatic(iceP_id, iceP_static, current);
    ::Ice::OutputStream* ostr = inS.startWriteParams();
    ostr->write(iceP_static);
    inS.endWriteParams();
    return true;
}
/// \endcond

/// \cond INTERNAL
bool
Media::Stream::_iceD_getRecordFiles(::IceInternal::Incoming& inS, const ::Ice::Current& current)
{
    _iceCheckMode(::Ice::Normal, current.mode);
    ::Ice::InputStream* istr = inS.startReadParams();
    ::std::string iceP_startTime;
    ::std::string iceP_endtime;
    istr->read(iceP_startTime);
    istr->read(iceP_endtime);
    inS.endReadParams();
    this->getRecordFiles(iceP_startTime, iceP_endtime, current);
    inS.writeEmptyParams();
    return true;
}
/// \endcond

/// \cond INTERNAL
bool
Media::Stream::_iceD_openVodStream(::IceInternal::Incoming& inS, const ::Ice::Current& current)
{
    _iceCheckMode(::Ice::Normal, current.mode);
    ::Ice::InputStream* istr = inS.startReadParams();
    RealStreamReqParam iceP_req;
    istr->read(iceP_req);
    inS.endReadParams();
    RealStreamRespParam iceP_resp;
    this->openVodStream(iceP_req, iceP_resp, current);
    ::Ice::OutputStream* ostr = inS.startWriteParams();
    ostr->write(iceP_resp);
    inS.endWriteParams();
    return true;
}
/// \endcond

/// \cond INTERNAL
bool
Media::Stream::_iceD_closeVodStream(::IceInternal::Incoming& inS, const ::Ice::Current& current)
{
    _iceCheckMode(::Ice::Normal, current.mode);
    ::Ice::InputStream* istr = inS.startReadParams();
    ::std::string iceP_callid;
    ::std::string iceP_id;
    istr->read(iceP_callid);
    istr->read(iceP_id);
    inS.endReadParams();
    this->closeVodStream(iceP_callid, iceP_id, current);
    inS.writeEmptyParams();
    return true;
}
/// \endcond

/// \cond INTERNAL
bool
Media::Stream::_iceD_controlVodStream(::IceInternal::Incoming& inS, const ::Ice::Current& current)
{
    _iceCheckMode(::Ice::Normal, current.mode);
    ::Ice::InputStream* istr = inS.startReadParams();
    ::std::string iceP_cmd;
    ::std::string iceP_callid;
    ::std::string iceP_id;
    istr->read(iceP_cmd);
    istr->read(iceP_callid);
    istr->read(iceP_id);
    inS.endReadParams();
    this->controlVodStream(iceP_cmd, iceP_callid, iceP_id, current);
    inS.writeEmptyParams();
    return true;
}
/// \endcond

namespace
{
const ::std::string iceC_Media_Stream_all[] =
{
    "closeStream",
    "closeVodStream",
    "controlVodStream",
    "getRecordFiles",
    "getStreamStatic",
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "openRealStream",
    "openVodStream"
};

}

/// \cond INTERNAL
bool
Media::Stream::_iceDispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair<const ::std::string*, const ::std::string*> r = ::std::equal_range(iceC_Media_Stream_all, iceC_Media_Stream_all + 11, current.operation);
    if(r.first == r.second)
    {
        throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
    }

    switch(r.first - iceC_Media_Stream_all)
    {
        case 0:
        {
            return _iceD_closeStream(in, current);
        }
        case 1:
        {
            return _iceD_closeVodStream(in, current);
        }
        case 2:
        {
            return _iceD_controlVodStream(in, current);
        }
        case 3:
        {
            return _iceD_getRecordFiles(in, current);
        }
        case 4:
        {
            return _iceD_getStreamStatic(in, current);
        }
        case 5:
        {
            return _iceD_ice_id(in, current);
        }
        case 6:
        {
            return _iceD_ice_ids(in, current);
        }
        case 7:
        {
            return _iceD_ice_isA(in, current);
        }
        case 8:
        {
            return _iceD_ice_ping(in, current);
        }
        case 9:
        {
            return _iceD_openRealStream(in, current);
        }
        case 10:
        {
            return _iceD_openVodStream(in, current);
        }
        default:
        {
            assert(false);
            throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
        }
    }
}
/// \endcond

/// \cond STREAM
void
Media::Stream::_iceWriteImpl(::Ice::OutputStream* ostr) const
{
    ostr->startSlice(ice_staticId(), -1, true);
    ::Ice::StreamWriter< Stream, ::Ice::OutputStream>::write(ostr, *this);
    ostr->endSlice();
}

void
Media::Stream::_iceReadImpl(::Ice::InputStream* istr)
{
    istr->startSlice();
    ::Ice::StreamReader< Stream, ::Ice::InputStream>::read(istr, *this);
    istr->endSlice();
}
/// \endcond

/// \cond INTERNAL
void
Media::_icePatchObjectPtr(StreamPtr& handle, const ::Ice::ObjectPtr& v)
{
    handle = StreamPtr::dynamicCast(v);
    if(v && !handle)
    {
        IceInternal::Ex::throwUOE(Stream::ice_staticId(), v);
    }
}
/// \endcond

namespace Ice
{
}

#endif