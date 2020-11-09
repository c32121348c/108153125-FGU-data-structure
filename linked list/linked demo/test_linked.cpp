#include <iostream>
#include "linked.h"
#include "test_linked.h"

using namespace std;

void TestLinked::error(const string err) {
    cout << "ERROR!" << endl;
    cout << "  ==> " << err << endl;

    exit(-1);
}

void TestLinked::test_append_data() {
    Linked linked{0};

    cout << "Testing function: append_data()..." << endl;

    linked.dump_list();

    for (int i = 0; i < 10; i += 1) {
        cout
            << "    Append node with node.data == "
            << i << endl;

        linked.append_data(i);
        linked.dump_list();

        if (!linked.contain_data(i)) {
            error("append_data() failed!!!");
        };
    }
}

void TestLinked::test_contain_data() {
    Linked linked{10};

    cout << "Testing function: contain_data()..." << endl;

    linked.dump_list();

    for (int i = 0; i < 10; i += 1) {
        cout << "    Contain node with node.data == " << i << endl;

        if (!linked.contain_data(i)) {
            error("contain_data() failed!!!");
        };
    }
}

void TestLinked::test_remove_data() {
    Linked linked{10};

    cout << "Testing function: remove_data()..." << endl;

    linked.dump_list();

    for (int i = 1; i < 10; i += 2) {
        cout << "    Delete node with node.data == " << i << endl;
        linked.remove_data(i);
        linked.dump_list();

        if (linked.contain_data(i)) {
            error("remove_data() failed!!!");
        };
    }
}