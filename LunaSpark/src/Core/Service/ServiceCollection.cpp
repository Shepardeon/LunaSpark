#include "Core/Service/ServiceCollection.h"

using namespace LunaSpark::Core;

void ServiceCollection::SetupRequirements()
{
    for (const auto& [key, svc] : _services)
    {
        svc->ResolveDependencies();
    }
}
