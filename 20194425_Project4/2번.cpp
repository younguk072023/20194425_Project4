#include <iostream>
#include <string>
using namespace std;

class Time {
private:
	int hours;
		int minutes;
public:
	Time() :hours{ 0 }, minutes{ 0 } {

	}
	Time(int h, int m) : hours{ h }, minutes{ m } {

	}
	void displayTime() {
		cout << hours << ":" << minutes << "\n";
	}
	Time& operator++() {
		if (minutes != 59) {
			++minutes;
		}
		else {
			minutes = 0;
			++hours;
		}
		return *this;
	}
	const Time operator++(int i) {
		Time temp = { *this };
		if (minutes != 59) {
			++minutes;
		}
		else {
			minutes = 0;
			++hours;
		}
		return temp;
}
	

};
int main() {
	Time a(10, 59);
	a.displayTime();
	a++;
	a.displayTime();
	a++;
		a.displayTime();
		return 0;
}