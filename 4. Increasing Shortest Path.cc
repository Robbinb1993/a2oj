#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
const int INF = 1 << 30;
const int MAXN = 155;

struct s {
   int id;
   int dist;
   int iw; //incoming weight
   int eu; //edges used
   bool operator < (const s& rhs) const {
      return dist > rhs.dist;
   }//operator <
   s() {}
   s(const int i, const int d) {
      id = i;
      dist = d;
      iw = 0;
      eu = 0;
   }//constructor
};

int N, Q;
vector<int> dist[155][155];
vector<vector<ii> > edges = vector<vector<ii> >(MAXN);
int getEdgeID[155][3030];

int Dijkstra(const int st, const int en, const int C) {
   priority_queue<s> Q;
   s curr, next;
   int w;
   for (int i = 0; i <= N; i++)
      for (int j = 0; j <= N; j++)
         for (int k = 0; k < (int)dist[i][j].size(); k++)
            dist[i][j][k] = INF;
   Q.push(s(st, 0));

   while (!Q.empty()) {
      curr = Q.top();
      Q.pop();
      if (curr.iw != 0 && dist[curr.id][curr.eu][getEdgeID[curr.id][curr.iw]] < curr.dist)
         continue;
      if (curr.id == en)
         return curr.dist;
      for (int i = 0; i < (int)edges[curr.id].size(); i++) {
         next.id = edges[curr.id][i].first;
         next.iw = edges[curr.id][i].second;
         next.eu = curr.eu + 1;
         if (next.eu > N - 1 || next.eu > C || next.iw <= curr.iw)
            continue;
         next.dist = curr.dist + next.iw;
         if (dist[next.id][next.eu][getEdgeID[next.id][next.iw]] > next.dist) {
            dist[next.id][next.eu][getEdgeID[next.id][next.iw]] = next.dist;
            Q.push(next);
         }//if
      }//for
   }//while
   return -1;
}//Dijkstra

int main() {
   int T;
   int M;
   int n1, n2, w;
   int A, B, C;
   scanf("%d", &T);
   while (T--) {
      for (int i = 0; i <= N; i++) {
         edges[i].clear();
         for (int j = 0; j <= N; j++)
            dist[i][j].clear();
      }//for
      scanf("%d %d %d", &N, &M, &Q);
      while (M--) {
         scanf("%d %d %d", &n1, &n2, &w);
         edges[n1].push_back(ii(n2, w));
         getEdgeID[n2][w] = (int)dist[n2][0].size();
         for (int i = 0; i <= N; i++)
            dist[n2][i].push_back(INF);
      }//while
      while (Q--) {
         scanf("%d %d %d", &A, &B, &C);
         printf("%d\n", Dijkstra(A, B, C));
      }//while
   }//while
   return 0;
}//main
