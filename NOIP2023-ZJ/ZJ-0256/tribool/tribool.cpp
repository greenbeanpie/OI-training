#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
int c;
struct edge{
	int nxt,to,va;
}a[N*2];
int head[N*2],cnt;
void add(int x,int y,int z){
	a[++cnt].nxt=head[x];
	head[x]=cnt;
	a[cnt].to=y;
	a[cnt].va=z;
}
struct bot{
	int op,i,va;
	//op == 2 is val{0,1,2}
	//else op==1 val={+}
	//else op==0 val={-}
}b[N];
int v[N];
void Yaixy(){
	cnt=0;
	memset(v,0,sizeof(v));
	memset(head,0,sizeof(head));
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
}
int fla=1;
void dfs(int x,int va){
	if(!fla) return;
	int i,j;
	v[x]=va;
	//if(x==856) cout<<"FFInd\n";
	for(i=head[x];i;i=a[i].nxt){
		int to=a[i].to;
		//cout<<"edge: "<<x<<" "<<to<<" "<<va<<" "<<a[i].va<<' '<<v[to]<<"\n";
	//if(to==104) cout<<"FFInd\n";
		int fff=0;
		if(b[to].op==2){
			if(v[to]<0) fff=1;
			v[to]=b[to].va;
		}
		//if(fff) cout<<to<<"\n";
		if(v[to]>=0){
			if(va==2){
				if(v[to]!=2){
					fla=0;
					return;
				}
			}
			else{
				if(a[i].va==0){
					if(va!=1-v[to]){
						fla=0;return;
					}
				}
				else if(va!=v[to]){//cout<<"!\n";
					fla=0;return;
				}
			}
		}
		if(v[to]<0||fff){
			if(a[i].va==0){
				if(va==2) v[to]=2;
				else v[to]=1-va;
			}
			else v[to]=va;
			dfs(to,v[to]);
		}
	}
}
vector<int> lisp;
int needfortest=104;
void fdlll(int x){
	/*if(x==104){
		cout<<"Find :\n";
	}*/
	int i,j;
	v[x]=3;
	lisp.push_back(x);
	for(i=head[x];i;i=a[i].nxt){
		int to=a[i].to;
		if(v[to]>0) continue;
		fdlll(to);
	}
}
int lll[N];
void solve(){
	int i,j;
	Yaixy();
	int n,m;
	cin>>n>>m;
	//cout<<n<<" "<<m<<"\n";
	for(i=1;i<=n;i++){
		b[i].i=i;
		b[i].op=1;
	}
//cout<<b[104].op<<' '<<b[104].i<<' '<<b[104].va<<"\n";
	for(i=1;i<=m;i++){
		char c;
		cin>>c;
		if(c=='+'){
			int x,y;
			cin>>x>>y;
			/*if(x==needfortest||y==needfortest){
				cerr<<"Attention1: "<<x<<" "<<y<<"\n";
				cerr<<b[y].op<<"\n";
			}*/
			b[x]=b[y];
		}
		else if(c=='-'){
			int x,y;
			cin>>x>>y;
			
			/*if(x==needfortest||y==needfortest){
				cerr<<"Attention2: "<<x<<" "<<y<<"\n";
				cerr<<b[y].op<<"\n";
			}*/
			if(b[y].op==2){
				b[x].op=2;
				//b[x].i=b[y].i;
				//b[x].val=b[y].val;
				if(b[y].va==2) b[x].va=2;
				else b[x].va=1-b[y].va;
			}
			else{
				b[x].op=1-b[y].op;
				b[x].i=b[y].i;
				b[x].va=1-b[y].va;
			}
			
		}
		else{
			int x;
			cin>>x;
			/*if(x==needfortest){
				cerr<<"Attention3"<<x<<"\n";
			}*/
			b[x].op=2;
			if(c=='T') b[x].va=1;
			else if(c=='F') b[x].va=0;
			else if(c=='U') b[x].va=2;
		}
	}
//cout<<b[104].op<<' '<<b[104].i<<' '<<b[104].va<<"\n";
	for(i=1;i<=n;i++){
		if(b[i].op==1){
			
			add(i,b[i].i,1);
			add(b[i].i,i,1);
		}
		else if(b[i].op==0){//cout<<"!\n";
			add(i,b[i].i,0);
			add(b[i].i,i,0);
		}
	}
	for(i=1;i<=n;i++) v[i]=-1;
	/*for(i=1;i<=n;i++){
		if(b[i].op==2) v[i]=b[i].va;
	}*/
	//for(i=1;i<=n;i++){
//	/	cout<<b[i].op<<" "<<b[i].i<<" "<<b[i].va<<"\n";
//	}
//cout<<"EGD\n";
//for(i=head[104];i;i=a[i].nxt) cout<<a[i].to<<" ";cout<<"\n";
	int ans=0,sss=0;
	for(i=1;i<=n;i++){
		if(v[i]<0){
			sss++;
			lisp.clear();
			fdlll(i);
			for(auto k:lisp) v[k]=-1;
			//cout<<"For a : ";
			//for(auto k:lisp) cout<<k<<" ";
			//cout<<"\n";
			if(b[i].op==2){
				fla=1;
				dfs(i,b[i].va);
				if(fla){
					int sum=0;
					for(auto k:lisp){
						if(v[k]==2) sum++;
					}
					ans+=sum;
					//cout<<"SUM==SIZE: "<<sum<<'\n';
				}
				for(auto k:lisp) lll[k]=v[k];
			}
			else{
				int mi=1e9;
				for(j=0;j<=2;j++){
					fla=1;
					dfs(i,j);
					//cout<<"For lisp: ";
					//for(auto k:lisp) cout<<v[k]<<' ';cout<<"\n";
					//cout<<"The fla is "<<fla<<"\n";
					if(fla){
						int sum=0;
						/*if(j<2&&lisp.size()>1){
							cout<<"may error:\n";
							for(auto k:lisp) cout<<k<<" ";cout<<"\n";
							for(auto k:lisp) cout<<v[k]<<" ";cout<<"\n";
						}*/
						for(auto k:lisp){
							//cout<<v[k]<<" ";
							if(v[k]==2) sum++;
						}//cout<<"\n";
						mi=min(mi,sum);
					}/*else{
						cout<<"may error:\n";
						for(auto k:lisp) cout<<k<<" ";cout<<"\n";
						for(auto k:lisp) cout<<v[k]<<" ";cout<<"\n";
					}*/
					for(auto k:lisp) v[k]=-1;
				}
				/*for(j=0;j<=2;j++){
					fla=1;
					dfs(i,j);
					//cout<<"For lisp: ";
					//for(auto k:lisp) cout<<v[k]<<' ';cout<<"\n";
					//cout<<"The fla is "<<fla<<"\n";
					if(fla){
						int sum=0;
						/*if(j<2&&lisp.size()>1){
							cout<<"may error:\n";
							for(auto k:lisp) cout<<k<<" ";cout<<"\n";
							for(auto k:lisp) cout<<v[k]<<" ";cout<<"\n";
						}*/
						/*for(auto k:lisp){
							//cout<<v[k]<<" ";
							if(v[k]==2) sum++;
						}//cout<<"\n";
						if(sum==mi) for(auto k:lisp){lll[k]=v[k];if(k==104) cout<<lll[k]<<"IN here\n";}
					}
					for(auto k:lisp) v[k]=-1;
				}*/
				ans=ans+mi;
			}
			for(auto k:lisp) v[k]=3;
		}
	}
	/*cout<<"!!!: ";
	cout<<v[104]<<"\n";
	//cerr<<"Ans:  ";
	for(i=1;i<=n;i++){
		ans+=(lll[i]==-1);
		if(lll[i]==-1) cout<<i<<"\n\n\n";
		//cout<<lll[i]<<" ";
	}cout<<"\n";
	cerr<<sss<<"\n\n\n";*/
	cout<<ans<<"\n";
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int i,j,k;
	int T;
	//T=1;
	//freopen("att.in","r",stdin);
	cin>>c>>T;
	//freopen("test.in","r",stdin);
	while(T--) solve();
}
/*
1 3
3 3
- 2 1
- 3 2
+ 1 3
3 3
- 2 1
- 3 2
- 1 3
2 2
T 2
U 2

1 1
3 3
- 2 1
- 3 2
+ 1 3

1 1
6 6
+ 3 1
U 4
+ 2 3
+ 4 5
U 6
+ 1 6

1 1
10 10
+ 8 1
U 7
+ 6 1
U 6
U 3
U 7
+ 1 1
U 4
U 9
+ 7 4

1 1
5 5
U 1
+ 2 1
+ 3 2
+ 4 3
+ 1 5

1 1
2 3
+ 1 2
U 2
+ 2 1
*/
