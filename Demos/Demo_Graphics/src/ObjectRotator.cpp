#include "ObjectRotator.h"

#include "EclipseEngine/include/Object.h"
#include "EclipseEngine/include/Transform.h"
#include "EclipseEngine/include/EclipseTime.h"

void ObjectRotator::Reset()
{
}

void ObjectRotator::Update()
{
	object->transform->Rotate(m_Rotation * m_Speed);
}
