#include<iostream>
#include<cstring>
using namespace std;

int c,t;
int n,m,k,d;
int maxans;

struct Chall{
	int x,y,z;
}chall[10005];

int an[100005];
void sear(int t){
	if(t >= n){
		int thisans=0;
		int flag=0;
		for(int i=1;i<=n;i++){
			if(an[i] == 1){
				thisans-=d;
				flag++;
				if(flag >k){
					return;
				}
			}else{
				flag = 0;
			}
			for(int j=1;j<=m;j++){
				if(i == chall[j].x && flag >= chall[j].y)
					thisans+=chall[j].z;
			}
		}
		maxans = max(maxans,thisans);
		return;

	}
	for(int i=0;i<=1;i++){
		an[t] = i;
		sear(t+1);
	}
}

int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&c, &t);
	for(int lll=0;lll<t;lll++){
		int ans=0;
		maxans = -1;
		memset(chall,0,sizeof chall);
		
		scanf("%d%d%d%d",&n,&m,&k,&d);
		for(int i=1;i<=m;i++) scanf("%d%d%d",&chall[i].x,&chall[i].y,&chall[i].z);
		sear(1);
		printf("%d",maxans);
		
		
		
	}
	
	
	
	
	return 0;
}
