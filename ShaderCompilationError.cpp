#include "ShaderCompilationError.h"



ShaderCompilationError::ShaderCompilationError(const std::string &what): std::logic_error(what)
{}

ShaderCompilationError::~ShaderCompilationError()
{
}
