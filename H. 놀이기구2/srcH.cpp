#include<stdio.h>
#include<algorithm>
#include<vector>
#include<functional>
#include<stdlib.h>
#include<queue>
using namespace std;

#define all(A) (A).begin(), (A).end()
#define II(A) int (A); scanf("%d",&(A));
#define DBG if(1)
#define NDBG if(0)

typedef long long ll;
typedef pair<int,int> pii;

const int MN = 200000 + 10;

int N, M, K, Q;
int lim[MN];
int who[MN];
int height[MN];
int satisfied[MN];

struct QUERY{
	int i, j, k;
}query[MN];

int half(int q){
	return (lim[query[q].k] - height[query[q].i] - height[query[q].j] + 1) / 2;
}

struct PQ{
	int q, v;
	PQ(){}
	PQ(int q, int v):q(q),v(v){}
	bool operator <(PQ A)const{
		return v > A.v;
	}
};

priority_queue<PQ> pq[MN];
int ans[MN];

int main(){
	scanf("%d%d%d%d", &N, &M, &K, &Q);
	for(int i=0;i<M;i++){
		scanf("%d", &lim[i]);
	}
	for(int i=0;i<K;i++){
		scanf("%d", &who[i]); who[i]--;
	}
	for(int i=0;i<Q;i++){
		scanf("%d%d%d", &query[i].i, &query[i].j, &query[i].k);
		query[i].i--, query[i].j--, query[i].k--;
		pq[query[i].i].emplace(i, half(i));
		pq[query[i].j].emplace(i, half(i));
	}
	for(int i=0;i<K;i++){
		if(i > 0){
			ans[i] = ans[i-1];
		}
		int n = who[i];
		height[n]++;
		if(i > 1 && ans[i-1] > ans[i-2]){
			height[n]++;
		}
		while(!pq[n].empty()){
			auto info = pq[n].top();
			if(height[n] < info.v){
				break;
			}
			pq[n].pop();
			if(half(info.q) <= 0){
				if(!satisfied[info.q]){
					satisfied[info.q] = 1;
					ans[i]++;
				}
			}
			else{
				pq[query[info.q].i].emplace(info.q, height[query[info.q].i] + half(info.q));
				pq[query[info.q].j].emplace(info.q, height[query[info.q].j] + half(info.q));
			}
		}
		printf("%d\n", ans[i]);
	}
	return 0;
} 
