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
