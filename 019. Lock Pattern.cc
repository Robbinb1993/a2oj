#include "stdio.h"
#include "string.h"
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;
typedef pair<int, int> ii;

int mapping[4][3];
ii getXY[12];

int DP[12][(1 << 12) + 10][42];
int L;

int ABS(const int v) {
   return v < 0 ? -v : v;
}//ABS

int startmask;

int solve(const int idx, const int bitmask, const int len) {
   int res = 0;
   bool valid;
   ii curr = getXY[idx], next;

   if (len >= L)
      return len == L;

   if (DP[idx][bitmask][len] != -1)
      return DP[idx][bitmask][len];

   for (int i = 0; i < 12; i++) {
      if (!(bitmask & (1 << i))) {
         next = getXY[i];
         valid = true;

         if (curr.first == next.first) {
            for (int j = 1; j < ABS(curr.second - next.second) && valid; j++) {
               if (!(bitmask & (1 << mapping[curr.first][curr.second + (curr.second > next.second ? -j : j)])))
                  valid = false;
               else if (startmask & (1 << mapping[curr.first][curr.second + (curr.second > next.second ? -j : j)]))
                  valid = false;
            }//for
         }//if
         else if (curr.second == next.second) {
            for (int j = 1; j < ABS(curr.first - next.first) && valid; j++) {
               if (!(bitmask & (1 << mapping[curr.first + (curr.first > next.first ? -j : j)][curr.second])))
                  valid = false;
               else if (startmask & (1 << mapping[curr.first + (curr.first > next.first ? -j : j)][curr.second]))
                  valid = false;
            }//for
         }//else if
         else if (ABS(curr.second - next.second) == ABS(curr.first - next.first)) {
            for (int j = 1; j < ABS(curr.second - next.second) && valid; j++) {
               if (!(bitmask & (1 << mapping[curr.first + (curr.first > next.first ? -j : j)][curr.second + (curr.second > next.second ? -j : j)])))
                  valid = false;
               else if (startmask & (1 << mapping[curr.first + (curr.first > next.first ? -j : j)][curr.second + (curr.second > next.second ? -j : j)]))
                  valid = false;
            }//for
         }//else if

         if (valid)
            res += solve(i, bitmask | (1 << i), len + ABS(curr.first - next.first) + ABS(curr.second - next.second));
      }//if
   }//for
   return DP[idx][bitmask][len] = res;
}//solve

int main() {
   int T, N;
   int x, y;

   int res;
   scanf("%d", &T);
   for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 3; j++) {
         mapping[i][j] = i * 3 + j;
         getXY[i * 3 + j] = ii(i, j);
      }//for
   }//for
   while (T--) {
      memset(DP, -1, sizeof(DP));
      startmask = res = 0;
      scanf("%d %d", &L, &N);
      while (N--) {
         scanf("%d %d", &y, &x);
         startmask |= (1 << mapping[x - 1][y - 1]);
      }//while
      if (L <= 40) {
         for (int i = 0; i < 12; i++) {
            if (!(startmask & (1 << i)))
               res += solve(i, startmask | (1 << i), 0);
         }//for
      }//if
      !res ? puts("BAD MEMORY") : printf("%d\n", res);
   }//while
   return 0;
}//main
