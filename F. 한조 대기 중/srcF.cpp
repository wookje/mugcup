#include <stdio.h>
#include <vector>
#include <memory.h>

using namespace std;

vector<int> A[501], B[501];
int visitedA[501], visitedB[501];
bool chkA[501], chkB[501];

bool gogoA(int a)
{
	for (auto b : A[a])
	{
		if (chkA[b]) continue;
		chkA[b] = true;
		if (visitedA[b] == -1 || gogoA(visitedA[b]))
		{
			visitedA[b] = a;
			return true;
		}
	}
	return false;
}

bool gogoB(int a)
{
	for (auto b : B[a])
	{
		if (chkB[b]) continue;
		chkB[b] = true;
		if (visitedB[b] == -1 || gogoB(visitedB[b]))
		{
			visitedB[b] = a;
			return true;
		}
	}
	return false;
}

int main()
{
	int N, M, K1, K2;

	scanf("%d %d %d %d", &N, &M, &K1, &K2);
	for (int i = 0; i < K1; ++i)
	{
		int a, b;
		scanf("%d %d", &a, &b); --a, --b;
		A[a].push_back(b);
	}
	for (int i = 0; i < K2; ++i)
	{
		int a, b;
		scanf("%d %d", &a, &b); --a, --b;
		B[a].push_back(b);
	}

	int res1 = 0, res2 = 0;
	memset(visitedA, -1, sizeof(visitedA));
	memset(visitedB, -1, sizeof(visitedB));
	for (int i = 0; i < N; ++i)
	{
		memset(chkA, 0, sizeof(chkA));
		memset(chkB, 0, sizeof(chkB));
		if (gogoA(i)) ++res1;
		if (gogoB(i)) ++res2;
	}

	if (res1 < res2) printf("네 다음 힐딱이");
	else printf("그만 알아보자");

	return 0;
}