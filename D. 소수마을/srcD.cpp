#include <stdio.h>
#include <math.h>
#include <functional>
#include <memory.h>
#include <queue>
#include <vector>
#include <map>
using namespace std;
bool isprime[10000];
vector<pair<int, int> > P;
vector<pair<int, int> > V[6000];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > Q;
int n;
int visited[4040];
int track[4040] = { 0, };
void findprime(){
	memset(isprime, true, sizeof(isprime));
	isprime[0] = false;
	isprime[1] = false;
	for (int i = 2; i < 10000; i++)
	{
		for (int j = i * 2; j < 10000; j += i)
		{
			isprime[j] = false;
		}
	}
}
int getlength(pair<int, int> a, pair<int, int> b){
	int dx = abs(a.first - b.first);
	int dy = abs(a.second - b.second);
	double len = sqrt((double)dx*dx + dy*dy);
	return (int)len;
}
void findAvailablePath(){
	for (int ii = 0; ii < P.size() - 1; ii++)
	{
		for (int j = ii + 1; j < P.size(); j++)
		{
			if (isprime[getlength(P[ii], P[j])]){
				V[ii].push_back(make_pair(getlength(P[ii], P[j]), j));
				V[j].push_back(make_pair(getlength(P[ii], P[j]), ii));
			}
		}
	}
}
int main(){
	fill(visited, visited + 4040, 987654321);
	getlength(make_pair(1, 2), make_pair(3, 6));
	findprime();

	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	P.push_back(make_pair(a, b));
	P.push_back(make_pair(c, d));
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		P.push_back(make_pair(a, b));
	}
	findAvailablePath();
	visited[0] = 0;
	Q.push(make_pair(0, 0));
	while (!Q.empty()){
		pair<int, int> cur = Q.top(); Q.pop();
		for (int i = 0; i < V[cur.second].size(); i++)
		{
			pair<int, int> there = V[cur.second][i];
			if (visited[there.second] > cur.first + there.first){
				visited[there.second] = cur.first + there.first;
				Q.push(make_pair(visited[there.second], there.second));
				track[there.second] = cur.second;
			}
		}
	}
	if (visited[1] == 987654321){
		printf("-1");
	}
	else{
		printf("%d", visited[1]);
	}
	return 0;
}