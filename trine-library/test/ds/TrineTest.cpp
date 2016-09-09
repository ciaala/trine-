//
// Created by Francesco Fiduccia on 9/8/16.
//

#include "gtest/gtest.h"
#include <iostream>
using namespace std;

namespace {
    class Test: public ::testing::Test {
    protected:
        Test() {

        }
        virtual ~Test() {
            cout << "Destructor" << endl;
        }
        virtual void SetUp() {
            cout << "SetUp" << endl;
        }
        virtual void TearDown() {
            cout << "TearDown" << endl;
        }
        int method_return_one() {
            return 1;
        }
        int method_return_two() {
            return 2;
        }
    };

    TEST(Test, method_return_one) {
        EXPECT_EQ(1, 2);
    }

    TEST(Test, method_return_two) {
        EXPECT_EQ(2, 2);
    }
}
int main(int argc, char **argv) {

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
