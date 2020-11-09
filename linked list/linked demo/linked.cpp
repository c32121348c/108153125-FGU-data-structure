#include <iostream>
#include "linked.h"

using namespace std;

Linked::Linked(int len) {
    head = new Node();
    Node *node = head;

    for (int i = 0; i < len; i ++) {
        node->next = new Node();

        node = node->next;

        node->data = i;
        node->next = nullptr;
    }
}

Linked::~Linked() {
    while (head->next != nullptr) {
        Node *dummy = head;

        head = head->next;
        delete dummy;    // 釋放記憶體
    }

    delete head; // 釋放最後一個節點
}

void Linked::append_data(int data) {
    // put your code here.
    // while (head->next != nullptr) {
    //     head = head->next;  // 找最後一個節點
    // }

    // head->next = new Node();    // 新增一個節點到
    //                             // Linked List 尾端
    // head->next->data = data;    // 設定 .data
    // head->next->next = nullptr; // 設定 .next
}

bool Linked::contain_data(int data) {
    Node *node = head;
    bool found = false;

    while (node->next != nullptr) {
        node = node->next;

        if (node->data == data) {
            found = true;

            break;
        }
    }

    return found;
}

void Linked::remove_data(int data) {
    // put your code here.
    // while (head->next != nullptr) {
    //     Node *dummy = head->next;   // 候選節點

    //     if (dummy->data == data) {  // 找到了？
    //         head->next = dummy->next;
    //         delete dummy;   // 釋放記憶體

    //         break;
    //     }

    //     head = head->next;
    // }
}

void Linked::dump_list() {
    cout << "  Linked List:" << endl;
    cout << "    ";

    Node *node = head;

    while (node->next != nullptr) {
        node = node->next;

        cout << "[" << node->data << "] -> ";
    }

    cout << "$" << endl;
}