#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

template<typename T>
void printVector(const T& t) {
	if(t.size()==0)
	{
		cout<<"Empty Vector\n";
		return;
	}
	for (int i = 0; i < t.size(); i++)
	{
		cout<<t[i]<<" ";
	}
	cout<<endl;
}
int binarySearch(vector<ll> A,ll target)
{
	int low = 0;
	int high = A.size()-1;
	int mid;
	while(low<=high)
	{
		mid = (low + high)/2;
		if(A[mid]==target)
		{
			return mid;
		}
		else if(A[mid] > target)
		{
			high = mid-1;
		}
		else
		{
			low = mid+1;
		}
	}
	return -1;
}
vector<ll> solve(vector<ll> A)
{
	int n= A.size();
	sort(A.begin(),A.end());
	vector<int> inDegree;
	vector<ll> ans;
	inDegree.assign(n,0);
	int idx;
	for (int i = 0; i < n; i++)
	{
		idx = binarySearch(A,A[i]*2LL);
		if(idx != -1)
		{
			inDegree[idx]++;
		}
		else if(A[i]%3==0)
		{
			idx = binarySearch(A,A[i]/3);
			if(idx != -1)
			{
				inDegree[idx]++;
			}
		}
	}
	int start_idx=0;
	for (int i = 0; i < n; i++)
	{
		if(inDegree[i]==0)
		{
			start_idx = i;
			break;
		}
	}
	for (int i = 0; i < n; i++)
	{
		ans.push_back(A[start_idx]);
		idx = binarySearch(A,A[start_idx]*2LL);
		if(idx != -1)
		{
			start_idx = idx;
		}
		else if(A[start_idx]%3==0)
		{
			idx = binarySearch(A,A[start_idx]/3);
			if(idx != -1)
			{
				start_idx = idx;
			}
		}	
	}
	return ans;
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	int n;
	ll temp;
	vector<ll> input;
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		cin>>temp;
		input.push_back(temp);
	}
	printVector(solve(input));
	return 0;
}