//#include <pch.h>
//#include "ImGuiInspector.h"
//
//#include "Eclipse.h"
//#include "Object.h"
//
//#include "imgui/imgui.h"
//#include "ImType.h"
//
//#include "ImGuiHelper.h"
//
//#include "Camera.h"
//#include "DebugComponent.h"
//#include "ImGuiRenderer.h"
//#include "ObjectRotator.h"
//#include "Light.h"
//#include "Transform.h"
//
//namespace Eclipse
//{
//	namespace Engine
//	{
//		namespace Gui {
//			bool ImGuiInspector::inspectorActive = false;
//			bool ImGuiInspector::addComponentActive = false;
//			ImGuiInspector* ImGuiInspector::Instance = nullptr;
//
//			void ImGuiInspector::Gui()
//			{
//				ImGuiTypes::ImGuiCall call;
//
//				RetrieveGuiData(call);
//
//				ImGuiRenderer::Instance->QueueCall(call);
//			}
//
//			void ImGuiInspector::RetrieveGuiData(Eclipse::Engine::ImGuiTypes::ImGuiCall& call)
//			{
//				if (selectedObject)
//				{
//					if (inspectorActive)
//					{
//						call.Push(new ImGuiTypes::ImType
//						(
//							[&]
//							{
//								ImGui::Begin("Inspector", &inspectorActive);
//								ImGui::InputText("Name", &selectedObject->name);
//								ImGui::NewLine();
//							}
//							));
//
//						selectedObject->RetrieveGuiData(call);
//
//						call.Push(new ImGuiTypes::ImType
//						(
//							[=]
//							{
//								ImGui::NewLine();
//
//								if (ImGui::Button("Add Component"))
//								{
//									addComponentActive = !addComponentActive;
//								}
//
//								ImGui::End();
//							}
//							));
//					}
//					else
//					{
//						addComponentActive = false;
//						selectedObject = nullptr;
//					}
//				}
//
//				if (selectedObject && inspectorActive && addComponentActive)
//				{
//					call.Push(new ImGuiTypes::ImType
//					(
//						[&]
//						{
//							ImGui::Begin("Add Component", &addComponentActive);
//
//							/*
//							 *	TODO: Find a better way to do this.
//							 */
//
//							ImGui::DrawAddComponentControl<Components::Camera>("Camera", selectedObject);
//							ImGui::DrawAddComponentControl<Components::Transform>("Transform", selectedObject);
//							ImGui::DrawAddComponentControl<Components::DebugComponent>("Debug Component", selectedObject);
//							ImGui::DrawAddComponentControl<Components::Light>("Light Component", selectedObject);
//							ImGui::DrawAddComponentControl<Components::ObjectRotator>("Object Rotator", selectedObject);
//
//							ImGui::End();
//						}
//						));
//				}
//			}
//
//			void ImGuiInspector::Created()
//			{
//				if (!Instance)
//				{
//					Instance = this;
//				}
//			}
//
//			void ImGuiInspector::Deleted()
//			{
//				delete Instance;
//			}
//		}
//	}
//}