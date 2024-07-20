#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), even, odd;
    vector<bool> isEven(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] % 2 == 0) {
            even.push_back(a[i]);
            isEven[i] = true;
        } else {
            odd.push_back(a[i]);
            isEven[i] = false;
        }
    }

    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end(), greater<int>());

    // In ra dãy số sau khi đã sắp xếp
    int evenIndex = 0, oddIndex = 0;
    for (int i = 0; i < n; i++) {
        if (isEven[i]) {
            cout << even[evenIndex++] << " ";
        } else {
            cout << odd[oddIndex++] << " ";
        }
    }

    return 0;
}