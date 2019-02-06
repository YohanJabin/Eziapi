/**
* \file Config.hpp
* \brief Config header
*/

#pragma once

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wparentheses"
#include <boost/variant.hpp>
#pragma GCC diagnostic pop

#include <string>
#include <vector>
#include <map>

/**
* \namespace Api::Config
* \brief Everything about Api::Config goes here
*/
namespace Api::Config
{
	/**
	* \struct Null
	* \brief Represent a json null value
	*/
	struct Null
	{
	};

	/**
	* \brief Reprensent any json value
	*/
	using Value = boost::make_recursive_variant<std::string,
												int,
												double,
												bool,
												std::map<std::string, boost::recursive_variant_>,
												std::vector<boost::recursive_variant_>,
												Null>::type;
	/**
	* \brief Reprensent a json array
	*/
	using Array = std::vector<Value>;
	/**
	* \brief Reprensent any json object
	*/
	using Object = std::map<std::string, Value>;
}