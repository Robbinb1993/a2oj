#include <bits/stdc++.h>
using namespace std;

int main() {
   int T, n;
   scanf("%d", &T);
   while (T--) {
      scanf("%d", &n);
      for (int i = 1000000 - n; i < 1000000; i++)
         printf("%d ", i);
      puts("");
   }//while
   return 0;
}//main
