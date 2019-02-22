#include <bits/stdc++.h>
using namespace std;

int fibo[100010];

int main() {
   int n;
   fibo[1] = 1;
   for (int i = 2; i <= 100000; i++)
      fibo[i] = (fibo[i - 1] + fibo[i - 2]) % 10;
   while (scanf("%d", &n) == 1)
      printf("%d\n", fibo[n]);
   return 0;
}//main
