#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll maxi(ll a, ll b){ return (a > b)?a:b;}
ll mini(ll a, ll b){ return (a < b)?a:b;}
ll get_max_sum(vector<int> A)
{
	ll max_sum = *max_element(A.begin(), A.end());
	ll temp_sum = 0;
	for (int i = 0; i < A.size(); ++i)
	{
		temp_sum += A[i];
		max_sum = maxi(temp_sum,max_sum);
		if(temp_sum < 0)
		{
			temp_sum = 0;
		}
	}
	return max_sum;
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    int n,temp;
    cin>>n;
    vector<int> input;
    for(int i=0;i<n;i++)
    {
    	cin>>temp;
    	input.push_back(temp);
    }
    cout<<get_max_sum(input)<<endl;
    return 0;
}