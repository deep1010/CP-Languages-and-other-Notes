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
int solve(vector<int> A)
{
    int n = A.size();
    if(n==0)
    {
        return 0;
    }
	vector<int> addIndex;
    vector<int> subIndex;
    for (int i = 0; i < n; i++)
    {
        addIndex.push_back(A[i]+i);
        subIndex.push_back(A[i]-i);
    }
    int ans1 = *max_element(addIndex.begin(),addIndex.end()) - *min_element(addIndex.begin(),addIndex.end());
    int ans2 = *max_element(subIndex.begin(),subIndex.end()) - *min_element(subIndex.begin(),subIndex.end());
    return max(ans1,ans2);
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
	cout<<solve(input)<<endl;
	return 0;
}

55 -8 43 52 8 59 -91 -79 -18 -94