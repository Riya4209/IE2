#ifndef INVOICE_HPP
#define INVOICE_HPP

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

class Item {

public:
    string name;
    double unitNetPrice;
    char vatType;
    int amountSold;

    Item(const string& itemName, double itemNetPrice, char itemVatType, int itemAmount)
        : name(itemName), unitNetPrice(itemNetPrice), vatType(itemVatType), amountSold(itemAmount) {}

    friend ostream& operator<<(ostream& str, const Item& item) {
        str << setw(20) << left << item.name << " | " << setw(5) << right << item.vatType
           << " | " << setw(4) << item.amountSold << " | " << setw(6) << fixed << setprecision(2)
           << item.unitNetPrice << " | " << setw(6) << fixed << setprecision(2)
           << (item.unitNetPrice * item.amountSold * (1 + (item.vatType == 'A' ? 0.23 : (item.vatType == 'B' ? 0.08 : 0))))
           << endl;
        return str;
    }
};

class Invoice {
private:
    long long sellerNIP;
    long long buyerNIP;
    vector<Item> items;

public:
    Invoice(long long seller, long long buyer) : sellerNIP(seller), buyerNIP(buyer) {}


    void add_item(const Item& item) {
        items.push_back(item);
    }

    friend ostream& operator<<(ostream& str, const Invoice& invoice) {
        str << "------------------VAT invoice------------------" << endl;
        str << "===============================================" << endl;
        str << "Seller: " << invoice.sellerNIP << "      Buyer: " << invoice.buyerNIP << endl << endl;
        str << setw(20) << "Name" << " | " << setw(5) << "VAT" << " | " << setw(4) << "Qty" << " | "
           << setw(6) << "Net" << " | " << setw(6) << "Total" << endl;
        str << "-----------------------------------------------" << endl;

        double totalNet = 0.0;
        double totalGross = 0.0;

        for (size_t i = 0; i < invoice.items.size(); ++i) {
            str << std::to_string(i + 1) << ". " << invoice.items[i];
            totalNet += invoice.items[i].unitNetPrice * invoice.items[i].amountSold;
            totalGross += invoice.items[i].unitNetPrice * invoice.items[i].amountSold *
                          (1 + (invoice.items[i].vatType == 'A' ? 0.23 : (invoice.items[i].vatType == 'B' ? 0.08 : 0)));
        }

        str << "------------------------------------ TOTAL ----" << endl;
        str << setw(46) << fixed << setprecision(2) << totalNet << " | " << setw(6) << fixed
           <<setprecision(2) << totalGross << endl;

        return str;
    }
};

#endif