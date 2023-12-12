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

    private:
        std::unique_ptr<App> app;
    };
}
