//#include <pch.h>
//#include "ImGuiHierarchy.h"
//
//#include <imgui.h>
//
//#include "Eclipse.h"
//#include "ImGuiInspector.h"
//#include "ImType.h"
//#include "Object.h"
//
//#include "ImGuiRenderer.h"
//
//#include "ObjectFactory.h"
//
//#include "SceneManager.h"
//#include "Scene.h"
//#include "Transform.h"
//
//namespace Eclipse
//{
//	namespace Engine
//	{
//		namespace Gui
//		{
//			ImGuiHierarchy* ImGuiHierarchy::Instance = nullptr;
//
//			void ImGuiHierarchy::RetrieveHierarchyLayout(Eclipse::Engine::ImGuiTypes::ImGuiCall& call,
//				Eclipse::Object* object, int index)
//			{
//				MaskObjectHierarchy(object);
//
//				call.Push(new ImGuiTypes::ImType
//				(
//					[=]
//					{
//						if (!object)
//						{
//							return;
//						}
//						HierarchyDraw(object, index);
//					}
//					));
//			}
//
//			void ImGuiHierarchy::RetrieveGuiData(Eclipse::Engine::ImGuiTypes::ImGuiCall& call)
//			{
//				if (m_Objects == nullptr)
//				{
//					FetchObjects();
//				}
//				if (m_Objects == nullptr)
//				{
//					Core::Debug::Error("Failed to fetch objects - ImGuiInspector.");
//					return;
//				}
//
//				call.Push(new ImGuiTypes::ImType
//				(
//					[&]
//					{
//						ImGui::Begin("Hierarchy");
//					}
//					));
//
//				call.Push(new ImGuiTypes::ImType
//				(
//					[&]
//					{
//						if (ImGui::Button("+"))
//						{
//							ObjectFactory::CreateObject<Object>("GameObject");
//						}
//					}
//					));
//
//				for (int i = 0; i < m_Objects->size(); i++)
//				{
//					auto object = m_Objects->at(i);
//					if (!object)
//						continue;
//
//					bool skip = false;
//					for (auto maskedObject : m_MaskedObjects)
//					{
//						if (object == maskedObject)
//						{
//							skip = true;
//							break;
//						}
//					}
//					if (!skip)
//					{
//						RetrieveHierarchyLayout(call, object, i);
//					}
//				}
//				m_MaskedObjects.clear();
//				call.Push(new ImGuiTypes::ImType
//				(
//					[&]
//					{
//						ImGui::End();
//					}
//					));
//			}
//
//			void ImGuiHierarchy::MaskObjectHierarchy(Eclipse::Object* object)
//			{
//				for (auto& pair : object->transform->children)
//				{
//					m_MaskedObjects.push_back(pair->object);
//					MaskObjectHierarchy(pair->object);
//				}
//			}
//
//			void ImGuiHierarchy::HierarchyDraw(Eclipse::Object* object, int index)
//			{
//				if (object->transform->children.empty())
//				{
//					// Has no children.
//					if (ImGui::Button((object->name + " " + std::to_string(index)).c_str()))
//					{
//						ImGuiInspector::Instance->selectedObject = object;
//						ImGuiInspector::inspectorActive = true;
//					}
//				}
//				// branch node
//				else
//				{
//					if (ImGui::BeginTable((object->name + " " + std::to_string(index)).c_str(), 2))
//					{
//						ImGui::TableNextColumn();
//						// has children
//						if (ImGui::CollapsingHeader((object->name + " " + std::to_string(index)).c_str()))
//						{
//							for (auto& pair : object->transform->children)
//							{
//								HierarchyDraw(pair->object, index);
//							}
//						}
//						ImGui::TableNextColumn();
//						if (ImGui::Button("Select"))
//						{
//							ImGuiInspector::Instance->selectedObject = object;
//							ImGuiInspector::inspectorActive = true;
//						}
//						ImGui::EndTable();
//					}
//				}
//			}
//
//			void ImGuiHierarchy::FetchObjects()
//			{
//				m_Objects = SceneManagement::SceneManager::Instance->GetActiveScene()->GetObjects();
//			}
//
//			void ImGuiHierarchy::Awake()
//			{
//				FetchObjects();
//			}
//
//			void ImGuiHierarchy::Gui()
//			{
//				ImGuiTypes::ImGuiCall call;
//				RetrieveGuiData(call);
//				ImGuiRenderer::Instance->QueueCall(call);
//			}
//
//			void ImGuiHierarchy::Created()
//			{
//				if (!Instance)
//					Instance = this;
//			}
//
//			void ImGuiHierarchy::Deleted()
//			{
//				delete Instance;
//			}
//		}
//	}
//}