#include<bits/stdc++.h>
using namespace std;

template<class T>inline void read(T&x){
	char last=' ',c;
	while(!isdigit(c=getchar()))last=c;
	x=c^48;
	while(isdigit(c=getchar()))x=(x<<3)+(x<<1)+(c^48);
	if(last=='-')x=-x;
}

const int MAXN=3e3+7,MAXV=37;
int n,m;
string s[MAXN];
int Mx[MAXN],Mi[MAXN];
int c[MAXV];

int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	read(n),read(m);
	int M=30;
	for(int i=1;i<=n;++i){
		cin>>s[i];
		Mx[i]=0,Mi[i]=30;
		for(int j=0;j<m;++j){
			Mx[i]=max(Mx[i],s[i][j]-'a');
			Mi[i]=min(Mi[i],s[i][j]-'a');
		}
		++c[Mx[i]];
	}
	for(int i=1;i<26;++i)c[i]+=c[i-1];
	for(int i=1;i<=n;++i){
		if(c[Mi[i]]-(Mx[i]==Mi[i])==0)cout<<1;
		else cout<<0;
	}
	puts("");
	return 0;
}
