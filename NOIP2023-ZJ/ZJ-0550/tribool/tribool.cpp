#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;

int n,m,ans;
int fa[maxn],val[maxn];
//int vis[maxn];

inline int read(){
	int x=0,k=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			k=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*k;
}

void Init(){
	for(int i=1;i<=n;i++){
		fa[i]=i;
		val[i]=i;
	}
	ans=0;
	return ;
}

int ogn(int x){
//	int res=fa[x];
//	if(fa[res]=res)
//		return res;
	queue<int>q;
	while(fa[x]!=x){
		q.push(x);
		x=fa[x];
//		cout<<" "<<x<<" "<<fa[x]<<"\n";
	}
	while(q.size()){
		fa[q.front()]=x;
		q.pop();
	}
//	if(fa[x]!=x)
//		return ogn(fa[x]);
	return x;
}


int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c=read(),T=read();
	while(T--){
		n=read(),m=read();
		Init();
		for(int i=1;i<=m;i++){
			char ch=getchar();
			int xx,yy; xx=read();
			if(ch=='T'||ch=='F')
				val[xx]=0;
			if(ch=='U')
				val[xx]=1919810;
			if(ch=='+'){
				yy=read();
				val[xx]=val[yy];
				if(val[yy]==0||val[yy]==1919810)
					continue;
				for(int j=1;j<=n;j++)
					if(abs(val[j])==xx&&j!=xx)
						val[j]=(val[j]/xx)*val[xx];
			}
			if(ch=='-'){
				yy=read();
				if(val[yy]==1919810||val[yy]==0){
					val[xx]=val[yy];
					continue;
				}
				val[xx]=-val[yy];
				for(int j=1;j<=n;j++)
					if(abs(val[j])==xx&&j!=xx)
						val[j]=(val[j]/xx)*val[xx];
			}
//			cout<<"#:  "<<ch<<"  \n";
		}
		for(int i=1;i<=n;i++){
			if(val[i]==-i)
				val[i]=1919810;
			else if(val[i]!=0&&val[i]!=1919810)
				fa[i]=abs(val[i]);
		}
		for(int i=1;i<=n;i++)
			fa[i]=ogn(i);
//		cout<<"#: ";
//		for(int i=1;i<=n;i++)
//			cout<<fa[i]<<" ";
//		cout<<"\n";
		for(int i=1;i<=n;i++)
			if(val[fa[i]]==1919810)
				ans++;
		printf("%d\n",ans);
	}	
	return 0;
}





