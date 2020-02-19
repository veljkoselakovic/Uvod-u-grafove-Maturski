#include <iostream>

using namespace std;
#define MAXN 305
int matrix[MAXN][MAXN];
int V,E;
int v, u, w;

int main()
{
    cin >> V >> E;
    for (int i=0;i<V;i++)
        for (int j=0;j<V;j++)
            matrix[i][j] = 1e8;
    for (int i=0;i<V;i++)
        matrix[i][i] = 0;
    for (int i=0;i<E;i++){
        cin >> u >> v >> w;
        matrix[u][v] = w;
    }
    for (int k=0;k<V;k++)
        for (int i=0;i<V;i++)
            for (int j=0;j<V;j++)
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);

    cout << endl;
    for (int i=0;i<V;i++){
        for (int j=0;j<V;j++){
            cout << matrix[i][j] << " " ;
        }
        cout << endl;
    }
}
