#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    ll arr[n+10];
    for(int i=2;i<=n;i++)
    {
        arr[i] = -1;
    }
    for(int i=2;i<=n;i+=2)
    {
        arr[i]=1;
    }
    int cur_id  = 3;
    int cur_val = 2;
    while(cur_id <=n)
    {
        // cout<<"CUR_ID   "<<cur_id<<"   cur_val   "<<cur_val<<endl;
        // for(int i=2;i<=n;i++)
            // cout<<arr[i]<<" ";
        // cout<<endl;
        if(arr[cur_id]!=-1)
        {
            cur_id+=2;
            continue;
        }
        int temp_id = cur_id;
        while(temp_id <= n)
        {
            // cout<<"CUR_ID   "<<cur_id<<"   cur_val   "<<cur_val<<"   temp_id   "<<temp_id<<endl;
            // for(int i=2;i<=n;i++)
                // cout<<arr[i]<<" ";
            // cout<<endl;
            if(temp_id%2==1)
            {
                arr[temp_id]=cur_val;
            }
            temp_id += cur_id;
        }
        cur_val++;
        cur_id+=2;
    }
    for(int i=2;i<=n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}