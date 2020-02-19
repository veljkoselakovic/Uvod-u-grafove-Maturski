#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> grid[N + 1];
vector<bool> poseceno(N + 1);

void dodajIvicu(int u, int v)
{
    grid[u].push_back(v);
    grid[v].push_back(u);
}

bool isBipartite(int v, vector<int>& color)
{

    for (int i : grid[v]) {

        if (poseceno[i] == false) {

            poseceno[i] = true;

            color[i] = !color[v];

            if (!isBipartite(grid, i, poseceno, color))
                return false;
        }

        else if (color[i] == color[v])
            return false;
    }
    return true;
}

int main()
{

}




