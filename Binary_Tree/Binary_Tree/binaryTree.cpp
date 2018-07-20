/*
	insert 시에 어떤것을 넘겨준는게 좋을까??
	data값?
	아니면
	그냥 node?

	어차피 나중에 뭐든 들어가게 하기위해 void pointer 나 template 쓰려면 
	node 를 넘겨주는게 좋을것 같긴한데 이경우 메인을 어떻게 손을대서 만들어야 하는지,

	또한 node 와 tree를 따로 만들어야 하는지.
	
	어찌 어찌 만들긴 했는데
	문제는 형선이가 출력하라고 한 모양대로 출력하는것이 생각보다 쉽지 않다.
	node에 depth 변수를 만들어서 트리의 높이를 측증하고 지금 만든 show 의알고리즘을 이용하여 depth가 0인것 부터 가장 깊은것까지 순서대로 찍어야 하나
	


*/



/*

class tree {
public :
node *nowNode;
void insert(int data);
tree(node nowNode) {
this->nowNode = &nowNode;
}
};

void tree::insert(int data) {

node newNode(data);
if (nowNode->data <= newNode.data) {
//왼쪽이 비어있으면 왼쪽에 삽입
if (nowNode->left == NULL)
{
nowNode->left = &newNode;
}//왼쪽에 data가 있으면 recursion 한번더
else {
nowNode->left->insert(*newNode->data);
}

}
else if (nowNode->data > newNode.data) {
//오른쪽이 비어있으면 오른쪽에 삽입
if (nowNode->right == NULL)
{
nowNode->right = &newNode;
}//오른쪽에 data가 있으면 recursion 한번더
else {
nowNode->right->insert(newNode);
}
}


}



*/


#include <iostream>
#include <Windows.h>
using namespace std;

class node{

private:
	
public:
	int data;
	int depth;
	node  *left;
	node *right;
	node(int data) {
		this->data = data;
	};
	~node() {};
	void insert(int data);
	void show();
};

//data 가지고 비교만 하다가 최종적으로 딱 트리구조에 들어갈때 node만들어서 넣어버리는 구조
void node::insert(int data) {

	if (this->data <= data) {
		//왼쪽이 비어있으면 왼쪽에 삽입
		if (this->left == NULL)
		{
			this->left = new node(data);
		}//왼쪽에 data가 있으면 recursion 한번더
		else {
			this->left->insert(data);
		}

	}
	else if (this->data > data) {
		//오른쪽이 비어있으면 오른쪽에 삽입
		if (this->right == NULL)
		{
			this->right = new node(data);
		}//오른쪽에 data가 있으면 recursion 한번더
		else {
			this->right->insert(data);
		}
	}


}

void node::show() {
	if (this->left != NULL) {
		this->left->show();
	}
	printf("%d\n",this->data);
	if (this->right != NULL) {
		this->right->show();
	}
	
}




int main() {
	//노드 객체 생성
	int a;
	scanf_s("%d", &a);
	node n(a);

	while(1) {
		scanf_s("%d", &a);
		printf("\n-----\n");
		n.insert(a);
		n.show();
		printf("\n======================================\n");


	}

	

	
	


	system("pause");
}


