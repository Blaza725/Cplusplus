#include <iostream>
#include <vector>
#include <chrono>
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

void generate_combinations(int n, int k, vector<int>& combination, int index) {
    if (index == k) {
        // In tổ hợp
        for (int i = 0; i < k; ++i) {
            cout << combination[i] << " ";
        }
        cout << endl;
        return;
    }

    // Duyệt các giá trị có thể có cho phần tử hiện tại
    for (int i = (index > 0) ? combination[index - 1] : 1; i <= n; ++i) {
        combination[index] = i;
        generate_combinations(n, k, combination, index + 1);
    }
}

int main() {
    faster;
    int n, k;
    cin >> n >> k;

    vector<int> combination(k);
    generate_combinations(n, k, combination, 0);
    return 0;
}