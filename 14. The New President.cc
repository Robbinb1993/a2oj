#include <bits/stdc++.h>
using namespace std;
const int MAXN = 110;
typedef pair<int, int> ii;

int main() {
   int T, C, V, v;
   vector<vector<int> > votes;
   vector<ii> ranking;
   scanf("%d", &T);
   while (T--) {
      scanf("%d %d", &C, &V);
      votes = vector<vector<int> >(V + 1, vector<int>());
      ranking = vector<ii>(C, ii(0, 0));
      for (int i = 0; i < C; i++)
         ranking[i].second = i + 1;

      for (int i = 0; i < V; i++) {
         for (int j = 0; j < C; j++) {
            scanf("%d", &v);
            v--;
            if (!j)
               ranking[v].first++;
            votes[i].push_back(v);
         }//for
      }//for

      sort(ranking.begin(), ranking.end(), greater<ii>());
      if (ranking[0].first * 2 > V)
         printf("%d %d\n", ranking[0].second, 1);
      else {
         for (int i = 0; i < V; i++) {
            for (int j = 0; j < C; j++) {
               v = votes[i][j];
               if (v + 1 == ranking[0].second) {
                  if (j)
                     ranking[0].first++;
                  break;
               }//if
               if (v + 1 == ranking[1].second) {
                  if (j)
                     ranking[1].first++;
                  break;
               }//if
            }//for
         }//for
         printf("%d %d\n", ranking[0].first > ranking[1].first ? ranking[0].second : ranking[1].second, 2);
      }//else
   }//while
   return 0;
}//main
