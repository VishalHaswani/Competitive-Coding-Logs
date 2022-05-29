#include<bits/stdc++.h>
 
#define fastio; ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
using namespace std;
 
void solve(int testCase) {
    int n, k, res = 0, prev;
    cin >> n >> k;
    vector<int> nums(n), idx(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        idx[i] = i;
    }
    sort(idx.begin(), idx.end(), [&nums](int a, int b) {return nums[a] > nums[b];});
    for (int i = 0; i < k; i++) {
        res += nums[idx[i]];
    }
    cout << res << endl;
    sort(idx.begin(), idx.begin() + k);
    idx[k - 1] = n - 1;
    prev = -1;
    for (int i = 0; i < k; i++) {
        cout << (idx[i] - prev) << " ";
        prev = idx[i];
    }
}
 
int main() {
    fastio;
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
    return 0;
}