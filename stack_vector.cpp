#include <iostream>
#include  <vector>
#include <Windows.h>
using namespace std;

template <typename T>
class stack {
private:
	vector<T> v;
	int count = 0;

public:
	stack() {}  //생성자가 여러개일 수 있는가? // 여러개라면 넘겨받는 ㄴ일무ㅏㅣㅗ물나췌
	~stack() {}
	T temp;
	void pop();
	void push();
	void show_stack();
};

template <typename T>
void stack<T>::pop() {
	if (v.empty()) {
		cout << "there is notting in stack";
	}
	else {
		temp = v.back();
		v.pop_back();
		cout << temp;
		count--;
	}
}

template <typename T>
void stack<T>::push() {
	T vin;
	cin >> vin;
	v.push_back(vin);
	count++;
}

template <typename T>
void stack<T>::show_stack() {
	cout << "현재 스택 ->";
	for (int i = 0; i < count; i++) {
		cout << v.at(i) << "-";
	}
	cout << "\n";

}




int main() {

	int in;
	char menu;

	//여기로 점프
here1:
	cout << "select the data type\n 1.int 2.char 3.double\n";
	cin >> menu;

	if (menu == '1') {
		stack<int> s;
		while (1) {
			cout << "1.push or 2.pop\n";
			cin >> menu;

			if (menu == '1') {
				s.push();
				s.show_stack();
			}
			else if (menu == '2') {
				s.pop();
				s.show_stack();
			}
		}
	}
	else if (menu == '2') {
		stack<char> s;
		while (1) {
			cout << "1.push or 2.pop\n";
			cin >> menu;

			if (menu == '1') {
				s.push();
				s.show_stack();
			}
			else if (menu == '2') {
				s.pop();
				s.show_stack();
			}
		}
	}
	else if (menu == 3) {
		stack<double> s;
		while (1) {
			cout << "1.push or 2.pop\n";
			cin >> menu;

			if (menu == '1') {
				s.push();
				s.show_stack();
			}
			else if (menu == '2') {
				s.pop();
				s.show_stack();
			}
		}
	}
	else {
		goto here1;
	}








	//system("pause");
	return 0;
}

