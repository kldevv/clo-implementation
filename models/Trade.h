//
// Created by 林冠佑 on 2022/8/23.
//

#ifndef CLO_IMPLEMENTATION_TRADE_H
#define CLO_IMPLEMENTATION_TRADE_H

#include <chrono>
#include <string>

using std::string;

struct Trade {
    std::chrono::system_clock timestamp {};
    unsigned int limit {};
    unsigned int quantity {};
    std::pair<string, string> orderIds; // matched, matching

    Trade(const std::chrono::system_clock& timestamp, unsigned int limit, unsigned int quantity, std::pair<string, string>  orderIds);
};


#endif //CLO_IMPLEMENTATION_TRADE_H
