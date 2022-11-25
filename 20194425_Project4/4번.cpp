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
		cout << "�̸�: " << getName() << "\n";
		cout << "����: " << getSal() << "\n";
		cout << "��ü �޿�: " << computeSalary() << "\n";
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
		cout << "�̸�: " << getName() << "\n";
		cout << "����: " << getSal() << "\n";
		cout << "���ʽ�: " << getBo() << "\n";
		cout << "��ü �޿�:  " << computeSalary() << "\n";
		
	}
};
int main() {
	Manager m1("��ö��", 200, 100);
	m1.print();

	return 0;
}