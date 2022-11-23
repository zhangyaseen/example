#include <iostream>
#include <cstdlib>
#include <exception>
 

void exception_set_terminate(void) {
    std::set_terminate([](){
        std::cout << "Unhandled exception\n" << std::flush;
        std::abort();
    });
    throw 1;
}

int main(){
    exception_set_terminate();

    return 0;
}