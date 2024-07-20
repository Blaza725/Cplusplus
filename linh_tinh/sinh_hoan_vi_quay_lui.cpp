#include<iostream>
using namespace std;

int a[100], n;

void output() {
    for(int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << endl;
}

void generate(int i) {
    if(i == n) {
        output();
        return;
    }
    for(int j = i; j <= n; j++) {
        swap(a[i], a[j]);
        generate(i + 1);
        swap(a[i], a[j]);
    }
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) a[i] = i;
    generate(1);
    return 0;
}