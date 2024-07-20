#include<iostream>
#include<vector>
#include<set>
using namespace std;

void output(vector<int>& partition) {
    for (int i = 0; i < partition.size(); i++)
        cout << partition[i] << " ";
    cout << endl;
}

void generatePartitions(int n, vector<int>& partition, int sum, int currentSum, int index, set<int>& used) {
    if (currentSum == sum && partition.size() > 1 && !(partition.size() == 2 && partition[0] == 0)) {
        output(partition);
        return;
    }

    for (int i = index; i <= n; i++) {
        if (used.find(i) != used.end()) continue;
        if (currentSum + i <= sum) {
            partition.push_back(i);
            used.insert(i);
            generatePartitions(n, partition, sum, currentSum + i, i + 1, used);
            used.erase(i);
            partition.pop_back();
        }
    }
}

int main() {
    int n;
    cout << "Nhap so nguyen duong n: ";
    cin >> n;
    vector<int> partition;
    set<int> used;
    generatePartitions(n, partition, n, 0, 0, used);
    return 0;
}