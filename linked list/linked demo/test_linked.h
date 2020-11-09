#ifndef __TEST_LINKED_H__
#define __TEST_LINKED_H__

#include <string>

class TestLinked {
    public:
        void test_append_data();
        void test_contain_data();
        void test_remove_data();

    private:
        void error(std::string);
};

#endif