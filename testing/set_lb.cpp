#include <iostream>
#include <set>

int main() {
    std::set<int> myset = {1, 2, 4, 5, 6};

    int key = 3;
    auto it = myset.lower_bound(key);

    if (it == myset.end()) {
        std::cout << "No element is greater than or equal to " << key << '\n';
    } else {
        std::cout << "The first element greater than or equal to " << key << " is " << *it << '\n';
    }

    return 0;
}
