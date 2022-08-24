//
// Created by 林冠佑 on 2022/8/22.
//

#ifndef CLO_IMPLEMENTATION_ENTRY_H
#define CLO_IMPLEMENTATION_ENTRY_H

#include "Order.h"
#include "Limit.h"

struct Entry {
    Order order{};
    Limit* limitHead{nullptr};

    Entry(const Order& order, Limit* const limitHead);
};


#endif //CLO_IMPLEMENTATION_ENTRY_H
