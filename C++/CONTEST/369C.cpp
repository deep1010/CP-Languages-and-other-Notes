#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<int> adj_list[100009];
int visited[100009];
int subset[100009];
map < pair<int,int> , int > edge_type;
bool check_for(int id)
{
    visited[id]=1;
    bool ans = false;
    for(int i=0;i<adj_list[id].size();i++)
    {
        int j = adj_list[id][i];
        if(visited[j]==0)
        {
            
            if(edge_type[{id,j}]==2)
            {
                subset[j]=1;
            }
            ans = check_for(j) || ans;
        }
    }

    if(ans==true)
    {
        subset[id]=0;
    }
    // cout<<"id "<<id<<" flag  "<<ans<<" subset "<<subset[id]<<endl;
    return ans || bool(subset[id]);
}
// void print_vector()
int main()
{
    int n,a,b,w;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        visited[i]=0;
        subset[i]=0;
    }
    for(int i=0;i<n-1;i++)
    {
        cin>>a>>b>>w;
        edge_type[{a,b}] = w;
        edge_type[{b,a}] = w;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    check_for(1);
    vector<int> ans;
    for(int i=1;i<=n;i++)
    {
        if(subset[i]==1)
        {
            ans.push_back(i);
        }
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
