# Eziapi

Everything is in the "Api" namespace.

## Api::Http namespace

|Enum classes|Description|
|-|-|
|Code|Contains some useful HTTP codes|
|Verb|Contains some HTTP request verbs|
|Version|Contains the supported versions of the HTTP protocol|

**KeyValue** : A map of string values with string keys.

|Structs|Description|
|-|-|
|Request|Represents an HTTP request|
|Response|Represents an HTTP response|
|Info|Contains some informations about the request|

## Api::Config

**Null** -> Represents a null value.

**Array** -> Represents a Json array

**Object** -> Represents a Json object

**Value** -> Represents a type, types can be :
- string
- int
- double
- bool
- Null
- Array
- Object

Like union, **variant** can take any values as long as it is templated with the right types.

### Example
```cpp
// Create a Value with the type std::string
Api::Config::Value jsonValue = std::string("This is a string");
// Get back the value and print it
// boost::get throw an exception if it is not the right type (see also: boost::get_if)
std::cout << boost::get<std::string>(jsonValue) << std::endl;

// Create a Json Object
Api::Config::Object jsonObject;
jsonObject["string"] = std::string("This is a string");
jsonObject["int"] = 5;
jsonObject["double"] = 5.0;
jsonObject["bool"] = true;
jsonObject["array"] = Api::Config::Array{1, 2, 3, 4, 5};

// the Value will now contain an Object
jsonValue = jsonObject;

// You can get back the Json Object like any other types
Api::Config::Object obj = boost::get<Api::Config::Object>(jsonValue);
std::cout << "string: " << boost::get<std::string>(obj["string"]) << std::endl;
std::cout << "int: " << boost::get<int>(obj["int"]) << std::endl;
std::cout << "double: " << boost::get<double>(obj["double"]) << std::endl;
std::cout << "bool: " << boost::get<bool>(obj["bool"]) << std::endl;
std::cout << "array size: " << boost::get<Api::Config::Array>(obj["array"]).size() << std::endl;
```

Output
```
This is a string
string: This is a string
int: 5
double: 5.000000
bool: true
array size: 5
```

**You should also look at Boost Visitor for a type safer alternative to boost::get**

## Api::IModule

|Methods|Description|
|-|-|
|configure|Loads a configuration passed as parameter|
|run|Runs the module logic, takes a Request, a Response and an Info struct as paremeters|

### Example
```cpp
std::vector<Api::IModule*> modules; // Contains the loaded modules
Api::Http::Request request; // The parsed request sent by the client
Api::Http::Resonse response; // The response to send back to the client
Api::Http::Info info; // The informations of the client

for (auto module : modules) {
    module->run(request, response, info);
}
```