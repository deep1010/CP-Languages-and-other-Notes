#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> intPair;
vector<vector<intPair> > adj;
vector<long long int> dist;
vector<bool> visited;
void dijkstra(int src)
{
	dist[src] = 0;
	priority_queue<intPair, vector<intPair>, greater<intPair> > pq;
	pq.push(make_pair(0, src));
	int curNode;
	while (!pq.empty())
	{
		curNode = pq.top().second;
		pq.pop();
		visited[curNode] = true;
		intPair edge;
		int u, v, w;
		for (int i = 0; i < (int)adj[curNode].size(); i++)
		{
			edge = adj[curNode][i];
			u = curNode;
			v = edge.first;
			w = edge.second;
			if (visited[v] == false && dist[v] > dist[u] + w)
			{
				dist[v] = dist[u] + w;
				pq.push(make_pair(dist[v], v));
			}
		}
	}
	return;
}
int main()
{
	int n, m;
	cin >> n >> m;
	vector<intPair> temp;
	temp.clear();
	adj.assign(n + 1, temp);
	dist.assign(n + 1, 1000000000);
	visited.assign(n + 1, false);
	int u, v, w;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(v, w));
	}
	dijkstra(1);
	for (int i = 2; i < n; i++)
	{
		cout << dist[i] << " ";
	}
	cout << dist[n];
	return 0;
}
