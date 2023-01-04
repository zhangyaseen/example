#include <iostream>
#include <string>
#include <cstring>

class Person {
public:
    Person() {
        std::cout << "call constructor with no param" << std::endl;
        pName = NULL;
        mTail = 0;
        mMoney = 0;
    }

    Person(std::string name, int tail, int money) {
        std::cout << "call constructor with param" << std::endl;
        pName = (char *)malloc(sizeof(name));
        strcpy(pName, name.c_str());
        mTail = tail;
        mMoney = money;
    }

    Person(const Person &person) {
        std::cout << "call copy constructor" << std::endl;
        pName = (char *)malloc(strlen(person.pName));
        strcpy(pName, person.pName);
        mTail = person.mTail;
        mMoney = person.mMoney;
    }

    ~Person() {
        std::cout << "call destructor" << std::endl;
        if (pName) {
            free(pName);
            pName = NULL;
        }
    }

public:
    char *pName;
    int mTail;
    int mMoney;
};

int main(void) {
    Person p;
    // std::cout << p.pName << ", " << p.mTail << ", " << p.mMoney << std::endl; // point is null

    Person p1("world", 100, 10000);
    std::cout << p1.pName << ", " << p1.mTail << ", " << p1.mMoney << std::endl;

    Person p2(p1);
    std::cout << p2.pName << ", " << p2.mTail << ", " << p2.mMoney << std::endl;

    Person("hahaha", 200, 20000);

    Person p3 = Person("balala", 300, 30000);
    std::cout << p3.pName << ", " << p3.mTail << ", " << p3.mMoney << std::endl;

    Person p4 = p3;
    // Person(p4); // not left variable = Person p4;
    Person p5 = Person(p4);
    std::cout << p5.pName << ", " << p5.mTail << ", " << p5.mMoney << std::endl;


    return 0;
}