#include <iostream>
#include <vector>
#include <algorithm>
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

bool check(long long x, long long p) {
    long long product = 1;
    while (x > 0) {
        product *= (x % 10);
        if (product > p) {
            return false;
        }
        x /= 10;
    }
    return true;
}

long long findSmallestN(long long p) {
    if (p == 0) {
        return -1;
    }
    if (p < 10) {
        return p;
    }

    vector<int> digits;
    for (int i = 9; i >= 2; --i) {
        while (p % i == 0) {
            digits.push_back(i);
            p /= i;
        }
    }

    if (p > 1) {
        return -1;
    }

    sort(digits.begin(), digits.end());

    long long result = 0;
    for (int digit : digits) {
        result = result * 10 + digit;
    }

    return result;
}

int main() {
    faster;
    int t;
    cin >> t;

    while (t--) {
        long long p;
        cin >> p;
        cout << findSmallestN(p) << endl;
    }

    return 0;
}