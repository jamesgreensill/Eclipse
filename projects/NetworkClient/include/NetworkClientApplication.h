#pragma once

#include <EclipseEngine/include/Application.h>

class NetworkClientApplication :
    public Eclipse::Engine::Application
{
public:
	void OnCreated() override;
	void OnBoot() override;
	void OnEngineInit() override;
	void OnAwake() override;
	void OnDisposed() override;
};

