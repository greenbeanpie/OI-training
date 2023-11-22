//      Author:WangJingze      //
//      Deep Dark Fantasy      //
#include<bits/stdc++.h>
#define re register
#define il inline
#define u32 int
#define u64 unsigned long long
#define ll long long
using namespace std;
const u32 MAXN=1e5+10;
u32 c,t;
u32 n,m;
u32 ans=0,cnt=0;
bool vis[MAXN],flag=false,pas=false;
char s[5];
int poi[MAXN];
struct node{
	bool pd;
	int idx;
}a[MAXN];

vector<node> edge[MAXN];


void dfs(re u32 pre,re bool val){
	++cnt;
	vis[pre]=true;
	if(poi[pre]==0) poi[pre]=val;
	if(poi[pre]==-3) flag=true;
	if(poi[pre]==-2||poi[pre]==-1) pas=true;
	for(re vector<node>::iterator it=edge[pre].begin();it!=edge[pre].end();++it){
		if(flag||pas){
			if(vis[it->idx]) continue;
			dfs(it->idx,true); continue;
		}
		if(vis[it->idx]){
			if(it->pd&&poi[pre]!=poi[it->idx])
				flag=true;
			if(it->pd==false&&poi[pre]==poi[it->idx])
				flag=true;
		}else{
			re bool temp;
			if(it->pd) temp=val;
			else temp=!val;
			dfs(it->idx,temp);
		}
	}return;
}


int main(){
freopen("tribool.in","r",stdin);
freopen("tribool.out","w",stdout);
scanf("%d%d",&c,&t); while(t--){
	memset(vis,false,sizeof(vis));
	memset(poi,0,sizeof(poi));
	scanf("%d%d",&n,&m);
	ans=0;
	for(re u32 i=1;i<=n;++i){
		a[i].pd=true;
		a[i].idx=i;
		edge[i].clear();
	}
	
	for(re u32 i=0;i<m;++i){
		scanf("%s",s);
		if(s[0]=='+'){
			re int from,to;
			scanf("%d%d",&from,&to);
			a[from].pd=a[to].pd;
			a[from].idx=a[to].idx;
		}if(s[0]=='-'){
			re int from,to;
			scanf("%d%d",&from,&to);
			a[from].pd=!a[to].pd;
			a[from].idx=a[to].idx;
		}if(s[0]=='T'){
			re int from;
			scanf("%d",&from);
			a[from].pd=true;
			a[from].idx=-1;
		}if(s[0]=='F'){
			re int from;
			scanf("%d",&from);
			a[from].pd=true;
			a[from].idx=-2;
		}if(s[0]=='U'){
			re int from;
			scanf("%d",&from);
			a[from].pd=true;
			a[from].idx=-3;
		}
	}
	
	for(re int i=1;i<=n;++i){
		if(a[i].idx<0) poi[i]=a[i].idx;
		else if(a[i].idx!=i){
			edge[i].push_back({a[i].pd,a[i].idx});
			edge[a[i].idx].push_back({a[i].pd,i});
		}else if(a[i].idx==i&&a[i].pd==false) poi[i]=-3;
	}
	
	
	
	for(re u32 i=1;i<=n;++i){
		cnt=0;
		flag=false; pas=false;
		if(!vis[i]) dfs(i,true);
		
//		if(flag) printf("1cnt=%d\n",cnt);
//		if(pas) printf("2cnt=%d\n",cnt);
		
		if(flag) ans+=cnt;
	}
//	
//	for(re u32 i=1;i<=n;++i){
//		printf("pd:%d   idx:%d\n",a[i].pd,a[i].idx);
//	}
//	
//	
//	for(re u32 i=1;i<=n;++i){
//		printf("poi:%d\n",poi[i]);
//	}puts("");
//	
	
	printf("%u\n",ans);
}return 0;}
/*

2 1
10 10
- 7 3
- 5 3
+ 3 7
- 1 6
+ 4 6
- 8 4
- 6 8
+ 2 2
- 9 9
- 10 10


5





Y@T2L32#
*/
