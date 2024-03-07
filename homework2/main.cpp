#include <iostream>
#include "Time.hpp"
#include "Invoice.hpp"

using namespace std;

int main() {
    // Time t1(200);
    // cout << t1 << endl;
    // Time t2;
    // cin >> t2;
    // cout << t2 << endl;

    // Time t3 = t2 - t1;
    // cout << t3 << endl;

    // int t3s = t3;
    // cout << t3s << endl;

    Invoice inv(7770003699, 123456789);
    inv.add_item(Item("M3 screw", 0.37, 'A', 100));
    inv.add_item(Item("2 mm drill", 2.54, 'B', 2));

    std::cout << inv << std::endl;

    return 0;
}
