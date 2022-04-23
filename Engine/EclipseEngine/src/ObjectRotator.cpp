#include <pch.h>
#include "ObjectRotator.h"

//#include <EclipseGui/include/ImType.h>
#include "Object.h"
#include "Transform.h"
//#include <EclipseGui/include/ImFloat.h>
//#include <EclipseGui/include/ImVec3.h>

//#include "imgui/imgui.h"

namespace Eclipse
{
	namespace Components
	{


	
		/*
			DEPRECATED.		
		*/

		void ObjectRotator::Update()
		{
			if (running)
			{
				object->transform->Rotate(angles * speed);
			}
		}

		void ObjectRotator::RetrieveGuiData()
		{
			//call.Push(new Engine::ImGuiTypes::ImType([=]
			//	{
			//		ImGui::Checkbox("Running", &running);
			//	}));
			//
			//call.Push(new Engine::ImGuiTypes::ImVec3("Angles", { &angles.x, &angles.y, &angles.z }));
			//call.Push(new Engine::ImGuiTypes::ImFloat("Speed", &speed));
		}

		void ObjectRotator::Reset()
		{

		}
	}
}