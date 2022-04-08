#pragma once
#include "Application.h"


class DemoApplication : public Eclipse::Engine::Application
{
public:
	virtual ~DemoApplication() = default;
	void OnAwake() override;
	void OnStart() override;
	void OnUpdate() override;
	void OnLateUpdate() override;
	void OnDraw() override;
	void OnGui() override;
	void OnDispose() override;
};
