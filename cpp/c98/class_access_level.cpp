#include <iostream>

class AccessLevels{
    public:
    AccessLevels() {
        readOnly = 0;
        noAcess = 0;
        readWrite = 0;
        writeOnly = 0;
    }
    ~AccessLevels(){}

    int getReadOnly() {
        return readOnly;
    }

    int setReadWrite(int val) {
        readWrite = val;
    } 

    int getReadWrite() {
        return readWrite;
    }

    void setWriteOnly(int val) {
        writeOnly = val;
    }

    private:
    int readOnly;
    int noAcess;
    int readWrite;
    int writeOnly;
};


int main(void) {
    AccessLevels al;
    std::cout << al.getReadOnly() << std::endl;
    al.setReadWrite(100);
    std::cout << al.getReadWrite() << std::endl;
    al.setWriteOnly(200);

    return 0;
}