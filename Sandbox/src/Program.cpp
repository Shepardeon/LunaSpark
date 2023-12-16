#include "Core/App/AppBuilder.h"
#include "Core/Service/IService.h"
#include <iostream>

class TestService : public LunaSpark::Core::IService
{
public:
    void ResolveDependencies() override
    {}

    void RunTest()
    {
        std::cout << "Hello from TestService" << std::endl;
    }
};

int main()
{
    auto app = LunaSpark::Core::AppBuilder()
        .WithName("Example")
        //.WithRunner([](LunaSpark::Core::App app) -> void { app.PrintName(); })
        .AddService<TestService>()
        .Build();

    app->Run();
    auto svc = app->Resolve<TestService>();
    svc.RunTest();
}
