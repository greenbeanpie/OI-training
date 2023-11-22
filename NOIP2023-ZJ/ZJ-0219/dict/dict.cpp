#include<bits/stdc++.h>
using namespace std;
#define For(i, l ,r) for(int i=(l);i<=(r);++i)
#define RFor(i, r ,l) for(int i=(r);i>=(l);--i)
char getdig(){char ch=getchar();while(ch<'a'||ch>'z')ch=getchar();return  ch;}
int read()
{
	int x=0,t=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')t=-t;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*t;
}
struct WORD
{
	int cnt[26];
	WORD(){memset(cnt,0,sizeof(cnt));}
};
bool cmp(WORD x,WORD y)	// > ?
{
	For(i, 0, 25)
		if(x.cnt[i]>y.cnt[i])return 0;
		else if(x.cnt[i]<y.cnt[i])return 1;
	return 0;
}
bool dcmp(WORD x,WORD y)	// > ?
{
	RFor(i, 25, 0)
		if(x.cnt[i]<y.cnt[i])return 0;
		else if(x.cnt[i]>y.cnt[i])return 1;
	return 0;
}
const int N=3005;
WORD a[N],pre[N],bak[N],tmp;
int a1[N],a2[N];
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);	
	int n=read(),m=read();
	For(i, 1 ,n)
		For(j, 1 ,m) ++a[i].cnt[getdig()-'a'];
	if(n==1){printf("1\n");return 0;}
	pre[1]=a[1];
	For(i, 2, n)
		if(dcmp(a[i],pre[i-1]))pre[i]=pre[i-1];else pre[i]=a[i];
	bak[n]=a[n];
	RFor(i, n - 1, 1)
		if(dcmp(a[i],bak[i+1]))bak[i]=bak[i+1];else bak[i]=a[i];
	For(i, 1 ,n)
	{
		a1[0]=0;
		For(j, 0, 25) For(k, 1, a[i].cnt[j]) a1[++a1[0]]=j;
		if(i==1)tmp=bak[i+1];
		else if(i==n)tmp=pre[i-1];
		else {if(dcmp(pre[i-1],bak[i+1]))tmp=bak[i+1];else tmp=pre[i-1];}
		a2[0]=0;
		RFor(j, 25, 0) For(k, 1, tmp.cnt[j]) a2[++a2[0]]=j;
		bool flag=0;
		For(j, 1, m)
			if(a1[j]<a2[j]){flag=1;break;}
			else if(a1[j]>a2[j]){flag=0;break;}
		if(flag)putchar('1');else putchar('0');
	}
	putchar('\n');
	return 0;
}
