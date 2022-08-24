//
// Created by 林冠佑 on 2022/8/22.
//

#ifndef CLO_IMPLEMENTATION_LIMIT_H
#define CLO_IMPLEMENTATION_LIMIT_H

#include <list>
struct Entry;

struct Limit {
    unsigned int limit{};
    unsigned long totalQuantity{};
    unsigned int entryCount{};
    std::list<Entry> entries;

    explicit Limit(unsigned int limit);
};


#endif //CLO_IMPLEMENTATION_LIMIT_H
