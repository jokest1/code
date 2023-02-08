#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include "DoubleLinkedLists.h"
using namespace std;
void test01() {
    DoubleLinkedLists<int> list;
    list.add(11);
    list.add(22);
    list.add(33);
    list.add(44);

    list.add(0, 55); // [55, 11, 22, 33, 44]
    list.add(2, 66); // [55, 11, 66, 22, 33, 44]
    list.add(list.size(), 77); // [55, 11, 66, 22, 33, 44, 77]

    list.remove(0); // [11, 66, 22, 33, 44, 77]
    list.remove(2); // [11, 66, 33, 44, 77]
    list.remove(list.size() - 1); // [11, 66, 33, 44]
    cout << list << endl;
}
int main() {
	test01();
	return 0;
}