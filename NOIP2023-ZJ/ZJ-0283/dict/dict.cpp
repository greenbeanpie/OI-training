#include<bits/stdc++.h>
#define N 3005
using namespace std;
int n,m,w1,w2;
char o[N];
string s[N],s1,s2,ans[N];
inline int read(){
	int res=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9')f=ch=='-'?-1:f,ch=getchar();
	while(ch>='0'&&ch<='9')res=res*10+ch-'0',ch=getchar();
	return res*f;
}
signed main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		scanf("%s",o+1);
		sort(o+1,o+m+1);
		for(int j=1;j<=m;++j)ans[i]+=o[j];
		for(int j=m;j;--j)s[i]+=o[j];
	}
	if(n==1){printf("1");return 0;}
	if(s[1]>s[2])s1=s[2],s2=s[1],w1=2;
	else s1=s[1],s2=s[2],w1=1;
	for(int i=3;i<=n;++i){
		if(s[i]<s1)s2=s1,s1=s[i],w1=i;
		else if(s[i]<s2)s2=s[i];
	}
	for(int i=1;i<=n;++i){
		if(i!=w1)printf("%d",ans[i]<s1);
		else printf("%d",ans[i]<s2);
	}
	return 0;
}