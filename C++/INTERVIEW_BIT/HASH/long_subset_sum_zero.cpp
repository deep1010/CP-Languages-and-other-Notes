#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mini(ll a, ll b){return a<b?a:b;}
ll maxi(ll a, ll b){return a>b?a:b;}
void solve(vector<int> A)
{
	int n = A.size();
	std::map<int, int> sum_map;
	sum_map.insert(make_pair(0,-1));
	int s=0;
	int e=0;
	ll max_len = -1;
	ll temp_sum = 0;
	for (int i = 0; i < n; ++i)
	{
		temp_sum += A[i];
		if (sum_map.find(temp_sum) == sum_map.end())
		{
			sum_map.insert(make_pair(temp_sum,i));
		}
		else
		{
			if((i - sum_map[temp_sum]) > max_len)
			{
				max_len = i - sum_map[temp_sum];
				s = sum_map[temp_sum]+1;
				e = i;
			}
		}
	}
	cout<<s<<" "<<e<<endl;
	return;
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	
	int n,temp;
	vector<int> input;

	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>temp;
		input.push_back(temp);
	}
	solve(input);
	return 0;
}