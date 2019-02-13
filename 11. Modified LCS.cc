#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int gcd(int a, int b) {
   return b == 0 ? a : gcd(b, a % b);
}

int main() {
   int T;
   scanf("%d", &T);
   ll N1, F1, D1, N2, F2, D2;

   int v1, v2;
   int g, steps1, steps2;

   while (T--) {
      scanf("%lld %lld %lld %lld %lld %lld", &N1, &F1, &D1, &N2, &F2, &D2);

      v1 = F1;
      v2 = F2;
      while (v1 != v2) { //find first common element (which exists and is <= 1e6 according to problem statement)
         if (v1 < v2)
            v1 += D1;
         else
            v2 += D2;
      }//while

      N1 -= (v1 - F1) / D1 + 1;
      N2 -= (v1 - F2) / D2 + 1;

      g = gcd(D1, D2);
      steps1 = D2 / g; //steps until next common element
      steps2 = D1 / g;

      printf("%lld\n", 1 + min(N1 / steps1, N2 / steps2));
   }//while
   return 0;
}//main
