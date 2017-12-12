#pragma once
#include <stdexcept>
#include <string>
class GlInitializationFail :
	public std::logic_error
{
public:
	GlInitializationFail(const std::string &what);
	~GlInitializationFail();
};

