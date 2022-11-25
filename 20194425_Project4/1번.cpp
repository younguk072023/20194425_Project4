#include <iostream>
#include<string>
using namespace std;

//1��
class Box {
private:
	double length;
	double width;
	double height;
public:
	Box(double l = 0, double w = 0, double h = 0) :length{ l }, width{ w }, height{ h } {

	}
	double getVolume(void) {
		return length * width * width;
	}
	double getlength(void) {
		return length;
	}
	double getheight(void) {
		return height;
	}
	double getwidth(void) {
		return width;
	}
	Box operator+(const Box& b2) {
		Box b;
		b.length = this->length + b2.length;
		b.height = this->height + b2.height;
		b.width = this->width + b2.width;

		return b;

	}
	bool operator==(Box& b2) {
		return(length == b2.length && height == b2.height && width == b2.width);
	}




	bool operator!=(Box& b2) {
		return !(*this == b2);

	}


	bool operator<(Box& b2) {
		return (this->getVolume() < b2.getVolume());
	}
	void print() {
		cout << "������ ����" << getlength() << "\n";
		cout << "������ �ʺ�" << getwidth() << "\n";
		cout << "������ ����" << getheight() << "\n";
		cout << "������ ����" << getVolume() << "\n\n";

	}
};
	int main() {
		Box a(10, 10, 10), b(20, 20, 20);
		cout << "���� #1\n";
		a.print();
		cout << "���� #2\n";
			b.print();

			cout.setf(cout.boolalpha);
			cout << (a < b);
			return 0;
	}