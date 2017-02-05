#include <cstdio>
int N, M, A[310][310],DP[310][310];
int max(int a, int b) {
	return a > b ? a : b;
}
int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			scanf("%d", &A[i][j]);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (i == 1 && j == 1)
				DP[i][j] = A[i][j];
			else
				DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]) + A[i][j];
		}
	}
	printf("%d\n", DP[N][M]);
	return 0;
}