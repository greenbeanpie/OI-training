#include<bits/stdc++.h>
using namespace std;
const int N = 3005;
int n, m, p, q, a[N], b[N], c[N][202], d[N], ans, cnt, sum, tot;
string sans, s1[N], s2[N], s3[N];
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin >> n >> m;
	if(n <= 300)
	{
		for (int i = 1; i <= n; i++)
		{
			cin >> s1[i];
			s1[i] = " " + s1[i];
			s2[i] = " ";
			s3[i] = " ";
			for (int j = 1; j <= m; j++) b[int(s1[i][j])]++;
			for (int j = 97; j <= 125; j++) for (int k = 1; k <= b[j]; k++) s2[i] = s2[i] + char(j);
			for (int j = 125; j >= 97; j--) 
			{
				for (int k = 1; k <= b[j]; k++) s3[i] = s3[i] + char(j);
				b[j] = 0;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			int flag = 1;
			for (int j = 1; j <= n; j++)
			{
				if(s2[i] > s3[j])
				{
					flag = 0;
					break;
				}
			}
			if(flag) cout << "1";
			else cout << "0";
		}
		return 0;
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			cin >> s1[i];
			s1[i] = " " + s1[i];
			s2[i] = " ";
			s3[i] = " ";
			for (int j = 1; j <= m; j++) 
			{
				b[int(s1[i][j])]++;
				c[i][int(s1[i][j])]++;
			}
			for (int j = 97; j <= 125; j++) for (int k = 1; k <= b[j]; k++) s2[i] = s2[i] + char(j);
			for (int j = 125; j >= 97; j--) 
			{
				for (int k = 1; k <= b[j]; k++) s3[i] = s3[i] + char(j);
				b[j] = 0;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			int flag = 1;
			for (int j = 1; j <= n; j++)
			{
				if(i == j) continue;
				if(s2[i][1] >= s3[j][1]) { flag = 0; break; }
			}
			if(flag) cout << "1";
			else cout << "0";
		}
		return 0;
	}
	return 0;
}
/*

*/
