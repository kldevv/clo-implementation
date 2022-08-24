#include <iostream>

#include "engine/Engine.h"

int main() {
    using std::cout;
    using std::endl;

    auto e = Engine();
    e.place(Order(false, 100, 100, "123"));
    e.place(Order(false, 99, 10, "456"));
    e.place(Order(false, 99, 40, "999"));
    e.place(Order(false, 99, 40, "31234"));
    e.place(Order(false, 98, 40, "120"));
    e.place(Order(true, 99, 20, "158"));
    e.place(Order(true, 99, 100, "156"));

    return 0;
}
