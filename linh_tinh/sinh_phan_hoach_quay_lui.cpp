#include<iostream>
#include<vector>
using namespace std;

vector<int> a;
int n, sum = n, cur;

void output() {
    for(int i = 0; i < a.size(); i++) cout << a[i] << " ";
    cout << endl;
}

void generatePartitions(int cur, int i) {
    if(cur == sum) {
        output();
        return;
    }
    for(int j = i; j < n; j++) {
        if(cur + j + 1 <= sum) {
            a.push_back(j + 1);
            generatePartitions(cur + j + 1, j);
            a.pop_back();
        }
    }
}

int main() {
    cin >> n;
    generatePartitions(0, 0);
    return 0;
}