#include<bits/stdc++.h>
#define ll long long
#define il inline
using namespace std;
il ll read(){
	ll a=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){a=a*10+ch-'0';ch=getchar();}
	return a*f;
}
ll c,t,n,m,x,y,pos,num[101000],ans;
char op;
struct node{
	int fa,val;
	bool op;
	//op=0=+ op=1=-
}p[101000];
int fan(int val){
	if(val==1)return 2;
	if(val==2)return 1;
	return 3;
}
//T=1 F=2 U=3
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	c=read();
	t=read();
	while(t--){
		memset(p,0,sizeof(p));
		memset(num,0,sizeof(num));
		ans=0;
		n=read();
		m=read();
		while(m--){
			cin>>op;
			if(op=='T'){
				x=read();
				p[x].fa=0;p[x].op=0;p[x].val=1;
			}
			else if(op=='F'){
				x=read();
				p[x].fa=0;p[x].op=0;p[x].val=2;
			}
			else if(op=='U'){
				x=read();
				p[x].fa=0;p[x].op=0;p[x].val=3;
			}
			else if(op=='+'){
				x=read();y=read();
				if(p[y].fa==0){
					if(p[y].val>0){
						p[x].val=p[y].val;
						p[x].fa=0;
						p[x].op=0;
					}
					else{
						p[x].val=0;
						p[x].fa=y;
						p[x].op=0;
					}
				}
				else{
					p[x].val=0;
					p[x].fa=p[y].fa;
					p[x].op=p[y].op;
				}
			}
			else if(op=='-'){
				x=read();y=read();
				if(p[y].fa==0){
					if(p[y].val>0){
						p[x].val=fan(p[y].val);
						p[x].fa=0;
						p[x].op=0;
					}
					else{
						p[x].val=0;
						p[x].fa=y;
						p[x].op=1;
					}
				}
				else{
					p[x].val=0;
					p[x].fa=p[y].fa;
					p[x].op=p[y].op^1;
				}
			}
		}
		for(int i=1;i<=n;i++){
			if((p[i].fa==i&&p[i].op)||p[i].val==3){
				ans++;
			}
			else if(!((p[i].fa==i&&p[i].op)||p[i].val==3)){
				num[p[i].fa]++;
			}
		}
		//for(int i=1;i<=n;i++)cout<<p[i].fa<<' '<<p[i].op<<' '<<p[i].val<<'\n';
		for(int i=1;i<=n;i++)if(num[i]>0)if((p[i].fa==i&&p[i].op)||p[i].val==3)ans+=num[i];
		cout<<ans<<'\n';
	}
	return 0;
}

