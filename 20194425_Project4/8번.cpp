#include <iostream>
using namespace std;

template<class T>
T getSmallest(T arr[], int b) {
	T first = arr[0];
	for (int i = 0; i < b; i++) {
		if (first > arr[i]) {
			first = arr[i];
		}
	}
	return first;
}
int main() {
	double list[] = { 1.2,3.3,9.0,1.5,8.7 };
	cout << "ÃÖ¼Ò°ª" << getSmallest(list, 5) << "\n";
	return 0;
}