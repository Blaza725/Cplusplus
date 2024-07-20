#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;

vector<int> a;
vector<vector<int>> subseqs;

void findSubsequences(int start, vector<int>& subseq) {
    if (subseq.size() > 1) {
        subseqs.push_back(subseq);
    }
    for (int i = start; i < a.size(); ++i) {
        if (subseq.empty() || a[i] > subseq.back()) {
            subseq.push_back(a[i]);
            findSubsequences(i + 1, subseq);
            subseq.pop_back();
        }
    }
}

void printSubsequences() {
    sort(subseqs.begin(), subseqs.end()); // Sort subsequences for lexicographical order
    for (auto& seq : subseqs) {
        for (int num : seq) {
            cout << num << " ";
        }
        cout << "\n";
    }
}

int main() {
    faster;
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> subseq;
    findSubsequences(0, subseq);
    printSubsequences();
    return 0;
}