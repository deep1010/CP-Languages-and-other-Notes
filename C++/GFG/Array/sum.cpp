#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    vector<ll> arr;
    while(t--)
    {
    	int n;
    	ll s;
    	ll tot_sum=0;
    	int temp;
    	cin>>n>>s;
    	arr.clear();
    	for(int i=0;i<n;i++)
    	{
    		cin>>temp;
    		arr.push_back(temp);
    		tot_sum+=temp;
    	}
    	if(s > tot_sum)
    	{
    		cout<<-1<<endl;
    		continue;
    	}
    	bool found=false;
    	int start = 0;
    	int end = 0;
    	ll sum = arr[0];
    	while(end < n && start < n)
    	{
    		// cout<<"here\n";
    		// cout<<"start\tend\tsum"<<endl;
    		// cout<<start<<"\t"<<end<<"\t"<<sum<<endl;
    		if(sum < s)
    		{
    			end++;
    			sum += arr[end];
    		}
    		else if(sum == s)
    		{
    			found = true;
    			break;
    		}
    		else if(sum > s)
    		{
    			sum -= arr[start];
    			if( start < end)
    				start++;
    			else if (start == end)
    			{
    				start++;
    				end = start;
    				sum = arr[start];
    			}
    		}
    	}
    	if(found)
    	{
    		cout<<start+1<<" "<<end+1<<endl;
    	}
    	else
    		cout<<-1<<endl;
    }
    return 0;
}