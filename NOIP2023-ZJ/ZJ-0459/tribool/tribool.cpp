#include<bits/stdc++.h>
using namespace std;
#define pd push_back
#define all(x) x.begin(),x.end()
#define allA(x,l,r) x+l,x+r+1
#define mpr make_pair
const int N=1e5+10;
//bool ud[N];
//int ID[N];
int T,id,n,m;
//vector<pair<int,int> > v[N];
/*void remake(int x){
	ud[x]=true;
	for(auto y:v[x])
		if(!ud[y.first])remake(y.first);
}*/
//set<int> st[N];
namespace A{
	int I[20],now[20];
	vector<array<int,3> >Q;
	int ans=1e9;
	bool check(){
		memcpy(now,I,sizeof(I));
		for(auto y:Q){
			if(y[0]==1)now[y[1]]=1;
			if(y[0]==2)now[y[1]]=0;
			if(y[0]==3)now[y[1]]=2;
			if(y[0]==4)now[y[1]]=now[y[2]];
			if(y[0]==5)now[y[1]]=(now[y[2]]==2?2:!now[y[2]]);
		}
		for(int i=1;i<=n;i++)
			if(I[i]!=now[i])
				return false;
		return true;
	}
	void dfs(int dep){
		if(dep==n+1){
			if(check()){
				int c=0;
				for(int i=1;i<=n;i++)
					c+=I[i]==2;
				ans=min(ans,c);
			}
			return;
		}
		I[dep]=0;
		dfs(dep+1);
		I[dep]=1;
		dfs(dep+1);
		I[dep]=2;
		dfs(dep+1);
	}
	void mian(){
		Q.clear();ans=1e9;
		vector<array<int,3> >Q;
		for(int i=1;i<=m;i++){
			char opt[5];int x,y;
			scanf("%s%d",opt,&x);
			if(opt[0]=='T')Q.pd({1,x,0});
			if(opt[0]=='F')Q.pd({2,x,0});
			if(opt[0]=='U')Q.pd({3,x,0});
			if(opt[0]=='+')scanf("%d",&y),Q.pd({4,x,y});
			if(opt[0]=='-')scanf("%d",&y),Q.pd({5,x,y});
		}
		dfs(1);
		printf("%d\n",ans);
	}
}
namespace B{
	int I[N];
	void mian(){
		memset(I,0,sizeof(I));
		for(int i=1;i<=m;i++){
			char opt[5];int x,y;
			scanf("%s%d",opt,&x);
			if(opt[0]=='T'||opt[0]=='F')I[x]=1;
			else I[x]=2;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
			ans+=I[i]==2;
		printf("%d\n",ans);
	}
}
namespace C{
	vector<int> v[N];
	vector<array<int,3> >Q;
	bool ud[N],uk[N];
	void dfs(int x){
		ud[x]=true;
		for(auto y:v[x])
			if(!ud[y])dfs(y);
	}
	void mian(){
		for(int i=1;i<=n;i++)v[i].clear();
		memset(ud,false,sizeof(ud));
		memset(uk,false,sizeof(uk));
		Q.clear();
		for(int i=1;i<=m;i++){
			char opt[5];int x,y;
			scanf("%s%d",opt,&x);
			if(opt[0]=='T')Q.pd({1,x,0});
			if(opt[0]=='F')Q.pd({2,x,0});
			if(opt[0]=='U')Q.pd({3,x,0});
			if(opt[0]=='+')scanf("%d",&y),Q.pd({4,x,y});
			if(opt[0]=='-')scanf("%d",&y),Q.pd({5,x,y});
		}
		reverse(all(Q));
		for(auto y:Q){
			if(y[0]==2){
				if(!uk[y[1]])
					ud[y[1]]=true;
			}else{
				if(!ud[y[2]])uk[y[1]]=true;
				v[y[2]].pd(y[1]);
			}
		}
		for(int i=1;i<=n;i++)
			if(ud[i])dfs(i);
		int ans=accumulate(allA(ud,1,n),0);
		cout<<ans<<'\n';
	}
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&id,&T);
	while(T--){
		scanf("%d%d",&n,&m);
		if(id==1||id==2){A::mian();continue;}
		if(id==3||id==4){B::mian();continue;}
		if(id==5||id==6){C::mian();continue;}
	//	for(int i=1;i<=n;i++)v[i].clear();
		/*memset(ud,0,sizeof(ud));
		memset(id,-1,sizeof(id));
		vector<array<int,3> >Q;
		for(int i=1;i<=m;i++){
			char opt[5];int x,y;
			scanf("%s%d",opt,&x);
			if(opt[0]=='T')Q.pd({1,x,0});
			if(opt[0]=='F')Q.pd({2,x,0});
			if(opt[0]=='U')Q.pd({3,x,0});
			if(opt[0]=='+')scanf("%d",&y),Q.pd({4,x,y});
			if(opt[0]=='-')scanf("%d",&y),Q.pd({5,x,y});
		}
		reverse(all(Q));
		for(auto P:Q){
			int x=P[1];
			if(P[0]=='T'){
				if(id[x]!=0&id[x]!=1&&id[x]!=2)
					id[x]=0;
			}
		}*/
	}
	return 0;
}
/*
3 1
2 2
T 2
U 2
*/
