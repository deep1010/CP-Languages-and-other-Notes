#include <stdio.h>
#include <limits.h>
int solve(int dp[][], int dimension[], int start, int end)
{
	return 0;
}
int main()
{

	int n;
	scanf("%d", &n);
	int dimension[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &dimension[i]);
	}
	long long int dp[n + 1][n + 1];
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			dp[i][j] = 0;
		}
	}
	int x = solve(dp, dimension, 0, n - 1);
	printf("%d\n",x);
	return 0;
}