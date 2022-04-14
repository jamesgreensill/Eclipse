#pragma once
#include <string>
#include <glm/fwd.hpp>
#include <imgui/imgui.h>

#include <EclipseEngine/include/Object.h>

namespace Eclipse
{
	namespace Graphics
	{
		class Shader;
		class Mesh;
	}
}

namespace ImGui
{
	IMGUI_API bool  InputText(const char* label, std::string* str, ImGuiInputTextFlags flags = 0, ImGuiInputTextCallback callback = nullptr, void* user_data = nullptr);

	auto DrawVec4Control(const std::string& label, float* x, float* y, float* z, float* w) -> void;
	auto DrawColorControl(const std::string& label, float* x, float* y, float* z, float* w) -> void;
	auto DrawVec3Control(const std::string& label, float* x, float* y, float* z) -> void;
	auto DrawVec2Control(const std::string& label, float* x, float* y) -> void;
	auto DrawFloatControl(const std::string& label, float* x) -> void;
	auto DrawIntControl(const std::string& label, int* x) -> void;
	auto DrawDoubleControl(const std::string& label, double* x) -> void;
	auto DrawStringControl(const std::string* label) -> void;

	template <typename T>
	auto DrawAddComponentControl(const std::string& label, Eclipse::Object* object) -> void
	{
		/*
		 *
		 *	TODO: assert that type is of component.
		 *
		 */
		if (ImGui::Button(label.c_str()))
		{
			object->AddComponent<T>();
		}
	}
}
