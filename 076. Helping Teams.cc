#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

int N, M;
int from[20], to[20], ret[20], amount[20], interest[20], idx[20];
int best;
vector<ii> V;

bool pos(int bm) {
   int st = bm;
   int curr = M;
   priority_queue<ii, vector<ii>, greater<ii> > Q;
   while (bm) {
      int b = bm & -bm;
      int v = idx[__builtin_ctz(b)];
      while (!Q.empty() && to[v] >= Q.top().first)
         curr += amount[Q.top().second] + interest[Q.top().second], Q.pop();
      curr -= amount[v];
      if (curr < 0)
         return 0;
      Q.push(ii(ret[v], v));
      bm -= b;
   }//while
   return 1;
}//pos

int main() {
   int T;
   scanf("%d", &T);
   for (int t = 1; t <= T; t++) {
      V.clear();
      best = 0;
      scanf("%d %d", &N, &M);
      for (int i = 0; i < N; i++) {
         scanf("%d %d %d %d %d", &from[i], &to[i], &amount[i], &ret[i], &interest[i]);
         V.push_back(ii(to[i], i));
      }//for
      sort(V.begin(), V.end());
      for (int i = 0; i < N; i++)
         idx[i] = V[i].second;
      for (int i = 1; i < (1 << N); i++) {
         int curr = __builtin_popcount(i);
         if (curr > best)
            if (pos(i))
               best = curr;
      }//for
      printf("Case %d: %d\n", t, best);
   }//for
   return 0;
}//main
