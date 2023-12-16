#pragma once

#include <string>
#include <functional>
#include <Core/Service/ServiceCollection.h>
#include <Core/Service/IService.h>

namespace LunaSpark::Core
{
    class App
    {
    public:
        void PrintName();
        void Run();

        template<class Service>
        Service& Resolve();

    private:
        friend class AppBuilder;

        std::string _name;
        std::function<void(App&)> _runner;
        std::unique_ptr<ServiceCollection> _services;
    };

    template<class Service>
    Service& App::Resolve()
    {
        return _services->GetService<Service>();
    }
}

