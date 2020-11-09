#include <iostream>

#include "node.h"

void append_data(Node *node, int data) {
    while (node->next != nullptr) {
        node = node->next;  // 找最後一個節點
    }

    node->next = new Node();    // 新增一個節點到
                                // Linked List 尾端
    node->next->data = data;    // 設定 .data
    node->next->next = nullptr; // 設定 .next
}

bool contain_data(Node *node, int data) {
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

void remove_data(Node *node, int data) {
    while (node->next != nullptr) {
        Node *dummy = node->next;   // 候選節點

        if (dummy->data == data) {  // 找到了？
            node->next = dummy->next;
            delete dummy;   // 釋放記憶體

            break;
        }

        node = node->next;
    }
}

void dump_list(Node *node) {
    std::cout << "  Linked List:" << std::endl;
    std::cout << "    ";

    while (node->next != nullptr) {
        node = node->next;

        std::cout << "[" << node->data << "] -> ";
    }

    std::cout << "$" << std::endl;
}

void free_list(Node *node) {
    while (node->next != nullptr) {
        Node *dummy = node;

        node = node->next;
        delete dummy;    // 釋放記憶體
    }
    delete node; // 釋放最後一個節點
}

Node *new_list(int len) {
    Node *head = new Node();
    Node *node = head;

    for (int i = 0; i < len; i ++) {
        node->next = new Node();

        node = node->next;

        node->data = i;
        node->next = nullptr;
    }

    return head;
}

void error(std::string err) {
    std::cout << "ERROR!" << std::endl;
    std::cout << "  ==> " << err << std::endl;

    exit(-1);
}

void test_append_data() {
    Node *head;

    std::cout
        << "Testing function: append_data()..."
        << std::endl;

    head = new_list(0);
    std::cout << std::hex << head->next << std::endl;
    dump_list(head);

    for (int i = 0; i < 10; i += 1) {
        std::cout
            << "    Append node with node.data == "
            << i << std::endl;

        append_data(head, i);
        dump_list(head);

        if (!contain_data(head, i)) {
            error("append_data() failed!!!");
        }
    }

    free_list(head);    // 釋放 Linked List
}

void test_contain_data() {
    Node *head;

    std::cout
        << "Testing function: contain_data()..."
        << std::endl;

    head = new_list(3);
    dump_list(head);

    for (int i = 0; i < 10; i += 1) {
        std::cout
            << "    Contain node with node.data == "
            << i << std::endl;

        if (!contain_data(head, i)) {
            error("contain_data() failed!!!");
        };
    }

    free_list(head);    // 釋放 Linked List
}

void test_remove_data() {
    Node *head;

    std::cout
        << "Testing function: remove_data()..."
        << std::endl;

    head = new_list(10);
    dump_list(head);

    for (int i = 1; i < 10; i += 2) {
        std::cout
            << "    Delete node with node.data == "
            << i << std::endl;

        remove_data(head, i);
        dump_list(head);

        if (contain_data(head, i)) {
            error("remove_data() failed!!!");
        };
    }

    free_list(head);    // 釋放 Linked List
}

int main(int argc, char *argv[]) {
    Node *head = new_list(3);

    dump_list(head);

//  test_append_data();
//  test_contain_data();
//  test_remove_data();
}