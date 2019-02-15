#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;

vector<int> V;
int G[130][130];
int n, m;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int floodFill(const int x, const int y, const int v) {
   int tot = 1;
   G[x][y] = 0;
   for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx >= 0 && nx < n && ny >= 0 && ny < m && G[nx][ny] == v)
         tot += floodFill(nx, ny, v);
   }//for
   return tot;
}//floodFill

int main() {
   int T, N, v, b, res;
   scanf("%d", &T);
   while (T--) {
      scanf("%d %d", &n, &m);
      for (int i = 0; i < n; i++)
         for (int j = 0; j < m; j++)
            scanf("%d", &G[i][j]);
      scanf("%d", &N);
      V.clear();
      while (N--) {
         scanf("%d", &v);
         V.push_back(v);
      }//while
      scanf("%d", &b);
      sort(V.begin(), V.end());
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < m; j++) {
            vector<int>::iterator it = lower_bound(V.begin(), V.end(), G[i][j]);
            int diff = INF;
            if (it != V.end()) {
               diff = abs(*it - G[i][j]);
               v = *it;
            }//if
            if (it != V.begin()) {
               it--;
               if (abs(*it - G[i][j]) <= diff)
                  G[i][j] = *it;
               else
                  G[i][j] = v;
            }//if
            else
               G[i][j] = v;
         }//for
      }//for
      res = 0;
      for (int i = 0; i < n; i++)
         for (int j = 0; j < m; j++)
            if (G[i][j])
               if (floodFill(i, j, G[i][j]) >= b)
                  res++;
      printf("%d\n", res);
   }//while
   return 0;
}//main
