#include<bits/stdc++.h>
using namespace std;
const int N = 100002;
int n, m, p, q, a[N], b[N], c[N], d[N], ans, cnt, sum, tot, C;
string s;
void sub1()
{
	if(a[1] != b[1]) s = s + '1';
	else s = s + '0';
	while (q--)
	{
		int x, y, v, A, B;
		A = a[1]; B = b[1];
		cin >> x >> y;
		for (int i = 1; i <= x; i++) 
		{
			cin >> p >> v;
			A = v;
		}
		for (int i = 1; i <= y; i++) 
		{
			cin >> p >> v;
			B = v;
		}
		if(A != B) s = s + '1';
		else s = s + '0';
	}
	cout << s;
}
void sub2()
{
	if((a[1] < b[1] && a[2] < b[2]) || (a[1] > b[1] && a[2] > b[2])) s = s + '1';
	else s = s + '0';
	while (q--)
	{
		int x, y, v, A, B, D, E;
		A = a[1]; B = b[1]; D = a[2]; E = b[2];
		cin >> x >> y;
		for (int i = 1; i <= x; i++) 
		{
			cin >> p >> v;
			a[p] = v;
		}
		for (int i = 1; i <= y; i++) 
		{
			cin >> p >> v;
			b[p] = v;
		}
		if((a[1] < b[1] && a[2] < b[2]) || (a[1] > b[1] && a[2] > b[2])) s = s + '1';
		else s = s + '0';
		a[1] = A; b[1] = B; a[2] = D; b[2] = E;
	}
	cout << s;
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin >> C >> n >> m >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> b[i];
	if(C == 1) { sub1(); return 0; }
	if(C == 2) { sub2(); return 0; }
	return 0;
}
