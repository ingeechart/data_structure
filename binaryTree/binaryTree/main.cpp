#include <iostream>
#include <queue>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

void space (int n){
    for(int i=0;i<n;i++)
        cout<<" ";
}

void branch(int n){
    cout<<"/";
    while(n-->0)
        cout<<" ";
    cout<<"\\";
}


class biTree{
    struct node{
        int data;
        node *left,*right;
        node() : left(nullptr),right(nullptr) {}
        node(int data) : data(data), left(nullptr),right(nullptr) {}
        ~node(){delete left; delete right;}
        int max_depth(){
            int left_depth = left ? left->max_depth() : 0;
            int right_depth = right ? right->max_depth() : 0;
            return (left_depth > right_depth ? left_depth : right_depth)+1;
        }
    };
    
    
public:
    node *root;
    biTree() : root(nullptr) {}
    ~biTree(){delete root;}
    
    int get_max_depth(){ return root ? root->max_depth() :0;}
    void insert(int data,node * root);
    void search();
    void showTree();
    void buildTree();
    void makeTree();
    
};


void biTree::insert(int data, node *parent){
    
    if(!root){
        root = new node(data);
    }else{
        if(parent->data>=data){
            if(parent->left==nullptr){
                node *tem = new node(data);
                parent->left=tem;
            }else {
                insert(data, parent->left);
            }
        }else{
            if(parent->right==nullptr){
                node *tem = new node(data);
                parent->right=tem;
            }else {
                insert(data, parent->right);
            }
        }
        
    }
    
}


void biTree::showTree(){
    queue<node *> q;
    q.push(root);
    while(!q.empty()){
        node * temp = q.front();
        cout<<temp->data<<" ";
        q.pop();
        if(temp->left!=NULL)
            q.push(temp->left);
        if(temp->right!=NULL)
            q.push(temp->right);
    }
}

void biTree::makeTree(){
    
    int md = get_max_depth();
    node **pData = new node *[1];
    *pData = root;
    int middlespace;
    
    
    //level 별로 출력
    for(int level =1; level<=md;level++){
        int itemCount = level==1? 1:pow(2,level-1);
        node** nextData = new node*[itemCount*2];  // 다음줄에 저장 할 것
        
        //앞공백
        //cout<<setw(pow(2,md-level+1));
        space(pow(2,md-level+1));
        //한줄 프린트 하고 다음줄에 뽑을것 저장.
        for( int i=0; i<itemCount ; i++){
            
            if(pData[i]){
                cout<<left<<setw(pow(2,md-level+2))<<pData[i]->data;
                //50cout<<pData[i]->data;
                //int nextcount = i*2+1;
                nextData[i*2]=pData[i]->left;
                nextData[i*2+1]=pData[i]->right;
                
            }
            else{
                cout<<left<<setw(pow(2,md-level+2))<<"x";
                //cout<<"_ ";
                nextData[i*2]=nullptr;
                nextData[i*2+1]=nullptr;
            }
        }
        cout<<"\n";
        //게다리
        for(int i =1;i<pow(2,md-level);i++){
            //앞공백
            space(pow(2,md-level+1)-i);
            
            //게다리 반복횟수 = pow(2,level-1)
            for(int j=0;j<pow(2,level-1);j++){
                branch(2*i-1);
                //중간공백 = (전체칸의 개수) - { 앞공백*2 + (게다리 개수)} / 개다리 개수
                //중간공백 = (pow(2,md-level+2)+1) - { 2*(pow(2,md-level+1)-i) + (2*i+1)*pow(2,level-1)}
                //int middlespace = 2*i+1 - ( (2*i+1)* pow(2,level-1));
                //중간공백 =
                middlespace= (pow(2,md+1)+1) - ( 2*(pow(2,md-level+1)-i) + (2*i+1)*pow(2,level-1));
                middlespace= middlespace/(pow(2,level-1)-1);
                space(middlespace);
            }
            cout<<"\n";
        }
        
        if(pData)
            delete[] pData;
        pData = nextData;
    }
    delete[] pData;
}


int main(){
    biTree bt;
    
    int n;
    while(1){
        cin >> n;
        bt.insert(n,bt.root);
        bt.makeTree();
        cout<<"\n";
    }
}


