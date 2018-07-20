/*
	insert �ÿ� ����� �Ѱ��ش°� ������??
	data��?
	�ƴϸ�
	�׳� node?

	������ ���߿� ���� ���� �ϱ����� void pointer �� template ������ 
	node �� �Ѱ��ִ°� ������ �����ѵ� �̰�� ������ ��� �����뼭 ������ �ϴ���,

	���� node �� tree�� ���� ������ �ϴ���.
	
	���� ���� ����� �ߴµ�
	������ �����̰� ����϶�� �� ����� ����ϴ°��� �������� ���� �ʴ�.
	node�� depth ������ ���� Ʈ���� ���̸� �����ϰ� ���� ���� show �Ǿ˰����� �̿��Ͽ� depth�� 0�ΰ� ���� ���� �����ͱ��� ������� ���� �ϳ�
	


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
//������ ��������� ���ʿ� ����
if (nowNode->left == NULL)
{
nowNode->left = &newNode;
}//���ʿ� data�� ������ recursion �ѹ���
else {
nowNode->left->insert(*newNode->data);
}

}
else if (nowNode->data > newNode.data) {
//�������� ��������� �����ʿ� ����
if (nowNode->right == NULL)
{
nowNode->right = &newNode;
}//�����ʿ� data�� ������ recursion �ѹ���
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

//data ������ �񱳸� �ϴٰ� ���������� �� Ʈ�������� ���� node���� �־������ ����
void node::insert(int data) {

	if (this->data <= data) {
		//������ ��������� ���ʿ� ����
		if (this->left == NULL)
		{
			this->left = new node(data);
		}//���ʿ� data�� ������ recursion �ѹ���
		else {
			this->left->insert(data);
		}

	}
	else if (this->data > data) {
		//�������� ��������� �����ʿ� ����
		if (this->right == NULL)
		{
			this->right = new node(data);
		}//�����ʿ� data�� ������ recursion �ѹ���
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
	//��� ��ü ����
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


