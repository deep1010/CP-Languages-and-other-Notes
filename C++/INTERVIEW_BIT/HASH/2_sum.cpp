#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

template<typename T>
void printVector(const T& t) {
	for (int i = 0; i < t.size(); i++)
	{
		cout<<t[i]<<" ";
	}
	cout<<endl;
}
vector<int> solve(vector<int> A,int B)
{
	int n = A.size();
	vector<int> ans;
	map < int,int> indexMap;
	for (int i = 0; i < n; i++)
	{
		if ( indexMap.find(A[i]) == indexMap.end() )
		{
			indexMap.insert( make_pair(A[i],i+1) );
		}
	}
	vector< pair<int,int> > vp;
	int id1,id2;
	for (int i = 0; i < n; i++)
	{
		if (indexMap.find(B-A[i]) != indexMap.end() )
		{
			id1 = max(i+1,indexMap[B-A[i]]);
			id2 = min(i+1,indexMap[B-A[i]]);
			if(id1 != id2)
				vp.push_back(make_pair(id1,id2));
		}
	}
	if(vp.size() > 0)
	{
		sort(vp.begin(),vp.end());
		ans.push_back(vp[0].second);
		ans.push_back(vp[0].first);
	}
	return ans;
	
}
int main()
{
	cin.tie(0);
	cout.tie(0);

	int n,target;
	cin>>n>>target;
	int temp;
	vector<int> input;
	for (int i = 0; i < n; i++)
	{
		cin>>temp;
		input.push_back(temp);
	}
	printVector(solve(input,target));
	

	return 0;
}