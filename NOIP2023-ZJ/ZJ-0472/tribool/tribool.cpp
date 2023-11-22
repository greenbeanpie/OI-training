#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct xx{
	char ch;
	int x,y;
}e[N];
int c,t,n,m,i,j,fx,fy,x,y,tot,ans,s,p,a[N],b[N];
char ch;
inline char read(){
	char ch=getchar();
	while(ch!='+'&&ch!='-'&&ch!='T'&&ch!='F'&&ch!='U')ch=getchar();
	return ch;
}
void cf(int x){
	for(int i=1;i<=n;i++)a[i]=b[i]=x%3,x/=3;
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&m);
		if(c==1||c==2){
			ans=n;
			for(i=1;i<=m;i++){
				e[i].ch=read();
				if(e[i].ch=='T')scanf("%d",&e[i].x);
				else if(e[i].ch=='F')scanf("%d",&e[i].x);
				else if(e[i].ch=='U')scanf("%d",&e[i].x);
				else if(e[i].ch=='+')scanf("%d%d",&e[i].x,&e[i].y);
				else scanf("%d%d",&e[i].x,&e[i].y);
			}
			for(j=0;j<pow(3,n);j++){
				s=p=a[0]=0;cf(j);
				for(i=1;i<=n;i++)
					if(a[i]!=b[i])p=1;
				for(i=1;i<=m;i++)
					if(e[i].ch=='T')b[e[i].x]=0;
					else if(e[i].ch=='F')b[e[i].x]=2;
					else if(e[i].ch=='U')b[e[i].x]=1;
					else if(e[i].ch=='+')b[e[i].x]=b[e[i].y];
					else b[e[i].x]=2-b[e[i].y];
				for(i=1;i<=n;i++){
					s+=(b[i]==1);
					if(a[i]!=b[i]){p=1;break;}
				}
				if(!p)ans=min(ans,s);
			}
			printf("%d\n",ans);
		}else if(c==3||c==4){
			ans=0;memset(a,0,sizeof(a));
			for(i=1;i<=m;i++){
				ch=read();
				if(e[i].ch=='T')scanf("%d",&x),a[x]=1;
				else if(e[i].ch=='F')scanf("%d",&x),a[x]=2;
				else scanf("%d",&x),a[x]=3;
			}
			for(i=1;i<=n;i++)ans+=(a[i]==2);
			printf("%d\n",ans);
		}/*else if(c==5||c==6){
			ans=0;
			for(i=1;i<=n;i++)a[i]=1;
			for(i=1;i<=m;i++){
				ch=read();
				if(ch=='U')scanf("%d",&x),a[x]=2;
				else scanf("%d%d",&x,&y),a[x]=a[y];
			}
			for(i=1;i<=n;i++)ans+=(a[i]==2);
			printf("%d\n",ans);
		}*/
	}
	return 0;
}
