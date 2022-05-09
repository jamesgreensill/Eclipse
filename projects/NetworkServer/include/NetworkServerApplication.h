#pragma once
#include "EclipseEngine/include/Application.h"


using namespace Eclipse;
using namespace Engine;

class NetworkServerApplication :
    public Application
{
public:
	void OnEngineInit() override;
};

