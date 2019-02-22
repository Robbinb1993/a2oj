#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int LOGN = 17;
const int MAXN = 100002;

int N;
int level[MAXN];
int DP[LOGN][MAXN];
bool seen[MAXN];
vvi edges;

void DFS0(const int u) {
   seen[u] = 1;
   for (int i = 0; i < (int)edges[u].size(); i++) {
      int e = edges[u][i];
      if (!seen[e]) {
         DP[0][e] = u;
         level[e] = level[u] + 1;
         DFS0(e);
      }//if
   }//for
}//DFS0

void prep() {
   memset(seen, 0, sizeof(bool) * (N + 1));
   level[1] = 0;
   for (int i = 0; i < LOGN; i++)
      DP[i][1] = 1;
   DFS0(1);
   for (int i = 1; i < LOGN; i++)
      for (int j = 1; j <= N; j++)
         DP[i][j] = DP[i - 1][DP[i - 1][j]];
}//prep

int LCA(int a, int b) {
   if (level[a] > level[b])
      swap(a, b);
   int diff = level[b] - level[a];
   for (int i = 0; i < LOGN; i++)
      if (diff & (1 << i))
         b = DP[i][b]; //move 2^i parents upwards
   if (a == b)
      return a;
   for (int i = LOGN - 1; i >= 0; i--)
      if (DP[i][a] != DP[i][b])
         a = DP[i][a], b = DP[i][b];
   return DP[0][a];
}//LCA

void fr(int &to) {
   char t; to ^= to;
   while (!isdigit((t = getchar_unlocked())));
   while (t > 47) { to = (to << 3) + (to << 1) + t - 48; t = getchar_unlocked(); }
}//fr

int main() {
   int T, Q, n1, n2;
   fr(T);
   for (int t = 1; t <= T; t++) {
      printf("Case %d:\n", t);
      fr(N); fr(Q);
      edges.assign(N + 1, vector<int>());
      for (int i = 0; i < N - 1; i++) {
         fr(n1); fr(n2);
         edges[n1].push_back(n2);
         edges[n2].push_back(n1);
      }//for
      prep();
      while (Q--) {
         fr(n1); fr(n2);
         int lca = LCA(n1, n2);
         printf("%d\n", level[n1] - level[lca] + level[n2] - level[lca]);
      }//while
   }//for
   return 0;
}//main

