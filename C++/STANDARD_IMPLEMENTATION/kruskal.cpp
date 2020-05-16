#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> intPair;
vector< pair<long long int,intPair> > edges;
vector<int> parent;
int root(int x)
{
  while(parent[x] != x)
  {
    parent[x] = parent[parent[x]];
    x = parent[x];
  }
  return parent[x];
}
void join(int x, int y)
{
  int root_x = root(x);
  int root_y = root(y);
  parent[root_x] = parent[root_y];
}
void Kruskal()
{
  for (size_t i = 0; i < parent.size(); i++) {
    parent[i] = i;
  }
  long long minCost = 0;
  intPair edge;
  long long int w;
  int u,v;
  cout<<"Edges Included in MST :\n";
  for (size_t i = 0; i < edges.size(); i++) {
    edge = edges[i].second;
    w = edges[i].first;
    u = edge.first;
    v = edge.second;
    if(root(u) != root(v))
    {
      cout<<u<<" <-> "<<v<<" with weight "<<w<<endl;
      join(u,v);
      minCost += w;
    }
  }
  cout<<"Total weight of MST:\t";
  cout<<minCost<<endl;
}
int main()
{
  int n,m;
  cin>>n>>m;

  int u,v,w;
  for (size_t i = 0; i < m; i++) {
    cin>>u>>v>>w;
    edges.push_back(make_pair(w,make_pair(u,v)));
  }
  parent.assign(n+1,0);
  sort(edges.begin(),edges.end());
  Kruskal();

  // for (size_t i = 0; i < edges.size(); i++) {
  //   cout<<edges[i].second.first<<" <-> "<<edges[i].second.second<<" weight "<<edges[i].first<<endl;
  // }
  return 0;
}
