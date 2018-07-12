#include <iostream>
#include <Windows.h>
using namespace std;

template <typename T>
class node {

private:
public:

	T data;
	node * prev;

	node(T data) {
		this->data = data;
	};
	~node() {};


};


template <typename T>
class stack {

private:
	int top = 0;
public:

	node<T> * topNode;

	stack() {};
	~stack() {};

	T pop();
	void push(T data);
	void size();  // top이 곧 사이즈
	bool isEmpty(); // top이 0이면 empty
	void showStack(); // stack에 들어있는것을 출력

};

template <class T>
void stack<T>::push(T data) {

	if (top == 0) {

		this->topNode = new node<T>(data);
		
	}
	else {
		
		node<T> *prev = this->topNode;
		this->topNode = new node<T>(data);
		this->topNode->prev = prev;
		
	}
	top++;
}

template <class T>
T stack<T>::pop() {
	
	if (isEmpty()) {
		cout << "stack is empty!" << endl;
	}
	else {
		T data = this->topNode->data;
		node<T> *temp = this->topNode;
		this->topNode = this->topNode->prev;
		delete  temp;
		top--;
		cout << "pop! " << data << endl;
		return data;
		
	}
	
}

template <class T>
void stack<T>::size() {
	cout << "size of stack is" << top << endl;
}

template <class T>
bool stack<T>::isEmpty() {
	if (top == 0) {
		//cout<< stack is empty<<endl;
		return 1;
	}
	else {
		//cout<< stack is not empty<<endl;
		return false;
	}
}

template <class T>
void stack<T>::showStack(){

	new node<T> *temp = this->topNode;

	for (int i = 0; i < top, i++) {
		cout << temp->data; << " ";

	}
	


}
int main(void) {

	//example
	stack<int> stack;
		
	int pick;

	while (1)
	{
		cout << "choose push or pop" << endl;
		cin >> pick;
		int temp = 0;
		if (pick == 1) {
			
			cin >> temp;
			stack.push(temp);
		}
		else if (pick == 2) {
			temp = stack.pop();
		}
		
		cout << endl;

	}


	system("pause");
	
}