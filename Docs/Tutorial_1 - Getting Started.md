# Welcome to the Eclipse Engine.

The Eclipse Engine has been designed to be as modular as possible, due to this design decision there is quite a bit of setup, but don't worry. I promise its simple!.

The first thing you want to do is actually acquire the engine and compile it for your development platform (windows & linux) the Eclipse Engine uses GitHub to house all its source code (as it follows the open source standard). Due to this having git installed on your system is a pre-requisite, you can find guides on how to install git on all supported operating systems [here](https://git-scm.com/downloads)

Once Git has been installed, you can follow these steps to clone the global repository with all the eclipse extensions.

## Cloning The Repository
To clone the repository on Windows & Linux simply type
```
cd "directory that you want to clone this repository into"
// example:
cd D:\dev\git\Eclipse

git clone https://github.com/jwrmg/Eclipse.git --recursive
```

## Generating a Solution
Generating a solution/workspace in Eclipse is simple due to the engine following the open source standard. Eclipse uses premake5 for solution/workspace generation. So to get started go into the "./.premake/" directory located at the root of the cloned repository.

once you are in this directory, open a command line interface and navigate your working directory to this "./.premake/" directory
```
// Example:
cd D:\dev\git\Eclipse\.premake\
```
after this you want to generate the solution/workspace with a specific code. here is a list of premake5 generation codes.

|Code|Description|
|----|-----------|
|vs2022|Generate Visual Studio 2022 project files|
|vs2019|Generate Visual Studio 2019 project files|
|vs2017|Generate Visual Studio 2017 project files|
|vs2015|Generate Visual Studio 2015 project files|
|vs2013|Generate Visual Studio 2013 project files|
|vs2012|Generate Visual Studio 2012 project files|
|vs2010|Generate Visual Studio 2010 project files|
|vs2008|Generate Visual Studio 2008 project files|
|vs2005|Generate Visual Studio 2005 project files|
|gmake|Generate GNU Makefiles (This generator is deprecated by gmake2)|
|gmake2|Generate GNU Makefiles (including [Cygwin](http://www.cygwin.com/) and [MinGW](http://www.mingw.org/))|
|xcode4|XCode projects|
|codelite|CodeLite projects|
More information can be found [here](https://premake.github.io/docs/Using-Premake).

```
// Example: premake5 [workspace code]
premake5 vs2019 // this will generate a solution for visual studio 2019
```

Assuming everything went smoothly, there should be a newly generated Build folder under ./Build/ 
If there was an error with the project generation please see this [here] for more information on how to get help.

Now that your newly generated engine project has been generated. You're ready to start working with the Eclipse Engine! 
*See the next tutorial for `Creating a new Project!`*



