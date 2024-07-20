#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;

int main() {
    faster;
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        unordered_map<char, int> ccnt;
        for (char c : s) {
            ccnt[c]++;
        }

        int unic = ccnt.size(); 
        int minlen = s.length();

        int start = 0, end = 0;
        int cnt = 0; 

        unordered_map<char, int> wccnt;

        while (end < s.length()) {
            char c = s[end];
            wccnt[c]++;

            if (wccnt[c] == 1) {
                cnt++;
            }

            while (cnt == unic) {
                minlen = min(minlen, end - start + 1);

                char startc = s[start];
                wccnt[startc]--;

                if (wccnt[startc] == 0) {
                    cnt--;
                }

                start++;
            }

            end++;
        }

        cout << minlen << endl;
    }

    return 0;
}