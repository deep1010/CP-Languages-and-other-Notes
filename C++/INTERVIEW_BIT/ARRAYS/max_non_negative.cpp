#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll maxi(ll a, ll b){ return (a > b)?a:b;}
ll mini(ll a, ll b){ return (a < b)?a:b;}
void print_vec(vector<int> A)
{
	for(int i=0;i<A.size();i++)
		cout<<A[i]<<" ";
	cout<<endl;
	return;
}
vector<int> get_ans(vector<int> A)
{
	vector<int> ans;
	vector<int> temp;
	ll temp_sum = 0;
	ll max_sum = -1;
	int i= 0;
	temp.clear();
	int n = A.size();
	while(i < n)
	{
		// cout<<"temp_arr ";
		// print_vec(temp);
		// cout<<"max_sum "<<max_sum<<" temp_sum "<<temp_sum<<endl;
		if( A[i] >= 0)
		{
			temp.push_back(A[i]);
			temp_sum+=A[i];
		}
		else
		{
			if(temp_sum > max_sum)
			{
				max_sum = temp_sum;
				ans = temp;
			}
			else if(temp_sum == max_sum)
			{
				if(temp.size() > ans.size())
				{
					max_sum = temp_sum;
					ans = temp;
				}
			}
			temp.clear();
			temp_sum = 0;
		}
		i++;
	}
	if(temp_sum > max_sum)
	{
		max_sum = temp_sum;
		ans = temp;
		temp.clear();
		temp_sum = 0;
	}
	else if(temp_sum == max_sum)
	{
		if(temp.size() > ans.size())
		{
			max_sum = temp_sum;
			ans = temp;
		}
	}
	return ans;
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int temp;
    vector<int> input;
    for(int i=0;i<n;i++)
    {
    	cin>>temp;
    	input.push_back(temp);
    }
    vector<int> ans;
    ans = get_ans(input);
    for(int i=0;i<ans.size();i++)
    {
    	cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}