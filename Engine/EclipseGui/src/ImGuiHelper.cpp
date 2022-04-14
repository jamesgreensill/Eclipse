#include <pch.h>
#include "ImGuiHelper.h"
#include <EclipseEngine/include/Core.h>
//#include <imgui.h>

namespace ImGui
{
	struct InputTextCallback_UserData
	{
		std::string* Str;
		ImGuiInputTextCallback  ChainCallback;
		void* ChainCallbackUserData;
	};

	auto InputTextCallback(ImGuiInputTextCallbackData* data) -> int
	{
		const auto user_data = static_cast<InputTextCallback_UserData*>(data->UserData);
		if (data->EventFlag == ImGuiInputTextFlags_CallbackResize)
		{
			// Resize string callback
			// If for some reason we refuse the new length (BufTextLen) and/or capacity (BufSize) we need to set them back to what we want.
			std::string* str = user_data->Str;
			IM_ASSERT(data->Buf == str->c_str());
			str->resize(data->BufTextLen);
			data->Buf = const_cast<char*>(str->c_str());
		}
		else if (user_data->ChainCallback)
		{
			// Forward to user callback, if any
			data->UserData = user_data->ChainCallbackUserData;
			return user_data->ChainCallback(data);
		}
		return 0;
	}
	auto InputText(const char* label, std::string* str, ImGuiInputTextFlags flags, ImGuiInputTextCallback callback,
		void* user_data) -> bool
	{
		IM_ASSERT((flags & ImGuiInputTextFlags_CallbackResize) == 0);
		flags |= ImGuiInputTextFlags_CallbackResize;

		InputTextCallback_UserData cb_user_data;
		cb_user_data.Str = str;
		cb_user_data.ChainCallback = callback;
		cb_user_data.ChainCallbackUserData = user_data;
		return InputText(label, (char*)str->c_str(), str->capacity() + 1, flags, InputTextCallback, &cb_user_data);
	}
	auto DrawVec3Control(const std::string& label, float* x, float* y, float* z) -> void
	{
		if (ImGui::BeginTable(label.c_str(), 4))
		{
			float deltaX = Eclipse::Core::Input::GetMouseDeltaX();

			if (deltaX < 0)
			{
				deltaX = -deltaX;
			}

			deltaX /= 100;

			ImGui::TableNextColumn();
			ImGui::Text("%s", label.c_str());
			ImGui::TableNextColumn();
			ImGui::DragFloat("X", x, deltaX);
			ImGui::TableNextColumn();
			ImGui::DragFloat("Y", y, deltaX);
			ImGui::TableNextColumn();
			ImGui::DragFloat("Z", z, deltaX);

			ImGui::EndTable();
		}
	}
	auto DrawVec4Control(const std::string& label, float* x, float* y, float* z, float* w) -> void
	{
		if (ImGui::BeginTable(label.c_str(), 5))
		{
			float deltaX = Eclipse::Core::Input::GetMouseDeltaX();

			if (deltaX < 0)
			{
				deltaX = -deltaX;
			}

			deltaX /= 100;

			ImGui::TableNextColumn();
			ImGui::Text("%s", label.c_str());
			ImGui::TableNextColumn();
			ImGui::DragFloat("X", x, deltaX);
			ImGui::TableNextColumn();
			ImGui::DragFloat("Y", y, deltaX);
			ImGui::TableNextColumn();
			ImGui::DragFloat("Z", z, deltaX);
			ImGui::TableNextColumn();
			ImGui::DragFloat("W", w, deltaX);

			ImGui::EndTable();
		}
	}
	auto DrawColorControl(const std::string& label, float* x, float* y, float* z, float* w) -> void
	{
		if (ImGui::BeginTable(label.c_str(), 2))
		{
			float* col[4];
			col[0] = x;
			col[1] = y;
			col[2] = z;
			col[3] = w;

			ImGui::TableNextColumn();
			ImGui::ColorEdit4(label.c_str(), *col);
			ImGui::EndTable();
		}
	}
	auto DrawVec2Control(const std::string& label, float* x, float* y) -> void
	{
		if (ImGui::BeginTable(label.c_str(), 3))
		{
			float deltaX = Eclipse::Core::Input::GetMouseDeltaX();

			if (deltaX < 0)
			{
				deltaX = -deltaX;
			}

			deltaX /= 100;

			ImGui::TableNextColumn();
			ImGui::Text("%s", label.c_str());
			ImGui::TableNextColumn();
			ImGui::DragFloat("X", x, deltaX);
			ImGui::TableNextColumn();
			ImGui::DragFloat("Y", y, deltaX);
			ImGui::EndTable();
		}
	}
	auto DrawFloatControl(const std::string& label, float* x) -> void
	{
		if (ImGui::BeginTable(label.c_str(), 2))
		{
			float deltaX = Eclipse::Core::Input::GetMouseDeltaX();

			if (deltaX < 0)
			{
				deltaX = -deltaX;
			}

			deltaX /= 100;

			ImGui::TableNextColumn();
			ImGui::Text("%s", label.c_str());
			ImGui::TableNextColumn();
			ImGui::DragFloat("", x, deltaX);
			ImGui::EndTable();
		}
	}
	auto DrawIntControl(const std::string& label, int* x) -> void
	{
		if (ImGui::BeginTable(label.c_str(), 2))
		{
			float deltaX = Eclipse::Core::Input::GetMouseDeltaX();

			if (deltaX < 0)
			{
				deltaX = -deltaX;
			}

			deltaX /= 100;

			ImGui::TableNextColumn();
			ImGui::Text("%s", label.c_str());
			ImGui::TableNextColumn();
			ImGui::DragInt("", x, deltaX);
			ImGui::EndTable();
		}
	}
	auto DrawDoubleControl(const std::string& label, double* x) -> void
	{
		if (ImGui::BeginTable(label.c_str(), 2))
		{
			float deltaX = Eclipse::Core::Input::GetMouseDeltaX();

			if (deltaX < 0)
			{
				deltaX = -deltaX;
			}

			deltaX /= 100;

			ImGui::TableNextColumn();
			ImGui::Text("%s", label.c_str());
			ImGui::TableNextColumn();
			// might not work.
			ImGui::DragFloat("", reinterpret_cast<float*>(x), deltaX);
			ImGui::EndTable();
		}
	}
	auto DrawIntCollection(const std::string& label, const std::vector<int*>& items, int perLine)
	{
		const float deltaX = Eclipse::Core::Input::GetMouseDeltaX();

		if (ImGui::BeginTable(label.c_str(), perLine))
		{
			const int rows = static_cast<int>(items.size() - 1) % perLine;
			int index = -1;

			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < perLine; j++)
				{
					index = i * i + j;
					int* ptr = items[index];
					ImGui::TableNextColumn();
					ImGui::DragInt("", ptr, deltaX);
					ImGui::TableNextColumn();
				}
			}
			ImGui::EndTable();
		}
	}
	auto DrawFloatCollection(const std::string& label, const std::vector<float*>& items, int perLine)
	{
		const float deltaX = Eclipse::Core::Input::GetMouseDeltaX();

		if (ImGui::BeginTable(label.c_str(), perLine))
		{
			const int rows = static_cast<int>(items.size() - 1) % perLine;
			int index = -1;

			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < perLine; j++)
				{
					index = i * i + j;
					float* ptr = items[index];
					ImGui::TableNextColumn();
					ImGui::DragFloat("", ptr, deltaX);
					ImGui::TableNextColumn();
				}
			}
			ImGui::EndTable();
		}
	}
	auto DrawDoubleCollection(const std::string& label, const std::vector<double*>& items, int perLine)
	{
		const float deltaX = Eclipse::Core::Input::GetMouseDeltaX();

		if (ImGui::BeginTable(label.c_str(), perLine))
		{
			const int rows = static_cast<int>(items.size() - 1) % perLine;
			int index = -1;

			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < perLine; j++)
				{
					index = i * i + j;
					double* ptr = items[index];
					ImGui::TableNextColumn();
					ImGui::DragFloat("", reinterpret_cast<float*>(ptr), deltaX);
					ImGui::TableNextColumn();
				}
			}
			ImGui::EndTable();
		}
	}
	auto DrawStringControl(const std::string* label) -> void
	{
		//if (label->c_str())
			//if (ImGui::BeginTable(label->c_str(), 1))
			//{
			//	ImGui::TableNextColumn();
			//	ImGui::Text("%s", label->c_str());
			//	ImGui::EndTable();
			//}
	}
}