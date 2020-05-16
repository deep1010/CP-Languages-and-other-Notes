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
vector<int> get_ans(vector<int> A)
{
	int n = A.size();
    vector<int> ans;
    ans.push_back(-1);
    
    int l,r;
    l = -1;
    r = -1;
    int minSwap = *max_element(A.begin(),A.end())+1;
    int maxSwap = -1;
    for (int i = 0; i < n-1; ++i)
    {
        if(A[i] > A[i+1] && A[i+1] <=minSwap)
        {
            l = i;
            minSwap = A[i+1];
        }
    }
    if(l == -1)
    {
        return ans;
    }
    for (int i = n-1; i > 0; i--)
    {
        if(A[i] < A[i-1] && A[i-1]  > maxSwap)
        {
            r = i;
            maxSwap = A[i-1];
        }
    }
    for(int i=0; i < l ;i++)
    {
        if(A[i] > minSwap)
        {
            l = i;
            break;
        }
    }
    for(int i=n-1; i > 0  ;i--)
    {
        if(A[i] < maxSwap)
        {
            r = i;
            break;
        }
    }
    ans.clear();
    ans.push_back(l);
    ans.push_back(r);
    return ans;
	
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    int n,temp;
    cin>>n;
    vector<int> input;
    for (int i = 0; i < n; ++i)
    {
    	cin>>temp;
    	input.push_back(temp);
    }
    print_vec(get_ans(input));
    return 0;
}