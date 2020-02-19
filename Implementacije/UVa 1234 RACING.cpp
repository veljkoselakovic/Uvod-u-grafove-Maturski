#include <bits/stdc++.h>
using namespace std;
#define MAX 10015
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

class disjSkup {
private:
  vi p, rank, velicinaSkupa;
  int nSet;
public:
    disjSkup(int N) {
    velicinaSkupa.assign(N, 1);
    nSet = N;
    rank.assign(N, 0);
    p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
    int findSet(int i){
        if (p[i] == i)
            return i ;
        else
            return (p[i] = findSet(p[i]));
    }
    bool istiSkup(int i, int j) {
         return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j) {
        if (!istiSkup(i, j)) {
            nSet--;
        int x = findSet(i);
        int y = findSet(j);

        if (rank[x] > rank[y]) {
            p[y] = x;
            velicinaSkupa[x] += velicinaSkupa[y];
        }
        else{
            p[x] = y;
            velicinaSkupa[y] += velicinaSkupa[x];
            if (rank[x] == rank[y])
                rank[y]++;
            }
        }
    }
  int brojSkupova() {
       return nSet;
    }
  int velicinaSkupai(int i) {
    return velicinaSkupa[findSet(i)];
    }
};


int brCvor, brIvica;

int main() {
  int sluc, u, v, w;
  scanf("%d", &sluc);

  while (sluc--){
      vector< pair<int, ii> > Ivice;
      scanf("%d %d", &brCvor, &brIvica);

      for (int i =0; i<brIvica; i++){
           scanf("%d %d %d", &u, &v, &w);
           Ivice.push_back(make_pair(-w, ii(u, v)));
      }
      sort(Ivice.begin(), Ivice.end());
      int duzinaIvice = Ivice.size();
      disjSkup DS(brCvor+1);
      int ans = 0;
      for (int j = 0; j < duzinaIvice; j++) {
           pair<int, ii> fr = Ivice[j];
           int a,b;
           a = fr.second.first;
           b = fr.second.second;
           if (!DS.istiSkup(a, b) )
             DS.unionSet(a, b);
           else
              ans += -fr.first;
      }
      printf("%d\n", ans);
  }
  return 0;
}
