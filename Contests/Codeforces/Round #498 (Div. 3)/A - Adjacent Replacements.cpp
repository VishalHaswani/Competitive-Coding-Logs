#include<bits/stdc++.h>
 
#define fastio; ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
using namespace std;
 
void solve(int testCase) {
    int n;
    cin >> n;
    vector<int> nums(n), idx(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    for (int i = 0; i < n; i++) {
        if (nums[i] % 2 == 0) {
            nums[i]--;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
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