# Graphics.
By the end of this Tutorial you will understand basics of the Graphics API within the Eclipse Engine. This tutorial will show you how to load custom models and shaders. Custom Texture loading is very limited at the moment.

## Getting Started
Before you can get started using the Graphics API. You must properly set the project up to support the Graphics API. The first thing you will need to do is link the project to the correct libraries. (refer to tutorial: [[Tutorial_2 - Projects.]] for information on linking).

The libraires required for this tutorial are the following
|Name|Link Code|Description|
|-|-|-|
|Eclipse Engine|EclipseEngine|This is the core engine<br>you will need to link to this<br>to use any engine features.
|Eclipse Debugging|EclipseDebugging|This is optional, but adds fancy<br>colors to console|
|Eclipse Graphics|EclipseGraphics|This is the graphics library for<br>the Eclispe Engine|
|ASSIMP|assimp|ASSIMP handles all the model loading|
|GLFW|glfw|GLFW handles all the windowing functionality|
|GLAD|glad|GLAD handles all the communication between the engine & OpenGL|

your `premake5.lua` file under `./Projects/[YOUR_PROJECT_NAME]` should look like this.
```lua
CreateProject(
"Test_Project",
-- Dependencies
{
    "EclipseEngine",
    "EclipseDebugging",
    "EclipseGraphics",
    "assimp",
    "glfw",
    "glad",
},
"%{wks.location}../Projects/Test_Project"
)
```

Before you can use the Graphics API you must add the GraphicsModule to the Engine.

Open your `ApplicationDriver.cpp` and you should see the following code.
```cpp
// Core Engine
#include <EclipseEngine/include/Application.h>
#include "ApplicationDemo.h"
	
int main()
{
	Eclipse::Engine::Application::Create<ApplicationDemo>({});
	Eclipse::Engine::Application::Initialize</*INSERT MODULES HERE*/>(Eclipse::Engine::Application::Instance);
	Eclipse::Engine::Application::Run();
}
```

Next you want to include the `WindowModule.h` file under `/EclipseEngine/include/WindowModule.h`
and
`GraphicsModule.h` file under `/EclipseGraphics/include/GraphicsModule.h`

```cpp
#include <EclipseEngine/include/WindowModule.h>
#include <EclipseGraphics/include/GraphicsModule.h>
```

Finally you want to modify the `Initialize<>` template arguments to include the window module. This can be done like so.

```cpp
Eclipse::Engine::Application::Initialize<Eclipse::Engine::WindowModule, Eclipse::Graphics::GraphicsModule>(Eclipse::Engine::Application::Instance);
```
	
Finally your project has been setup for rendering and you can now use the Graphics API.

## Rendering An Object.
This section will focus on rendering an object using the default resources that the engine supplies.
due to the limited graphical api that Eclipse - v0.1a has. Loading Models, Shaders and Textures is very limited, and currently only supports a singular texture and shader, whilst theoretically supporting a larger amount.

The first step to rendering an object is to actually load the object into the engine!. To do this you must use the resource manager. Don't worry, its simple!

First step is to override the virtual function `OnEngineInit()` provided by the application class in `ApplicationDemo.h`. 
This will look something like the following:
```cpp
class ApplicationDemo : public Eclipse::Engine::Application
{
protected:
	void OnEngineInit() override;
};
```

Once you have overridden `OnEngineInit()` you will need to load the resources (models, shaders and textures). To do this you will use the `ResourceManager.h` api. So make sure to include it within the `ApplicationDemo.cpp` file like so:
```cpp
#include <EclipseEngine/include/ResourceManager.h>
```

Alright, so we have the resource manager included, but what about the resources? The resources that we will need in this tutorial are `Eclipse::Graphics::ShaderProgram`, `Eclipse::Graphics::Texture`, and `Eclipse::Graphics::Model`. These are all under the EclipseGraphics module, so we will need to include them like so.

```cpp
#include <EclipseGraphics/include/ShaderProgram.h>
#include <EclipseGraphics/include/Texture.h>
#include <EclipseGraphics/include/Model.h>
```

Now that we have the resources included we can load them into the engine! In the `OnEngineInit()` function you will want to use the functions `ResourceManager::Load<T>(...)` and `ResourceManager::SetDefault<T>(...)` to load the resources and set the engines default resources.

```cpp
using namespace Eclipse;
using namespace Engine;
using namespace Graphics;

void ApplicationDemo::OnEngineInit()
{
    // Load and Set default shader.
    ResourceManager::SetDefault(ResourceManager::Load<ShaderProgram>({ R"(./data/shaders/default.vs)", "", R"(./data/shaders/default.fs)"}));
    // Load and Set default texture.
    ResourceManager::SetDefault(ResourceManager::Load<Texture>({ R"(./data/textures/default.jpg)" }));
    // Load an external model.
    ResourceKey cat_model_key = ResourceManager::Load<Model>({R"(./data/models/cat.fbx)"});
}
```
*Note: You can find the default resources under `$(WorkingDir)/data/[type]/[resource]` *

The resource manager uses an array of directories to load specific resources, due to this specific resources require more directories to properly load.

