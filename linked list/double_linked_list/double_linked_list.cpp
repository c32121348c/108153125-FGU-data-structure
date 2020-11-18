#include <iostream>
using namespace std;

struct Node {
    Node *next; // 指向下一個 node
    Node *mae;  //指向上一個資料

    int data = 0;   // 實際資料
};

void append_data(Node *node, int data) {
    Node *p = new Node();
    while (node->next != nullptr) {
        node = node->next;  // 找最後一個節點
    }
    p = node;                   // 保存上一個節點
    node->next = new Node();    // 新增一個節點到
                                // Linked List 尾端
    node = node->next;
    node->mae = p;        // 設定 .mae
    node->data = data;    // 設定 .data
    node->next = nullptr; // 設定 .next
}

void remove_data(Node *node, int data) {
    Node *p = new Node();
    while (node->next != nullptr) {
        Node *dummy = node->next;   // 候選節點

        if (dummy->data == data) {  // 找到了？
            p = node;
            node->next = dummy->next;
            node = node->next;
            node->mae = p;

            delete dummy;   // 釋放記憶體
            break;
        }
        node = node->next;
    }
}

void dump_list(Node *node) {
    cout << "Linked List: ";
    while (node->next != nullptr) {
        node = node->next;
        
        //cout << "[" << node->data << "] ";
        cout << node->mae << "[" << node->data  << " " << node << "]" << node->next << "-";  //顯示前後指標
    }
    cout << "$" << endl;
}

Node *new_list(int len) {
    Node *head = new Node();
    Node *node = head;
    Node *p = nullptr;
    for (int i = 1; i <= len; i ++) {
        p = node;
        node->next = new Node();
        node = node->next;

        node->mae = p;
        node->data = i;
        node->next = nullptr;
    }
    return head;
}

int main(int argc, char *argv[]){
    Node *head = new_list(3);
    cout << "head:" << head << endl; //顯示head
    append_data(head, 99);
    remove_data(head, 2);
    dump_list(head);
}