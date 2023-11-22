#include<bits/stdc++.h>
using namespace std;
typedef pair<int*,int> p;

const int N = 2010, K = 5e5 + 10;

int n, m;

int a[N], b[N], f[N][N];

p stk[K];int top;

void store(int &x)
{
	stk[++top] = make_pair(&x,x);
}

void restore()
{
	while(top)
	{
		*stk[top].first = stk[top].second;
		top--;
	}
}

int chk()
{
	int i, j;
	for(i=0;i<=n;i++)
		for(j=0;j<=m;j++)
			f[i][j] = 0;
	f[0][0] = 1;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			if(f[i][j])
			{
				int k;
				for(k=j+1;k<=m;k++)
				{
					if(!((a[1]>b[1]&&a[i+1]>b[k])||(a[1]<b[1]&&a[i+1]<b[k]))) break;
					f[i+1][k] = 1;
				}
				for(k=i+1;k<=n;k++)
				{
					if(!((a[1]>b[1]&&a[k]>b[j+1])||(a[1]<b[1]&&a[k]<b[j+1]))) break;
					f[k][j+1] = 1;
				}
			}
	return f[n][m];
}

int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int c, q, i;
	scanf("%d%d%d%d", &c, &n, &m, &q);
	for(i=1;i<=n;i++) scanf("%d", &a[i]);
	for(i=1;i<=m;i++) scanf("%d", &b[i]);
	printf("%d", chk());
	while(q--)
	{
		int kx, ky;
		scanf("%d%d", &kx, &ky);
		while(kx--)
		{
			int p, v;
			scanf("%d%d", &p, &v);
			store(a[p]);
			a[p] = v;
		}
		while(ky--)
		{
			int p, v;
			scanf("%d%d", &p, &v);
			store(b[p]);
			b[p] = v;
		}
		printf("%d", chk());
		restore();
	}
	return 0;
}