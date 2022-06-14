# Networking & Chatting
By the end of this Tutorial you will understand basics of the Networking API within the Eclipse Engine. This tutorial will show you how to Send, Receive and Handle packets with `EclipseNetworking`.

(*Note: EclipseNetworking has only been verified to work on windows 10 & 11.<br>If your device/os is unsupported please, please submit an issue [here](https://www.github.com/jwrmg/Eclipse/issues).*)

## Getting Started
Before you can get started using the Networking API. You must properly set the project up to support the Networking API. The first thing you will need to do is link the project to the correct libraries. (refer to tutorial: [[Tutorial_2 - Projects.]] for information on linking). This tutorial will be using the pre-provided `EclipseChat` API to create a small interface to send messages back and fourth through the console.

|Name|Link Code|Description|
|-|-|-|
|Eclipse Engine|EclipseEngine|This is the core engine<br>you will need to link to this to use any engine features.
|Eclipse Debugging|EclipseDebugging|This is optional, but adds fancy colors to console|
|Eclipse Networking|EclispeNetworking|This is the core Networking API.|
|Eclipse Chat|EclipseChat|Native chat API integrated with the Networking API.|
|GLFW|glfw|GLFW handles all the windowing functionality|
|GLAD|glad|GLAD handles all the communication between the engine & OpenGL|
|RakNet|raknet|RakNet handles all the low-level networking functionality|
|Winsock|Ws2_32.lib|Used by RakNet for low-level networking functionality|
|WinLDAP|Wldap32.lib|Used by Winsock for low-level networking functionality|
|Crypt32.lib|Crypt32.lib|Used by RakNet for packet encryption.|

Your `premake5.lua` file under `./Projects/[YOUR_PROJECT_NAME]` should look like this.
```lua
CreateProject(
    "Network Server",
    {
    -- Engine Modules
        "EclipseEngine",
        "EclipseDebugging",
        "EclipseNetworking",
        "EclipseChat",
    -- Module Dependencies.
        "glad",
        "glfw",
        "raknet",
    -- Windows Dependencies.
        "Ws2_32.lib",
        "Wldap32.lib",
        "Crypt32.lib"
    },
    "%{wks.location}../Projects/NetworkServer"
)
```

Due to the nature of Networking. You require 2 projects. One for the Server and one for the Client.
(*Note: Unless told. Perform the tutorial on both projects.*)

Before you can use the Networking API you must add the NetworkingModule to the Engine.

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

Next you want to include the `DebugModule.h` file under `/EclipseDebugging/include/DebugModule.h`
and
`NetworkingModule.h` file under `/EclipseNetworking/include/NetworkingModule.h`

```cpp
#include <EclipseDebugging/include/DebugModule.h>
#include <EclipseNetworking/include/NetworkingModule.h>
```

Finally you want to modify the `Initialize<>` template arguments to include the window module. This can be done like so.

```cpp
Eclipse::Engine::Application::Initialize<Eclipse::Debug::DebugModule, Eclipse::Networking::NetworkingModule>(Eclipse::Engine::Application::Instance);
```
	
Finally your project has been setup for networking using the Networking API.

## ChatSender
**THIS IS TO BE DONE ON THE CLIENT PROJECT**

Before you can begin work on the client you will need to setup a way to have IO asynchronously through the console. As this is not vital to the ChatAPI it is not required. However for this tutorial it is.

Create 2 new files: `ChatSender.h` and `ChatSender.cpp`. And put them in the `[Project]\include` & `[Project]\src` respectively and regenerate the project. Just copy and paste the following into your files respectively.

`ChatSender.h` contents:
```cpp
#pragma once
#include <EclipseEngine/include/Component.h>
#include <EclipseChat/include/NetworkChatInterface.h>


namespace Eclipse
{
	namespace Application
	{
		class ChatSender : public Components::Component
		{
		private:
			Chat::NetworkChatInterface* netInterface = nullptr;
			void _fetchCaches();
			void ThreadedCin();
			
			std::thread inputThread;

		protected:
			void Awake() override;
			void Update() override;
			void Reset() override;
			void Start() override;
			void Dispose() override;
		};
	}
}

```

`ChatSender.cpp` contents:
```cpp
#include "ChatSender.h"

#include <EclipseEngine/include/Object.h>
#include <EclipseEngine/include/Console.h>

#include <thread>

namespace Eclipse
{
    namespace Application
    {
        void ChatSender::_fetchCaches()
        {
            netInterface = object->m_ComponentContainer.GetComponent<Chat::NetworkChatInterface>();
        }

        void ChatSender::ThreadedCin()
        {
            while (true)
            {
                netInterface->Send(Engine::Console::ReadLine());
            }
        }

        void ChatSender::Awake()
        {
            _fetchCaches();
            // Create a new thread.
            inputThread = std::thread([this] {this->ThreadedCin(); });
        }

        void ChatSender::Update() {/*void*/}

        void ChatSender::Reset() {/*void*/}

        void ChatSender::Start() {/*void*/}

        void ChatSender::Dispose()
        {
            inputThread.join();
        }
    }
}
```

Alright now that you have regenerated the project and have the Component `ChatSender` to use. Its time to setup the client.

## Setting up the Client Project.
**NOTE: EVERYTHING UNDER THIS SECTION APPLIES TO THE CLIENT PROJECT.**

So, what should our Client Application do? Well because it will allow the user to communicate to everyone on the server. To do this we will need a way to connect to any server with any port. So we will allow for the user to type an ip-address and port.

To do this we will use the `Console::ReadLine() -> std::string` function to prompt an input and return it as a string. In the `ApplicationDemo` class override the `OnEngineInit() -> void`. Within the `ApplicationDemo.cpp` we will want to include the following header files.

```cpp
// Used to create an object in the scene.
#include <EclipseEngine/include/Object.h>
// Used to composite
#include <EclipseNetworking/include/NetworkClient.h>

#include "EclipseChat/include/ConsoleChatWriter.h"
#include "EclipseChat/include/NetworkChatInterface.h"

#include "ChatSender.h"
#include "EclipseEngine/include/Console.h"
#include "EclipseNetworking/include/NetworkIdentifiers.h"
```

We already know the `Object.h` header file. So it wont be explained. 
The `NetworkClient.h` is a component used to declare this application as a client.
The `ConsoleChatWriter.h` is a component used by the `ChatManager` component as a message output. Because the `ChatManager` is a modular system that uses 2 components to fully function. It Requires an `Input` component that is derived from `ChatInterface.h` and it has an optional `Output` component that is derived `ChatWriter.h`. This chat writer is optional, if it does not exist the chat manager will simply not output any messages, however it will still function. The `Input` and `Output` components being used for this tutorial are the `NetworkChatInterface.h` and the `ConsoleChatWriter.h` respectively. Due to this functionality it allows for the user to create custom input and output components and well as mix & match components. This allows for diverse customizability, and follows the `Open Closed Principle` as it is open for extension but closed for modification.

The `Console.h` is an Eclispe Wrapper around the Windows console.
The `NetworkIdentifers.h` is what we will be used to identify that our packet is a chat message.

Alright, so lets get coding!.

The first thing we want to do is get the ip-address and port of the server the user will connect to, there are plenty of ways to do this, but for our tutorial we will simply poll the user to enter the ip-address & port as mentioned above. This can be done by using the `Console.h` class.

```cpp
void NetworkClientApplication::OnEngineInit()
{
    Console::WriteLine("Enter the server IP.");
    std::string ipString = Console::ReadLine();

    Console::WriteLine("Enter port to start server.");
    std::string portString = Console::ReadLine();

... more code below

}
```

Once we have obtained the users input we will need to parse the data into their appropriate types. Luckily we only need to parse the port as `EclispeNetworking` uses `std::string` as the input for an ip-address. To do this we can use the function `std::stoi` within a `try..catch` statement. This will ensure that we can handle the exception instead of the application immediately crashing, as `std::stoi` does not give errors nicely.

```cpp
void NetworkClientApplication::OnEngineInit()
{

... more code above
	// create an empty short container for the port.
	short port;
    try
    {
	    // attempt to parse the string to an integer and cast it to a short.
        port = static_cast<short>(std::stoi(portString));
    }
    catch (...)
    {
	    // safely handle the exception. In this case we want the application to stop.
        External::Debug::DebugAPI::Error("Port input was invalid.");
        // query the engine to stop.
        Application::Stop();
        return;
    }
    
... more code below

}
```
Another way to handle the exception is to ask the user to re-enter a new port. However for this tutorial this functionality will be enough. Once we have the port in a `short` data type. We can now begin to add the components to build the Networking Client.

The first thing we want to do is create an `Eclipse::Object()` and add the following components: `ChatSender.h`, `NetworkClient.h`, `NetworkChatInterface.h`, `ConsoleChatWriter.h`, `ChatManager.h`, and add the object to the scene.
```cpp
void NetworkClientApplication::OnEngineInit()
{

... more code above

 // create object
    const auto client_object = new Object();

	// Add the `ChatSender` component.
    client_object->m_ComponentContainer.AddComponent<Eclipse::Application::ChatSender>();

	// Add the `NetworkClient` component and store it in a variable as it will be used later.
    const auto client = client_object->m_ComponentContainer.AddComponent<NetworkClient>();
	// Add the `NetworkChatInterface` component and store it in a variable as it will be used later.
    const auto chatInterface = client_object->m_ComponentContainer.AddComponent<Chat::NetworkChatInterface>();

	// Add the `ChatManager` component.
    client_object->m_ComponentContainer.AddComponent<Chat::ChatManager>();

	// Add the `ConsoleChatWriter` component.
    client_object->m_ComponentContainer.AddComponent<Chat::ConsoleChatWriter>();

	// Finally add the object to the active scene.
    SceneManagement::SceneManager::Instance->GetActiveScene()->AddObject(client_object);
    
... more code below

}
```

Once this `Networking Client` object has been created & composited we can now prepare the client's handler and begin the interface.

```cpp
void NetworkClientApplication::OnEngineInit()
{
	// Prepare the Handler to accept packets with the `EID_MESSAGE` Identifier.
	client->handler.OnPacketReceived.AddEvent((unsigned)EID_MESSAGE, new EclipseEvent<NetworkPacket&>);

	// Start the chat interface.
    if (chatInterface)
        chatInterface->StartInterface();

	// Start the client process.
    if (client)
    {
        client->networkPort = port;
        client->networkAddress = ipString;
        client->StartProcess();
    }
}
```
And that's it, pretty simple right? Now all that is left to do is set up the server project.

## Setting up the Server Project.
**NOTE: EVERYTHING UNDER THIS SECTION APPLIES TO THE SERVER PROJECT.**

So, what should our Server Application do? Well because our clients are connected to our server, we need to be notified when a Client sends a message to the server. And we need the server to relay our message to all connected clients. (luckily all of this is taken care of us by the integrated chat api.), however we will need to set the server up and get the user's input on which port they'd like to start the server on.

To do this we will use the `Console::ReadLine() -> std::string` function to prompt an input and return it as a string. In the `ApplicationDemo` class override the `OnEngineInit() -> void`. Within the `ApplicationDemo.cpp` we will want to include the following header files.

```cpp
// Used to create an object in the scene.
#include <EclipseEngine/include/Object.h>
// Used to composite
#include <EclipseNetworking/include/NetworkServer.h>

#include "EclipseChat/include/ConsoleChatWriter.h"
#include "EclipseChat/include/NetworkChatInterface.h"
#include "EclipseEngine/include/SceneManager.h"

#include "EclipseEngine/include/Console.h"
#include "EclipseNetworking/include/NetworkIdentifiers.h"
```

We already know the `Object.h` header file. So it wont be explained. 
The `NetworkClient.h` is a component used to declare this application as a client.
The `ConsoleChatWriter.h` is a component used by the `ChatManager` component as a message output. Because the `ChatManager` is a modular system that uses 2 components to fully function. It Requires an `Input` component that is derived from `ChatInterface.h` and it has an optional `Output` component that is derived `ChatWriter.h`. This chat writer is optional, if it does not exist the chat manager will simply not output any messages, however it will still function. The `Input` and `Output` components being used for this tutorial are the `NetworkChatInterface.h` and the `ConsoleChatWriter.h` respectively. Due to this functionality it allows for the user to create custom input and output components and well as mix & match components. This allows for diverse customizability, and follows the `Open Closed Principle` as it is open for extension but closed for modification.

The `Console.h` is an Eclispe Wrapper around the Windows console.
The `NetworkIdentifers.h` is what we will be used to identify that our packet is a chat message.

Alright, so lets get coding!.

The first thing we want to do is get the ip-address and port of the server the user will connect to, there are plenty of ways to do this, but for our tutorial we will simply poll the user to enter the ip-address & port as mentioned above. This can be done by using the `Console.h` class.

```cpp
void NetworkClientApplication::OnEngineInit()
{
    Console::WriteLine("Enter port to start server.");
    std::string portString = Console::ReadLine();

... more code below

}
```

Once we have obtained the users input we will need to parse the data into their appropriate types. Luckily we only need to parse the port as `EclispeNetworking` uses `std::string` as the input for an ip-address. To do this we can use the function `std::stoi` within a `try..catch` statement. This will ensure that we can handle the exception instead of the application immediately crashing, as `std::stoi` does not give errors nicely.

```cpp
void NetworkClientApplication::OnEngineInit()
{

... more code above
	// create an empty short container for the port.
	short port;
    try
    {
	    // attempt to parse the string to an integer and cast it to a short.
        port = static_cast<short>(std::stoi(portString));
    }
    catch (...)
    {
	    // safely handle the exception. In this case we want the application to stop.
        External::Debug::DebugAPI::Error("Port input was invalid.");
        // query the engine to stop.
        Application::Stop();
        return;
    }
    
... more code below

}
```
Another way to handle the exception is to ask the user to re-enter a new port. However for this tutorial this functionality will be enough. Once we have the port in a `short` data type. We can now begin to add the components to build the Networking Client.

The first thing we want to do is create an `Eclipse::Object()` and add the following components: `ChatSender.h`, `NetworkClient.h`, `NetworkChatInterface.h`, `ConsoleChatWriter.h`, `ChatManager.h`, and add the object to the scene.
```cpp
void NetworkClientApplication::OnEngineInit()
{

... more code above

	// create server object
    const auto serverObject = new Object();
	// Add the `NetworkServer` component and store it in a variable as it will be used later.
    const auto server = serverObject->m_ComponentContainer.AddComponent<NetworkServer>();
    // Add the `NetworkChatInterface` component and store it in a variable as it will be used later.
    const auto chatInterface = serverObject->m_ComponentContainer.AddComponent<Chat::NetworkChatInterface>();
    // Add the `ChatManager` component.
    serverObject->m_ComponentContainer.AddComponent<Chat::ChatManager>();
    // Add the `ConsoleChatWriter` component.
    serverObject->m_ComponentContainer.AddComponent<Chat::ConsoleChatWriter>();

    // Add the server object to the scene.
    SceneManagement::SceneManager::Instance->GetActiveScene()->AddObject(serverObject);;
    
... more code below

}
```

Once this `Networking Client` object has been created & composited we can now prepare the client's handler and begin the interface.

```cpp
void NetworkClientApplication::OnEngineInit()
{

... more code above

	// Prepare the Handler to accept packets with the `EID_MESSAGE` Identifier.
	server->handler.OnPacketReceived.AddEvent((unsigned)EID_MESSAGE, new EclipseEvent<NetworkPacket&>);

	// Start the chat interface.
    if (chatInterface)
        chatInterface->StartInterface();

	// Start the client process.
    if (server)
    {
        server->networkPort = port;
        server->StartProcess();
    }
}
```
And that is it. You can compile both projects. You will want to start the server first and type in any port in between 0-65535. You will then want to start the client and type `localhost` as the ip-address and the port you chose for the server and you should be connected to the server. To allow outside connected to connect to your server you will need to port-forward your network on the port you chose, however that is beyond the scope of this tutorial.

And this is the final tutorial (as of 06/09/2022). Happy coding!.

- The Eclispe Team.

