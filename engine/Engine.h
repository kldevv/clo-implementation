//
// Created by 林冠佑 on 2022/8/23.
//

#ifndef CLO_IMPLEMENTATION_ENGINE_H
#define CLO_IMPLEMENTATION_ENGINE_H

#include <vector>
#include <unordered_map>
#include <string>

#include "../models/Order.h"
#include "../book/CLO.h"
#include "../models/Trade.h"

class Engine {
    std::vector<Trade> logs {};
    CLO book {};

    Order match(Order order);

public:
    void place(Order order);

    void cancel(const string& orderId);

    void modify(const string& orderId, unsigned int quantity);
};


#endif //CLO_IMPLEMENTATION_ENGINE_H
