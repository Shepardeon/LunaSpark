#pragma once

#include <string>
#include <map>
#include <memory>
#include "Core/Service/IService.h"

namespace LunaSpark::Core 
{
    class ServiceCollection
    {
    public:
        template<class Service, typename... Args>
        void AddService(Args&&... params);

        template<class Service>
        Service& GetService();

        void SetupRequirements();

    private:
        std::map<std::string, std::unique_ptr<IService>> _services;
    };

    template <class Service, typename... Args>
    void ServiceCollection::AddService(Args&&... params)
    {
        _services.try_emplace(typeid(Service).name(),
            std::make_unique<Service>(std::forward<Args>(params)...));
    }

    template<class Service>
    Service& ServiceCollection::GetService()
    {
        auto& svc = _services.at(typeid(Service).name());
        return *static_cast<Service*>(svc.get());
    }
}
