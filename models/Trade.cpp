//
// Created by 林冠佑 on 2022/8/23.
//

#include "Trade.h"

#include <utility>

Trade::Trade(const std::chrono::system_clock& timestamp, unsigned int limit, unsigned int quantity,
          std::pair<string, string>  orderIds): timestamp{timestamp}, limit{limit}, quantity{quantity}, orderIds{std::move(orderIds)} {}
