#include "Core/App/AppBuilder.h"

int main()
{
    auto app = LunaSpark::Core::AppBuilder()
        .WithName("Example")
        .Build();

    app->PrintName();
}
