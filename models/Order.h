//
// Created by 林冠佑 on 2022/8/22.
//

#ifndef CLO_IMPLEMENTATION_ORDER_H
#define CLO_IMPLEMENTATION_ORDER_H

#include <string>

struct Order {
    bool isBuy{};
    unsigned int limit{};
    unsigned int quantity{};
    std::string id{};

    Order(bool isBuy, unsigned int limit, unsigned int quantity, const std::string& id);
    Order() = default;
};


#endif //CLO_IMPLEMENTATION_ORDER_H
