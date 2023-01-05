#include <iostream>
#include <string>
#include <cstring>

class Person {
public:
    Person() {
        std::cout << "Person: call constructor with no param" << std::endl;
        pName = NULL;
        mTail = 0;
        mMoney = 0;
    }

    Person(std::string name, int tail, int money) {
        std::cout << "Person: call constructor with param" << std::endl;
        pName = (char *)malloc(sizeof(name));
        strcpy(pName, name.c_str());
        mTail = tail;
        mMoney = money;
    }

    Person(const Person &person) {
        std::cout << "Person: call copy constructor" << std::endl;
        pName = (char *)malloc(strlen(person.pName));
        strcpy(pName, person.pName);
        mTail = person.mTail;
        mMoney = person.mMoney;
    }

    ~Person() {
        std::cout << "Person: call destructor" << std::endl;
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

class Student {
public:
    Student() {
        std::cout << "Student: call constructor with no param" << std::endl;
        pName = NULL;
        mTail = 0;
        mMoney = 0;
    }

    Student(std::string name, int tail, int money): mTail(tail), mMoney(money) {
        std::cout << "Student: call constructor with param" << std::endl;
        pName = (char *)malloc(sizeof(name));
        strcpy(pName, name.c_str());
    }


    ~Student() {
        std::cout << "Student: call destructor" << std::endl;
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


void default_constructor(void) {
    std::cout << "default constructor begin=======>" << std::endl;
    Person p;
    // std::cout << p.pName << ", " << p.mTail << ", " << p.mMoney << std::endl; // point is null

    Person p1("default", 100, 10000);
    std::cout << p1.pName << ", " << p1.mTail << ", " << p1.mMoney << std::endl;
    std::cout << "<===============default constructor end" << std::endl;
}

void constructor_with_param(){
    std::cout << "constructor with param begin========>" << std::endl;
    Person("param1", 200, 20000);

    Person p = Person("param2", 300, 30000);
    std::cout << p.pName << ", " << p.mTail << ", " << p.mMoney << std::endl;

    Student stu = Student("student", 500, 5000);
    std::cout << stu.pName << ", " << stu.mTail << ", " << stu.mMoney << std::endl;

    std::cout << "<===========constructor with param end" << std::endl;
}

void func_copy(Person p) {
    std::cout << p.pName << ", " << p.mTail << ", " << p.mMoney << std::endl;
}

Person return_internal_copy(){
    Person p("internal", 101, 10001);
    return p;
}

void copy_constructor(void) {
    std::cout << "copy constructor begin===========>" << std::endl;
    Person p("copy", 101, 10001);

    Person p2(p);
    std::cout << p2.pName << ", " << p2.mTail << ", " << p2.mMoney << std::endl;

    Person p3 = Person(p);
    std::cout << p3.pName << ", " << p3.mTail << ", " << p3.mMoney << std::endl;

    Person p4 = p3;
    // Person(p4); // not left variable = Person p4;
    std::cout << p4.pName << ", " << p4.mTail << ", " << p4.mMoney << std::endl;

    func_copy(p);

    Person p5 = return_internal_copy();
    std::cout << p5.pName << ", " << p5.mTail << ", " << p5.mMoney << std::endl;

    std::cout << "<========copy constructor end" << std::endl;
}

class Phone {
public:
	std::string brand;
	Phone() {
		std::cout << "Phone: default constructor" << std::endl;
	};
	Phone(std::string temp){
		brand = temp;
		std::cout << "Phone: class phone parameters init" << std::endl;
	};
};

class UserA{
public:
	int age;
	Phone phone;
	UserA(int a, std::string name) {
		std::cout << "UserA: class parameter init" << std::endl;
		age = a;
		phone = Phone(name);
	};
};

class UserB{
public:
	int age;
	Phone phone;
	UserB(int a, std::string name):age(a),phone(name){
		std::cout << "UserB: class parameter init list" << std::endl;
	}
};

void constructor_init_list(void) {
    std::cout << "userA call" << std::endl;
    UserA(100, "phone");

    std::cout << "userB call" << std::endl;
    UserB(100, "Phone");
}

int main(void) {

    default_constructor();

    constructor_with_param();

    copy_constructor();

    constructor_init_list();

    std::cout << "class constructor end" << std::endl;

    return 0;
}