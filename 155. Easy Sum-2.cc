#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mod = 33554431;

int fastpw(LL base, int pw) {
   LL res = 1;
   while (pw) {
      if (pw & 1)
         res = (res * base) % mod;
      base = (base * base) % mod;
      pw >>= 1;
   }//while
   return res;
}//fastpw

int main() {
   int T, N;
   scanf("%d", &T);
   while (T--) {
      scanf("%d", &N);
      int res = fastpw(2, N + 1) - 1;
      if (res < 0)
         res += mod;
      printf("%d\n", res);
   }//while
   return 0;
}//main
