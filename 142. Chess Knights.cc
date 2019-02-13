#include <bits/stdc++.h>
using namespace std;

int n, m;
const int dx[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
const int dy[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
bool seen[210][210];
int res;

void DFS(const int x, const int y) {
   res++;
   seen[x][y] = 1;
   for (int i = 0; i < 8; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !seen[nx][ny])
         DFS(nx, ny);
   }//for
}//DFS

int main() {
   int T, x, y;
   scanf("%d", &T);
   while (T--) {
      scanf("%d %d %d %d", &n, &m, &x, &y);
      res = 0;
      memset(seen, 0, sizeof(seen));
      DFS(x, y);
      printf("%d\n", res);
   }//while
   return 0;
}//main
