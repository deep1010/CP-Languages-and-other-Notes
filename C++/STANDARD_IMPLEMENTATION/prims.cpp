#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> edge;
vector<vector<edge> > allEdges;
vector<bool> visited;
void Prims()
{
  long long int minCost = 0;
  edge minEdge;
  int src = 1;
  priority_queue<edge, vector<edge>, greater<edge> > edgePQ;
  edgePQ.push(make_pair(0, src));
  while (!edgePQ.empty())
  {
    minEdge = edgePQ.top();
    edgePQ.pop();
    src = minEdge.second;
    if (visited[src] == true)
    {
      continue;
    }
    visited[src] = true;
    minCost += minEdge.first;

    edge curEdge;
    for (int i = 0; i < allEdges[src].size(); i++)
    {
      curEdge = allEdges[src][i];
      if (visited[curEdge.second] == false)
      {
        edgePQ.push(curEdge);
      }
    }
  }
  cout << minCost << endl;
}
int main()
{
  int n, m;
  cin >> n >> m;
  vector<edge> temp;
  temp.clear();
  allEdges.assign(n + 1, temp);
  visited.assign(n + 1, false);
  int u, v, w;
  for (size_t i = 0; i < m; i++)
  {
    cin >> u >> v >> w;
    allEdges[u].push_back(make_pair(w, v));
    allEdges[v].push_back(make_pair(w, u));
  }
  Prims();
  return 0;
}
