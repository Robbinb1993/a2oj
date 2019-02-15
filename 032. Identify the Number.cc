#include <bits/stdc++.h>
using namespace std;

char S[20];
int R, Q;
int best;

void solve(const int idx, const int v) {
   if (!S[idx]) {
      if (v % Q == R)
         best = max(best, v);
      return;
   }//if
   solve(idx + 1, v * 10 + S[idx] - '0');
   solve(idx + 1, v);
}//solve

int main() {
   int T;
   scanf("%d", &T);
   while (T--) {
      scanf("%s %d %d", S, &R, &Q);
      best = -1;
      solve(0, 0);
      if (best == -1)
         puts("Not found");
      else
         printf("%d\n", best);
   }//while
   return 0;
}//main
