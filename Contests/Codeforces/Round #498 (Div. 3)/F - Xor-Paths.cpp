#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

vector<vector<long long>> weights;
vector<vector<map<long long,unsigned int>>> xors;
short int n, m, maxDepth1, maxDepth2;
long long k, res = 0;

void dfsFromTopLeft(int row, int col, int depth, long long val) {
	if (depth > maxDepth1 || row == n || col == m) {
		return;
	}
	//cout << row << " " << col << endl;

	val ^= weights[row][col];
	//cout << row << " " << col << ": " << val << endl;
	xors[row][col][val]++;
	
	dfsFromTopLeft(row + 1, col, depth + 1, val);
	dfsFromTopLeft(row, col + 1, depth + 1, val);
}

void dfsFromBotRight(int row, int col, int depth, long long val) {
	if (row < 0 || col < 0) {
		return;
	}
	if (depth == maxDepth2) {
		//cout << row << " " << col << endl;
		auto posible = xors[row][col].find(val ^ k);
		if (posible != xors[row][col].end()) {
			//cout << row << " " << col << endl;
			res += posible->second;
		}
	}
	else {
		//cout << row << " " << col << endl;
		val ^= weights[row][col];
		//xors[row][col][val]++;

		dfsFromBotRight(row - 1, col, depth + 1, val);
		dfsFromBotRight(row, col - 1, depth + 1, val);
	}
	return;
}

int main() {
	fastio;
    cin >> n >> m >> k;
    weights = vector<vector<long long>>(n, vector<long long>(m));
    xors = vector<vector<map<long long,unsigned int>>>(n, vector<map<long long,unsigned int>>(m));
    maxDepth1 = (n + m - 2) / 2;
    maxDepth2 = n + m - 2 - maxDepth1;
    
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		cin >> weights[i][j];
    	}
    }

    dfsFromTopLeft(0, 0, 0, 0);
    dfsFromBotRight(n -1, m - 1, 0, 0);
    cout << res;
    return 0;
}

