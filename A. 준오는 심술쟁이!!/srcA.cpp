#include <iostream>
#include <string>

#define min(x, y) ((x)<(y)?(x):(y))

using namespace std;

typedef long long ll;

const int MOD = 1000000007;
const int MAX_LEN = 3000;
const int MAX_SUM = 3000;

int s;
int dp[MAX_LEN + 1][MAX_SUM + 1]; //글자수, s개수
string str;

int main()
{
	cin >> s;
	cin >> str;

	int len = str.length();

	/*int len_i, s_j;
	for (len_i = 1; len_i <= MAX_LEN; ++len_i) dp[len_i][0] = 1;
	for (s_j = 0; s_j <= 25; ++s_j) dp[1][s_j] = 1;
	for (len_i = 2; len_i <= MAX_LEN; ++len_i)
	{
		int limit_s = min(len_i * 25, MAX_SUM);
		for (s_j = 1; s_j <= limit_s; ++s_j)
		{
			int limit_k = min(25, s_j);
			for (int k = 0; k <= limit_k; k++)
			{
				dp[len_i][s_j] += dp[len_i - 1][s_j - k];
				dp[len_i][s_j] %= MOD;
			}
		}
	}*/

	int len_i, s_j;
	for (len_i = 1; len_i <= MAX_LEN; ++len_i) dp[len_i][0] = 1;
	for (s_j = 0; s_j <= 25; ++s_j) dp[1][s_j] = 1;
	for (len_i = 2; len_i <= MAX_LEN; ++len_i)
	{
		int limit_s = min(len_i * 25, MAX_SUM);
		for (s_j = 1; s_j <= limit_s; ++s_j)
		{
			ll temp = (dp[len_i - 1][s_j] + dp[len_i][s_j - 1]);
			if (s_j > 25) temp = temp - dp[len_i - 1][s_j - 26] + MOD;
			dp[len_i][s_j] = temp % MOD;
		}
	}

	cout << dp[len][s];

	return 0;
}