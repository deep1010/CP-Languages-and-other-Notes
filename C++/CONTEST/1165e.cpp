#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    cin.tie(0);
    cout.tie(0);
    int n,temp;
    ll mod = 998244353;
    cin>>n;
    vector<int> a;
    vector<int> b;
    for(int i=0;i<n;i++)
    {
    	cin>>temp;
    	a.push_back(temp);
    }
    for(int i=0;i<n;i++)
    {
    	cin>>temp;
    	b.push_back(temp);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    for(int i=0;i<n;i++)
    {

    }
    return 0;
}