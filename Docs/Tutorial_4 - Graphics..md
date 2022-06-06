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

your `premake5.lua` file under `./Projects/[YOUR_PROJECT_NAME]` shoud look something like this.
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
