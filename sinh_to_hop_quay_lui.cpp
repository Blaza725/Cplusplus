#include<iostream>
#include<vector>
using namespace std;

int start, n, k;
vector<int> a;

void generate(int start) {
    if(a.size() == k) {
        for(int i = 0; i < a.size(); i++) cout << a[i] << " ";
        cout << endl;
        return;
    }
    for(int i = start; i <= n; i++) {
        a.push_back(i);
        generate(i + 1);
        a.pop_back();
    }
}

int main() {
    cin >> n >> k;
    generate(1);
    return 0;
}