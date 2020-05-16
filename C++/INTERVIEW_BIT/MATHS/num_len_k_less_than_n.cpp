#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mini(ll a, ll b){return a<b?a:b;}
ll maxi(ll a, ll b){return a>b?a:b;}
int count_lower(vector<int> A, int val)
{
	int ans = 0;
	for (int i = 0; i < A.size(); ++i)
	{
		if (A[i] >= val)
		{
			break;
		}
		else
			ans++;
	}
	// printf("Count_lower\t val=%d count=%d\n",val,ans);
	return ans;
}
bool is_present(string A,vector<int> B)
{
	cout<<A<<endl;
	for (int i = 0; i < A.size(); ++i)
	{
		if (binary_search(B.begin(), B.end(),A[i]-'0') == 0)
		{
			// printf("false\n");
			return false;
		}
	}
	// printf("true\n");
	return true;
}
int solve(vector<int> A, int B, int C)
{
	int n = A.size();
    string c_str = to_string(C);
    int c_len = c_str.size();
    int b_len = B;
    int ans = 0;
    // cout<<"b_len "<<b_len<<" c_len "<<c_len<<" C "<<C<<endl;
    if(b_len > c_len || n==0)
        return 0;
    else if (b_len == 1)
    {
        // cout<<"First if\n";
        for (int i = 0; i < n; ++i)
            {
                if (A[i] < C)
                {
                    ans++;
                }
            }
        return ans;
    }
    else if(b_len < c_len)
    {
        // cout<<"Second If\n";
        if(A[0]==0)
            ans = (n-1)*(pow(n,b_len-1));
        else
            ans = pow(n,b_len);
        return ans;
    }
    else
    {
        int temp;
        bool to_add = true;
        // cout<<"third If\n";
        int dp[15] = {0};
        dp[0] = 0;
        for (int i = 1; i <= b_len; ++i)
        {
            dp[i] = dp[i-1] * n;
            temp = count_lower(A,c_str[i-1]-'0');

            if(i==1 && A[0]==0 && b_len!=1)
                temp--;
            if(to_add)
            {
                dp[i] += temp;
                to_add = (count_lower(A,c_str[i-1]-'0'+1)) == (1 + count_lower(A,c_str[i-1]-'0'));
            }
        }
        return dp[b_len];

    }
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	int n,b,c,temp;
	vector<int> input;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>temp;
		input.push_back(temp);
	}
	cin>>b>>c;
	cout<<solve(input,b,c)<<endl;
	return 0;
}