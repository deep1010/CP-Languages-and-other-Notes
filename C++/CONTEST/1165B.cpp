#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int a[n+5];
    for(int i=0;i<n;i++)
    {
    	cin>>a[i];
    }
    sort(a,a+n);
    int cur_id = 1;
    int ans = 0;
    for(int i=0;i<n;i++)
    {
    	// cout<<ans<<" "<<cur_id<<endl;
    	if(a[i] >= cur_id)
    	{
    		ans++;
    		cur_id++;
    	}
    }
    cout<<ans<<endl;
    return 0;
}