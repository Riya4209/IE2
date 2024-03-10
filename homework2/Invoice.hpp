#ifndef INVOICE_HPP
#define INVOICE_HPP

#include "Item.hpp"
#include <vector>

using namespace std;

class Invoice {
private:
    long long sellerNIP;
    long long buyerNIP;
    vector<Item> items;

public:
    Invoice(long long seller, long long buyer);
    void add_item(const Item& newItem);
    friend ostream& operator<<(ostream& os, const Invoice& invoice);
};

#endif