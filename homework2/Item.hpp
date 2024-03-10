#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

using namespace std;

class Item {
private:
    string name;
    double unitNetPrice;
    char vatType;
    int amountSold;

public:
    Item(const string& itemName, double netPrice, char vat, int amount);
    string getName() const;
    double getUnitNetPrice() const;
    char getVATType() const;
    int getAmountSold() const;
    double calculateNetTotal() const;
    double calculateTotalPrice() const;
};

#endif