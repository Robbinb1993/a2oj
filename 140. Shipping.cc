#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;

int N;

int solve2(const int v) {
   int curr = INF;
   for (int i = 1; i <= v; i++)
      if (v % i == 0)
         curr = min(curr, i + v / i);
   return curr;
}//solve2

int solve() {
   int best = INF;
   for (int i = 1; i <= N; i++)
      if (N % i == 0)
         best = min(best, N / i + solve2(i));
   return best;
}//solve

int main() {
   int T;
   scanf("%d", &T);
   while (T--) {
      scanf("%d", &N);
      printf("%d\n", solve());
   }//while
   return 0;
}//main
