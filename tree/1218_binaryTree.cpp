#include <iostream>
using namespace std;

//建構子
class node{
    public:
        int data;
        node *left, *right;
};

//函數原型
void printGivenLevel(node *root, int level);
int height(node *node);
node *newNode(int data);

//遍歷迴圈
void printLevelOrder(node *root){
    int h = height(root);
    for(int i=1; i<=h; i++){
        printGivenLevel(root, i);
    }
}

void printGivenLevel(node *root, int level){
    if(root == nullptr)  //檢查節點是否有值
        return;
    if(level == 1)
        cout << root->data << " ";
    else if(level > 1){
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}

//檢查到沒有孩子時為0 一層一層加回去統計層數
int height(node *node){
    if(node == nullptr)
        return 0;
    else{
        int lheight = height(node->left);
        int rheight = height(node->right);

        if(lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}

node *newNode(int data){
    node *Node = new node();
    Node->data = data;
    Node->left = nullptr;
    Node->right = nullptr;

    return (Node);
}

int main(){
    node *root = newNode(1);
    
    root->left = newNode(2);
    // root->left->left = newNode(3);
    // root->left->left->left = newNode(4);
    // root->left->left->left->left = newNode(5);

    cout << height(root);
    cout << "樹的遍歷結果為:\n";
    printLevelOrder(root);

    return 0;
}