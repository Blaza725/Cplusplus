#include<iostream>
using namespace std;

int a[100], n;
bool check = true;

void first() {
    for(int i = 1; i <= n; i++) a[i] = i;
}

void output() {
    for(int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << endl;
}

void generate() {
    int i = n - 1;
    while(i >= 1 && a[i] > a[i + 1]) i--;
    if(i == 0) check = false;
    else {
        int k = n;
        while(a[i] > a[k]) k--;
        swap(a[i], a[k]);
        int l = i + 1, r = n;
        while(l <= r) {
            swap(a[l], a[r]);
            l++;
            r--;
        }
    }
}

int main() {
    cin >> n;
    first();
    while(check) {
        output();
        generate();
    }
    return 0;
}
