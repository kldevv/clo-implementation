//
// Created by 林冠佑 on 2022/8/22.
//

#include "Order.h"

Order::Order(const bool isBuy, const unsigned int limit, const unsigned int quantity, const std::string& id) {
    this->isBuy = isBuy;
    this->limit = limit;
    this->quantity = quantity;
    this->id = id;
}