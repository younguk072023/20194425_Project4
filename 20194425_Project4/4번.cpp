#include<iostream>
#include <string>

using namespace std;

class Employee {
	string name;
	int salary;
public:
	Employee(string n, int s) :name(n), salary(s) {

	}
	virtual int computeSalary() {
		return salary;
	}
	int getSal() {
		return salary;

	}
	string getName() {
		return name;
	}
	void setSal(int s) {
		salary = s;
	}
	void setName(string n) {
		name = n;
	}
	virtual void print() {
		cout << "이름: " << getName() << "\n";
		cout << "월급: " << getSal() << "\n";
		cout << "전체 급여: " << computeSalary() << "\n";
	}
};
class Manager : public Employee {
	int bonus;
public:
	Manager(string n, int s, int b) :Employee(n, s), bonus(b) {

	}
	int getBo() {
		return bonus;
	}
	int computeSalary() {
		return (getSal() + getBo());
	}
	void print() {
		cout << "이름: " << getName() << "\n";
		cout << "월급: " << getSal() << "\n";
		cout << "보너스: " << getBo() << "\n";
		cout << "전체 급여:  " << computeSalary() << "\n";
		
	}
};
int main() {
	Manager m1("김철수", 200, 100);
	m1.print();

	return 0;
}