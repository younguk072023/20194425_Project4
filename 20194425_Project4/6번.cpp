#include <iostream>
using namespace std;

class Weapon {
public:
	Weapon() {

	}
	virtual void load() = 0;

};
class Bomb :public Weapon {
public:
	Bomb() {

	}
	void load() {
		cout << "ÆøÅºÀ» ÀûÀçÇÕ´Ï´Ù.\n";
	}
};
class Gun :public Weapon {
public:
	Gun() {

	}
	void load() {
		cout << "ÃÑÀ» ÀûÀçÇÕ´Ï´Ù.\n";
	}
};

int main() {
	Weapon* weapons[3] = { NULL };
	weapons[0] = new Gun;
	weapons[1] = new Bomb;
	weapons[2] = new Bomb;

	for (int i = 0; i < 3; i++) {
		weapons[i]->load();
	}
	for (int i = 0; i < 3; ++i) {
		delete weapons[i];
		weapons[i] = NULL;
	}
}