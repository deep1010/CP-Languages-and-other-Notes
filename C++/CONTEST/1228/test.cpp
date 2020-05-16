// C++ program to print all primes smaller than or equal to 
// n using Sieve of Eratosthenes 
#include <bits/stdc++.h> 
using namespace std; 
long long int p=1;
long long int mod = 1000000007;
long long int gcd(int a, int b) 
{ 
    if (b == 0)
    {
        p = (p %mod)* (a%mod);
        p = p % mod; 
        return a;
    }
    long long int x = gcd(b, a % b);
    p = (p%mod) * (x%mod);
    p = p%mod;
    return x;
      
} 
int main() 
{ 
	int x,n;
    cin>>x>>n;
    long long int x_ = gcd(x,n);
    cout<<p<<endl;
	return 0; 
} 
