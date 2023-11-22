#include<bits/stdc++.h>
using namespace std;
const int MAXN=3010;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
}
int n,m;
int a[MAXN][MAXN],b[MAXN][MAXN],minn=1;
int ans[MAXN];
bool flag;
inline bool cmp(int x,int y){return x>y;}
signed main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	n=read();m=read();char s;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>s;b[i][j]=a[i][j]=s-'a'+1;
	}	
	
	for(int i=1;i<=n;i++)sort(a[i]+1,a[i]+m+1,cmp);
	for(int i=1;i<=n;i++)sort(b[i]+1,b[i]+m+1);
	
	for(int i=2;i<=n;i++){
		for(int j=1;j<=m;j++)
			if(a[minn][j]>a[i][j]){minn=i;break;}
			else if(a[minn][j]<a[i][j])break;
	}
	
	for(int i=1;i<=n;i++){
		if(i==minn){ans[i]=1;continue;}
		flag=1;
		for(int k=1;k<=m;k++){
			if(b[i][k]==a[minn][k])continue;
			else if(b[i][k]<a[minn][k]){flag=1;break;}
			else if(b[i][k]>a[minn][k]){flag=0;break;}	
		}
		if(flag==1)ans[i]=1;
	}
	for(int i=1;i<=n;i++)printf("%d",ans[i]);
	return 0;
}
