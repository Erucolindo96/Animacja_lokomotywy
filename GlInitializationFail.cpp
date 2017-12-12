#include "GlInitializationFail.h"


GlInitializationFail::GlInitializationFail(const std::string & what) : std::logic_error(what)
{}

GlInitializationFail::~GlInitializationFail()
{}
