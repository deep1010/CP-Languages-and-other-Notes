#include "stdc++.h"
using namespace std;
void build(vector<int> &tree,vector<int> &input,int par,int l,int r)
{
  if(l==r)
  {
    tree[par] = input[l];
  }
  else
  {
    int m = (l+r)/2;
    build(tree,input,2*par+1,l,m);
    build(tree,input,2*par+2,m+1,r);
    tree[par] = min(tree[2*par+1],tree[2*par+2]);
  }
}
void update(vector<int> &tree,vector<int> &input,int par,int l,int r,int idx,int val)
{
  // cout<<"l\tr\tidx\tval\n";
  // cout<<l<<"\t"<<r<<"\t"<<idx<<"\t"<<val<<"\n";
  if(idx > r || idx < l)
    return;
  if(l==r && l==idx)
  {
    tree[par] = val;
    input[l] = val;
  }
  else
  {
    int m = (l+r)/2;
    update(tree,input,2*par+1,l,m,idx,val);
    update(tree,input,2*par+2,m+1,r,idx,val);
    tree[par] = min(tree[2*par+1],tree[2*par+2]);
  }
}
int query(vector<int> &tree,int par,int l,int r,int start,int end)
{
  // start - end is the range covered by tree's node.
  // l - r is the rnge of given query.
  if(l > end || r < start)
  {
    return INT_MAX;
  }
  if(l<=start && end <= r)
  {
    return tree[par];
  }
  else
  {
    int mid = (start + end)/2;
    int q1 = query(tree,2*par+1,l,r,start,mid);
    int q2 = query(tree,2*par+2,l,r,mid+1,end);
    return min(q1,q2);
  }
}
void printTree(vector<int> &tree)
{
  cout<<"\n\n\n=========Printing Tree=========\n\n\n";
  int t = 0;
  // cout<<tree[0]<<endl;
  for (size_t i = 0; i < tree.size(); i++)
  {
    cout<<tree[i]<<" ";
    if(i==t)
    {
      cout<<endl;
      t++;
      t*=2;
    }
  }
  cout<<endl;
}
int main()
{
  int n,q;
  int temp;
  vector<int> input;
  cin>>n>>q;
  for (size_t i = 0; i < n; i++) {
    cin>>temp;
    input.push_back(temp);
  }
  int t=1;
  while(t < n)
  {
    t*=2;
  }
  while(n < t)
  {
    input.push_back(INT_MAX);
    n++;
  }
  vector<int> tree;
  tree.assign(2*n-1,0);
  build(tree,input,0,0,n-1);
  // cout<<"input size "<<input.size()<<" tree size "<<tree.size()<<endl;
  // printTree(tree);
  int l,r;
  char operation;
  for(int i=0;i<q;i++)
  {
    cin>>operation>>l>>r;
    if(operation == 'u')
    {
      update(tree,input, 0, 0, n-1, l-1, r);
      // printTree(tree);
    }
    else
    {
      cout<<query(tree, 0, l-1, r-1, 0, n-1)<<endl;
    }
  }
  return 0;
}
