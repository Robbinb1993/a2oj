#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
const double eps = 1e-8;

ii coord[26];
char getChar[10][10];
char line[110], s[110];
string res;

void solve(const int idx) {
   char curr = line[idx];
   char nxt = line[idx + 1];
   if (!line[idx + 1])
      return;
   const double dx = coord[nxt - 'A'].first - coord[curr - 'A'].first;
   const double dy = coord[nxt - 'A'].second - coord[curr - 'A'].second;
   for (int i = 1; i <= 20; i++) {
      double x = coord[curr - 'A'].first + (i / double(20) + eps) * dx;
      double y = coord[curr - 'A'].second + (i / double(20) + eps) * dy;
      char now = getChar[(int)(round(x) + eps)][(int)(round(y) + eps)];
      if (now != res[(int)res.length() - 1])
         res += now;
   }//for
   solve(idx + 1);//test
}//solve

bool check(const string& S) {
   int idx = 0;
   for (int i = 0; i < (int)res.length(); i++) {
      if (res[i] == S[idx]) {
         idx++;
         if (idx == (int)S.length())
            return 1;
      }//if
   }//for
   return 0;
}//check

int main() {
   int T, N;
   int curr = 0;
   for (int i = 2; i <= 6; i++)
      coord[curr] = ii(i, 4), getChar[i][4] = curr++ + 'A';
   for (int i = 3; i >= 1; i--)
      for (int j = 1; j <= 7; j++)
         coord[curr] = ii(j, i), getChar[j][i] = curr++ + 'A';
   scanf("%d", &T);
   while (T--) {
      scanf("%d", &N);
      scanf(" %s", line);
      res = line[0];
      solve(0);
      bool flag = 0;
      for (int i = 0; i < N; i++) {
         scanf(" %s", s);
         if (!flag) {
            if (check(s)) {
               printf("%s\n", s);
               flag = 1;
            }//if
         }//if
      }//for
      if (!flag)
         puts("NO SOLUTION");
   }//while
   return 0;
}//main
