#include "App.h"
#include <iostream>

using namespace LunaSpark::Core;

void App::PrintName()
{
    std::cout << this->_name << std::endl;
}

void App::Run()
{
    this->_runner(*this);
}
