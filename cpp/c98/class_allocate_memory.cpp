#include <iostream>
#include <cstring>

class User1{
public:
    User1() {
        std::cout << "user1 default constructor" << std::endl;
        mAge = 100;
        pName = (char*)malloc(sizeof("user1") + 1);
        strcpy(pName, "user1");
    }
    User1(const char *name, int age) {
        std::cout << "user1 param constructor" << std::endl;
        mAge = age;
        pName = (char*)malloc(sizeof(name));
        strcpy(pName, name);
    }
    ~User1() {
        std::cout << "user1 default destructor" << std::endl;
        if (pName) {
            delete pName; // free(pName);
            pName = NULL;
        }
    }
    void init() {
        std::cout << "user1 init" << std::endl;
        mAge = 100;
        pName = (char*)malloc(sizeof("user1") + 1);
        strcpy(pName, "user1");
    }
    void clean() {
        std::cout << "user1 clean" << std::endl;
        if (pName) {
            free(pName);
            pName = NULL;
        }
    }
private:
    int mAge;
    char *pName;
};

void allocate_with_malloc() {
    User1 user1;

    User1 *user2 = (User1 *)malloc(sizeof(User1));
    if (!user2) {
        return;
    }
    user2->init();
    user2->clean();
}

void allocate_with_new() {
    User1 *user1 = new User1;
    delete user1;
}


void allocate_list() {
    char *str1 = new char[100];
    delete[] str1;

    int* pArr = new int[100]{1, 2, 3, 4, 5, 6};
    delete[] pArr;

    User1 user1[] = {User1("hello", 100), User1("world", 100)};
    user1[0].clean();
    user1[1].clean();

    User1 *user = new User1[5];
    delete[] user;
}

int main(void) {
    // allocate_with_malloc();

    // allocate_with_new();

    allocate_list();

    return 0;
}