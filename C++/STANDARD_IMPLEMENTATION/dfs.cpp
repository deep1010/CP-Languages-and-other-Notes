#include "../stdc++.h"
using namespace std;
vector<vector<int> > adj;
vector<bool> visited;
void dfs(vector<int> &path,int src)
{
  visited[src] = true;
  path.push_back(src);
  cout<<"\nPath of "<<src<<":\t";
  for (size_t i = 0; i < path.size(); i++) {
    cout<<path[i]<<" ";
  }
  for (size_t i = 0; i < adj[src].size(); i++) {
    if(visited[adj[src][i]] == false)
    {
      dfs(path,adj[src][i]);
    }
  }
  path.pop_back();
}
int main()
{
  int  n,m;
  cin>>n>>m;
  vector<int> temp;
  temp.clear();
  adj.assign(n+1,temp);
  visited.assign(n+1,false);
  int u,v;
  for (int i = 0; i < m; i++) {
    cin>>u>>v;
    adj[u].push_back(v);
    // adj[v].push_back(u);
  }
  vector<int> path;
  for (size_t i = 0; i < n; i++) {
    if(visited[i]==false)
      dfs(path,i);
  }

}
