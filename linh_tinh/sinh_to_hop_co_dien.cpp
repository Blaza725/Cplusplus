#include<iostream>
using namespace std;

int a[100], n, k;
bool check = true;

void first() {
    for(int i = 1; i <= k; i++) a[i] = i;
}

void output() {
    for(int i = 1; i <= k; i++) cout << a[i] << " ";
    cout << endl;
}

void next_combination() {
    int i = k;
    while(i >= 0 && a[i] == n - k + i) i--;
    if(i > 0) {
        a[i]++;
        for(int j = i + 1; j <= k; j++) a[j] = a[i] + j - i;
    } 
    else check = false;
}

int main() {
    cin >> n >> k;
    first();
    while(check) {
        output();
        next_combination();
    }
    return 0;
}