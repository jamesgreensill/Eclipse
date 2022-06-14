# Windowing in Eclipse
By the end of this tutorial you will know how to create a windowed application in the Eclipse Engine.
	
Due to the nature of the Eclipse Engine being modular, applications do not have a window by default and you must add it as an engine module. In this tutorial we will go through on how to do just that and go through how to customize the window to your liking.

*Note: This tutorial requires that the project be properly linked to the engine. See the previous tutorial to find out how to do that!*

Windowing in the Eclipse Engine uses the library `GLFW` to handle all windowing functionality, you can read more about the library [here](https://www.glfw.org/).

So, now that you have been briefed, lets begin!
	
For this tutorial you will need to link to the following modules & libraries.
|Name|Link Code|Description|
|-|-|-|
|Eclipse Engine|EclipseEngine|This is the core engine<br>you will need to link to this<br>to use any engine features.
|Eclipse Debugging|EclipseDebugging|This is optional, but adds fancy<br>colors to console|
|GLFW|glfw|GLFW handles all the windowing functionality|
|GLAD|glad|GLAD handles all the communication between the engine & OpenGL|

your `premake5.lua` file under `./Projects/[YOUR_PROJECT_NAME]` shoud look something like this.
```lua
CreateProject(
"YOUR_PROJECT_NAME",
-- Dependencies
{
    "EclipseEngine",
    "EclipseDebugging",
    "glfw",
    "glad",
},
"%{wks.location}../Projects/YOUR_PROJECT_NAME"
)
```
	
Once you linked your project to the engine, you will need to regenerate your premake5 workspace. Refer to the previous tutorial for information on linking.
	
Alright, now that our project is ready, we can begin developing!
	
Now to create a window in the Eclipse Engine. It is rather simple, actually its just 2 line of code. Open your `ApplicationDriver.cpp` and you should see the following code.
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

```cpp
#include <EclipseEngine/include/WindowModule.h>
```

Finally you want to modify the `Initialize<>` template arguments to include the window module. This can be done like so.

```cpp
Eclipse::Engine::Application::Initialize<Eclipse::Engine::WindowModule>(Eclipse::Engine::Application::Instance);
```
	
and... that it! surprising right? If you now compile your project and run your application, a console & window should now appear! but the fun doesn't stop there, why don't we customize our window a little bit?

At the moment you can only change the current settings of the window.
|Setting|Default|Description|
|-|-|-|
|windowTitle|"Application"|This is the title string of the window|
|windowWidth|1280px|This is the width of the window|
|windowHeight|720px|This is the height of the window|
|minWindowWidth|100px|This is the minimum window width|
|minWindowHeight|100px|This is the minimum window height|
|refreshColor|BLACK|This is the refresh/clear color of the frame|

Alright, lets get customizing. I want my window to be 1,000px wide and 1,000px long and have the Title "Tutorial_3 - Hello There... Window"
For me to do this I can simply pass the arguments into the structure under the `Create<>({})` function like so.
```cpp
Eclipse::Engine::Application::Create<ApplicationDemo>({"Tutorial_3 - Hello There... Window", 1000,1000,100,100});
```

And its that simple! You now have a fully functional window, but whats a window without graphics?
*See the next tutorial for `Graphics, we're glad to have you!`
	
