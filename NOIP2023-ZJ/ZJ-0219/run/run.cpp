#include<bits/stdc++.h>
using namespace std;
#define For(i, l ,r) for(int i=(l);i<=(r);++i)
#define RFor(i, r ,l) for(int i=(r);i>=(l);--i)
#define O(x) cerr<<#x<<":"<<x<<endl
int read()
{
	int x=0,t=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')t=-t;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*t;
}
namespace Sub1_9
{
	const int N=1005,M=100005;
	long long f[N];long long sum[N][N];
	struct NODE
	{
		int las,val;long long s;
		friend bool operator < (NODE,NODE);
	};
	bool operator < (NODE x,NODE y){return x.las<y.las;}
	vector<NODE> ac[N];int cur[N],siz[N];
	int min32(int x,int y){return x<y?x:y;}
	long long max64(long long x,long long y){return x>y?x:y;}
	int max32(int x,int y){return x>y?x:y;}	
	void Main()
	{
		int T=read();
		while(T--)
		{
			int n=read(),m=read(),lim=read();long long dec=read();
			For(i, 1, m)
			{
				int x=read(),y=read(),v=read();
				ac[x].push_back((NODE){y,v,0});
			}
//			cout<<"S"<<endl;
			For(i, 1 ,n)
			{
				sort(ac[i].begin(),ac[i].end()),siz[i]=cur[i]=ac[i].size(),cur[i]--;
				For(j, 0, siz[i]-1) {if(!j)ac[i][j].s=ac[i][j].val;else ac[i][j].s=ac[i][j-1].s+ac[i][j].val;}
			}
//			cout<<"S"<<endl;
			For(i, 1, n)
				For(j, i, min32(i+lim-1, n))
				{
					int &k=cur[j];
					if(k<0){sum[i][j]=sum[i][j-1];continue;}
					for(;k>=0&&j-i+1<ac[j][k].las;--k);
					if(~k)sum[i][j]=sum[i][j-1]+ac[j][k].s;else sum[i][j]=sum[i][j-1];
//					cout<<i<<" "<<j<<" "<<sum[i][j]<<endl;
				}
			f[1]=0;
			For(i, 2, n+1)
			{
				f[i]=f[i-1];
				For(j,max32(i-1-lim+1,1),i-1)f[i]=max64(f[i],f[j-1]+sum[j][i-1]-dec*(i-j));
//				cout<<i<<" "<<f[i]<<" "<<max32(i-1-lim+1,1)<<endl;
			}
			printf("%lld\n",f[n+1]);
			For(i, 1 ,n) vector<NODE> ().swap(ac[i]);
			memset(sum,0,sizeof(sum));
		}
		return;
	}
}
/*
namespace Sub_All
{
	const int N=1000000000+5,M=100050;
	namespace Seg
	{
		struct NODE{int son[2];long long tag,bst;void makeIni(){son[0]=son[1]=tag=bst=0;}}tr[M<<5];	//memory!
		int tot=1;
		void pushDown(int x)
		{
			if(!tr[x].son[0])tr[x].son[0]=++tot,tr[tot].makeIni();
			if(!tr[x].son[1])tr[x].son[1]=++tot,tr[tot].makeIni();
			tr[tr[x].son[0]].tag+=tr[x].tag;tr[tr[x].son[1]].tag+=tr[x].tag;
			tr[tr[x].son[0]].bst+=tr[x].tag;tr[tr[x].son[1]].bst+=tr[x].tag;
		}
		void makeUp(int x)
	{
		tr[x].bst=max(tr[tr[x].son[0]].bst,tr[tr[x].son[1]].bst);
	}
		void update(int &x,int l,int r,int idx,long long val)
		{
			if(!x)x=++tot,tr[tot].makeIni();
			if(l==r){tr[x].bst=max(tr[x].bst,val);return;}
			pushDown(x);int mid=l+r>>1;
			if(idx<=mid)update(tr[x].son[0],l,mid,idx,val);
			if(idx>mid)update(tr[x].son[1],mid+1,r,idx,val);
			makeUp(x);
		}
		void modify(int &x,int l,int r,int L,int R,long long val)
		{
			if(!x)x=++tot,tr[tot].makeIni();
			if(L<=l&&R>=r){tr[x].bst+=val;tr[x].tag+=val;return;}
			int mid=l+r>>1;pushDown(x);
			modify(tr[x].son[0],l,mid,L,R,val);modify(tr[x].son[1],mid+1,r,L,R,val);
			makeUp(x);
		}
		long long query(int &x,int l,int r,int L,int R)
		{
			if(!x)return 0;
			if(L<=l&&R>=r)return tr[x].bst;
			int mid=l+r>>1;pushDown(x);
			long long res=-1e15;
			if(mid<=L)res=max(res,query(tr[x].son[0],l,mid,L,R));
			if(mid>R)res=max(res,query(tr[x].son[1],mid+1,r,L,R));
			return res;
		}
	}
	using namespace Seg;
	vector<int> V;
	struct NODE
	{
		int las,val;
//		friend bool operator < (NODE,NODE);
	};
//	bool operator < (NODE x,NODE y){return x.las<y.las;}
	vector<NODE> lc[N],rc[N];//int cur[N],siz[N];
	int getid(int x){return lower_bound(V.begin(),V.end(),x)-V.begin()+1;}
	pair<int,long long> f[M<<1];int cnt=0;
	int  G[M][3];
	void Main()
	{
		int T=read();
		while(T--)
		{
			int n=read(),m=read(),lim=read();long long dec=read();tot=1;
			For(i ,1 ,m)
			{
				int x=read(),y=read(),v=read();if(x-y+1<=0)continue;V.push_back(x);V.push_back(x-y+1);
				G[i]={x-y+1,x,v};
			}
			V.push(n+1);
			sort(V.begin(),V.end());V.erase(unique(V.begin(),V.end()),V.end());
			For(i, 1, m)
			{
				int x=getid(G[i][0]),y=getid(G[i][1]);
				lc[x].push_back({y,g[i][2]});
				rc[y].push_back({x,g[i][2]});
			}
			int siz=V.siz();
			f[cnt=1]={1,0};
			For(id, 0, siz-1)
			{
				int i=V[id];
				for(auto v:lc[id])
				{
					if(f[cnt].first==i)SEG::update(1,1,n,i,f[cnt-1].second);
						else SEG::update(1,1,n,i,f[cnt].second+dec*i);
					break;
				}
				for(auto v:rc[id])
					SEG::modify(1,1,n,1,rc[id].lst,v.val);	//1
				vector<NODE> ().swap(rc[id]);
				++cnt;f[cnt]={i+1,SEG::query(1,1,n,i-lim+1,i)-dec*i};
			}
			printf("%lld\n",f[cnt].second);
			vector<int> ().swap(V);
		}
	}
}
*/
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);	
	int C=read();
	if(C<=9){Sub1_9::Main();return 0;}
//	Sub_All::Main();
return 0;
}
