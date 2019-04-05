//
// Created by fulva on 2019/4/5.
//

#ifndef BACKPACK_BACKPACK_H
#define BACKPACK_BACKPACK_H


#include <array>
#include <vector>
#include "Item.h"

template<size_t n>
class Backpack {
public:
    Backpack(int volumeLimit, int weightLimit);

    void initialItem(size_t index, int price, int volume, int weight);

    bool setNextCombo();

    std::string currentState();

    int currentPrice();

    void fillWithLastItem();
private:
    bool isFull() const;

    void cleanWithLastItem();

    double volumeLeft() const;

    double weightLeft() const;

    double volumeLimit;
    double weightLimit;
    std::array<Item, n> items;
};

template<size_t n>
bool Backpack<n>::setNextCombo() {
    cleanWithLastItem();
    bool valid = false;
    for (int i = 0; i < items.size() - 1; i++) {
        Item &item = items.at(i);
        item.setCount(item.getCount() + 1);
        if (isFull()) {
            item.setCount(0);
        } else {
            valid = true;
            break;
        }
    }
    if (!valid) {
        return false;
    }
    fillWithLastItem();
    return true;
}

template<size_t n>
bool Backpack<n>::isFull() const {
    return volumeLeft() < 0 || weightLeft() < 0;
}

template<size_t n>
void Backpack<n>::fillWithLastItem() {
    Item &item = items.back();
    bool enough = false;
    int i = 0;
    while (!enough) {
        item.setCount(i);
        if (volumeLeft() < 0 || weightLeft() < 0) {
            enough = true;
            item.setCount(i - 1);
        } else {
            i++;
        }
    }
}

template<size_t n>
double Backpack<n>::volumeLeft() const {
    double volume = 0;
    for (Item const &item:items) {
        volume += item.getVolume();
    }
    return volumeLimit - volume;
}

template<size_t n>
double Backpack<n>::weightLeft() const {
    double weight = 0;
    for (Item const &item:items) {
        weight += item.getWeight();
    }
    return weightLimit - weight;
}

template<size_t n>
Backpack<n>::Backpack(int volumeLimit, int weightLimit):volumeLimit(volumeLimit), weightLimit(weightLimit) {}

template<size_t n>
void Backpack<n>::initialItem(size_t index, int price, int volume, int weight) {
    Item &item = items[index];
    item = Item(price, weight, volume);
}

template<size_t n>
std::string Backpack<n>::currentState() {
    std::string string;
    for (Item &item:items) {
        string.append(std::to_string(item.getCount()) + ":");
    }
    string.append("::");
    string.append(std::to_string(currentPrice()));
    string.append("\n");
    return string;
}

template<size_t n>
int Backpack<n>::currentPrice() {
    int i = 0;
    for (Item &item:items) {
        i += item.getPrice();
    }
    return i;
}

template<size_t n>
void Backpack<n>::cleanWithLastItem() {
    Item &item = items.back();
    item.setCount(0);
}


#endif //BACKPACK_BACKPACK_H
