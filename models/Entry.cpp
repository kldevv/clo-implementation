//
// Created by 林冠佑 on 2022/8/22.
//

#include "Entry.h"

Entry::Entry(const Order& order, Limit* const limitHead) {
    this->order = order;
    this->limitHead = limitHead;
}