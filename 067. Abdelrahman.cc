#include <bits/stdc++.h>
using namespace std;

int main() {
   int T, N, M;
   scanf("%d", &T);
   for (int t = 1; t <= T; t++) {
      scanf("%d %d", &N, &M);
      printf("Case %d: %d\n", t, M - N + 1);
   }//for
   return 0;
}//main
