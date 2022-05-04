# Eclipse Engine
Author - [@jwrmg](https://www.github.com/jwrmg) | [GitHub](https://www.github.com/jwrmg) | [Discord]() 
* Started on 9th of March 2022
* Last Update on 4th of May 2022  

Table of Contents
====================

* [Introduction](#introduction)
* [Installation](#installation)
  * [Getting Started](#getting-started)
  * [Installing](#installing)
* [Usage](#usage)
    * [Creating a new application](#creating-a-new-application)
    * [Running the application](#running-the-application)
    * [Testing the application](#testing-the-application)
* [Features](#features)
  * [Completed](#completed)
  * [In Development](#in-development)
  * [Planned](#planned)
* [Deployment](#deployment)
    * [Deploying the application](#deploying-the-application)
    * [Deploying the application to Google Cloud](#deploying-the-application-to-google-cloud)
    * [Deploying the application to Heroku](#deploying-the-application-to-heroku)
    * [Deploying the application to Azure](#deploying-the-application-to-azure)
    * [Deploying the application to AWS](#deploying-the-application-to-aws)
    * [Deploying the application to Digital Ocean](#deploying-the-application-to-digital-ocean)
    * [Deploying the application to Netlify](#deploying-the-application-to-netlify)
* [Libraries](#libraries)
* [Licenses](#licenses)
    * [Main License](#main-license)
    * [Library Licenses](#library-licenses)
* [Contributing](#contributing)

* [Extra Stuff](#extra-stuff)
  * [Future Plans](#future-plans)
  * [FAQ](#faq)
  * [Support](#support)
  * [Acknowledgements](#acknowledgements)
  * [Credits](#credits)
  * [Contact](#contact)

---

Introduction
============
    To be written.

Installation
===
* ### Getting Started
      To be written.
* ### Installing
      To be written.

Usage
=====
* ### Creating a new application
Simple inherit from Engine::Application and override the selection of virtual functions avaliable.
```cpp
class DemoApplication :
    public Application
{
public:
	// replacement for constructor.
	void OnCreated() override;
	// boots all engine modules
	void OnBoot() override;
	// called when the engine begins to intialize.
	void OnEngineInit() override;
	// called prior to the first frame.
	void OnAwake() override;
	// replacement for destructor.
	void OnDisposed() override;
};
```

Eclipse Engine has been designed to be modular to its very core. So creating an application is different to most other engines you will find out there.
To create an Application using Eclipse you will need add a list of modules to the engine. You can achieve this as follows. Please see [Native Modules](#native-modules)
* ### Running the application
```cpp
int main()
{
    	// Create an instance of DemoApplication with the specified settings.
    	Application::Create<DemoApplication>(settings);
    	// Use a variadic function to add a list of module types.
    	Application::Initialize<Debug::DebugModule, Graphics::GraphicsModule, Gui::GuiModule>(Application::Instance);
    	// Run the Application.
    	Application::Run();
}
  ```
Native Modules
======================
* DebugModule <- under the debug namespace.
* GraphicsModule <- under the graphics namespace.
* WindowModule <- under the engine namespace. 
* GuiModule <- under the gui namespace.
* ChatModulew <- under the chat namespace.
* NetworkModule <- under the networking namespace.


Features
========
* ### Completed
	* Core Engine
		* ECS Container
		* Time
		* Object
		* ResourceManager
		* System
		* Transform
		* Event
		* Function Wrapper
		* API
		* APILoader
		* BaseModel
		* ESingle (Singleton Pattern)
		* Engine Module
	* Graphics
		* Model Loading
		* Texture Loading
		* Shader Loading
		* Phong Model Lighting
	* Networking
		* Basic Client
		* Basic Server
		* Networking Bus
		* Eclipse Packet
		* Packet Handling
	* Debugging
		* Error Logging
		* Debug Logging
		* Logging
		* Assertions
* ### In Development
* ### Planned
	* Core Engine
		*  
	* Graphics
		* Shadow mapping
		* Texture Maps (normal, diffuse, specular)
		* Raytracing.
		* GLSL shaders.
		* Particles
		* Rigged Animations
		* 2D Stuff
	* Networking
		* Packet compressing
		* Packet batching
		* Dead Reckoning
		* Authentication
		* Packet Encrypting
	* Encryption
		* RSA Encryption & Decryption
		* Prime Number Generation & Verification
	* Debugging
	* Chat
		* Chat Interface
		
Libraries
=========
* [Assimp](https://github.com/assimp/assimp).
* [GLFW3](https://github.com/glfw/glfw).
* [ImGUI](https://github.com/ocornut/imgui).
* [RakNet](https://github.com/facebookarchive/RakNet).
* [Mono](https://github.com/mono/mono).

Licenses
=======
* ### Main License
      To be written.

* ### Library Licenses
  * [Assimp License](https://github.com/assimp/assimp/blob/master/LICENSE).
  * [GLFW3 License](https://github.com/glfw/glfw/blob/master/LICENSE.md).
  * [ImGUI License](https://github.com/ocornut/imgui/blob/master/LICENSE.txt).
  * [RakNet](https://github.com/facebookarchive/RakNet/blob/master/LICENSE).
  * [Mono License](https://github.com/mono/mono/blob/main/LICENSE).

Contributing
============
      To be written.

Extra Stuff
==========
* ## Future Plans
      To be written.

* ## FAQ
      To be written.  

* ## Support
      To be written.

* ## Acknowledgements
      To be written.

* ## Credits
      To be written.

* ## Contact
      To be written.

---

#### Please contact me for removal if you or your resources are in this section.
#### Resources of study
* [Raylib CheatSheet - Raylib.com](https://www.raylib.com/cheatsheet/cheatsheet.html)
* [Yeet Engine - Michael Kirsch](https://github.com/MichaelKirsch/YEET-Engine)
* [CppOpenGLEngine - Calvin Soueid](https://github.com/BlackxSnow/CppOpenGLEngine)
* [Aqua Engine - Lewis Comstive](https://github.com/lcomstive/AquaEngine)
* [Hazel Engine - Yan Chernikov](https://github.com/TheCherno/Hazel)
* [LearnOpenGL.com](https://learnopengl.com/)
</details>




