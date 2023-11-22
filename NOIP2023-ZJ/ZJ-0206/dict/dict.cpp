#include<bits/stdc++.h>
using namespace std;
#define N 3010
#define For(i,j,k) for(int i=j;i<=k;i++)
#define DFor(i,j,k) for(int i=j;i>=k;i--)
#define ll long long
struct node{
	short a[N];
	int tpe,id;
}b[N*2];
int n,m,tot;
int tmp[N],pos[N][2],cnt[30];
pair <int,int> mn1,mn2;
char ch;
bool cmp(node x,node y){
	For(i,1,m){
		if(x.a[i]<y.a[i]) return 1;
		if(x.a[i]>y.a[i]) return 0;
	}
	return 0;
}
void work(){
	For(i,1,m) cnt[tmp[i]]++;
	int now=0;
	For(i,1,26){
		while(cnt[i]){
			tmp[++now]=i;
			cnt[i]--;
		} 
	}
}
signed main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==1){
		printf("1");
		return 0;
	}
	For(i,1,n){
		ch=getchar();
		while(ch=='\n') ch=getchar();
		For(j,1,m){
			tmp[j]=ch-'a'+1;
			ch=getchar();
		} 
		work();
		For(j,1,m) b[i*2-1].a[j]=tmp[j];
		For(j,1,m) b[i*2].a[j]=tmp[m-j+1];
		b[i*2-1].id=b[i*2].id=i;
		b[i*2-1].tpe=0,b[i*2].tpe=1;
	}
	sort(b+1,b+2*n+1,cmp);
	For(i,1,2*n){
		if(i==1||cmp(b[i-1],b[i])) tot=i;
		pos[b[i].id][b[i].tpe]=tot;
	}
	mn1.first=mn2.first=2*N+1;
	For(i,1,n){
		if(pos[i][1]<mn1.first){
			mn1.first=pos[i][1];
			mn1.second=i;
		}else if(pos[i][1]<mn2.first){
			mn2.first=pos[i][1];
			mn2.second=i;
		}
	}
	For(i,1,n){
		if(mn1.second!=i){
			if(mn1.first<=pos[i][0]) printf("0");
			else printf("1");
		}else{
			if(mn2.first<=pos[i][0]) printf("0");
			else printf("1");
		}
	}
	return 0;
}

