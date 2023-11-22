//tribool
#include <bits/stdc++.h>
#define Max 100010
#define re register
using namespace std;
int c,t;
int n,m;
int ans;
char op;
int ty[Max];
bool vis[Max],vcnt[Max];
int top[Max],siz[Max];
queue<int> topl;

inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

inline void check(int i,int j){
	if(ty[i]==191981001) ty[j]=191981000;
	else if(ty[i]==191981000) ty[j]=191981001;
	else if(ty[i]==191981002) ty[j]=ty[i];
	else ty[j]=-ty[i];
}

inline int dfs(int x){
	if(vis[x]) {
		if(!top[x])top[x]=x;
		return top[x];
	}
	vis[x]=true;
	if(ty[x]>=191981000) {
		top[x]=x;
		siz[x]++;
		return top[x];
	}
	int to=abs(ty[x]);
//	cout<<x<<" "<<ty[x]<<" "<<to<<endl;//
	top[x]=dfs(to);
	siz[top[x]]++;
//	cout<<top[x]<<" "<<siz[top[x]]<<endl;//
//	cout<<to<<" "<<top[x]<<endl;//
//	cout<<ty[x]<<endl;//
	if(to!=top[x]) {
		if(ty[x]<0) check(to,x);
		else ty[x]=ty[to];
	}
	return top[x];
}

int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	c=read(),t=read();
	while(t--){
		n=read(),m=read(),ans=0;
		for(re int i=1;i<=n;i++) siz[i]=top[i]=0,vis[i]=vcnt[i]=false,ty[i]=i;
		while(!topl.empty()) topl.pop();
		while(m--){
			cin>>op;
			if(op=='T') ty[read()]=191981001;
			else if(op=='F') ty[read()]=191981000;
			else if(op=='U') ty[read()]=191981002;
			else if(op=='+') ty[read()]=read();
			else if(op=='-') ty[read()]=-read();
		}
//		for(re int i=1;i<=n;i++) cout<<ty[i]<<" ";//
//		cout<<endl;//
		for(re int i=1;i<=n;i++){
			if(vis[i]) continue;
			topl.push(dfs(i));
//			cout<<ty[i]<<" ";//
//			cout<<i<<" "<<top[i]<<" ";//
//			cout<<siz[top[i]]<<endl;//
//			cout<<ty[top[i]]<<endl;//
		}
//		for(re int i=1;i<=n;i++) cout<<ty[i]<<" ";//
//		cout<<endl;//
		while(!topl.empty()){
			int i=topl.front();
//			cout<<i<<" ";//
			topl.pop();
			if(vcnt[i]) continue;
			vcnt[i]=true;
			if(i==-ty[i]) ty[i]=191981002;
			if(ty[i]==191981002) ans+=siz[i];
//			cout<<ty[top[i]]<<endl;//
		}
//		int cnt=0;
//		for(re int i=1;i<=n;i++){
//			if(ty[top[i]]==191981002) ty[i]=191981002,cnt++;
//		}
//		cout<<cnt<<endl;
//		for(re int i=1;i<=n;i++) cout<<top[i]<<" ";//
		cout<<ans<<endl;
	}
	return 0;
}
/*
1 1
10 10

*/

