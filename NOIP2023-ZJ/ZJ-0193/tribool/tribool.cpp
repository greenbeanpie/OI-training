#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int c,t,n,m,s[maxn],nw[maxn],fa[maxn],ans;
struct Work{
	int op,x,y;
}p[maxn];
int read(){
	int ret=0,y=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') y=-y;ch=getchar();}
	while(isdigit(ch)) ret=(ret<<1)+(ret<<3)+(ch&15),ch=getchar();
	return ret*y;
}
void check(int num){
	for(int i=1;i<=n;i++) nw[i]=s[i];
	for(int i=1;i<=m;i++){
		if(p[i].op==0||p[i].op==1||p[i].op==2) nw[p[i].x]=p[i].op;
		if(p[i].op==3) nw[p[i].x]=nw[p[i].y];
		if(p[i].op==4){
			if(nw[p[i].y]==2) nw[p[i].x]=2;
			else nw[p[i].x]=nw[p[i].y]^1;
		}
	}
	for(int i=1;i<=n;i++)
	  if(nw[i]!=s[i]) return;
	ans=min(ans,num);
	return;
}
void dfs(int i,int num){
	if(i==n+1){check(num);return;}
	s[i]=0;
	dfs(i+1,num);
	s[i]=1;
	dfs(i+1,num);
	s[i]=2;
	dfs(i+1,num+1);
	return;
}
void solve1(){
	t=read();
	while(t--){
		n=read();m=read();ans=n;
		for(int i=1;i<=m;i++){
			char ch=getchar();
			while(ch!='T'&&ch!='F'&&ch!='U'&&ch!='+'&&ch!='-') ch=getchar();
			if(ch=='T'||ch=='F'||ch=='U'){
				if(ch=='T') p[i].op=0;
				if(ch=='F') p[i].op=1;
				if(ch=='U') p[i].op=2;
				p[i].x=read();
			}else{
				if(ch=='+') p[i].op=3;
				if(ch=='-') p[i].op=4;
				p[i].x=read();p[i].y=read();
			}
		}
		dfs(1,0);
		printf("%d\n",ans);
	}
	return;
}
void solve2(){
	t=read();
	while(t--){
		n=read();m=read();ans=0;memset(s,0,sizeof s);
		for(int i=1;i<=m;i++){
			char ch=getchar();
			while(ch!='T'&&ch!='F'&&ch!='U') ch=getchar();
			int x=read();
			if(ch=='U') s[x]=1;
		}
		for(int i=1;i<=n;i++) ans+=s[i];
		printf("%d\n",ans);
	}
	return;
}
int get(int x){return fa[x]==x?x:fa[x]=get(fa[x]);}
void solve3(){
	t=read();int cnt=0;
	while(t--){cnt++;int num=0;
		n=read();m=read();ans=0;memset(s,0,sizeof s);
		for(int i=1;i<=n;i++) fa[i]=i;
		for(int i=1;i<=m;i++){
			char ch=getchar();
			while(ch!='U'&&ch!='+') ch=getchar();
			if(ch=='U'){
				p[i].op=0;p[i].x=read();
			}else if(ch=='+'){
				p[i].op=1;
				p[i].x=read();p[i].y=read();
			}
		}
		int lst=ans;
		for(int i=1;i<=n;i++){
			lst=ans;
			for(int j=1;j<=m;j++){
				if(p[j].op==0){
					if(!s[p[j].x]) ans++;
					s[p[j].x]=1;
				}
				else{
					if(!s[p[j].x]&&s[p[j].y]) ans++;
					else if(s[p[j].x]&&!s[p[j].y]) ans--;
					s[p[j].x]=s[p[j].y];
				}
			}
			if(ans==lst) break;
		}
		printf("%d\n",ans);
	}
	return;
}
void solve4(){
	t=read();int cnt=0;
	while(t--){cnt++;int num=0;
		n=read();m=read();ans=0;memset(s,0,sizeof s);
		for(int i=1;i<=n;i++) fa[i]=i;
		for(int i=1;i<=m;i++){
			char ch=getchar();
			while(ch!='U'&&ch!='+') ch=getchar();
			if(ch=='U'){
				p[i].op=0;p[i].x=read();
			}else if(ch=='+'){
				p[i].op=1;
				p[i].x=read();p[i].y=read();
			}
		}
		int lst=ans;
		for(int i=1;i<=n;i++){
			lst=ans;
			for(int j=1;j<=m;j++){
				if(p[j].op==0){
					if(!s[p[j].x]) ans++;
					s[p[j].x]=1;
				}
				else{
					if(!s[p[j].x]&&s[p[j].y]) ans++;
					else if(s[p[j].x]&&!s[p[j].y]) ans--;
					s[p[j].x]=s[p[j].y];
				}
			}
			if(ans==lst) break;
		}
		printf("%d\n",ans);
	}
	return;
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	c=read();
	if(c==1||c==2) solve1();
	else if(c==3||c==4) solve2();
	else if(c==5) solve3();
	else if(c==6) solve4();
	return 0;
}
/*
1 3
3 3
‐ 2 1
‐ 3 2
+ 1 3
3 3
‐ 2 1
‐ 3 2
‐ 1 3
2 2
T 2
U 2
*/