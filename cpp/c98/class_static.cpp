#include <iostream>
#include <cstring>

class Person {
    public:
    static int sNum;
    private:
    static int sOther;
};

int Person::sNum = 0;
int Person::sOther = 0;

void static_variable(void) {
    std::cout << "sNum: " << Person::sNum << std::endl;
    Person::sNum = 100;
    std::cout << "sNum: " << Person::sNum << std::endl;

    // std::cout << "sOther: " << Person::sOther << std::endl; // error

    Person p1, p2;
    p1.sNum = 200;
    std::cout << "p1 sNum: " << p1.sNum << std::endl;
    std::cout << "p2 sNum: " << p2.sNum << std::endl;
}

class Person2 {
    public:
    void changeParam1(int param) {
        mParam = param;
        mSum = param;
    }

    static void changeParam2(int param) {
        // mParam = param;// error
        mSum = param;
    }

    private:
    static void changeParam3(int param) {
        // mParam = param; error;
        mSum = param;
    }

    private:
    int mParam;
    static int mSum;
};

int Person2::mSum = 0;

void static_func() {
    Person2 p1;
    p1.changeParam1(100);

    Person2::changeParam2(200);

    // Person2::changeParam3(300); error
}

class Person3{
    public:
    const static int mShare = 0;
};

void static_const_only_read() {
    std::cout << "person3 mShare: " << Person3::mShare << std::endl;
}

class Printer{
public:
    static Printer* getInstance() {
        return pPrinter;
    }
    void printText(std::string text) {
        std::cout << "text: " << text << std::endl;
        std::cout << "used mTimes: " << mTimes << std::endl;
        mTimes++;
    }
private:
    Printer() {
        mTimes = 0;
    }
    Printer(const Printer &Printer) {}
private:
    static Printer* pPrinter;
    int mTimes;
};

Printer * Printer::pPrinter = new Printer;

void singletonMode() {
    Printer* printer = Printer::getInstance();
    printer->printText("hello");
    printer->printText("world");
}

int main(void) {
    static_variable();

    static_func();

    static_const_only_read();

    singletonMode();

    return 0;
}