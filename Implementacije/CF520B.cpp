#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> g(10004, -1);
queue<int> q;

int main()
{
	cin >> n >> m;
	if(m < n)
	{
		cout << n - m << endl;
		return 0;
	}

	g[n] = 0;
	q.push(n);
	int vrh;
	while(!q.empty())
	{
		vrh = q.front();
		if(vrh == m)
		{
			cout << g[vrh] << endl;
			return 0;
		}
		q.pop();
		if(2 * vrh <= 10000)
			if(g[2 * vrh] == -1)
			{
				g[2 * vrh] = g[vrh] + 1;
				q.push(2 * vrh);
			}
		if (vrh > 1 && g[vrh - 1] == -1)
		{
			g[vrh - 1] = g[vrh] + 1;
			q.push(vrh - 1);
		}
	}
	return 0;
}
