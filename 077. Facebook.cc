#include <bits/stdc++.h>
using namespace std;
typedef pair<int, string> is;

map<string, int> m;

int main() {
   ios::sync_with_stdio(0);
   int T, N, K;
   string line, S;
   cin >> T;
   for (int t = 1; t <= T; t++) {
      m.clear();
      cin >> N >> K;
      getline(cin, line);
      while (N--) {
         getline(cin, line);
         stringstream ss(line);
         ss >> S;
         if (S == "liked")
            ss >> S;
         else
            ss >> S, ss >> S;
         S = S.substr(0, (int)S.length() - 2);
         m[S]++;
      }//while
      vector<is> V;
      for (map<string, int>::iterator it = m.begin(); it != m.end(); it++)
         V.push_back(is(it->second, it->first));
      sort(V.begin(), V.end(), greater<is>());
      cout << "Case " << t << ":\n";
      for (int i = 0; i < K; i++)
         cout << V[i].second << "\n";
   }//while
   return 0;
}//main
