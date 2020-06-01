#include <bits/stdc++.h>

using namespace std;

int main() {
	cout << "Enter the number of items: ";
	int n;
	cin >> n;
	cout << "Enter their weights in an order: ";
	int w[n+1], p[n+1];
	for(int i = 1; i < n; i++)
		cin >> w[i];
	cout << "Enter their profits respectively: ";
	for(int i = 1; i < n; i++)
		cin >> p[i];
	cout << "Enter the maximum weight permissible: ";
	int W;
	cin >> W;
	int dp[n+1][W+1];
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= W; j++) {
			if(j-w[i] < 0)
				dp[i][j] = dp[i-1][j];
			else
				dp[i][j] = max(dp[i-1][j], p[i]+dp[i-1][j-w[i]]);
		}
	}
	cout << "The maximum profit that can be earned is : " << dp[n][W];
	cout << '\n';
	return 0;
}
