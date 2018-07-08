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
	stack() {}  //�����ڰ� �������� �� �ִ°�? // ��������� �Ѱܹ޴� ���Ϲ����Ӥǹ�����
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
	cout << "���� ���� ->";
	for (int i = 0; i < count; i++) {
		cout << v.at(i) << "-";
	}
	cout << "\n";

}




int main() {

	int in;
	char menu;

	//����� ����
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

