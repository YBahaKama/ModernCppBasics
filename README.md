# ModernCppBasics


In order to run the desired cpp. Just uncomment the define in the 1st line of the cpp file.
Note: be sure not more then 1 define is open, otherwise the code will not compile.



In this repository, you can find sample code about basics of modern C++ (c++11 and onward). My goal in this repository is to provide simple and clear examples of modern C++ features, such as smart pointers, lambda expressions, range-based for loops, and more.
The code is organized in a way that each cpp file demonstrates a specific feature or concept. You can run each cpp file independently to see how the feature works.

RAII.cpp

In this file, you can find examples of Resource Acquisition Is Initialization (RAII) in C++. RAII is a programming idiom that ensures resources are properly managed and released when they go out of scope. The code demonstrates how to use RAII to manage resources like file handles and memory.


SmartPointers.cpp

In this file, you can find examples of smart pointers in C++. Smart pointers are a modern C++ feature that helps manage dynamic memory automatically. The code demonstrates how to use `std::unique_ptr` and `std::shared_ptr` to manage resources without manual memory management.

Move-Semantics.cpp

In this file, you can find examples of move semantics in C++. Move semantics is a feature introduced in C++11 that allows the transfer of resources from one object to another without copying. The code demonstrates how to use move constructors and move assignment operators to optimize resource management.