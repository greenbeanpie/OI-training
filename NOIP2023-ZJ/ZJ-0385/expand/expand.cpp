#include<bits/stdc++.h>
#define int long long
using namespace std; constexpr int maxn(5e5+10);
// man zu suo you fi-gi dou tong hao
// ye jiu shi man zu suo you  fi<gi huo zhe fi>gi
// er qie da xiao yi jing ding le , ruo a1<b1 ze ken ding shi xiao yu fou ze shi da yu
// yuan lai dou ke yi yan shen
int winc,n,m,q;
namespace subtask1{ int a[5],b[5],oria[5],orib[5];
	inline void make_it(){
		if(n==1&&m==1) cout << (a[1]!=b[1]);
		else if(n==2&&m==1){
			if(a[1]>b[1]) cout << (a[2]>b[1]);
			else if(a[1]<b[1]) cout << (a[2]<b[1]);
			else cout << 0;
		}else if(n==1&&m==2){
			if(b[1]>a[1]) cout << (b[2]>a[1]);
			else if(b[1]<a[1]) cout << (b[2]<a[1]);
			else cout << 0;
		}else{
			if(a[1]>b[1]){
				cout << (a[2]>b[2]);
			}else if(a[1]<b[1]){
				cout << (a[2]<b[2]);
			}else cout << 0;
		}
	}
	inline void solve(){
		for(int i=1;i<=n;i++) cin >> oria[i],a[i]=oria[i];
		for(int i=1;i<=m;i++) cin >> orib[i],b[i]=orib[i];
		make_it();
		for(int i=1,ka,kb,pa,pb,va,vb;i<=q;i++){
			cin >> ka >> kb;
			while(ka--) cin >> pa >> va,a[pa]=va;
			while(kb--) cin >> pb >> vb,b[pb]=vb;
			make_it();
			for(int i=1;i<=n;i++) a[i]=oria[i];
			for(int i=1;i<=m;i++) b[i]=orib[i];
		}
	}
}
namespace subtask2{ constexpr int maxn(2e3+10);
	bool f[maxn][maxn];
	int oria[maxn],orib[maxn],a[maxn],b[maxn];
// mo ren a[1]>b[1] f[i][j] dai biao ke bu ke yi yong i fu gai j
// xu yao man zu ke yi yong i-1 fu gai j huo zhe yong i fu gai j-1 bing qie man zu da yu tiao jian 
/*
6 6 60
8 4 12 2 7 10
3 6 11 1 9 5
*/
	inline void make_it(){
		memset(f,false,sizeof f);
		if(a[1]<b[1]){
			for(int j=1;j<=n;j++){
				if(b[1]<=a[j]) break;
				f[1][j]=true;
			}
			for(int i=2;i<=m;i++){
				for(int j=1;j<=n;j++){
					f[i][j]=(f[i-1][j]|f[i][j-1])&(b[i]>a[j]);
				}
			} cout << f[m][n];
		}else if(a[1]>b[1]){
			for(int j=1;j<=m;j++){
				if(a[1]<=b[j]) break;
				f[1][j]=true;
			}
			for(int i=2;i<=n;i++){
				for(int j=1;j<=m;j++){
					f[i][j]=(f[i-1][j]|f[i][j-1])&(a[i]>b[j]);
				}
			} cout << f[n][m];
		} else cout << 0;
	}
	inline void solve(){
		for(int i=1;i<=n;i++) cin >> oria[i],a[i]=oria[i];
		for(int i=1;i<=m;i++) cin >> orib[i],b[i]=orib[i];
		make_it();
		for(int i=1,ka,kb,pa,pb,va,vb;i<=q;i++){
			cin >> ka >> kb;
			while(ka--) cin >> pa >> va,a[pa]=va;
			while(kb--) cin >> pb >> vb,b[pb]=vb;
			make_it();
			for(int i=1;i<=n;i++) a[i]=oria[i];
			for(int i=1;i<=m;i++) b[i]=orib[i];
		}
	}
}
namespace subtask3{
	inline void solve(){
		
	}
}
signed main(){ freopen("expand.in","r",stdin),freopen("expand.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	cin >> winc >> n >> m >> q;
	if(winc<=2) subtask2::solve();
	else if(winc<=7) subtask2::solve();
	else if(winc<=14) subtask3::solve();
	return 0;
}
/*
6 6 6 0
3 6 11 1 9 5
8 4 12 2 7 10

3 3 6  1 1 9  5
8 4 12 2 7 10 10
*/