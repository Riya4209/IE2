#include "Invoice.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

Invoice::Invoice(long long seller, long long buyer) : sellerNIP(seller), buyerNIP(buyer) {}

void Invoice::add_item(const Item& newItem) {
    items.push_back(newItem);
}

ostream& operator<<(ostream& os, const Invoice& invoice) {
    os << "------------------VAT invoice------------------\n";
    os << "===============================================\n";
    os << "Seller: " << invoice.sellerNIP << "      Buyer: " << invoice.buyerNIP << "\n\n";

    os << setw(20) << "c.j." << setw(10) << "VAT" << setw(5) << "il." << setw(7) << "net"
       << setw(8) << "total\n";

    int index = 1;
    double totalNet = 0.0, totalValue = 0.0;

    for (const auto& item : invoice.items) {
        os << index << ". " << setw(15) << item.getName() << " | " << setw(4) << item.getUnitNetPrice()
           << "  " << item.getVATType() << " | " << setw(3) << item.getAmountSold() << " | " << setw(6)
           << item.calculateNetTotal() << " | " << item.calculateTotalPrice() << "\n";

        totalNet += item.calculateNetTotal();
        totalValue += item.calculateTotalPrice();
        index++;
    }

    os << "\n------------------------------------ TOTAL ----\n";
    os << setw(44) << totalNet << " | " << totalValue << "\n";

    return os;
}