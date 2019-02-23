#include <bits/stdc++.h>
using namespace std;

int A[1010][1010];
int DP[1010][1010];

int main() {
   int T, N, M;
   scanf("%d", &T);
   while (T--) {
      scanf("%d %d", &N, &M);
      for (int i = 0; i < N; i++)
         for (int j = 0; j < M; j++)
            scanf("%d", &A[i][j]);
      int best = A[N - 1][M - 1];
      for (int j = 0; j <= M; j++)
         DP[N][j] = 0;
      for (int i = N - 1; i >= 0; i--) {
         DP[i][M] = 0;
         for (int j = M - 1; j >= 0; j--) {
            DP[i][j] = A[i][j] + DP[i][j + 1] + DP[i + 1][j] - DP[i + 1][j + 1];
            best = max(best, DP[i][j]);
         }//for
      }//for
      printf("%d\n", best);
   }//while
   return 0;
}//main
