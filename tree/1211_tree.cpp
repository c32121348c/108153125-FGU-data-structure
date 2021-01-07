#include <iostream>
using namespace std;

//定義節點
class node{
    public:
        int data;
        node *left, *right;
};

int main() {
    node *OAO1 = new node;
    node *OAO2 = new node;
    node *OAO3 = new node;
    node *OAO4 = new node;

    OAO1->data = 1;
    OAO1->left = OAO2;
    OAO1->right = OAO3;

    OAO2->data = 2;
    OAO2->left = nullptr;
    OAO2->right = OAO4;

    OAO3->data = 3;
    OAO3->left = nullptr;
    OAO3->right = nullptr;

    OAO4->data = 4;
    OAO4->left = nullptr;
    OAO4->right = nullptr;

    cout << "OAO1: " << OAO1 << " " << OAO1->data << " " << OAO1->left << " " << OAO1->right << endl;
    cout << "OAO2: " << OAO2 << " " << OAO2->data << " " << OAO2->left << " " << OAO2->right << endl;
    cout << "OAO3: " << OAO3 << " " << OAO3->data << " " << OAO3->left << " " << OAO3->right << endl;
    cout << "OAO4: " << OAO4 << " " << OAO4->data << " " << OAO4->left << " " << OAO4->right << endl;

    return 0;
}