#include <iostream>

using namespace std;

template <typename T>
class node {
private:

public:
	T data;
	node *nextNode;

	node(T data) {
		this->data = data;
	};
	~node() {};
};

template <typename T>
class queue {
private:
	int size = 0;
public:

	node<T> * head;
	node<T> *tail;

	void push(T data);
	T pop();
	void queueStatus();
	bool isEmpty(); // top¿Ã 0¿Ã∏È empty
	void Qsize();
};

template <class T>
void queue<T>::push(T data) {

	if (isEmpty()) {
		//create node and tag head and tail
		this->head = new node<T>(data);
		this->tail = this->head;
	}
	else {
		//create node
		this->tail->nextNode = new node<T>(data);
		//tag  to new node
		this->tail = this->tail->nextNode;
	}
	size++;

	return;
}

template <class T>
T queue<T>::pop() {

	if (isEmpty()) {
		cout << "there is nothing in stack" << endl;

	}
	else {
		T data = this->head->data;
		node<T> *temp = this->head;

		//tag head to nextNode
		this->head = this->head->nextNode;

		cout << "pop! " << data << endl;
		//and delete
		delete temp;
		size--;
		return data;
	}
}

template <class T>
void queue<T>::queueStatus() {

	node<T> *temp = this->head;
	for (int i = 0; i < size; i++) {
		cout << temp->data << " ";
		if (i + 1 == size)
			continue;
		temp = temp->nextNode;

	}

}

template <class T>
bool queue<T>::isEmpty() {  // if size is empty ture

	if (size == 0)
		return true;
	else
		return false;


}

template <class T>
void queue<T>::Qsize() {

	cout << "size of queue is " << size << endl;

}

int main() {

	queue<int> queue;

	int pick;

	while (1) {

		cout << " choose push or pop" << endl;
		cin >> pick;
		int temp = 0;
		if (pick == 1) {
			cin >> temp;
			queue.push(temp);
			queue.queueStatus();
		}
		else if (pick == 2) {
			temp = queue.pop();
			queue.queueStatus();
		}

		cout << endl;
	}

	return 0;

}