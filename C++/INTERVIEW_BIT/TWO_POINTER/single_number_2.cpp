#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mini(ll a, ll b){return a<b?a:b;}
ll maxi(ll a, ll b){return a>b?a:b;}
int solve(vector<int> A)
{
	int count[32][2] = {0};
	for (int i = 0; i < 32; i++)
	{
		count[i][0] = 0;
		count[i][1] = 0;
	}
	int n = A.size();
	for (int i = 0; i < n; i++)
	{
		int temp = A[i];
		int bit_id = 0;
		if(temp==0)
		{
			count[0][0]++;
		}
		else
		{
			while(temp)
			{
				count[bit_id][temp%2]++;
				bit_id++;
				temp/=2;
			}
		}
	}
	for(int i=0; i<32;i++)
	{

	}
	int ans = 0;
	for (int i = 0; i < 32; i++)
	{
		if (count[i][1]%3!=0)
		{
			/* bit should be 1 */
			ans += pow(2,i);
		}
	}
	return ans;
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	int n,temp;
	vector<int> input;
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		cin>>temp;
		input.push_back(temp);
	}
	cout<<solve(input)<<endl;
	

	return 0;
}