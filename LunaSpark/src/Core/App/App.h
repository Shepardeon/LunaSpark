#pragma once

#include <string>

namespace LunaSpark::Core
{
    class App
    {
    public:
        void PrintName();

    private:
        friend class AppBuilder;
        std::string _name;
    };
}

