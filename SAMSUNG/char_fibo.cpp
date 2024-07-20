#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;

const int MAX_N = 46;
ll length[MAX_N];
ll countA[MAX_N];

void precompute() {
    length[0] = length[1] = 1;
    countA[0] = 1; // F[0] = "A"
    countA[1] = 0; // F[1] = "B"
    for (int i = 2; i < MAX_N; ++i) {
        length[i] = length[i-1] + length[i-2];
        countA[i] = countA[i-1] + countA[i-2];
    }
}

ll countAInFirstK(int n, ll k) {
    if(n == 0) return k == 1 ? 1 : 0;
    if(n == 1) return 0;
    if(k <= length[n-1]) return countAInFirstK(n-1, k);
    else return countA[n-1] + countAInFirstK(n-2, k - length[n-1]);
}

int main() {
    precompute();
    int T;
    cin >> T;
    while (T--) {
        int n;
        ll k;
        cin >> n >> k;
        cout << countAInFirstK(n, k) << endl;
    }
    return 0;
}