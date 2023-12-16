#pragma once

namespace LunaSpark::Core
{
    class IService
    {
    public:
        virtual void ResolveDependencies() = 0;
    };
}
