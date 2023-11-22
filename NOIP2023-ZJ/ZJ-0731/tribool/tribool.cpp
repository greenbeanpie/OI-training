#include <bits/stdc++.h>
#define endl '\n'
//#define int long long
using namespace std;
const int N=100005;
int c,T,n,m;
int u,v,p,cnt,ans;
int a[N],sign[N],sum[N];
int in[N],out[N];
char op;
bool flag;
struct edge{
	int to,val;
};
vector <edge> g[N];
void IO(string name){
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}
//void init(){
//	ans=0;	  flag=0;   cnt=0;
//	memset(a,0x3f,sizeof(a));
//	memset(in,0,sizeof(in));
//	memset(out,0,sizeof(out));
//	memset(sum,0,sizeof(sum));
//	memset(sign,1,sizeof(sign));
//}
//void add(int u,int v,int w){
//	g[u].push_back({v,w});
//	in[v]++,out[u]++;
//}
//void topo()
//	queue <int> Q;
//	for(int i=1;i<=n;i++)
//		if(in[i]==0)	Q.push(i),sign[i]=1;
//	if(Q.empty()) Q.push(1);
//	while(!Q.empty()){
//		int x=Q.front();
//		Q.pop();
//		for(int i=0;i<(int)g[x].size();i++){
//			int p=g[x][i].to,w=g[x][i].val;
//			in[p]--,out[x]--;
//			sign[p]*=w;
//			sum[p]+=sign[p];
//			if(in[p]==0)	Q.push(p);
//		}
//	}
//}
signed main(){
	IO("tribool");
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>m;
//		init();
		memset(a,1,sizeof(a));
		for(int i=1;i<=m;i++){
			cin>>op;
			if(op=='+'){
				flag=1;
				cin>>u>>v;
//				add(v,u,1);
			}	
			if(op=='-'){
				flag=1;
				cin>>u>>v;
//				add(v,u,-1);
			}
			else{
				cin>>p;
				if(op=='T')	a[p]=1/*,sign[p]=1*/;
				if(op=='F')	a[p]=-1/*,sign[p]=-1*/;
				if(op=='U')	a[p]=0;
			}
		}
		if(flag==0){
			ans=0;
			for(int i=1;i<=n;i++)
				if(a[i]==0)	ans++;
			cout<<ans<<endl;	
		}
//		else{
//			topo();
//			for(int i=1;i<=n;i++)
//				cout<<sum[i]<<' ';
//			cout<<endl;	
//		}
	}
	return 0;
}
// 9:59   喜报！！！：吃了个小面包 
// 10：19 喜报！！！：我不会写 
// 11：51 喜报！！！：写炸了 

