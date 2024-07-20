#include <iostream>
#include <vector>
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

bool isFibonacci(int n) {
    if (n <= 1) {
        return true;
    }
    int a = 0, b = 1, c = 1;
    while (c < n) {
        a = b;
        b = c;
        c = a + b;
    }
    return c == n;
}

int main() {
    faster;

    int n, k;
    cin >> n >> k;

    vector<int> comb(k);
    for (int i = 0; i < k; ++i) {
        comb[i] = i + 1;
    }

    int cnt = 1;
    do {
        if (isFibonacci(cnt)) {
            cout << cnt << ": ";
            for (int i = 0; i < k; ++i) {
                cout << comb[i] << " ";
            }
            cout << endl;
        }

        int i = k - 1;
        while (i >= 0 && comb[i] == n - k + i + 1) {
            i--;
        }
        if (i >= 0) {
            comb[i]++;
            for (int j = i + 1; j < k; ++j) {
                comb[j] = comb[j - 1] + 1;
            }
        } else {
            break;
        }

        cnt++;
    } while (true);

    return 0;
}