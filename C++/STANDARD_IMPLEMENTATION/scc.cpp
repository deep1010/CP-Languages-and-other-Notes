#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,m;
  cin>>n>>m;
  vetor<vector<int> > adj;
  vector<vector<int> > adjReversed;
  vector<int> temp;
  vector<bool> visited;
  temp.clear();
  adj.assign(n+1,temp);
  adjReversed.assign(n+1,temp);
  int u,v;
  for (size_t i = 0; i < m; i++) {
    cin>>u>>v;
    adj[u].push_back(v);
    adjReversed[v].push_back(u);
  }
  visited.assign(n+1,false);
  stack<int> s;
  for(int i=1;i<=n;i++)
  {
    if(visited[i]==false)
    {
      dfs(adj,visited,s);
    }
  }
}
