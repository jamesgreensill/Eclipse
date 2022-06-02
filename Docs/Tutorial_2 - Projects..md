# Creating a new Project!
Creating a project in the Eclipse Engine is unfortunately a bit of an involved process, however stay with me on this because by the end of this tutorial you will fully understand how to create and compile an Eclipse Project!.

Some useful information to know before getting started with Eclipse Projects is Lua as this is the language that premake5 bases their generation scrips off.

First we will look at creating a project the ***easy*** way...
## Generating a project (the easy way)!
There are prebuilt scripts that will generate a template project that can & will need to be expanded upon.
To locate these scripts go the the directory `./Projects/` and there will be a script called `project_generator.bat` run this script and you will be prompted to enter a project name, for education purposes we will use the name `Test_Project` as our project name today, however the name can be anything.

After you have entered your project name, hit enter on your command line interface to submit this into the project generator, and thats it! you should now have a new folder under `./Projects/[YOUR_PROJECT_NAME]`. 

now move onto linking a project

## Creating a project (the more involved way)!
Due to the nature of premake5 creating projects is relatively simple, however it is an involved process. 
The list of steps are as follows:
	- #1 Creating a directory for your project under `./Projects/`
	- #2 Creating a `premake5.lua` file under the `./Projects/[YOUR_PROJECT_NAME]/` directory
	- #3 Modifying the `./Projects/Projects.lua` to append a project include.
	- #4 Creating an `ApplicationDriver.cpp` file and `ApplicationDemo.cpp` file under `./Projects/[YOUR_PROJECT_NAME}/src/`
	- #5 Creating an `ApplicationDemo.h` file under `./Projects/[YOUR_PROJECT_NAME]/include/src/`

Now that all the steps have been listed we can begin creating our very own Eclispe Project!.

##### Step 1: Creating a directory under `./Projects/` with the name of your project.
This is as simple as it states, simply create a new folder under the `./Projects/` directory in the repository with the name of your project.

##### Step 2: Creating a `premake5.lua` at the root of your project directory.
This is also a relatively simple step, under the directory `./Projects/[YOUR_PROJECT_NAME]/` create a new text file with the name of `premake5` and the extension of `.lua`

##### Step 3: Modify the `./Projects/Projects.lua` to include your project in the generation process.
All projects that are to be included within the premake5 workspace generation process must be included within the `./Projects/Projects.lua` file. To do this simply append the following line `include "YOUR_PROJECT_NAME"` to the end of the file. 

*Note: If this file doesn't exist, simply create one and put continue as normal.*

here is an example
```lua
include "DemoApplication" -- some other project
include "YOUR_PROJECT_NAME" -- your project
```

##### Step 4: Creating the initial source files!
Create a new directory at the root of your project directory named `src` (this is important, it must be named `src`). And create 2 files. One is to be named `ApplicationDriver.cpp` and the other will be named `ApplicationDemo.cpp` these will be the entry point for our application in a later tutorial.

The `ApplicationDriver.cpp` file should look like this.
```cpp
#include <EclipseEngine/include/Application.h>
#include "ApplicationDemo.h"

int main()
{
	Eclipse::Engine::Application::Create<ApplicationDemo>({});

	Eclipse::Engine::Application::Initialize</*YOUR MODULES HERE*/>(Eclipse::Engine::Application::Instance);

	Eclipse::Engine::Application::Run();
}
```
*Note: This code will be explained in a later tutorial, for now just put it in the file as it is required for compilation.*

The `ApplicationDemo.cpp` file should look like this.
```cpp
#include "ApplicationDemo.h"

void ApplicationDemo::OnCreated()
{
	/*void*/
}

void ApplicationDemo::OnBoot()
{
	/*void*/
}

void ApplicationDemo::OnEngineInit()
{
	/*void*/
}
```
*Note: This code will be explained in a later tutorial, for now just put it in the file as it is required for compilation.*

