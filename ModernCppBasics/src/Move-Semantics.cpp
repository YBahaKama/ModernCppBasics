#define RUN_MOVESEMANTICS

#include <iostream>
#include <string>


namespace MoveSemantics {

	class TestClassMS {

	private:
		int testData;
		std::string testString;

	public:
		TestClassMS() {
			testData = 42;
			testString = "Hello, World!";
			std::cout << "Constructor called. testData = " << testData << ", testString = " << testString << std::endl;
		}

		TestClassMS(int data) {
			testData = data;
			testString = "Hello, World!";
			std::cout << "Parameterized constructor called. testData = " << testData << ", testString = " << testString << std::endl;
		}

		TestClassMS(std::string data) {
			testData = 43;
			testString = data;

			std::cout << "Parameterized constructor called with string. testData = " << testData << ", testString = " << testString << std::endl;
		}

		TestClassMS(int datai, std::string datas) {
			testData = datai;
			testString = datas;


			std::cout << "Parameterized constructor called with int and string. testData = " << testData << ", testString = " << testString << std::endl;
		}

		TestClassMS(TestClassMS& inp) noexcept {
			testData = inp.testData;
			testString = inp.testString;
			std::cout << "Copy constructor called. testData = " << testData << ", testString = " << testString << std::endl;

		}

		TestClassMS(TestClassMS&& inp) noexcept {
			testData = inp.testData;
			testString = inp.testString;
			inp.testData = NULL;
			inp.testString = "";

			std::cout << "Move constructor called. testData = " << testData << ", testString = " << testString << std::endl;

		}

		void printObj() {
			std::cout << "printObj called. testData = " << testData << ", testString = " << testString << std::endl;
		}
	};
} // namespace MoveSemantics



#ifdef RUN_MOVESEMANTICS
int main() {

	MoveSemantics::TestClassMS myObj1;
	MoveSemantics::TestClassMS myObj2(3);
	MoveSemantics::TestClassMS myObj3("Test");
	MoveSemantics::TestClassMS myObj4(3, "Test");
	MoveSemantics::TestClassMS myObj5(myObj3); // Copy constructor

	std::cout << "start printing!\n";

	myObj1.printObj();

	MoveSemantics::TestClassMS myObj6(std::move(myObj2)); // Move constructor
	myObj2.printObj(); // myObj2 should be in a valid but unspecified state after move
	myObj6.printObj();

	return 0;
}
#endif // RUN_MOVESEMANTICS