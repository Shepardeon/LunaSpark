#include "AppBuilder.h"

using namespace LunaSpark::Core;

AppBuilder::AppBuilder()
{
    app = std::make_unique<App>();
}

std::unique_ptr<App> AppBuilder::Build()
{
    return std::move(app);
}

AppBuilder& AppBuilder::WithName(std::string name)
{
    app->_name = name;
    return *this;
}
