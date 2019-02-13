#include <bits/stdc++.h>
using namespace std;

int main() {
   std::ios::sync_with_stdio(false);
   int T;
   int count1[30], count2[30];
   bool yes;
   string enc, org;
   cin >> T;
   getline(cin, enc);
   while (T--) {
      for (int i = 0; i < 30; i++)
         count1[i] = count2[i] = 0;
      getline(cin, enc);
      getline(cin, org);

      for (int j = 0; j < (int)org.length(); j++) {
         count1[org[j] - 'a']++;
         count2[enc[j] - 'a']++;
      }//for

      yes = !memcmp(count1, count2, sizeof(count1));
      if (!yes) {
         for (int i = 0; i < (int)enc.length() - (int)org.length(); i++) {
            count2[enc[i] - 'a']--;
            count2[enc[i + (int)org.length()] - 'a']++;
            if (!memcmp(count1, count2, sizeof(count1))) {
               yes = true;
               break;
            }//if
         }//for
      }//if
      yes ? puts("YES") : puts("NO");
   }//while
   return 0;
}//main
