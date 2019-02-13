#include <bits/stdc++.h>
using namespace std;

int main() {
   int T, N, M;
   char S[30];
   scanf("%d", &T);
   while (T--) {
      scanf("%d %d", &N, &M);
      M %= 26;
      for (int i = 0; i < N; i++) {
         scanf(" %s", S);
         for (int j = 0; S[j]; j++) {
            if (islower(S[j]))
               S[j] = (S[j] - 'a' + M) % 26 + 'A';
            else
               S[j] = (S[j] - 'A' + M) % 26 + 'a';
         }//for
         printf("%s", S);
         if (i != N - 1)
            printf(" ");
      }//for
      puts("");
   }//while
   return 0;
}//main
