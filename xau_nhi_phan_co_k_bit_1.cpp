#include<bits/stdc++.h>
#define MAX 100
using namespace std;

int n, k, arr[MAX] = {}, dem = 0;

void output() {
    for (int i = 1; i <= n; ++i) cout << arr[i];
    cout << endl;
}
 
void generate(int tmp) {
    for (int i = 0; i <= 1; ++i) {
        arr[tmp] = i;
        if(tmp == n) {
            int dem = 0;
            for (int i = 1; i <= n; ++i) 
                dem += arr[i];
            if(dem == k) 
                output();
        }
        else generate(tmp + 1);
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        generate(1);
    }
    return 0;
}