#include <iostream>
#include  <vector>
#include <string>

using namespace std;
//스택이 비어있는지 검사하는 isEmpty
//스택 사이즈 검사
//스택 클리어할때 pop을 사이즈 만큼 해서 클리어 하지 말것.

class stack {
private:
	vector<string> v;
	int count = 0;

public:
	stack() {}
	~stack() {}
	string	temp;
	void pop();
	void push();
	void showStack();
	bool isEmpty();
	void stackSize();
	void stackClear();
};


void stack::pop() {
	if (v.empty()) {
		cout << "there is notting in stack\n";
	}
	else {
		temp = v.back();
		v.pop_back();
		count--;
	}
}

void stack::push() {
	string vin;
	cin.ignore();
	getline(cin, vin);
	//cin >> vin;
	// cout << vin;
	v.push_back(vin);
	count++;
}

void stack::showStack() {
	cout << "stack ->";
	for (int i = 0; i < count; i++) {
		cout << v.at(i) << "-";
	}
	cout << "\n";

}

bool stack::isEmpty() {
	if (count == 0)
		return true;
	else
		return false;

}

void stack::stackSize() {
	cout << "size is " << count << endl;
}

void stack::stackClear() {
	v.clear();
	count = 0;
}


int main() {

	int menu;
	stack s;
	while (1) {
		cout << "1.push or 2.pop or 3.isEmpty 4.stackSize 5.stackClear";
		cin >> menu;
		if (menu == 1) {
			s.push();
			s.showStack();
		}
		else if (menu == 2) {
			s.pop();
			s.showStack();
		}
		else if (menu == 3) {
			cout << s.isEmpty() << endl;
		}
		else if (menu == 4) {
			s.stackSize();
		}
		else if (menu == 5) {
			s.stackClear();
			s.showStack();
		}

	}

	//system("pause");
	return 0;
}