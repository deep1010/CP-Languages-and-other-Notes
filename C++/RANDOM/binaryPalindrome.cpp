#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define cin(a) scanf("%d",&a)
#define cinl(a) scanf("%lld",&a)
#define b begin
#define e end
#define f first
#define s second
#define vi vector<int>
#define vl vector<long long int>
#define INF IMT_MAX-100
#define pb push_ back
#define mp make_pair


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
	int n;
	cin>>n;
	int bitsLength = ceil(log2(n+1));
	int i=0;
	int j=bitsLength-1;
	int front = n;
	int back = n;
	int bitFront;
	int bitBack;bitFront
	int count = 0;
	while(j > i)
	{
		printf("j %d i %d\n",j,i);
		printf("front %d back %d\n",front,back);
		//find bitFront
		bitFront = front / (int)pow(2,j);
		front = front % (int)pow(2,j);
		j--;

		//find bitBack
		bitBack = back % 2;
		back /= 2;
		i++;
		printf("bitFront %d bitBack %d\n",bitFront,bitBack);
		//if not same cout -1 return 0;
		if(bitFront != bitBack)
		{
			cout<<"-1"<<endl;
			return 0;
		}

		else if (bitFront==1)
		{
			count+=2;
		}
	}
	if(j==i)
	{
		count += back %2;
	}
	cout<<count<<endl;
	return 0;
}