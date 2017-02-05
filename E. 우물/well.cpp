#include<stdio.h>
#include<algorithm>
#include<vector>
#include<functional>
#include<stdlib.h>
using namespace std;

#define all(A) (A).begin(), (A).end()
#define II(A) int (A); scanf("%d",&(A));
#define DBG if(1)
#define NDBG if(0)

typedef long long ll;
typedef pair<int,int> pii;

const int MN = 100000 + 100;

vector<int> E[MN];

int N, M;
int req[MN];
ll ans;

void apply(int n, int v){
	req[n] -= v;
	for(int t: E[n]){
		req[t] -= v;
	}
	ans += v;
}

void dfs(int n, int bef){
	int maxv = 0;
	for(int t: E[n]) if(t != bef){
		dfs(t, n);
		maxv = max(maxv, req[t]);
	}
	apply(n, maxv);
}

int main(){
	scanf("%d%d", &N, &M);
	if(N-1 != M){
		for(;;);
	}
	for(int i=0;i<N;i++){
		scanf("%d", &req[i]);
	}
	for(int i=0;i<M;i++){
		II(a)II(b); a--, b--;
		E[a].push_back(b), E[b].push_back(a);
	}
	dfs(0, -1);
	if(req[0] > 0){
		apply(0, req[0]);
	}
	printf("%lld\n", ans);
	return 0;
} 
