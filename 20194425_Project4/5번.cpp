#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class sprite {
protected:
	int x, y;
	char shape;
public:
	sprite(int x, int y, char shape) :x{ x }, y{ y },shape{shape}{}
	virtual ~sprite() {}
	virtual void move(char d) = 0;
	char getshape() { return shape; }

	int getX() { return x; }
	int getY() { return y; }

	bool checkcollision(sprite* other) {
		if (x == other->getX() && y == other->getY())
			return true;
		else
			return true;
	}

};

class Hero :public sprite {
public:
	Hero(int x, int y) :sprite(x, y, 'H'){}
	void draw() { cout << "H"; }
	void move(char d) {
		if (d == 'a') { x -= 1; }
		else if (d == 'w') { y -= 1; }
		else if (d == 's') { y += 1; }
		else if (d == 'd') { x += 1; }

	}
};
class Treasure :public sprite {
public:
	Treasure(int x,int y):sprite(x,y,'T'){}
	void move(char d){}

};
class Enemy : public sprite {
public:
	Enemy(int x,int y):sprite(x,y,'E'){}
	void move(char d){}

};
class Board {
	char *board;
	int width, height;
public:
	Board(int w, int h) :width{ w }, height{ h } {
		board = new char[width * height];
		clearBoard();
	}
	~Board() {
		delete board;

	}
	void setValue(int r, int c, char shape) {
		board[r * width + c] = shape;
	}
	void printBoard() {
		for (int i = 0; i < height; i++) {
			cout << "\t";
			for (int j = 0; j < width; j++)
				cout << board[i * width + j];
			cout << endl;
		}
	}
void clearBoard() {
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			board[i * width + j] = '.';
}
};
void drawLine(char x) {
	cout << endl;
	for (int i = 0; i < 100; i++)
		cout << x;
	cout << endl;

}
int main() {
	vector<sprite*>list;
	int width, height;

	cout << "������ ũ�⸦ �Է��Ͻÿ�[�ִ� 10x10]:" << endl;
	cout << "����: ";
	cin >> width;
	cout << "����: ";
	cin >> height;

	Board board(height, width);
	list.push_back(new Hero(0, 0));
	list.push_back(new Treasure(height - 1, width - 1));
	list.push_back(new Enemy(3, 3));

	drawLine('*');
	cout << "�� ������ ��ǥ�� ����(T)�̳� ��(E)�� ������ �ʰ� ������ �����ϴ� ���̴�.";
	cout << "���ΰ��� a,s,w,d Ű�� �̿��Ͽ� ������ �� �ִ�." << endl;
	drawLine('*');
	cout << endl;
	while (true) {
		board.clearBoard();
		for (auto& e : list)
			board.setValue(e->getY(), e->getX(), e->getshape());
		board.printBoard();

		char direction;
		cout << "���� �����ϱ��(a,s,w,d): ";
		cin >> direction;

		for (auto& e : list)
			e->move(direction);
		drawLine('-');

	}
	for (auto& e : list)
		delete e;
	list.clear();
	return 0;
}