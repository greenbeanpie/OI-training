#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0,f=1;char ch;ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
}
const int N=3500;
char sh[N][N];
int t[50];
int maxx[N][N],minn[N][N];
int ans[N];
signed main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int n=read(),m=read();
	if(n==1){
		printf("1");
		return 0;
	}
	for(int i=1;i<=n;i++){
		int tot=0;
		char ch=getchar();
		while(ch<'a'||ch>'z'){ch=getchar();}
		while(ch>='a'&&ch<='z'){
			sh[i][++tot]=ch;
			ch=getchar();
		}
//		cin>>sh[i]+1;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=26;j++) t[j]=0;
		for(int j=1;j<=m;j++) t[sh[i][j]-'a']++;
		int now=0;
		for(int j=1;j<=m;j++){
			while(t[now]==0) now++;
			minn[i][j]=now;
//			printf("%d",minn[i][j]);
			t[now]--;
		}
//		printf("\n");
		for(int j=0;j<=26;j++) t[j]=0;
		for(int j=1;j<=m;j++) t[sh[i][j]-'a']++;
		now=25;
		for(int j=1;j<=m;j++){
			while(t[now]==0) now--;
			maxx[i][j]=now;
			t[now]--;
		}
	}
	//baoli
	for(int i=1;i<=n;i++){
		int judg=1;
		for(int j=1;j<=n;j++){
			if(j==i) continue;
			for(int k=1;k<=m;k++){
				if(minn[i][k]>maxx[j][k]){
					judg=0;
					break;
				}
				else if(minn[i][k]<maxx[j][k]) break;
			}
			if(judg==0) break;
		}
		if(judg==1) ans[i]=1;
		else ans[i]=0;
	}
	for(int i=1;i<=n;i++){
		printf("%d",ans[i]);
	}
	return 0;
}
