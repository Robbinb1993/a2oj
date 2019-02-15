#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int A[100010];

int main() {
   int T, N, curr;
   LL res;
   scanf("%d", &T);
   while (T--) {
      scanf("%d", &N);
      for (int i = 0; i < N; i++)
         scanf("%d", &A[i]);
      curr = res = 0;
      for (int i = 1; i < N; i++) {
         res += min(A[i], curr);
         int nxt = -1;
         if (A[i] < curr)
            nxt = A[i];
         A[i] = max(0, A[i] - curr);
         if (nxt != -1)
            curr = nxt;
         int toRem = min(A[i - 1], A[i]);
         res += 2 * toRem;
         curr += toRem;
         A[i] -= toRem;
      }//for
      printf("%lld\n", res);
   }//while
   return 0;
}//main
