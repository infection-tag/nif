#include <iostream>
#include "nif.h"
#include "nif-err.h"

using namespace std;

int main() {
    string hello = "hello, world";
    string testStorys = "My test Story";
    chapter c1(1, hello);
    newStory testStory(c1, testStorys);
    chapter c2(2, "wassup");

    c1 >> c2;
    testStory.printOptions();
    endStory(0);
}
