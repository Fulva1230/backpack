//
// Created by fulva on 2019/4/5.
//

#ifndef BACKPACK_ITEM_H
#define BACKPACK_ITEM_H


class Item {
public:
    Item() = default;

    Item(int price, int weight, int volume);

    int getPrice() const;

    double getWeight() const;

    double getVolume() const;

    int getCount() const;

    void setCount(int count);

private:
    int count = 0;
    int price;
    double weight;
    double volume;
};


#endif //BACKPACK_ITEM_H
