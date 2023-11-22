#include<bits/stdc++.h>
using namespace std;
#define long long ll
int a[3010][3010], b[3010][3010], mii, mi2;
int n, m;
char c;
bool cmp(int x[], int y[])
{
	for(int i = 1;i <= m;i ++) if(x[i] < y[i]) return true; else if(x[i] > y[i]) return false;
	return false;
}
int main()
{
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	cin >> n >> m;
	for(int i = 0;i <= 3000;i ++) a[3005][i] = a[3006][i] = 30;
	mii = 3005, mi2 = 3006;
	for(int i = 1;i <= n;i ++)
	{
		int cc[30], tmp[3010], dd[30];
		for(int j = 0;j <= 29;j ++) cc[j] = 0, dd[j] = 0;
		for(int j = 1;j <= m;j ++)
		{
			c = getchar();
			while(c < 'a' || c > 'z')  c = getchar();
			tmp[j] = c - 'a' + 1;
			cc[c - 'a' + 1] ++;
			dd[c - 'a' + 1] ++;
		}
		for(int j = 26;j >= 1;j --) cc[j] += cc[j + 1];
		for(int j = 1;j <= 26;j ++) dd[j] += dd[j - 1];
		for(int j = 1;j <= m;j ++) a[i][cc[tmp[j]] --] = tmp[j], b[i][dd[tmp[j]] --] = tmp[j];
		if(cmp(a[i], a[mii])) mii = i;
		else if(cmp(a[i], a[mi2])) mi2 = i;
//		for(int j = 1;j <= m;j ++) cout << a[i][j] << " ";
//		cout << endl;
//		for(int j = 1;j <= m;j ++) cout << b[i][j] << " ";
//		cout << endl;
	}
	
//	cout << endl;
//	for(int i = 1;i <= m;i ++) cout << a[mii][i] << " ";
//	cout << endl;
//	for(int i = 1;i <= m;i ++) cout << a[mi2][i] << " ";
//	cout << endl;
	
	if(n == 1)
	{
		cout << 1;
		return 0;
	} 
	for(int i = 1;i <= n;i ++)
	{
		if(mii == i)
		{
			if(cmp(b[i], a[mi2])) cout << 1;
			else cout << 0;
		}
		else
		{
			if(cmp(b[i], a[mii])) cout << 1;
			else cout << 0;
		}
	}
	return 0;
}
