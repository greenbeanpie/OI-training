#include<bits/stdc++.h>
#define ll long long
#define MAXN 500005
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int C,n,m,q;
int xori[MAXN],xch[MAXN],yori[MAXN],ych[MAXN],p[MAXN],st[MAXN];
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&C,&n,&m,&q);
	rep(i,1,n)scanf("%d",&xori[i]);
	rep(i,1,m)scanf("%d",&yori[i]);
	if(C<=7){
		q++;int fff=0;
		while(fff++,q--){
			memset(p,0,sizeof(p));
			memset(st,0,sizeof(st));
			rep(i,1,n)xch[i]=xori[i];
			rep(i,1,m)ych[i]=yori[i];
			if(fff!=1){
				int cx,cy;scanf("%d%d",&cx,&cy);
				rep(i,1,cx){
					int pos,v;scanf("%d%d",&pos,&v);
					xch[pos]=v;
				}
				rep(i,1,cy){
					int pos,v;scanf("%d%d",&pos,&v);
					ych[pos]=v;
				}	
			}
			if(xch[n]<=ych[m]||xch[1]<=ych[1]){
				printf("0");
				continue;
			}
			p[1]=1;st[1]=1;
			int flag=0;
			rep(i,1,m)
				if(xch[1]>ych[i])
					p[1]=i;
				else break;
			rep(i,2,n){
				if(xch[i]>=xch[i-1]){
					int tmp=st[i-1]+1;
					st[i]=tmp;
					while(xch[i]>ych[tmp]){
						p[i]=tmp;
						tmp++;
					}
				}
				else{
					int tmp=st[i-1]+1;
					while(xch[i]<=ych[tmp])tmp++;
					if(p[i-1]>=tmp)st[i]=tmp;
					while(xch[i]>ych[tmp]){
						p[i]=tmp;
						tmp++;
					}
				}
				if(p[i]<i){
					flag=1;
					break;
				}
			}
			if(!flag)printf("1");
			else printf("0");
		}
	}
	else{
		int fff=0;
		while(fff++,q--){
			memset(p,0,sizeof(p));
			memset(st,0,sizeof(st));
			rep(i,1,n)xch[i]=xori[i];
			rep(i,1,m)ych[i]=yori[i];
			if(fff!=1){
				int cx,cy;scanf("%d%d",&cx,&cy);
				rep(i,1,cx){
					int pos,v;scanf("%d%d",&pos,&v);
					xch[pos]=v;
				}
				rep(i,1,cy){
					int pos,v;scanf("%d%d",&pos,&v);
					ych[pos]=v;
				}	
			}
			if(xch[1]>ych[1]||xch[n]>ych[m])
				printf("1");
			else printf("0");
		}
	}
	return 0;
}

