#include<bits/stdc++.h>

#define fastio; ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

void solve(int testCase) {
    int n;
    string a, b;

    cin >> n >> a >> b;
    int i = 0, j = n - 1, res = 0;
    map<char,short int> freq;
    while (i < j) {
    	freq[a[i]]++; freq[a[j]]++;
    	freq[b[i]]++; freq[b[j]]++;
    	switch(freq.size()) {
    		case(4):
    			res += 2;
    			break;
    		case(3):
    			if (a[i] == a[j]) {
    				res += 2;
    			}
    			else {
    				res += 1;
    			}
    			break;
    		case(2):
    			if (freq.begin()->second != (--freq.end())->second) {
    				res++;
    			}
    			break;
    	}
    	freq.clear();
    	i++;
    	j--;
    }
    if (i == j and a[i] != a[j]) {
    	res++;
    }
    cout << res;
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