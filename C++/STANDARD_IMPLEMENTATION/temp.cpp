// #include <bits/stdc++.h
 #include "stdc++.h"
using namespace std;
class Graph 
{ 
    int V; 
    list<int> *adj;
    void printAllPathsUtil(int , int , vector<bool>, vector<int>, int &,vector<vector<int> > &); 
  
public: 
    Graph(int V); // Constructor 
    void addEdge(int u, int v); 
    void printAllPaths(int s, int d,vector<vector<int> > &); 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int u, int v) 
{ 
    adj[u].push_back(v);
    adj[v].push_back(u);
} 

void Graph::printAllPaths(int s, int d,vector<vector<int> > &AllPaths) 
{ 
    
    vector<bool> visited;
    visited.assign(V,false);
    vector<int> path;
    path.assign(V,0); 
    int path_index = 0;
    printAllPathsUtil(s, d, visited, path, path_index,AllPaths); 
} 

void Graph::printAllPathsUtil(int u, int d, vector<bool> visited,vector<int> path, int &path_index,vector<vector<int> > &AllPaths) 
{ 
    visited[u] = true; 
    path[path_index] = u; 
    path_index++;
    vector<int> temp;
    if (u == d) 
    {
    	temp.clear();
        for (int i = 0; i<path_index; i++) 
            temp.push_back(path[i]);
        AllPaths.push_back(temp);
          
    } 
    else
    { 
        list<int>::iterator i; 
        for (i = adj[u].begin(); i != adj[u].end(); ++i) 
            if (!visited[*i]) 
                printAllPathsUtil(*i, d, visited, path, path_index,AllPaths); 
    }  
    path_index--; 
    visited[u] = false;
}
vector<int> getNums(string s)
{
	vector<int> ans;
    string temp;
    s+=",";
    for(char i : s)
    {
        if(i==',')
        {
            ans.push_back(atoi(temp.c_str()));
            temp="";
        }
        else
            temp+=i;
    }
    return ans;
}
bool checkLock(string A)
{
    if(A.size()%2==0)
    {
        string B = A;
        reverse(B.begin(),B.end());
        if(A==B)
            return true;
    }
    else
    {
        string t1 = A.substr(1);
        string B;
        B = t1;
        reverse(B.begin(),B.end());
        if(B==t1)
            return true;
    }
    return false;
}
int main()
{
	int n,m;
	string input3;
	string input4;
	string input5;
	string input6;
	cin>>n>>m;
	cin>>input3>>input4>>input5>>input6;
	vector<int> A = getNums(input3);
	vector<int> B = getNums(input4);
	vector<int> C = getNums(input5);
	vector<vector<int> > Paths;
	int weight[105][105];
	string lock[105][105];
	Graph g(n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			weight[i][j]=0;
		}
	}
	for (int i = 0; i < A.size(); ++i)
	{
		g.addEdge(A[i],B[i]);
		weight[A[i]][B[i]] = C[i];
		weight[B[i]][A[i]] = C[i];
        lock[A[i]][B[i]] = input6[i];
        lock[B[i]][A[i]] = input6[i];
	}
	g.printAllPaths(0,1,Paths);
	if(Paths.size()==0)
	{
        cout<<-1<<endl;
        return 0;
	}
    string curLock;
    curLock.clear();
    int minDist = INT_MAX;
    int curDist = 0;
    for(vector<int> path : Paths)
    {
        curDist = 0;
        curLock.clear();
        for(int i=0;i<path.size()-1;i++)
        {
            curDist += weight[path[i]][path[i+1]];
            curLock += lock[path[i]][path[i+1]];
        }
        if(checkLock(curLock))
        {
        	cout<<curLock<<endl;
            minDist = min(minDist,curDist);
        }
    }
    cout<<minDist<<endl;
	return 0;
}