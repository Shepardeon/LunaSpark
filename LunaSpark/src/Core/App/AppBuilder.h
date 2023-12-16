#pragma once

#include <memory>
#include <string>
#include "App.h"

namespace LunaSpark::Core
{
    class AppBuilder
    {
    public:
        AppBuilder();
        std::unique_ptr<App> Build();

        AppBuilder& WithName(std::string);
        AppBuilder& WithRunner(std::function<void(App&)>);

        template<class Service, typename... Args>
        AppBuilder& AddService(Args&&... params);

    private:
        std::unique_ptr<App> app;
    };

    template<class Service, typename... Args>
    AppBuilder& AppBuilder::AddService(Args&&... params)
    {
        app->_services->AddService<Service>(params...);
        return *this;
    }
}
