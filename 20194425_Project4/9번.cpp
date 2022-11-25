#include <iostream>
using namespace std;

template<typename T>
class Circle {
	T  x, y, r;
public:
	Circle(T _x, T _y, T _r) {
		x = _x;
		y = _y;
		r = _r;
	}
	T area() {
		double a = 3.14 * r * r;
		return a;
	}
};
int main() {
	Circle<double> circleA(0.0, 0.0, 10.0);
	cout << "¸éÀû" << circleA.area() << "\n";
	return 0;
}
