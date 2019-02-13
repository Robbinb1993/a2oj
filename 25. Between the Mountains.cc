#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;

vector<int> V[2];

int main() {
   int T, N, v, idx, best;
   scanf("%d", &T);
   while (T--) {
      V[0].clear(); V[1].clear();
      for (int i = 0; i < 2; i++) {
         scanf("%d", &N);
         for (int j = 0; j < N; j++) {
            scanf("%d", &v);
            V[i].push_back(v);
         }//for
         sort(V[i].begin(), V[i].end());
      }//for
      idx = 0;
      best = INF;
      for (int i = 0; i < V[0].size(); i++) {
         while (idx + 1 < (int)V[1].size() && V[1][idx + 1] <= V[0][i])
            idx++;
         best = min(best, abs(V[0][i] - V[1][idx]));
         if (idx + 1 < (int)V[1].size())
            best = min(best, abs(V[0][i] - V[1][idx + 1]));
      }//for
      printf("%d\n", best);
   }//while
   return 0;
}//main
