#include <iostream>
using namespace std;

int main() {
   std::ios::sync_with_stdio(false);
   int T;
   int x, y, q;
   string signalSeq;
   cin >> T;
   getline(cin, signalSeq);
   while (T--) {
      x = y = q = 0;
      getline(cin, signalSeq);
      for (int i = 0; i < (int)signalSeq.length(); i++) {
         if (signalSeq[i] == 'U') y++;
         else if (signalSeq[i] == 'R') x++;
         else if (signalSeq[i] == 'D') y--;
         else if (signalSeq[i] == 'L') x--;
         else q++;
      }//for
      cout << x - q << " " << y - q << " " << x + q << " " << y + q << endl;
   }//while
   return 0;
}//main
