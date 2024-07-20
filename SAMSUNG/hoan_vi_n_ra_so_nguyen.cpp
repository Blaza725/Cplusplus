# include <bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

bool next_permutation(vector<int>& digits) {
    int i = digits.size() - 2;
    while (i >= 0 && digits[i] >= digits[i + 1]) {
        --i;
    }
    if (i < 0) {
        return false;
    }
    int j = digits.size() - 1;
    while (digits[j] <= digits[i]) {
        --j;
    }
    swap(digits[i], digits[j]);
    reverse(digits.begin() + i + 1, digits.end());
    return true;
}

int main() {
    faster;
    int t;
    cin >> t;
    while (t--) {
        string n;
        cin >> n;

        vector<int> digits;
        for (char c : n) {
            digits.push_back(c - '0');
        }

        sort(digits.begin(), digits.end());

        do {

            int i = 0;
            while (i < digits.size() && digits[i] == 0) {
                ++i;
            }

            for (int j = i; j < digits.size(); ++j) {
                cout << digits[j];
            }
            cout << endl;
        } while (next_permutation(digits));
    }

    return 0;
}