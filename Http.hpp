/**
* \file Http.hpp
* \brief Http header
*/

#pragma once

#include <map>
#include <chrono>

/**
* \namespace Api::Http
* \brief Everything about Api::Http goes here
*/
namespace Api::Http
{
	/**
	* \enum Code
	* \brief Describe all http status code for http response
	*/
	enum class Code
	{
		UNKNOWN							= -1,
		CONTINUE                        = 100,
		SWITCHING_PROTOCOLS             = 101,
		OK                              = 200,
		CREATED                         = 201,
		ACCEPTED                        = 202,
		NONAUTHORITATIVE_INFORMATION    = 203,
		NO_CONTENT                      = 204,
		RESET_CONTENT                   = 205,
		PARTIAL_CONTENT                 = 206,
		MULTIPLE_CHOICES                = 300,
		MOVED_PERMANENTLY               = 301,
		FOUND                           = 302,
		SEE_OTHER                       = 303,
		NOT_MODIFIED                    = 304,
		USE_PROXY                       = 305,
		TEMPORARY_REDIRECT              = 307,
		BAD_REQUEST                     = 400,
		UNAUTHORIZED                    = 401,
		PAYMENT_REQUIRED                = 402,
		FORBIDDEN                       = 403,
		NOT_FOUND                       = 404,
		METHOD_NOT_ALLOWED              = 405,
		NOT_ACCEPTABLE                  = 406,
		PROXY_AUTHENTICATION_REQUIRED   = 407,
		REQUEST_TIMEOUT                 = 408,
		CONFLICT                        = 409,
		GONE                            = 410,
		LENGTH_REQUIRED                 = 411,
		PRECONDITION_FAILED             = 412,
		REQUEST_ENTITY_TOO_LARGE        = 413,
		REQUEST_URI_TOO_LARGE           = 414,
		UNSUPPORTED_MEDIA_TYPE          = 415,
		REQUESTED_RANGE_NOT_SATISFIABLE = 416,
		EXPECTATION_FAILED              = 417,
		IM_A_TEAPOT                     = 418,
		INTERNAL_SERVER_ERROR           = 500,
		NOT_IMPLEMENTED                 = 501,
		BAD_GATEWAY                     = 502,
		SERVICE_UNAVAILABLE             = 503,
		GATEWAY_TIMEOUT                 = 504,
		HTTP_VERSION_NOT_SUPPORTED      = 505
	};

	/**
	* \enum Verb
	* \brief Describ all http verb (method) for http request
	*/
	enum class Verb
	{
        UNKNOWN = -1,
		OPTIONS,
		GET,
		HEAD,
		POST,
		PUT,
		DELETE,
		TRACE,
		CONNECT
    };

	/**
	* \enum Version
	* \brief Describe all http version for request and response
	*/
	enum class Version
	{
        UNKNOWN = -1,
		HTTP_0_9,
		HTTP_1_0,
		HTTP_1_1,
		HTTP_2_0
    };

	using KeyValue = std::map<std::string, std::string>;

	/**
	* \struct Request
	* \brief Describe a Http Request
	*/
	struct Request
	{
		Verb		verb;
		std::string	target;
		Version		version;
		KeyValue	header;
		std::string	body;
	};

	/**
	* \struct Response
	* \brief Describe a Http Response
	*/
	struct Response
	{
		Version		version;
		Code		code;
		std::string	reason;
		KeyValue	header;
		std::string	body;
	};

	struct Info
	{
		std::string								ip;
		std::uint16_t							port;
		std::chrono::system_clock::time_point	serverUpTime;
		std::chrono::system_clock::time_point	requestTime;
	};
}