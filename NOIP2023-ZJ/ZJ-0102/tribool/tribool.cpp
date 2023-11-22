#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,m,a[N][2],x,y,num,f[N],fl[N],st[N],top;
//v:0=F,1=U,2=T,(3,i)=i,(4,i)=!i
inline int read(){
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x;
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	memset(fl,-1,sizeof(fl));
	read(),T=read();
	while(T--){
		n=read(),m=read();
		for(int i=1;i<=n;i++)a[i][0]=3,a[i][1]=i,f[i]=3;
		for(int i=1;i<=m;i++){
			char op;cin>>op;
			if(op=='+')x=read(),y=read(),a[x][0]=a[y][0],a[x][1]=a[y][1];
			else if(op=='-'){
				x=read(),y=read();
				if(a[y][0]<=2)a[x][0]=2-a[y][0],a[x][1]=0;
				else a[x][0]=7-a[y][0],a[x][1]=a[y][1];
			}
			else x=read(),a[x][0]=(op=='F'?0:(op=='U'?1:2)),a[x][1]=0;
		}
		for(int i=1;i<=n;i++)
			if(a[i][0]<=2)f[i]=a[i][0];
		for(int i=1;i<=n;i++)
			if(f[i]==3){
				st[++top]=i;
				int v=0;
				while(true){
					if(f[st[top]]<=2)break;
					if(fl[st[top]]!=-1){f[st[top]]=fl[st[top]]^v;break;}
					st[top+1]=a[st[top]][1];fl[st[top]]=v;
					if(a[st[top]][0]==4)v^=1;
					top++;
				}top--;
				while(top){
					f[st[top]]=(a[st[top]][0]==3?f[st[top+1]]:2-f[st[top+1]]);
					fl[st[top]]=-1;top--;
				}
			}
		num=0;
		for(int i=1;i<=n;i++)num+=(f[i]==1);
		printf("%d\n",num);
	}
	return 0;
}