#include <iostream>
#include <algorithm>
using namespace std;

int c,m,n,q;
long long kx,ky,p,v;
long long a[500050],b[500050],rea[500050],reb[500050];

void check()
{
	bool zheng,fu;
	zheng = (a[1] - b[1] > 0);
	fu = (a[1] - b[1] < 0);
	long long tmp = min(m,n);
	for(int delta = 0;delta < tmp;delta++)
	{
		bool flag = true;
		for(int i = 1;i <= delta + 1;i++)
			if(((a[i] - b[1] > 0) != zheng) || ((a[i] - b[1] < 0) != fu))
				flag = false;
		for(int i = delta + 2;i <= tmp;i++)
			if(((a[i] - b[i - delta] > 0) != zheng) || ((a[i] - b[i - delta] < 0) != fu))
				flag = false;
		if(n > m)
		{
			for(int i = tmp + 1;i - delta <= m;i++)
				if(((a[i] - b[i - delta] > 0) != zheng) || ((a[i] - b[i - delta] < 0) != fu))
					flag = false;
			for(int i = m + delta;i <= n;i++)
				if(((a[i] - b[m] > 0) != zheng) || ((a[i] - b[m] < 0) != fu))
					flag = false;
		}
		else if(m >= n)
		{
			for(int i = tmp + 1;i <= n;i++)
				if(((a[i] - b[i - delta] > 0) != zheng) || ((a[i] - b[i - delta] < 0) != fu))
					flag = false;
			for(int i = n;i <= m;i++)
				if(((a[n] - b[i] > 0) != zheng) || ((a[n] - b[i] < 0) != fu))
					flag = false;
		}
		if(flag)
		{
			cout << 1;
			return;
		}
	}
	cout << 0;
	return;
}

int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin >> c >> n >> m >> q;
	if(c == 1)
	{
		int a,b,q1,q2,c,d;
		cin >> a >> b;
		cout << 1;
		while(q--)
		{
			cin >> q1 >> q2;
			for(int i = 1;i <= q1;i++) cin >> c >> d;
			for(int i = 1;i <= q2;i++) cin >> c >> d;
			cout << 1;
		}
	}
	else if(c == 2)
	{
		int a1,a2,b1,b2,place,tmp,q1,q2;
		cin >> a1 >> a2 >> b1 >> b2;
		if((a1 - b1) * (a2 - b2) > 0) cout << 1;
		else cout << 0;
		while(q--)
		{
			cin >> q1 >> q2;
			for(int i = 1;i <= q1;i++)
			{
				cin >> place >> tmp;
				if(place == 1) a1 = tmp;
				else a2 = tmp;
			}
			for(int i = 1;i <= q2;i++)
			{
				cin >> place >> tmp;
				if(place == 1) b1 = tmp;
				else b2 = tmp;
			}
			if((a1 - b1) * (a2 - b2) > 0) cout << 1;
			else cout << 0;
		}
	}
	else
	{
		for(int i = 1;i <= n;i++)
		{
			cin >> a[i];
			rea[i] = a[i];
		}
		for(int i = 1;i <= m;i++)
		{
			cin >> b[i];
			reb[i] = b[i];
		}
		check();
		while(q--)
		{
			for(int i = 1;i <= n;i++) a[i] = rea[i];
			for(int i = 1;i <= m;i++) b[i] = reb[i];
			cin >> kx >> ky;
			for(int i = 1;i <= kx;i++)
			{
				cin >> p >> v;
				a[p] = v;
			}
			for(int i = 1;i <= ky;i++)
			{
				cin >> p >> v;
				b[p] = v;
			}
			check();
		}
	}
	return 0;
}