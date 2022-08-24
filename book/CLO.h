//
// Created by 林冠佑 on 2022/8/22.
//

#ifndef CLO_IMPLEMENTATION_CLO_H
#define CLO_IMPLEMENTATION_CLO_H

#include <set>
#include <string>
#include <unordered_map>
#include <vector>
#include <list>
#include <functional>

#include "../models/Limit.h"
#include "../models/Entry.h"
#include "../models/Order.h"

using std::unordered_map;
using std::vector;
using std::string;
using std::set;


class CLO {
public:
    set<unsigned int> buys{};
    set<unsigned int> sells{};
    unordered_map<string, std::list<Entry>::iterator> entries{};
    unordered_map<unsigned int, Limit*> limits{};

    CLO() = default;

    const Entry& place(const Order& order);

    void cancel(const string& orderId);

    const Entry& modify(const string& orderId, unsigned int quantity);
};


#endif //CLO_IMPLEMENTATION_CLO_H
