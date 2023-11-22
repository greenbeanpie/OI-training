#include<bits/stdc++.h>
using namespace std;
#define pd push_back
#define all(x) x.begin(),x.end()
#define allA(x,l,r) x+l,x+r+1
#define mpr make_pair
int n,m;
const int N=3e3+10;
const int M=2e6+10;
char s[N][N];
int tr[M][26];
int I[M],cnt[M];
//vector<int> cnt[M];
int idx=0;
void insert(char *s,int id){
	int rt=0;int L=strlen(s+1);
	for(int i=1;i<=L;i++){
		int x=s[i]-'a';
		if(!tr[rt][x])tr[rt][x]=++idx;
		rt=tr[rt][x];
	}
	I[rt]=id;cnt[rt]++;
	assert(rt<M);
}
bool getval(char *s,int id){
	int rt=0;int L=strlen(s+1);
	for(int i=1;i<=L;i++){
		int x=s[i]-'a';
		for(int p=0;p<x;p++)
			if(tr[rt][p])return false;
		if(!tr[rt][x])return true;
		rt=tr[rt][x];
	}
	return cnt[rt]<=1&&I[rt]==id;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
//	int p1=1;
	scanf("%d%d",&n,&m);
	//if(n==1){puts("1");return 0;}
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++)sort(allA(s[i],1,m)),reverse(allA(s[i],1,m)),insert(s[i],i);
	for(int i=1;i<=n;i++){
		reverse(allA(s[i],1,m));
		putchar(getval(s[i],i)?'1':'0');
		reverse(allA(s[i],1,m));
	}
//	int p2=1;
//	printf("\n%d",(&p2)-(&p1));
	return 0;
}
/*
3 1
a
b
c

*/

