//
// Created by fulva on 2019/4/5.
//

#include "Item.h"

Item::Item(int price, int weight, int volume) : price(price), weight(weight), volume(volume) {}

int Item::getPrice() const {
    return price * count;
}

double Item::getWeight() const {
    return weight * count;
}

double Item::getVolume() const {
    return volume * count;
}

int Item::getCount() const {
    return count;
}

void Item::setCount(int count) {
    Item::count = count;
}
