#include<bits/stdc++.h>
using namespace std;
int n,m,N,S;
struct Amadeus{
	int id;
	int a[30];
	bool vis;
	bool operator<(const Amadeus b)const{
		if(!vis&&!b.vis){
			for(int i=1;i<=26;i++){
				if(a[i]==b.a[i])continue;
				return b.a[i]<a[i];
			}
			return 1;
		}
		if(vis&&b.vis){
			for(int i=26;i>=1;i--){
				if(a[i]==b.a[i])continue;
				return a[i]<b.a[i];
			}
			return 1;
		}
		if(!vis&&b.vis){
			int i=1,j=26;
			while(!a[i])i++;
			while(!b.a[j])j--;
			if(i<j)return 1;
			if(j<i)return 0;
			if(a[i]<b.a[j])return 0;
			if(b.a[j]<a[i])return 1;
			if(a[i]==n)return 1;
			return 0;
		}
		if(vis&&!b.vis){
			int i=26,j=1;
			while(!a[i])i--;
			while(!b.a[j])j++;
			if(i<j)return 1;
			if(j<i)return 0;
			if(a[i]<b.a[j])return 1;
			if(b.a[j]<a[i])return 0;
			if(a[i]==n)return 0;
			return 1;
		}
		return 0;
	}
}a[6005];
char s[3005];
bool vis[3005],ans[3005];
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch)){ret=ret*10+ch-'0';ch=getchar();}
	return ret*f;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	n=read();m=read();N=n<<1;
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		a[i].id=i;
		for(int j=1;j<=m;j++)a[i].a[s[j]-'a'+1]++;
		a[i+n]=a[i];a[i+n].vis=1;
	}
	sort(a+1,a+1+N);
	for(int i=1;i<=N;i++){
		if(!a[i].vis){
			if(!S)ans[a[i].id]=1;
			else if(S==1&&vis[a[i].id])ans[a[i].id]=1;
		}else {S++;vis[a[i].id]=1;}
	}
	for(int i=1;i<=n;i++)printf("%d",ans[i]);
	return 0;
}