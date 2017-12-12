#pragma once
#include <stdexcept>
class ShaderCompilationError :
	public std::logic_error
{
public:
	ShaderCompilationError(const std::string &what);
	virtual ~ShaderCompilationError();
};

