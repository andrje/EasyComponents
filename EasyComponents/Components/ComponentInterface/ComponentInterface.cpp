#include "ComponentInterface.h"


// dTor
ComponentInterface::~ComponentInterface()
{}



// get type
const std::string& ComponentInterface::get_type()
{
	return *component_type_;
}


// get name
const std::string& ComponentInterface::get_name()
{
	return *instance_name_;
}


// get id
const size_t ComponentInterface::get_id()
{
	return instance_id_;
}

