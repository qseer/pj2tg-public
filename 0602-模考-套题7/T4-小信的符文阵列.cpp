#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define ff first
#define ss second
typedef pair<int, int> pii;
typedef pair<pair<int, int>, int>piii;
typedef long long ll;
const int inf = 0x3f3f3f;
const int mod = 1e9 + 7;
const int inv2 = (mod + 1) / 2;
//using i128 = __int128;
//using i64 = __int64_t;
//using u64 = unsigned long long;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int>a(n + n + 5);
	vector<char>b(n + n + 5);
	vector<vector<int>>mi(2 * n + 5, vector<int>(n + n + 5));
	vector<vector<int>>ma(2 * n + 5, vector<int>(n + n + 5));
	for (int i = 1; i <= n + n; i++)
	{
		for (int j = 1; j <= n + n; j++)
		{
			ma[i][j] = -1e17;
			mi[i][j] = 1e18;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> b[i];
		a[i + n] = a[i];
		b[i + n] = b[i];
		ma[i][i] = mi[i][i] = a[i];
		ma[i + n][i + n] = mi[i + n][i + n] = a[i + n];
	} 
	for (int len = 2; len <= n; len++)
	{
		for (int i = 1; i + len - 1 <= 2 * n; i++)
		{
			int l = i;
			int r = i + len - 1;
			//符号小一位 
			for (int d = l; d <= r - 1; d++)
			{
				if (b[d] == '+' || b[d] == '?')
				{
					ma[l][r] = max(ma[l][r], ma[l][d] + ma[d + 1][r]);
					mi[l][r] = min(mi[l][r], mi[l][d] + mi[d + 1][r]);
				}
				if (b[d] == '-' || b[d] == '?')
				{
					ma[l][r] = max(ma[l][r], ma[l][d] - mi[d + 1][r]);
					mi[l][r] = min(mi[l][r], mi[l][d] - ma[d + 1][r]);
				}
				if (b[d] == '*' || b[d] == '?')
				{
					//四个数
					int c1 = ma[l][d] * ma[d + 1][r];
					int c2 = ma[l][d] * mi[d + 1][r];
					int c3 = mi[l][d] * ma[d + 1][r];
					int c4 = mi[l][d] * mi[d + 1][r];
					ma[l][r] = max({ma[l][r], c1, c2, c3, c4});
					mi[l][r] = min({mi[l][r], c1, c2, c3, c4});
					
				}
				
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << abs(mi[i][i + n - 1]) << abs(ma[i][i + n - 1]);
	}
	return 0;
} 
