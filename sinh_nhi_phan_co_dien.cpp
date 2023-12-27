#include<iostream>
using namespace std;

int a[100], n;
bool check = true;

void first() {
    for(int i = 1; i <= n; i++) a[i] = 0;
}

void output() {
    for(int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << endl;
}

void next() {
    int i = n;
    while(i >= 1 && a[i] == 1) {
        a[i] = 0;
        i--;
    }
    if(i == 0) check = false;
    else a[i] = 1;
}

int main() {
    cin >> n;
    first();
    while(check) {
        output();
        next();
    }
    return 0;
}