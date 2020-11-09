#ifndef __LINKED_H__
#define __LINKED_H__

#include "node.h"

class Linked {
    public:
        Linked(int);
        ~Linked();

    public:
        void append_data(int);
        bool contain_data(int);
        void remove_data(int);

    public:
        void dump_list();

    private:
        Node *head;
};

#endif