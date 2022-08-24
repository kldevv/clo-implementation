//
// Created by 林冠佑 on 2022/8/23.
//

#include "Engine.h"

#include <chrono>
#include <iostream>
#include <utility>

using std::string;
using std::cout;
using std::endl;

Order Engine::match(Order order) {
        while (order.isBuy && !book.sells.empty() && *(book.sells.begin()) <= order.limit && order.quantity != 0) {
            auto limit = book.limits[*(book.sells.begin())];

            while (limit->totalQuantity != 0 && order.quantity != 0) {
                auto& entry = limit->entries.front();

                auto offset = std::min(entry.order.quantity, order.quantity);
                entry.order.quantity -= offset;
                order.quantity -= offset;
                limit->totalQuantity -= offset;
                this->logs.emplace_back(Trade(std::chrono::system_clock(), entry.order.limit, offset, std::make_pair(entry.order.id, order.id)));

                cout << "***Trade***" << endl;
                cout << "Limit: " << logs.back().limit << endl;
                cout << "Quantity: " << logs.back().quantity << endl;

                if (entry.order.quantity == 0) {
                    limit->entries.pop_front();
                    limit->entryCount -= 1;
                }
            }

            if (limit->totalQuantity == 0) {
                book.sells.erase(*(book.sells.begin()));
                delete limit;
            }
        }

    while (!order.isBuy && !book.buys.empty() && *(book.buys.rbegin()) >= order.limit && order.quantity != 0) {
        auto limit = book.limits[*(book.buys.rbegin())];

        while (limit->totalQuantity != 0 && order.quantity != 0) {
            auto& entry = limit->entries.front();

            auto offset = std::min(entry.order.quantity, order.quantity);
            entry.order.quantity -= offset;
            order.quantity -= offset;
            limit->totalQuantity -= offset;
            this->logs.emplace_back(Trade(std::chrono::system_clock(), entry.order.limit, offset, std::make_pair(entry.order.id, order.id)));

            cout << "***Trade***" << endl;
            cout << "Limit: " << logs.back().limit << endl;
            cout << "Quantity: " << logs.back().quantity << endl;

            if (entry.order.quantity == 0) {
                limit->entries.pop_front();
                limit->entryCount -= 1;
            }
        }

        if (limit->totalQuantity == 0) {
            book.sells.erase(*(book.sells.rbegin()));
            delete limit;
        }
    }
    return order;
}

void Engine::place(Order order) {
    Order remainingOrder = match(order);
    if (remainingOrder.quantity > 0) {
        cout << "***Order Placed***" << endl;
        cout << "Side: " << (order.isBuy ? "Buy" : "Sell") << endl;
        cout << "Limit: " << order.limit << endl;
        cout << "Quantity: " << remainingOrder.quantity << endl;
        book.place(remainingOrder);
    }
}

void Engine::cancel(const string &orderId) {
    book.cancel(orderId);
}

void Engine::modify(const string &orderId, unsigned int quantity) {
    book.modify(orderId, quantity);
}


