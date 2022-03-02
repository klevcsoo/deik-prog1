#include <iostream>

struct B1 {
    virtual void vf() {
        std::cout << "B1::vf()" << std::endl;
    }

    void f() {
        std::cout << "B1::f()" << std::endl;
    }

    virtual void pvf() = 0;
};

struct D1 : B1 {
    void vf() override {
        std::cout << "D1::vf()" << std::endl;
    }

    void f() {
        std::cout << "D1::f()" << std::endl;
    }
};

struct D2 : D1 {
    void pvf() override {
        std::cout << "D2::pvf()" << std::endl;
    }
};

struct B2 {
    virtual void pvf() = 0;
};

struct D21 : B2 {
    std::string hello = "Hello, World!";

    void pvf() override {
        std::cout << hello << std::endl;
    }
};

struct D22 : B2 {
    int num = 25246889;

    void pvf() override {
        std::cout << num << std::endl;
    }
};

void f(B2& b2ref) {
    b2ref.pvf();
}

int main() {
    // HIBA: object of abstract class type "B1" is not allowed:C/C++(322)
    // (gondolom ez a lényeg)
    // B1 b1_instance;
    // b1_instance.vf(); b1_instance.f();

    // std::cout << std::endl;

    // D1 d1_instance;
    // d1_instance.vf(); d1_instance.f();

    // std::cout << std::endl;

    // B1& b1_reference(d1_instance);
    // b1_reference.vf(); b1_reference.f();

    D2 d2_instance;
    d2_instance.vf(); d2_instance.f(); d2_instance.pvf();

    std::cout << std::endl;

    D21 d21_instance; D22 d22_instance;
    f(d21_instance); f(d22_instance);

    return 0;
}
