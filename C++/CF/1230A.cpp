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

int main()
{
	cin.tie(0);
	cout.tie(0);
	int a[4];
	
	cin>>a[0]>>a[1]>>a[2]>>a[3];
	sort(a,a+4);

	if(a[0]+a[3] == a[1]+a[2] || a[3] == a[1]+a[2]+a[0])
		cout<<"YES\n";
	else
		cout<<"NO\n";	
	
	return 0;
}