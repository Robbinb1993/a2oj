#include <iostream>
#include "stdio.h"
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
   int T;
   ll possibilities, counter;
   char start;
   string s;
   scanf("%d", &T);
   while (T--) {
      cin >> s;
      possibilities = 1;
      counter = 0;
      start = '?';
      for (int i = 0; i < (int)s.length(); i++) {
         if (s[i] == '?')
            counter++;
         if (i && s[i] == '?' && s[i - 1] != '?')
            start = s[i - 1];
         else if (s[i] != '?' && start != '?' && start != s[i]) {
            possibilities = (possibilities * (counter + 1)) % MOD;
            start = '?';
         }//else if
         if (s[i] != '?')
            counter = 0;
      }//for
      printf("%d\n", possibilities);
   }//while
   return 0;
}//main
