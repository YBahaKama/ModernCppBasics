//#define RUN_SMAARTPTR

#include <iostream>
#include <memory>

namespace SmartPointers {
	class vec2 {
	private:
		double x;
		double y;
	public:
		vec2() = default;
		vec2(double x, double y) : x(x), y(y) {
			std::cout << "vec2 created: (" << x << ", " << y << ")" << std::endl;
		}

		~vec2() {
			std::cout << "vec2 destroyed: (" << x << ", " << y << ")" << std::endl;
		}

		double getX() const { return x; }
		double getY() const { return y; }
	};


	class triangle {
	private:
		vec2 a;
		vec2 b;
		vec2 c;

	public:
		triangle() = default;
		triangle(vec2 a, vec2 b, vec2 c) {
			try
			{
				this->a = a;
				this->b = b;
				this->c = c;

				std::cout << "Triangle created" << std::endl;
			}
			catch (const std::exception&)
			{
				std::cout << "Triangle creation error!" << std::endl;

			}


		}

		~triangle() {
			std::cout << "Triangle destroyed" << std::endl;
		}

		void draw() const {
			std::cout << "Drawing triangle with vertices: "
				<< a.getX() << ", " << a.getY() << "; "
				<< b.getX() << ", " << b.getY() << "; "
				<< c.getX() << ", " << c.getY() << std::endl;

			for (auto i = -5; i < 6; i++)
			{
				for (auto j = -5; j < 6; j++)
				{
					if (a.getX() == j && a.getY() == -i || b.getX() == j && b.getY() == -i || c.getX() == j && c.getY() == -i)
					{
						std::cout << "* ";

					}
					else
					{
						std::cout << ", ";
					}
				}
				std::cout << std::endl;
			}

		}
	};
} // namespace SmartPointers

#ifdef RUN_SMAARTPTR
int main() {

	std::unique_ptr<SmartPointers::triangle> ptr1(new SmartPointers::triangle(SmartPointers::vec2(-1, 0), SmartPointers::vec2(0, 1), SmartPointers::vec2(1, 0)));

	std::shared_ptr<SmartPointers::triangle> ptr2(new SmartPointers::triangle(SmartPointers::vec2(-1, 2), SmartPointers::vec2(2, 1), SmartPointers::vec2(1, 2)));

	std::shared_ptr<SmartPointers::triangle> ptr3 = ptr2; // shared ownership

	std::cout << "Drawing triangles:" << std::endl;
	std::cout << "ptr1\n";
	ptr1.get()->draw();
	std::cout << "ptr2\n";
	ptr2.get()->draw();
	std::cout << "ptr3\n";
	ptr3.get()->draw();

	return 0;
}
#endif