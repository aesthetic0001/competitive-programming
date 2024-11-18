#include <iostream>
#include <set>

int main() {
    std::set<int> s = {7};

    int query = 6; // Element to find the floor of
    auto it = s.lower_bound(query);

    if (it != s.begin() && (it == s.end() || *it > query)) {
        --it; // Move to the previous element
    }

    if (it != s.end() && *it <= query) {
        std::cout << "Floor of " << query << " is " << *it << '\n';
    } else {
        std::cout << "No floor found for " << query << '\n';
    }

    return 0;
}

