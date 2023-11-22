#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int read(){
	int res=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9'){res=res*10+ch-'0';ch=getchar();}
	return res*f;
}
int point,T,n,m,x,y;char ch;
int sum,cnt[N][5];
struct node{int p,flag;}now[N];
vector<node>mapp[N][5];
queue<node>q;
bool f[N][5];
void init(){
	memset(now,0,sizeof(now));
	for(int i=1;i<=n;i++)now[i].p=i,now[i].flag=1;
	sum=0;
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>point>>T;
	while(T--){
		cin>>n>>m;
		init();
		for(int i=1;i<=m;i++){
			cin>>ch;
			if(ch=='+'){
				x=read();y=read();
				now[x].p=now[y].p;
				now[x].flag=now[y].flag;
			}else if(ch=='-'){
				x=read();y=read();
				if(now[y].p<0){
					if(now[y].p==-1)now[x].p=-3;
					else if(now[y].p==-3)now[x].p=-1;
					else now[x].p=-2;
				}else{
					now[x].p=now[y].p;
					now[x].flag=1-now[y].flag;
				}
			}else{
				x=read();now[x].flag=1;
				if(ch=='T')now[x].p=-1;
				else if(ch=='U')now[x].p=-2;
				else now[x].p=-3;
			}
		}
		if(point==3||point==4){
			for(int i=1;i<=n;i++){
				if(now[i].p==-2)sum++;
			}
			cout<<sum<<endl;
		}else{
			cout<<0<<endl;
		}
	}
	return 0;
}
/*
3 1
3 2
U 3
U 2
*/
