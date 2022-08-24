//
// Created by 林冠佑 on 2022/8/22.
//

#include "CLO.h"

const Entry& CLO::place(const Order& order) {
    if (this->entries.find(order.id) != this->entries.end()) {
        // TODO: replace with exception
        throw -1;
    }

    if (this->limits.find(order.limit) == this->limits.end()) {
        this->limits[order.limit] = new Limit(order.limit);
        if (order.isBuy) {
            this->buys.insert(order.limit);
        } else {
            this->sells.insert(order.limit);
        }
    }

    auto const limit = this->limits[order.limit];

    limit->entries.emplace_back(order, limit);
    limit->entryCount += 1;
    limit->totalQuantity += limit->entries.back().order.quantity;

    this->entries[order.id] = std::prev(limit->entries.end());

    return limit->entries.back();
}

void CLO::cancel(const string &orderId) {
    if (this->entries.find(orderId) == this->entries.end()) {
        // TODO: replace with exception
        throw -1;
    }

    auto entry = this->entries[orderId];
    this->entries.erase(orderId);

    auto limit = entry->limitHead;

    limit->entryCount -= 1;
    limit->totalQuantity -= entry->order.quantity;
    if (limit->totalQuantity == 0) {
        if (entry->order.isBuy) {
            auto it = buys.find(limit->limit);
            buys.erase(it);
        } else {
            auto it = sells.find(limit->limit);
            sells.erase(it);
        }
        limits.erase(limit->limit);
        delete limit;
    } else {
        limit->entries.erase(entry);
    }
}

const Entry& CLO::modify(const string &orderId, const unsigned int quantity) {
    if (this->entries.find(orderId) == this->entries.end()) {
        // TODO: replace with exception
        throw -1;
    }

    auto limit = entries[orderId]->order.limit;
    auto isBuy = entries[orderId]->order.isBuy;

    cancel(orderId);
    return place(Order(isBuy, limit, quantity, orderId));
}

