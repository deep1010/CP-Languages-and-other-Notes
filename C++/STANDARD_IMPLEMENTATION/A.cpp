#include<stdio.h>
#include<string.h>
#include "stdc++.h"
using namespace std;
class Graph 
{ 
    int V; 
    list<int> *adj;
    void getAllPathsHelper(int , int , vector<bool>, vector<int>, int &,vector<vector<int> > &); 
  
public: 
    Graph(int V); // Constructor 
    void addEdge(int u, int v); 
    void getAllPaths(int s, int d,vector<vector<int> > &); 
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

void Graph::getAllPaths(int s, int d,vector<vector<int> > &AllPaths) 
{ 
    
    vector<bool> visited;
    visited.assign(V,false);
    vector<int> path;
    path.assign(V,0); 
    int path_index = 0;
    getAllPathsHelper(s, d, visited, path, path_index,AllPaths); 
} 

void Graph::getAllPathsHelper(int u, int d, vector<bool> visited,vector<int> path, int &path_index,vector<vector<int> > &AllPaths) 
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
                getAllPathsHelper(*i, d, visited, path, path_index,AllPaths); 
    }  
    path_index--; 
    visited[u] = false;
}
void getNums(char* input,vector<int> &ans)
{
    string A;
    for(int i=0;i<strlen(input);i++)
    {
        if(input[i]==',')
        {
            ans.push_back(atoi(A.c_str()));
            A.clear();
        }
        else
        {
            A+= input[i];
        }
    }
    ans.push_back(atoi(A.c_str()));
}
bool checkLock(string A)
{
    if(A.size() <=1 )
        return true;
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
    vector<vector<int> > Paths;
    vector<int> A;
    vector<int> B;
    vector<int> C;
    getNums(input3.c_str(),A);
    getNums(input4.c_str(),B);
    getNums(input5.c_str(),C);
    string edgeLock(input6);
    int weight[105][105];
    string lock[105][105];
    Graph g(105);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            weight[i][j]=0;
            lock[i][j] = "";
        }
    }
    for(int i=0;i<A.size();i++)
    {
        g.addEdge(A[i],B[i]);
        weight[A[i]][B[i]] = C[i];
        weight[B[i]][A[i]] = C[i];
        lock[A[i]][B[i]] = edgeLock[i];
        lock[B[i]][A[i]] = edgeLock[i];
    }
    g.getAllPaths(0,1,Paths);
    if(Paths.size()==0)
        return -1;
    string curLock;
    int minDist = INT_MAX-100;
    int curDist = 0;
    vector<int> curPath;
    for(int i=0;i<Paths.size();i++)
    {
        curPath = Paths[i];
        curDist = 0;
        curLock = "";
        for(int j=0;j<curPath.size()-1;j++)
        {
            curDist += weight[curPath[j]][curPath[j+1]];
            curLock += lock[curPath[j]][curPath[j+1]];
        }
        if(checkLock(curLock))
        {
            minDist = min(minDist,curDist);
        }
    }
    if(minDist == INT_MAX-100)
        return -1;
    return minDist;
}