# Logger
A lightweight easy-to-use logging class with 4 different stages.
- **Info**
- **Warning**
- **Error**
- **Fatal Error**  

How to integrate it into a project with ***Premake***
-------
Clone the repository with git into a folder of your choice.

In your main **premake5.lua**, include it into your workspace and include it into your project:
```lua
workspace "NameOfWorkspace"
  architecture "x86_64"
  ...

include "path-to-Logger-folder/Logger" <-- Include it into your workspace/solution

project "NameOfProject
  ...
  
  includedirs {
    "path-to-Logger-folder/Logger/src" <-- To include the header file into your project
  }
  
  links {
    "Logger" <-- To link it to your project
  }
```

How to use it
----
Create a logger with:
```c++
Log::Logger my_logger("MyLogger"); //The name here will be displayed in the console
```
And then use it as you would use `printf`:
```
my_logger.Info("Info");
my_logger.Warning("Warning");
my_logger.Error("Error");
my_logger.FatalError("Fatal Error");
```
or:
```
int number = 6;
my_logger.Info("Number is: %i", number);
...
```
For more info on formatting, see [here].

It checks if a console window is already open, if not, it will create one.

[here]: https://www.cplusplus.com/reference/cstdio/printf/
