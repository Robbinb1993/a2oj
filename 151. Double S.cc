#include <bits/stdc++.h>
using namespace std;

int k, n;
int DP[1001][10];
int val[10];
int id = 0;

bool solve(const int idx, const int v) {
   if (v == k)
      return 1;
   if (idx == n || v > k || DP[v][idx] == id)
      return 0;
   DP[v][idx] = id;
   if (solve(idx + 1, v))
      return 1;
   if (solve(idx + 1, v + val[idx]))
      return 1;
}//solve

int main() {
   int T;
   scanf("%d", &T);
   while (T--) {
      scanf("%d %d", &k, &n);
      bool flag = 0;
      for (int j = 0; j < n; j++) {
         scanf("%d", &val[j]);
         flag |= !val[j];
      }//for
      id++;
      if (!k)
         flag ? puts("YES") : puts("NO");
      else
         solve(0, 0) ? puts("YES") : puts("NO");
   }//while
   return 0;
}//main
