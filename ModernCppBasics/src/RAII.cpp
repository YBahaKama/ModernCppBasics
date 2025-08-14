//#define RUN_RAII

#include <iostream>


	class TestClass {
	private:
		int testData;

	public:
		// Constructor
		TestClass() {
			testData = 42;
			std::cout << "Constructor called. testData = " << testData << std::endl;
		}

		// Destructor
		~TestClass() {
			std::cout << "Destructor called." << std::endl;
			//delete &testData;


		}

		// Example method to access testData
		int getTestData() const {
			return testData;
		}
	};


	void doSomething() {
		// This function is just to demonstrate that the destructor will be called when the object goes out of scope.
		TestClass localObj;
		std::cout << "Inside doSomething, testData = " << localObj.getTestData() << std::endl;
	} // localObj goes out of scope here, and its destructor is called.

#ifdef RUN_RAII
	int main() {
		// RAII is a programming idom. Shortly it means that resources are acquired during the lifetime of an object 
		// and released when the object goes out of scope.
		// RAII is a common pattern in C++ for managing resources such as memory, file handles, and network connections.

		TestClass objNew; // Creates an object on the stack
		TestClass* objNew2 = new TestClass(); // Creates another object on the heap
		std::cout << "Accessing testData on stack: " << objNew.getTestData() << std::endl;
		std::cout << "Accessing testData on heap: " << objNew2->getTestData() << std::endl;

		doSomething(); // Call a function that creates a local object, demonstrating RAII

		// When the function doSomething() returns, the local object localObj is destroyed, and its destructor is called.
		// When the main function returns, the stack object objNew is destroyed, and its destructor is called.

		// even we don't call the destructors of the classes, when we start the program we can see both creation and destruction of object on te stack.

		delete objNew2;  // you can uncomment this line to manually delete the heap object and see the difference


		return 0;
	}// Note: The destructor for objNew2 will be called automatically when the program exits, but it's a good practice to delete heap-allocated objects to avoid memory leaks.
#endif
