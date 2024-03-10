#include "Item.hpp"

Item::Item(const std::string& itemName, double netPrice, char vat, int amount)
    : name(itemName), unitNetPrice(netPrice), vatType(vat), amountSold(amount) {}

std::string Item::getName() const {
    return name;
}

double Item::getUnitNetPrice() const {
    return unitNetPrice;
}

char Item::getVATType() const {
    return vatType;
}

int Item::getAmountSold() const {
    return amountSold;
}

double Item::calculateNetTotal() const {
    return unitNetPrice * amountSold;
}

double Item::calculateTotalPrice() const {
    double vatRate;
    switch (vatType) {
    case 'A':
        vatRate = 0.23;
        break;
    case 'B':
        vatRate = 0.08;
        break;
    case 'C':
        vatRate = 0.0;
        break;
    default:
        vatRate = 0.0;
    }
    return calculateNetTotal() * (1.0 + vatRate);
}
