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
int get_ans(vector<int> A)
{
	int n = A.size();
	int max_val = A[0];
	for(int i=0;i<n;i++)
	{
		max_val = max(max_val,A[i]);
	}
	if(max_val <= 0)
		return 1;
	max_val += 1;
	for (int i = 0; i < n; ++i)
	{
		if (A[i]<0 || A[i] >= n)
		{
			A[i] = 0;
		}
	}
	// cout<<"After zero \n";
	// A.push_back(0);
	// print_vec(A);
	// cout<<"After Sum \n";
	int id;
	n = A.size();
	for(int i=0;i<n;i++)
	{
		id = A[i]%max_val;
		A[id] += max_val;
	}
	// print_vec(A);
	int ans = min(n+1,max_val);
	for(int i = 1;i<n;i++)
	{
		if(A[i] < max_val)
		{
			ans = i;
			break;
		}
	}
	return ans;
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    int n;
    int temp;
    vector<int> input;
    cin>>n;
    for (int i = 0; i <n ; ++i)
    {
    	cin>>temp;
    	input.push_back(temp);
    }
    cout<<get_ans(input)<<endl;    
    return 0;
}