#include <bits/stdc++.h>
using namespace std;

int main() {
   ios::sync_with_stdio(0);
   stack<char> R;
   string line;
   while (getline(cin, line) && line != "***") {
      for (int i = 0; i < (int)line.length(); i++) {
         if (isdigit(line[i]))
            R.push(line[i]);
      }//for
      if (!R.empty()) {
         cout << R.top();
         R.pop();
      }//if
      while (!R.empty()) {
         cout << " " << R.top();
         R.pop();
      }//while
      cout << "\n";
   }//while
   return 0;
}//main
