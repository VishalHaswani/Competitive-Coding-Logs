#include<bits/stdc++.h>
 
#define fastio; ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
using namespace std;
 
void solve(int testCase) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    int i = -1, j = n;
    long long sum_i = 0, sum_j = 0, max_satf_sum = -1;
    while (i < j) {
        if (sum_i == sum_j) {
            max_satf_sum = sum_i;
            sum_i += nums[++i];
            sum_j += nums[--j];
        }
        else if (sum_i > sum_j) {
            sum_j += nums[--j];
        }
        else {
            sum_i += nums[++i];
        }
    }
    cout << max_satf_sum;
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