#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mini(ll a, ll b){return a<b?a:b;}
ll maxi(ll a, ll b){return a>b?a:b;}
int solve(vector<int> A, vector<int> B, vector<int> C)
{
	int i=0,j=0,k=0;
	int a,b,c;
	int ans = abs(max(A[0],max(B[0],C[0])) - min(A[0],min(B[0],C[0])));
	int x = A.size();
	int y = B.size();
	int z = C.size();
	while(i < x && j<y && k<z)
	{
		a=A[i];
		b=B[j];
		c=C[k];
		ans = min(ans,abs(max(a,max(b,c)) - min(a,min(b,c))));
		// cout<<a<<" "<<b<<" "<<c<<" "<<ans<<endl;
		if(a<=b && a<=c)
			i++;
		else if (b<=a && b<=c)
			j++;
		else
			k++;
	}
	return ans;
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	vector<int> A,B,C;
	int n;
	int temp;
	for (int i = 0; i < 3; i++)
	{
		cin>>n;
		for (int j = 0; j < n; j++)
		{
			cin>>temp;
			if(i==0)
				A.push_back(temp);
			else if(i==1)
				B.push_back(temp);
			else
				C.push_back(temp);
		}
		
	}
	cout<<solve(A,B,C)<<endl;
	return 0;
}