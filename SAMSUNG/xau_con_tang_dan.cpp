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

// Custom comparator for sorting subsequences
bool customSort(const vector<int>& v1, const vector<int>& v2) {
    if (!v1.empty() && !v2.empty()) {
        for (int i = 0; i < min(v1.size(), v2.size()) - 1; ++i) {
            if (v1[i] < v2[i]) {
                return true;
            }
            else if (v1[i] == v2[i]) {
                if (i+1 < min(v1.size(), v2.size()) && v1[i+1] > v2[i+1]) {
                    return true;
                }
            }
            else if (v1[i] > v2[i]) {
                return false;
            }
        }
        return v1.size() < v2.size();
    }
}

void printSubsequences() {
    sort(subseqs.begin(), subseqs.end(), customSort);
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