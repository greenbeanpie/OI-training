#include<algorithm>
#include<cstdio>
int c,m,n,Q,x[1000],y[1000],x1[1000],y_[1000],p,q,p1,q1,kx,ky;
int max(int *x,int l,int r)
{
	int m = x[l];
	for (int i = l+1;i <= r;++i)
		if (x[i] > m)
			m = x[i];
	return m;
}
int min(int *x,int l,int r)
{
	int m = x[l];
	for (int i = l+1;i <= r;++i)
		if (x[i] < m)
			m = x[i];
	return m;
}
bool check(int *x,int *y)
{
	if (x[1] == y[1] || x[n] == y[m] || (x[1]-y[1])*(x[n]-y[m]) < 0)
	{
		return 0;
	}
	if (x[1] < y[1])
	{
	p = q = p1 = q1 = 1;
	while (p < n && q < m)
	{
		while (q < m && x[p] < y[q] && max(x,p,n) < max(y,q+1,m))
			++q;
		while (p < n && x[p] < y[q] && min(y,q,m) > min(x,p+1,n))
			++p;
		if (p == p1 && q == q1)
			return 0;
		p1 = p,q1 = q;
	}
	while (q < m && x[p] < y[q] && max(x,p,n) < max(y,q+1,m))
		++q;
	while (p < n && x[p] < y[q] && min(y,q,m) > min(x,p+1,n))
		++p;
	if (p == n && q == m)
		return 1;
	else
		return 0;
	}
	else
	{
	p = q = p1 = q1 = 1;
	while (p < n && q < m)
	{
		while (q < m && x[p] > y[q] && min(x,p,n) > min(y,q+1,m))
			++q;
		while (p < n && x[p] > y[q] && max(y,q,m) < max(x,p+1,n))
			++p;
		if (p == p1 && q == q1)
			return 0;
		p1 = p,q1 = q;
	}
	while (q < m && x[p] > y[q] && max(x,p,n) < max(y,q+1,m))
		++q;
	while (p < n && x[p] > y[q] && min(y,q,m) > min(x,p+1,n))
		++p;
	if (p == n && q == m)
		return 1;
	else
		return 0;
	}
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&Q);
	for (int i = 1;i <= n;++i)
		scanf("%d",&x[i]);
	for (int i = 1;i <= m;++i)
		scanf("%d",&y[i]);
	printf("%d\n",check(x,y));
	for (int i = 1;i <= n;++i)
		x1[i] = x[i];
	for (int i = 1;i <= m;++i)
		y_[i] = y[i];
	for (int i = 1;i <= Q;++i)
	{
		scanf("%d%d",&kx,&ky);
		for (int j = 1;j <= kx;++j)
			scanf("%d",&p),scanf("%d",&x[p]);
		for (int j = 1;j <= ky;++j)
			scanf("%d",&p),scanf("%d",&y[p]);
		printf("%d\n",check(x,y));
	for (int i = 1;i <= n;++i)
		x[i] = x1[i];
	for (int i = 1;i <= m;++i)
		y[i] = y_[i];
	}
	return 0;
}