#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 20;
const int MAXN = 1010;
typedef pair<int, int> ii;

int N, M, L;

vector<ii> coins;
vector<int> stations;

int totCost[MAXN], temp[MAXN];
int dist[MAXN];

int ABS (const int v) {
   return v < 0 ? -v : v;
}

int read() {
   int rtn=0;char ch=getchar();
   while(ch>'9'||ch<'0')ch=getchar();
   while(ch<='9'&&ch>='0')rtn=(rtn<<3)+(rtn<<1)+ch-'0',ch=getchar();
   return rtn;
}//fast read

void getSums(const int idx, const int sum, const int cost) {
   temp[0] = totCost[0] = 0;
   for (int j = 1; j < MAXN; j++)
      temp[j] = totCost[j] = INF;

   for (int i = 0; i < M; i++) {
      for (int j = 0; j < MAXN - coins[i].second; j++)
         if (totCost[j] != INF)
            temp[j + coins[i].second] = min(totCost[j + coins[i].second], totCost[j] + coins[i].first);
      memcpy(totCost, temp, sizeof(totCost));
   }//for

   for (int j = 0; j < MAXN; j++)
      if (totCost[j] > L)
         totCost[j] = INF;
}//getSums

int Dijkstra() {
   priority_queue<ii, vector<ii>, greater<ii> > Q;
   int E = stations[N - 1];
   int S = stations[0];
   ii curr;
   for (int i = 1; i < MAXN; i++)
      dist[i] = INF;
   dist[0] = 0;
   Q.push(ii(0, 0));
   while (!Q.empty()) {
      curr = Q.top();
      Q.pop();
      if (curr.second == N - 1)
         return curr.first;
      if (dist[curr.second] < curr.first)
         continue;
      for (int i = curr.second + 1; i < N; i++) {
         if (totCost[stations[i] - stations[curr.second]] != INF) {
            if (curr.first + 1 < dist[i]) {
               dist[i] = curr.first + 1;
               Q.push(ii(dist[i], i));
            }//if
         }//if
      }//for
   }//while
   return -1;
}//Dijkstra

int main() {
   int T;
   int C, V, station;
   T = read();
   while (T--) {
      N = read();
      M = read();
      L = read();
      coins.clear();
      stations.clear();

      for (int i = 0; i < N; i++) {
         scanf("%d", &station);
         stations.push_back(station);
      }//for

      sort(stations.begin(), stations.end());

      for (int i = 0; i < M; i++) {
         C = read(); V = read();
         coins.push_back(ii(C, V));
      }//for

      sort(coins.begin(), coins.end());
      getSums(0, 0, 0);

      printf("%d\n", Dijkstra());
   }//while
   return 0;
}//main
