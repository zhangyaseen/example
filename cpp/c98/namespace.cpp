#include <iostream>

namespace A{
    int a = 10;
    namespace C {
        int a = 30;
    }
}

namespace B {
    int a = 20;
}

namespace B {
    namespace D{
        int a = 40;
    }
}

namespace B {
    void hello_world(void) {
        std::cout << "hello world" << std::endl;
    }
    void hello_namespace();
}

void B::hello_namespace(void) {
    std::cout << "hello namespace" << std::endl;
}

namespace {
    void print_static(void) {
        std::cout << "It can only be called within this file" << std::endl;
    }
}

int main(void) {
    std::cout << "A:a=" << A::a << std::endl;
    std::cout << "B:a=" << B::a << std::endl;
    std::cout << "A::C::a=" << A::C::a << std::endl;
    std::cout << "B::D::a=" << B::D::a << std::endl;

    B::hello_world();

    namespace C = B;
    C::hello_namespace();

    using namespace B;
    hello_namespace();

    print_static();

    return 0;
}