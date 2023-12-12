#include "Core/App/AppBuilder.h"

int main()
{
    auto app = LunaSpark::Core::AppBuilder()
        .WithName("Example")
        //.WithRunner([](LunaSpark::Core::App app) -> void { app.PrintName(); })
        .Build();

    app->Run();
}
