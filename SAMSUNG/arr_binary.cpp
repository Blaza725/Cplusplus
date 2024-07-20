#include <iostream>
#include <vector>
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main() {
    faster;
	int N, Q;
	cin >> N >> Q;

	vector<int> binary(N, 0);

	for (int i = 0; i < Q; ++i) {
		int x, y;
		cin >> x >> y;
		for (int j = x - 1; j < y; ++j) {
			binary[j] ^= 1; 
		}
	}

	for (int i = 0; i < N; ++i) {
		cout << binary[i] << " ";
	}

	return 0;
}