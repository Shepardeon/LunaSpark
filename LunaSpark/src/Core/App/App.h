#pragma once

#include <string>
#include <functional>

namespace LunaSpark::Core
{
    class App
    {
    public:
        void PrintName();
        void Run();

    private:
        friend class AppBuilder;

        std::string _name;
        std::function<void(App&)> _runner;
    };
}

