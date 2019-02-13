#include <bits/stdc++.h>
using namespace std;

int DP[100010][101];
int stones[101];
int y, n;

void solve(const int sum, const int idx) {
   if (DP[sum][idx])
      return;
   DP[sum][idx] = 1;
   if (idx == n)
      return;
   solve(sum + stones[idx], idx + 1);
   solve(sum, idx + 1);
}//solve

int main() {
   int T;
   scanf("%d", &T);
   while (T--) {
      scanf("%d %d", &y, &n);
      for (int i = 0; i < n; i++)
         scanf("%d", &stones[i]);
      memset(DP, 0, sizeof(DP));
      solve(0, 0);
      for (int i = 1; i <= 100000; i++)
         if (DP[i][n])
            printf("%d\n", i + y);
   }//while
   return 0;
}//main
