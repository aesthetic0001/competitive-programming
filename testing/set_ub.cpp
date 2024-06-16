#include <iostream>
#include <set>

int main() {
    std::set<int> myset = {1, 2, 4, 5, 6};

    int key = 7;
    auto it = myset.upper_bound(key);

    if (it == myset.begin()) {
        std::cout << "No element is less than or equal to " << key << '\n';
    } else {
        it--;
        std::cout << "The first element less than or equal to " << key << " is " << *it << '\n';
    }

    return 0;
}
