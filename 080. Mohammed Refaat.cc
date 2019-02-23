#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
const int INF = 1 << 30;

vector<vector<ii> > edges;
int dist[100010];
int N, M;

int Dijkstra(const int st, const int ed) {
   for (int i = 1; i <= N; i++)
      dist[i] = INF;
   priority_queue<ii, vector<ii>, greater<ii> > Q;
   Q.push(ii(0, st));
   dist[st] = 0;
   while (!Q.empty()) {
      ii curr = Q.top();
      Q.pop();
      if (curr.first > dist[curr.second])
         continue;
      if (curr.second == ed)
         return curr.first;
      for (int i = 0; i < (int)edges[curr.second].size(); i++) {
         int d = curr.first + edges[curr.second][i].second;
         if (d < dist[edges[curr.second][i].first])
            dist[edges[curr.second][i].first] = d, Q.push(ii(d, edges[curr.second][i].first));
      }//for
   }//while
   return -1;
}//Dijkstra

int main() {
   int T, n1, n2, w;
   scanf("%d", &T);
   for (int t = 1; t <= T; t++) {
      scanf("%d %d", &N, &M);
      edges.assign(N + 5, vector<ii>());
      while (M--) {
         scanf("%d %d %d", &n1, &n2, &w);
         edges[n1].push_back(ii(n2, w));
         edges[n2].push_back(ii(n1, w));
      }//while
      scanf("%d %d", &n1, &n2);
      printf("Case %d: %d\n", t, Dijkstra(n1, n2));
   }//for
   return 0;
}//main
