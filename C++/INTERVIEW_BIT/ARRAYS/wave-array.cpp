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
vector<int> solve(vector<int> A)
{
	sort(A.begin(),A.end());
	int i = 0,j=1,n=A.size();
	while(i < n && j <n)
	{
		swap(A[i],A[j]);
		i+=2;
		j = i+1;
	}
	return A;
}
int main()
{
	cin.tie(0);
	cout.tie(0);

	int n;
	cin>>n;
	int temp;
	vector<int> input;
	for (int i = 0; i < n; i++)
	{
		cin>>temp;
		input.push_back(temp);
	}
	printVector(solve(input));
	return 0;
}