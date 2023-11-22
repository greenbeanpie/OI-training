#include<bits/stdc++.h>
using namespace std;
const int N=3010;
int n,m,t[26];
char f[N][N],e[N][N],minn[N],min2[N];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	minn[1]=min2[1]='z'+1;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		memset(t,0,sizeof t);
		scanf("%s",f[i]+1);
		for(int j=1;j<=m;++j)++t[f[i][j]-'a'];
		for(int j=0,cur=0;j<26;++j)
			for(int k=1;k<=t[j];++k)
				f[i][++cur]=j+'a';
		memcpy(e[i],f[i],m+1);
		reverse(e[i]+1,e[i]+1+m);
		if(strcmp(e[i]+1,minn+1)!=1)
			memcpy(min2,minn,m+1),
			memcpy(minn,e[i],m+1);
		else if(strcmp(e[i]+1,min2+1)!=1)
			memcpy(min2,e[i],m+1);
//		printf("f:%s e:%s\n",f[i]+1,e[i]+1);
	}
//	printf("minn:%s min2:%s\n",minn+1,min2+1);
	for(int i=1;i<=n;++i){
		int res=strcmp(e[i]+1,minn+1);
		if(!res)
			putchar('0'+(strcmp(f[i]+1,min2+1)<0));
		else
			putchar('0'+(strcmp(f[i]+1,minn+1)<0));
	}
	return 0;
}