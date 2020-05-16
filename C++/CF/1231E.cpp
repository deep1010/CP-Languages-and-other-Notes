#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

template<typename T>
void printVector(const T& t) {
	if(t.size()==0)
	{
		cout<<"Empty Vector\n";
		return;
	}
	for (int i = 0; i < t.size(); i++)
	{
		cout<<t[i]<<" ";
	}
	cout<<endl;
}
int LCS_Modified(string s,string t)
{
	int n = s.size();
	int ans = 0;
	vector<vector<int> > dp;
	vector<int> temp;
	temp.assign(n,0);
	for (int i = 0; i < n; i++)
	{
		dp.push_back(temp);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(s[i] == t[j])
			{
				if(i==0 || j==0)
					dp[i][j] = 1;
				else
					dp[i][j] = dp[i-1][j-1] + 1;
				
			}
			else
			{
				if(i==0)
					dp[i][j] = 0;
				else
					dp[i][j] = dp[i-1][j];
			}
			ans = max(ans,dp[i][j]);
		}
	}
	return ans;
	
}
void solve()
{
	int n;
	string s,t,a,b;
	cin>>n>>s>>t;
	a = s;
	b = t;
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	if(a == b)
	{
		cout<<n - LCS_Modified(s,t)<<endl;
		return;

	}
	else
	{
		cout<<-1<<endl;
		return;
	}
	
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}