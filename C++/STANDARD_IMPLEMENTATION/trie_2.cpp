#include "stdc++.h"
using namespace std;
struct Node
{
  struct Node* children[26];
  bool isLeaf;
  bool noChild;
  int weight;
};

Node* getNode()
{
  Node* newNode = new Node;
  newNode->weight = -1;
  newNode->isLeaf = false;
  newNode->noChild = true;
  for (size_t i = 0; i < 26; i++) {
    newNode->children[i] = NULL;
  }
  return newNode;
}

void insert(Node* root,string toInsert,int weight)
{
  Node* head = root;
  char c;
  for(int i=0;i<toInsert.size();i++)
  {
    c = toInsert[i];
    if(head->children[c-'a'] == NULL)
    {
      head->children[c-'a'] = getNode();
      head->noChild = false;
    }
      head = head->children[c-'a'];
  }
  head->isLeaf = true;
  head->weight = weight;
}
pair<int,Node*> search(Node* root,string toSearch)
{
  Node* head = root;
  char c;
  Node *temp = getNode();
  for(int i=0;i<toSearch.size();i++)
  {
    c = toSearch[i];
    if(head->children[c-'a']==NULL)
    {
      return make_pair(0,temp);
    }
    head = head->children[c-'a'];
  }
  if(head->isLeaf)
  {
    return make_pair(1,head);
  }
  else
    return make_pair(2,head);
}
void getSuggestionHelper(Node* root,string &prefix,int &maxWeight)
{
  if(root->isLeaf)
  {
    maxWeight = max(maxWeight,root->weight);
  }
  if(root->noChild)
    return;
  else
  {
    for (size_t i = 0; i < 26; i++) {
      if(root->children[i])
      {
        prefix.push_back('a'+i);
        getSuggestionHelper(root->children[i],prefix,maxWeight);
        prefix.pop_back();
      }
    }
  }
  return;
}
int getSuggestion(Node* root,string query)
{
  int maxWeight;
  pair<int,Node*> response = search(root,query);
  if(response.first==0)
  {
    maxWeight = -1;
  }
  else
  {
    maxWeight = response.second->weight;
    string prefix = query;
    getSuggestionHelper(response.second,prefix,maxWeight);
  }
  return maxWeight;
}
int main()
{
  Node* root = getNode();
	int n,q,w;
  string s;
  cin>>n>>q;
  for (size_t i = 0; i < n; i++) {
    cin>>s>>w;
    insert(root,s,w);
  }
  map<string,int> qMap;
  for (size_t i = 0; i < q; i++) {
    cin>>s;
    if(qMap.find(s)==qMap.end())
    {
        int temp = getSuggestion(root,s);
        qMap.insert(make_pair(s,temp));
        cout<<temp<<endl;
    }
    else
    {
        cout<<qMap[s]<<endl;
    }
  }
  return 0;
}