The most prominant one is the `ShaderProgram` resource. In this example it uses 3 directories, which correspond to the vertex shader, geometry shader and the fragment shader.
```cpp
ResourceManaget::Load<ShaderProgram>({"Vertex.vs", "Geometry.gs", "Fragment.fs"});
```
Other resources such as `Texture` and `Model` only require one directory to load, and will only use the first directory supplied.

The `SetDefault<T>(ResourceKey)` function allows you to set a custom default/fallback resource. It uses type_id's to determine what type it the resource should represent. You can use the `GetDefault<T>()` to get the default key of `typeid(T)`

However we are storing the model key as a variable to use later for rendering of the model.

Now that the resources we will use for this tutorial have been loaded. We can get to actually creating some objects to use these resources. In this part of the tutorial you will need to include the following header files:
```cpp
// Engines object manager
#include <EclipseEngine/include/SceneManager.h>
// Engines object class
#include "EclipseEngine/include/Object.h"

// Components
#include <EclipseGraphics/include/Camera.h>
#include <EclipseGraphics/include/MeshRenderer.h>
#include <EclipseGraphics/include/Light.h>
// Required to use the Object's Transform.
#include "EclipseEngine/include/Transform.h"

```

Another core part of the engine you will need is `SceneManager.h` api to load objects into the engine. The scene manager will allow you to load scenes, save scenes, and most importantly add objects to a scene. The scene manager handles all the behaviours and components on objects. 

The core `Object` class acts as a composite base for all behaviours and components. This allows you to add components, query components, delete a component and use a hierarchy tree to search for components in children/parents.

The `Camera` class inherits from `Component` and as such is a Component which can be composited into an object. Its core functionality acts as a data structure with some helper functionality and other systems such as the renderer take advantage of this data to render the scene using this camera component.

The `MeshRenderer` class inherits from `Component` and as such is a Component which can be composited into an object. Its core functionality as a data structure with some helper functions. It overrides the `Draw` virtual function and buffers a draw call to the renderer.

the `Light` class inherits from `Component` and as such is a Component which can be composited into an object. Its core functionality acts as a data structure with some helper functionality and other systems such as the renderer take advantage of this data to render objects with lighting calculations.

The `Transform` class inherits from `Component` and as such is a Component which will automatically be composited into an object. Its core functionality is to act as a data structure to act like a data structure to hold translation, rotation and scale.

Alright, so the first object we are going to create is the camera object. This object will consist of a camera component. Appending from the code above, it should look something like this.

```cpp
// create camera object
Eclipse::Object* camera_object = new Eclipse::Object();
camera_object->m_ComponentContainer.AddComponent<Eclipse::Components::Camera>();
```

and then we will create the model object. This will consist of a MeshRenderer component. This time we want to store a reference to the component. Try and do this your self!

(*The code should look like this*)
```cpp
Eclipse::Object* cat_object = new Eclipse::Object();
Eclipse::Components::MeshRenderer* cat_mesh_renderer = cat_object->m_ComponentContainer.AddComponent<Eclipse::Components::MeshRenderer>();
```
You can also use `Object::ComponentContainer::GetComponent<T>()` to get a reference to a specific component.

Next we will set the model of the mesh renderer like so.
```cpp
cat_mesh_renderer->SetModel(cat_model_key);
```
finally due to the scale of the object we need to translate it. This can be done like so.
```cpp
// This will change the cat's position in world space.
cat_object->transform->SetTranslation({0.0f,0.0f,1500.0f});
// This will change the cat's rotation in world space.
cat_object->transform->SetRotation({4.71f,0.35f,0.0f});
```

The final object we will create is a light. This object will provide illumination to the scene. Currently Eclipse only support directional lights.
After this we will modify the values: AmbientColor, SpecularColor, DiffuseColor and SpecularIntensity. These colors folow the RGBA pattern. I want you to try and add and create a new object, add the light component and set these values to make the cat red.

(*The code should look like this.*)
```cpp
// create light object
Eclipse::Object* light_object = new Eclipse::Object();
// add light component
Eclipse::Components::Light* light_object_light = light_object->m_ComponentContainer.AddComponent<Eclipse::Components::Light>();
light_object_light->SetAmbientColor({ 0.1,0,0, 0.1 });
light_object_light->SetSpecularColor({ 1,0,0,0.1 });
light_object_light->SetDiffuseColor({ 1,0,0,0.1 });
light_object_light->SetIntensity(32);
```

Though we have created objects, they are not in the scene yet. Its quite simple to add the objects you have created into a scene. Firstly you have to get a pointer to the current scene like so:
```cpp
Eclipse::Engine::SceneManagement::Scene* scene = Eclipse::Engine::SceneManagement::SceneManager::Instance->GetActiveScene();
```
due to this being a pointer, you can freely modify this to add new objects like so:
```cpp
scene->AddObject(camera_object);
scene->AddObject(cat_object);
scene->AddObject(light_object);
```

and that is it! if you hit run, and everything went right. Then you should have a red cat in your scene fiercely looking at you.

*Next Tutorial: `Networking.`*