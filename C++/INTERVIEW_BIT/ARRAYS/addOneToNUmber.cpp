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
vector<int> solve(vector<int> A)
{
	if(A.size()==0)
	{
		return A;
	}
	while(A.size() > 1 && A[0]==0)
	{
		A.erase(A.begin());
	}
	
	A.insert(A.begin(),0);

	int i= A.size()-1;
	int temp;
	for ( i ; i >= 0 ; i--)
	{
		temp = A[i];
		temp +=1;
		A[i] = temp%10;
		if(temp < 10)
			break;
	}
	
	while(A.size() > 1 && A[0]==0)
	{
		A.erase(A.begin());
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