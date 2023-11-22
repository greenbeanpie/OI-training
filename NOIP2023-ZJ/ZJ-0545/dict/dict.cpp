#include<bits/stdc++.h>
using namespace std;

const int N=3010,SZ=2e7;

int n,m,id;
string s[N],t,mn1,mn2;

char buf[SZ],*pp=buf-1;
inline int read()
{
	while(*++pp<45);
	int res=*pp&15;
	while(*++pp>45&&*pp<90) res=(res<<3)+(res<<1)+(*pp&15);
	return res;
}
inline void read(string &x)
{
	while(*++pp<90);
	x.push_back(*pp);
	while(*++pp>90) x.push_back(*pp);
}

int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	fread(buf,1,SZ,stdin);
	
	n=read(),m=read();
	t.resize(m);
	for(int i=1;i<=n;++i)
	{
		read(s[i]);
		sort(s[i].begin(),s[i].end());
		for(int j=m-1;~j;--j)
			t[m-j-1]=s[i][j];
		if(!id||t<mn1) mn2=mn1,id=i,mn1=t;
		else if(mn2.empty()||t<mn2) mn2=t;
	}
	
	pp=buf-1;
	for(int i=1;i<=n;++i)
		if(mn2.empty()||s[i]<mn1||i==id&&s[i]<mn2)
			*++pp='1';
		else *++pp='0';
	
	fwrite(buf,1,pp-buf+1,stdout);
	return 0;
}