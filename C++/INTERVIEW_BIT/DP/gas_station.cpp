#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll maxi(ll a, ll b){ return (a > b)?a:b;}
ll mini(ll a, ll b){ return (a < b)?a:b;}
void print_vec(vector<int> A)
{
	for (int i = 0; i < A.size(); ++i)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;
	return;
}
int solve(vector<int> A, vector<int> B)
{
	vector<int> diff;
	int n = A.size();
	ll temp_sum = 0;
	for (int i = 0; i < n; ++i)
	{
		diff.push_back(A[i]-B[i]);
		temp_sum+=diff[i];
	}
	if (temp_sum < 0)
	{
		return -1;
	}
	else
	{
		int s = 0;
		int e = 0;
		int t_sum = 0;
		while(s < n && e < n)
		{
			// cout<<"s "<<s<<" e "<<e;
			t_sum += diff[e];
			if(t_sum < 0)
			{
				s = e+1;
				e = s;
				t_sum = 0;
			}
			else
			{
				e++;
			}
			// cout<<" t_sum "<<t_sum<<endl;
		}
		return s;
	}
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    vector<int> gas;
    vector<int> cost;
    int n,temp;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
    	cin>>temp;
    	gas.push_back(temp);
    }

    for (int i = 0; i < n; ++i)
    {
    	cin>>temp;
    	cost.push_back(temp);
    }
    cout<<solve(gas,cost)<<endl;
    return 0;
}