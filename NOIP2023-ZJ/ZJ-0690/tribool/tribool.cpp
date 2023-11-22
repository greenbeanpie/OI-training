#include <bits/stdc++.h>
using namespace std;
#define elif else if

int c, t, n, m, x, y, _sum;
int a[100005], l[100005], N[100005], Nl[100005], s[100005];
char ch;
char chh[25];
int xx[25], yy[25];

//void work1(){
//	cin >> x >> y;
//	if(!N[x])
//		N[x] = y, a[x] = l[y];
//	Nl[x] = y, l[x] = l[y], s[x] = s[y];
//}

//void work2(){
//	cin >> x >> y;
//	if(!N[x])
//		N[x] = y, a[x] = -l[y];
//	Nl[x] = y, l[x] = -l[y], s[x] = s[y] + 1;
//}

//void work3(){
//	cin >> x;
//	if(ch == 'T')
//		y = 1;
//	elif(ch == 'U')
//		y = 0;
//	else
//		y = -1;
//	if(!N[x])
//		N[x] = x, a[x] = y;
//	Nl[x] = x, l[x] = y;
//}

//int getfaN(int x){
//	if(x == N[x])
//		return x;
//	return N[x] = getfaN(N[x]);
//}

//int getfaNl(int x){
//	if(x == Nl[x])
//		return x;
//	return Nl[x] = getfaNl(Nl[x]);
//}

void work1(){
	int sum = 0;
	memset(a, 0, sizeof(a));
	while(m--){
		cin >> ch >> x;
		if(a[x])
			continue;
		if(ch == 'U')
			sum++;
		a[x] = 1;
	}
	cout << sum << '\n';
	return;
}

void work2(){
	int sum = 0;
	memset(a, 0, sizeof(a));
	while(m--){
		cin >> ch >> x;
		if(ch == 'U'){
			a[x] = 1;
			continue;
		}
		cin >> y;
		a[x] = a[y];
	}
	for(int i = 1; i <= n; i++)
		sum += a[i];
	cout << sum << '\n';
	return;
}

int check(){
	for(int i = 1; i <= n; i++)
		l[i] = a[i];
	for(int i = 1; i <= m; i++){
		if(chh[i] == '+')
			l[xx[i]] = l[yy[i]];
		if(chh[i] == '-')
			l[xx[i]] = -l[yy[i]];
		if(chh[i] == 'U')
			l[xx[i]] = 0;
		if(chh[i] == 'T')
			l[xx[i]] = 1;
		if(chh[i] == 'F')
			l[xx[i]] = -1;
	}
	for(int i = 1; i <= n; i++)
		if(l[i] != a[i])
			return 0;
	return 1;
}

void dfs(int x){
	if(x > n){
		if(check()){
			int sum = 0;
			for(int i = 1; i <= n; i++)
				if(a[i] == 0)
					sum++;
			_sum = min(_sum, sum);
		}
		return;
	}
	a[x] = -1;
	dfs(x + 1);
	a[x] = 0;
	dfs(x + 1);
	a[x] = 1;
	dfs(x + 1);
	return;
}

void work3(){
	memset(a, -2, sizeof(a));
	for(int i = 1; i <= m; i++){
		cin >> chh[i] >> xx[i];
		if(chh[i] == '-' || chh[i] == '+')
			cin >> yy[i];
	}
	_sum = m;
	dfs(1);
	cout << _sum << '\n';
	return;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> m;
//		memset(a, 0, sizeof(a));
//		memset(l, 0, sizeof(l));
//		memset(N, 0, sizeof(N));
//		memset(Nl, 0, sizeof(Nl));
//		memset(s, 0, sizeof(s));
//		while(m--){
//			cin >> ch;
//			if(ch == '+')
//				work1();
//			if(ch == '-')
//				work2();
//			if(ch == 'T' || ch == 'U' || ch == 'F')
//				work3();
//			cout << ch << ' ' << x << ' ' << y << '\n';
//		}
//		cout << 3 << '\n';
//		for(int i = 1; i <= n; i++)
//			getfaN(i), getfaNl(i);
//		cout << 2 << '\n';
//		for(int i = 1; i <= n; i++){
//			if(l[i] == 0){
//				if(a[i] != 0)
//					a[Nl[i]] = l[i] = a[i] * (s[i] % 2 ? -1 : 1);
//			}
//		}
//		int sum = 0;
//		for(int i = 1; i <= n; i++)
//			if(a[i] == 0 && s[i] % 2)
//				sum++;
//		cout << sum << '\n';
		if(c == 3 || c == 4)
			work1();
		if(c == 5 || c == 6)
			work2();
		if(c == 1 || c == 2)
			work3();
	}
	return 0;
}
