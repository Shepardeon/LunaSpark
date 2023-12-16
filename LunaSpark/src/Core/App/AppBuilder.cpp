#include "AppBuilder.h"

#include <iostream>

using namespace LunaSpark::Core;

void DefaultRunner(App& app)
{
    std::cout << "Executing default runner" << std::endl;
    app.PrintName();
}

AppBuilder::AppBuilder()
{
    app = std::make_unique<App>();
    app->_runner = DefaultRunner;
    app->_services = std::make_unique<ServiceCollection>();
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

AppBuilder& AppBuilder::WithRunner(std::function<void(App&)> runner)
{
    app->_runner = runner;
    return *this;
}
