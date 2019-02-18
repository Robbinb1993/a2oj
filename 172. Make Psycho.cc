#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1200;
const int SQRN = sqrt(1200);

int K;
int spf[MAXN];
int ID = 0;
int DP[100][100001];
bool isPsycho[MAXN];
vector<int> psycho;

//O(N log^2 N)
void Sieve() {
   for (int i = 2; i <= SQRN; i++) {
      if (!spf[i]) {
         spf[i] = i;
         for (int j = 2 * i; j <= MAXN; j += i)
            if (spf[j] == 0)
         spf[j] = i;
      }//if
   }//for
   for (int i = 2; i <= MAXN; i++)
      if (!spf[i])
         spf[i] = i;
}//Sieve

//O(N log N)
void primeFactorization(const int start) {
   int v = start;
   int odd, even;
   odd = even = 0;
   while (v != 1) {
      int curr = spf[v];
      int counter = 0;
      while (v % curr == 0)
         v /= spf[v], counter++;
      if (counter & 1)
         odd++;
      else
         even++;
   }//while
   if (even > odd)
      isPsycho[start] = 1;
}//primeFactorization

bool solve(const int idx, const int v) {
   if (v == K)
      return 1;
   if (v > K)
      return 0;
   if (idx == (int)psycho.size())
      return 0;
   if (DP[idx][v] == ID)
      return 0;
   DP[idx][v] = ID;
   if (solve(idx + 1, v + psycho[idx]))
      return 1;
   if (solve(idx + 1, v))
      return 1;
}//solve

int main() {
   Sieve();
   for (int i = 1; i < MAXN; i++)
      primeFactorization(i);
   int T, N, v;
   scanf("%d", &T);
   while (T--) {
      psycho.clear();
      scanf("%d %d", &N, &K);
      while (N--) {
         scanf("%d", &v);
         if (isPsycho[v])
            psycho.push_back(v);
      }//while
      ID++;
      printf("%s\n", solve(0, 0) ? "Yes" : "No");
   }//while
   return 0;
}//main
