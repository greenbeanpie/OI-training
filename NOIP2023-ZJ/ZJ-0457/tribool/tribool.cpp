#include<bits/stdc++.h>
using namespace std;
struct Amadeus{
	int opt,a,b;
}a[100005];
int c,t,n,m,ans;
int s[100005],S[100005];
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch)){ret=ret*10+ch-'0';ch=getchar();}
	return ret*f;
}
void dfs(int step){
	if(step==n+1){
		for(int i=1;i<=n;i++)S[i]=s[i];
		for(int i=1;i<=m;i++){
			if(a[i].opt==0)S[a[i].a]=S[a[i].b];
			else if(a[i].opt==1)S[a[i].a]=S[a[i].b]==3?3:3-S[a[i].b];
			else S[a[i].a]=a[i].opt-1;
		}
		for(int i=1;i<=n;i++)if(s[i]!=S[i])return;
		int cnt=0;
		for(int i=1;i<=n;i++)cnt+=s[i]==3;
		ans=min(ans,cnt);
		return;
	}
	for(int i=1;i<=3;i++){
		s[step]=i;
		dfs(step+1);
	}
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	c=read();t=read();
	if(c==1||c==2){
		while(t--){
			memset(a,0,sizeof a);
			memset(s,0,sizeof s);
			memset(S,0,sizeof S);ans=1<<30;
			n=read();m=read();
			for(int i=1;i<=m;i++){
				char ch;scanf("%c",&ch);
				a[i].a=read();
				if(ch=='+'){a[i].opt=0;a[i].b=read();}
				else if(ch=='-'){a[i].opt=1;a[i].b=read();}
				else if(ch=='T'){a[i].opt=2;s[a[i].a]=1;}
				else if(ch=='F'){a[i].opt=3;s[a[i].a]=2;}
				else if(ch=='U'){a[i].opt=4;s[a[i].a]=3;}
			}
			dfs(1);
			printf("%d\n",ans);
		}
		return 0;
	}
	if(c==3||c==4){
		while(t--){
			memset(s,0,sizeof s);
			memset(a,0,sizeof a);ans=0;
			n=read();m=read();
			for(int i=1;i<=m;i++){
				char ch;scanf("%c",&ch);
				a[i].a=read();
				if(ch=='T')s[a[i].a]=1;
				else if(ch=='F')s[a[i].a]=2;
				else if(ch=='U')s[a[i].a]=3;
			}
			printf("%d\n",ans);
		}
		return 0;
	}
	if(c==5){
		while(t--){
			memset(s,0,sizeof s);
			memset(S,0,sizeof S);
			memset(a,0,sizeof a);
			ans=0;
			n=read();m=read();
			for(int i=1;i<=m;i++){
				char ch;scanf("%c",&ch);
				a[i].a=read();
				if(ch=='+'){a[i].opt=0;a[i].b=read();}
				else if(ch=='U')s[a[i].a]=3;
			}
			for(int i=1;i<=n;i++)S[i]=s[i];
			for(int T=1;T<=m;T++){
				for(int i=1;i<=n;i++)s[i]=S[i];
				for(int i=1;i<=m;i++){
					if(a[i].opt=='+')s[a[i].a]=(s[a[i].b]==3)?3:0;
					else if(a[i].opt=='U')s[a[i].a]=3;
				}
				for(int i=1;i<=n;i++)if(s[i])S[i]=3;
			}
			for(int i=1;i<=n;i++)if(S[i]==3)ans++;
			printf("%d\n",ans);
		}
	}
	if(c==6){
		while(t--){
			memset(s,0,sizeof s);
			memset(S,0,sizeof S);
			memset(a,0,sizeof a);
			ans=0;
			n=read();m=read();int M=sqrt(m);
			for(int i=1;i<=m;i++){
				char ch;scanf("%c",&ch);
				a[i].a=read();
				if(ch=='+'){a[i].opt=0;a[i].b=read();}
				else if(ch=='U')s[a[i].a]=3;
			}
			for(int i=1;i<=n;i++)S[i]=s[i];
			for(int T=1;T<=M;T++){
				for(int i=1;i<=m;i++){
					if(a[i].opt=='+')s[a[i].a]=s[a[i].b]==3?3:0;
					else if(a[i].opt=='U')s[a[i].a]=3;
				}
				for(int i=1;i<=n;i++)if(s[i])S[i]=3;
			}
			for(int i=1;i<=n;i++)if(S[i]==3)ans++;
			printf("%d\n",ans);
		}
	}
	return 0;
}