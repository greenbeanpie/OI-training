#include <bits/stdc++.h>
#define int long long
#define F(a,b,c) for(int a=b ; a<=c ; a++)
#define open(A) { freopen(#A".in" , "r" , stdin); freopen(#A".out" , "w" , stdout); }
using namespace std;


const int LXB=2e6+5;
const int lxb=3e3+5;
const int mod=998244353;
const int INF=mod+114514;







int n,m,l;
int s[lxb];
int p[lxb][lxb][2];


bool cp(int x , int y) {
	return x<y;
}

void to(int i , int t)
{
	F(j,1,m) p[i][j][t] = s[j];
}

bool cmp(int i , int j)
{
	F(k,1,m){
		if(p[i][k][0] > p[j][k][1]) return 1;
		if(p[i][k][0] < p[j][k][1]) return 0;
	}
	return 0;
}

void solve()
{
	char tmp;
	cin>>n>>m;
	F(i,1,n){
		F(j,1,m){
			cin>>tmp;
			s[j] = tmp-'a';
		}
		sort(s+1 , s+1+m , cp);
		to(i,0);
		reverse(s+1,s+1+m);
		to(i,1);
	}
	int mi=1;
	F(i,2,n){
		F(j,1,m){
			if(p[i][j][1] < p[mi][j][1]) {
				mi=i ; break;
			}
		}
	}
	F(i,1,n)
	{
		if(cmp(i,mi) and i!=mi)
			cout<<0;
		else cout<<1;
	}
	cout<<endl;
}



signed main()
{
	int T=1;
	open(dict);
	while(T--)
	{
		solve();
	}
}
