#include <bits/stdc++.h>
using namespace std;
int n, m, b[210][210], bo, c[210][210], t[30];
char ch;
struct node
{
	int x, y, step;
} a[30][5];
const int dx[] = {0, 1, 0, -1, 0};
const int dy[] = {0, 0, 1, 0, -1};
void bfs()
{
	queue<node> q;
	b[1][1] = 1;
	q.push((node){1, 1, 0});
	while (!q.empty())
	{
		node u = q.front();
		q.pop();
		for (int i = 1; i <= 4; i++)
		{
			int cx = u.x + dx[i], cy = u.y + dy[i], ccx, ccy;
			if (c[cx][cy])
			{
				if (cx == a[c[cx][cy]][1].x && cy == a[c[cx][cy]][1].y)
					ccx = a[c[cx][cy]][2].x, ccy = a[c[cx][cy]][2].y;
				else
					ccx = a[c[cx][cy]][1].x, ccy = a[c[cx][cy]][1].y;
				cx = ccx, cy = ccy;
			}
			if (cx < 1 || cx > n || cy < 1 || cy > m || b[cx][cy])
				continue;
			b[cx][cy] = 1;
			q.push((node){cx, cy, u.step + 1});
			if (cx == n && cy == m)
			{
				cout << u.step + 1;
				bo = 1;
				return;
			}
		}
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			cin >> ch;
			if (ch >= 'A' && ch <= 'Z')
				a[ch - 'A' + 1][++t[ch - 'A' + 1]] = (node){i, j}, c[i][j] = ch - 'A' + 1;
			if (ch == '1')
				b[i][j] = 1;
		}
	bfs();
	if (!bo)
		cout << "No Solution.";
}