#include <bits/stdc++.h>
using namespace std;

int t[100010];

int main() {
   int T, d, D, N;
   scanf("%d", &T);
   while (T--) {
      scanf("%d %d", &D, &N);
      for (int i = 0; i < N; i++)
         scanf("%d", &t[i]);
      sort(t, t + N, greater<int>());
      int res = 0;
      d = 1;
      for (int i = 0; i < N; i++)
         if (t[i] < D - d)
            res++, d++;
      printf("%d\n", res);
   }//while
   return 0;
}//main
