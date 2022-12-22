#include <iostream>

void array_reference_typedef(void) {
    typedef int ArrRef[10];
    int arr[10];

    ArrRef& aRef = arr;
    for (int i = 0; i < 10; i++) {
        aRef[i] = i + 1;
    }

    for (int i = 0; i < 10; i++) {
        std::cout << aRef[i] << "\t";
    }
    std::cout << std::endl;
}

void array_refence_common(void) {
    int arr[10];
    int(&aRef)[10] = arr;

    for (int i = 0; i < 10; i++) {
        aRef[i] = i + 1;
    }

    for (int i = 0; i < 10; i++) {
        std::cout << aRef[i] << "\t";
    }
    std::cout << std::endl;
}

int& func_as_left_value(void) {
    static int a = 100;
    std::cout << "func as left value a: " << a << std::endl;
    return a;
}

struct Teacher {
    int m_age;
};

void alloc_and_init_by_pointer(Teacher** teacher) {
    *teacher = (Teacher*)malloc(sizeof(Teacher));
    (*teacher)->m_age = 100;
}

void alloc_and_init_by_reference(Teacher*& teacher) { teacher->m_age = 200; }

void point_reference() {
    Teacher* teacher = NULL;
    alloc_and_init_by_pointer(&teacher);
    std::cout << "alloc_and_init_by_pointer : " << teacher->m_age << std::endl;

    alloc_and_init_by_reference(teacher);
    std::cout << "alloc_and_init_by_reference: " << teacher->m_age << std::endl;

    free(teacher);
}

int main(void) {
    array_reference_typedef();

    array_refence_common();

    func_as_left_value();
    func_as_left_value() = 200;
    func_as_left_value();

    point_reference();

    return 0;
}