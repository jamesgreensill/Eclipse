#pragma once
#include <EclipseEngine/include/Component.h>
#include <EclipseEngine/include/EngineMacros.h>

#include <glm/glm.hpp>

class ObjectRotator :
	public Eclipse::Components::Component
{
protected:
	void Reset() override;
	void Update() override;
public:
	GET(Speed, return m_Speed;);
	SET(Speed, float, m_Speed = value;);
	GET(Rotation, return m_Rotation; );
	SET(Rotation, glm::vec3, m_Rotation = value; );

private:
	float m_Speed = 1;
	glm::vec3 m_Rotation = {};
};
