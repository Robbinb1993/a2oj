#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e5;

char S[MAXN + 1];
int sum[MAXN + 1];

int main() {
   int T, N, K, Q, prv;
   char f;
   scanf("%d", &T);
   for (int t = 1; t <= T; t++) {
      printf("Case %d:\n", t);
      scanf(" %s", S);
      N = strlen(S);
      scanf("%d %d", &K, &Q);
      while (Q--) {
         scanf(" %c", &f);
         prv = 0;
         for (int i = 1; i <= N; i++)
            sum[i] = sum[i - 1] + (S[i - 1] == f);
         LL res = 0;
         for (int i = K; i <= N; i++) {
            if (sum[i] - sum[i - K] == K) {
               res += (i - K + 1 - prv) * LL(N - i + 1);
               prv = i - K + 1;
            }//if
         }//for
         printf("%lld\n", res);
      }//while
   }//for
   return 0;
}//main
