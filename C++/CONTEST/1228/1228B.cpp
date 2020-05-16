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
int pow_mod(int A, int B, int C) {
    if(B==0)
        return 1%C;
    long long int y;
    if(B&1)
    {
        y = (A%C);
        y = (y * pow_mod(A,B-1,C)) % C;
    }
    else
    {
        y = pow_mod(A,B/2,C) % C;
        y = (y * y) % C;
    }
    return (int)(y+C)%C;
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	int h,w;
	cin>>h>>w;
	int row[h+5];
	int col[w+5];
	int rem = 0;
	for (int i = 0; i < h; i++)
	{
		cin>>row[i];
	}
	for (int i = 0; i < w; i++)
	{
		cin>>col[i];
	}
	int acc_row;
	int acc_col;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if(j == row[i] )
				acc_row = 0;
			else if(j < row[i])
				acc_row = 1;
			else
				acc_row = 2;

			if(i == col[j])
				acc_col = 0;
			else if(i < col[j])
				acc_col = 1;
			else
				acc_col = 2;

			if((acc_col == 1 && acc_row == 0) || (acc_col == 0 && acc_row == 1))
			{
				cout<<0<<endl;
				return 0;
			}
			else if(acc_col==2 && acc_row==2)
			{
				rem++;
			}
			
		}
	}
	// if(rem==0)
	// 	cout<<0<<endl;
	// else
	// {
		cout<<pow_mod(2,rem,1000000007)<<endl;
	// }
		
	
	
	return 0;
}