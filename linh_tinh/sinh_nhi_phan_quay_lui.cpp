#include<iostream>
using namespace std;

int a[100], n;

void output() {
    for(int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << endl;
}

void generate(int i) {
    for(int j = 0; j <= 1; j++) {
        a[i] = j;
        if(i == n) output();
        else generate(i + 1);
    }
}

int main() {
    cin >> n;
    generate(1);
    return 0;
}