##### Step 5: The final step, creating the header files.
Create a new directory at the root of your project directory named `include` (this is important, it must be named `include`). And create a file named `ApplicationDemo.h`

The `ApplicationDemo.h` file should look like this.
```cpp
#pragma once
#include <EclipseEngine/include/Application.h>

class NetworkClientApplication :
    public Eclipse::Engine::Application
{
public:
	void OnCreated() override;
	void OnBoot() override;
	void OnEngineInit() override;
	void OnAwake() override;
	void OnDisposed() override;
};
```
*Note: This code will be explained in a later tutorial, for now just put it in the file as it is required for compilation.*

and thats it! you have successfully created the file structure for your project, now onto linking!

## Linking a project
Once your project has been created you will need enter the dependencies for your project! but what does a dependency mean in the Eclispe Engine? Since the Eclipse Engine was designed from the ground up to be modular every aspect of the engine is seperated into packages known as eclipse modules, by default the core repository will clone all the official modules, (as of *31/5/2022* there is no way to choose what modules are cloned.) so all you need to do is link your project to the modules that your project requires.

Here is a list of all official modules for the Eclipse Engine.
|Module Link Code|Description|Repo|Dependencies|
|-|-|-|-|
|EclipseEngine|The core engine functionality|[here]()|n/a|
|EclipseDebugging|Core debugging functionality for the engine|[here]()|EclipseEngine|
|EclipseNetworking|Core networking functionality for the engine|[here]()|raknet, Ws2_32.lib, Wldap32.lib, Crypt32.lib|
|EclipseGraphics|Core rendering functionality for the engine|[here]()|glfw, glad, assimp, EclipseEngine|
|EclipseScripting|Core scripting API for the engine|[here]()|EclipseEngine|
|EclipseGui|Core Graphical UI|[here]()|glfw, glad, imgui, EclipseEngine|
|EclipseChat|Chat buffer module for the eclipse engine|[here]()|EclipseEngine|



Here are some rules that the Eclipse Engine uses.
	- All external vendors are lowercase.
	- All internal modules follow Pascal Case notation.
	- .lib link files notation cannot be changed and are case sensitive when linking.

Alright, now we can begin linking out project to the engine! you will want to go into the generated project directory under `./Projects/[YOUR_PROJECT_NAME]/` and go to and open the `./premake5.lua` file. Once this has opened in your editor of choice you should see something like this.

```lua
CreateProject(
    "[YOUR_PROJECT_NAME]",
    -- Dependencies
    {
    },
    "%{wks.location}../Projects/[YOUR_PROJECT_NAME]"
)
```

If you do indeed see something that resembles the above, then congratulations your project successfully generated! If you do not then you can copy and paste the above code into the `Projects/[YOUR_PROJECT_NAME]./premake5.lua` file.

So due to the way premake5 links projects we have to use string literals within the curly braces. This can be done as so:

```lua
CreateProject(
    "[YOUR_PROJECT_NAME]",
    -- Dependencies
    {
	    -- modules
        "EclipseEngine",
        "EclipseDebugging",
        "EclipseGraphics",
        "EclipseNetworking",
        "EclipseChat",
        "EclipseScripting",
        "EclipseGui",
        -- vendors
        "assimp",
        "glfw",
        "raknet",
        "glad",
        "imgui",
        -- libraries
        "Ws2_32.lib",
        "Wldap32.lib",``
        "Crypt32.lib"
    },
    "%{wks.location}../Projects/[YOUR_PROJECT_NAME]"
)
```

You can refer to the `Module Link Code` tab and the `Dependencies` tab of the table for the Eclispe linking codes. 

Finally, once you have filled out the required modules and libraries you wish to link your project to, you can re-generate the premake5 workspace.
You can do this by going to the `./.premake5/` directory and following the steps provided in the previous tutorial.

Once the project has been re-generated you can find the workspace files under the  `./Build/` directory.
Compiling will be different for every IDE and OS and covering how to compile a project for your specific case is beyond the scope of this tutorial.

*See the next tutorial for `Hello There... Window`












