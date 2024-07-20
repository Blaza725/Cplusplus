#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;

const int MAX_N = 46;
ll length[MAX_N]; 
ll countB[MAX_N]; 

void precompute() {
    length[0] = length[1] = 1;
    countB[0] = 0; 
    countB[1] = 1; 
    for (int i = 2; i < MAX_N; ++i) {
        length[i] = length[i-1] + length[i-2];
        countB[i] = countB[i-1] + countB[i-2];
    }
}

ll countBInFirstK(int n, ll k) {
    if (n == 0) return 0; 
    if (n == 1) return k == 1 ? 1 : 0; 
    if (k <= length[n-1])
        return countBInFirstK(n-1, k);
    else
        return countB[n-1] + countBInFirstK(n-2, k - length[n-1]);
}

int main() {
    faster;
    precompute();
    int T;
    cin >> T;
    while (T--) {
        int n;
        ll k;
        cin >> n >> k;
        cout << countBInFirstK(n, k) << endl;
    }
    return 0;
}