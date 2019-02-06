/**
* \file IModule.hpp
* \brief IModule class
*/

#pragma once

#include "Http.hpp"
#include "Config.hpp"

/**
* \namespace Api
* \brief Everything about the Api goes here
*/
namespace Api
{
	/**
	* \class IModule
	* \brief Interface for modules
	*/
	class IModule
	{
	public:
		/**
		* \brief Virtual default destructor
		*/
		virtual ~IModule() = default;
		/**
		* \brief Configure the module
		* \param[in] Json object
		* \return 'true' if everything goes well, 'false' either
		*/
		virtual bool configure(const Api::Config::Value &) = 0;
		/**
		* \brief Run the module
		* \param[in] Http Request Object
		* \param[out] Http Response Object
		* \param[in] Http Info Object
		*/
		virtual void run(const Api::Http::Request &, Api::Http::Response &, const Api::Http::Info &) = 0;
	};
}