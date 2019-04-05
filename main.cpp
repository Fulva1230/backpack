#include <iostream>
#include <cmath>
#include "Backpack.h";
#include "Item.h";

#define DEBUG

int main() {
    double items[9][3] = {{450, 2800 * 1.2,  4},
                          {570, 3340 * 1.15, 5},
                          {225, 3500 * 1.3,  2},
                          {500, 2000 * 1.08, 3},
                          {250, 2030 * 1.12, 1},
                          {55,  800 * 1.5,   0.1},
                          {140, 700 * 1.3,   0.3},
                          {300, 500 * 1.2,   0.6},
                          {650, 500 * 1.1,   3}};
    Backpack<9> backpack(100000, 580);
    for (int i = 0; i < 9; i++) {
        backpack.initialItem(i, std::round(items[i][0]), items[i][1], items[i][2]);
    }
    std::cout << backpack.currentState();
    backpack.fillWithLastItem();
    int maxPrice = backpack.currentPrice();
    std::string maxState;
    while (backpack.setNextCombo()) {
        if (maxPrice < backpack.currentPrice()) {
            maxPrice = backpack.currentPrice();
            maxState = backpack.currentState();
        }
#ifdef DEBUG
        std::cout << backpack.currentState();
#endif
    }

    return 0;
}