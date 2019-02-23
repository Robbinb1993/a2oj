 #include <bits/stdc++.h>
 using namespace std;

int main() {
   int T, N, X, Y, tot, last;
   scanf("%d", &T);
   while (T--) {
      scanf("%d %d %d", &N, &X, &Y);
      tot = 1;
      for (int i = 1; i < X && i <= N - 1; i++)
         printf("%d ", i), tot++;
      if (Y == 1)
         printf("%d", last = min(X + 1, N != X ? N : X + 1));
      else
         printf("%d", X), last = X;
      for (int i = last + 1; tot < N; i++)
         printf(" %d", i), tot++;
      puts("");
   }//while
   return 0;
}//main
