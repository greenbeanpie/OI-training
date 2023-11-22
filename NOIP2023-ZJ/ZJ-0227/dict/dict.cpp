#include<bits/stdc++.h>

using namespace std;

const int MAXN=3007;

int n, m, t[30];
char s[MAXN][MAXN], tmp[MAXN], minn[MAXN];
bool flag;

int pd(char *_a, char *_b)
{
	for(int i=0; i<m; i++)
		if(_a[i]<_b[i]) return 1;
		else if(_a[i]>_b[i]) return 0;
	return 2;
}

signed main()
{
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	cin>>n>>m;
	for(int i=1; i<=n; ++i)
		scanf("%s", s[i]);
	for(int i=1; i<=n; ++i){
		for(int j=0; j<26; ++j) t[j]=0;
		for(int j=0; j<m; ++j) ++t[s[i][j]-'a'];
		for(int j=0, pos=25; j<m; ++j){
			while(t[pos]==0) --pos;
			tmp[j]=pos+'a', --t[pos];
		}
		if(i==1 || pd(tmp, minn))
			for(int j=0 ; j<m; ++j)
				minn[j]=tmp[j];
		for(int j=0; j<m; ++j) ++t[s[i][j]-'a'];
		for(int j=0, pos=0; j<m; ++j){
			while(t[pos]==0) ++pos;
			s[i][j]=pos+'a', --t[pos];
		}
	}
	for(int i=1; i<=n; ++i)
		if(pd(s[i], minn)!=0) putchar('1');
		else putchar('0');
	return 0;
}
