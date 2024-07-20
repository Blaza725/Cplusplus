#include <iostream>
#include <cmath>
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;

ll maxPrimeFactor(ll n) {
    int maxPrime = -1;
    int i = 2;
    while(i <= sqrt(n)) {
        while(n % i == 0) {
            maxPrime = i;
            n /= i;
        }
        i++;
    }
    if(n > 1) {
        maxPrime = n;
    }
    return maxPrime;
}

int main() {
    faster;
    int t;
    cin >> t;
    while (t--) {
        ll l, r;
        cin >> l >> r;
        int sum = 0;
        for(ll i = l; i <= r; ++i) {
            sum += maxPrimeFactor(i);
        }
        cout << sum << endl;
    }
    return 0;
}