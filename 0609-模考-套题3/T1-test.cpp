#include<bits/stdc++.h>
using namespace std;

int solve(string s){
	// freopen("A.in","r",stdin);
	// freopen("A.out","w",stdout);
	// string s;
	// cin >> s;
	string ss = s;
	int len = s.size();
	
	for (int i = 0 ; i < len ; i++) {
		if (s[i] == '0' ) {
			s[i] = '1';
			
		}
	}
	
	cout << "原数字为：" << ss << ", " << "修改后的数字为：" << s << endl;
	// cout << s;
	return 0;
}

int main() 
{
	for(int n=1; n<=10000; ++n) 
	{
		solve(to_string(n));
	}
}