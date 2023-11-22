#include <bits/stdc++.h>
#define int long long 
using namespace std;
/*
其实修改就是为了让测试点多一点，应该没有性质的
发现其实就是要让x中每个值都比y中每个值大或者小
而且大或者小是固定的，因为首尾肯定要大和小的
n^2应该不算难，设f[i][j]表示x走到i，y走到j是否可行
每一步肯定不能空耗，要么是从f[i-1][j]转移过来，要么是从f[i][j-1]转移过来，要么是f[i-1][j-1]
*/
const int N=5e5+5,M=2005;
int ID,n,m,q;
int a[N],b[N],oa[N],ob[N];
int x,y;
vector<int> cga,cgb;
bool f[M][M];
inline int solvebf(void){
	memset(f,false,sizeof f);
	if(a[1]>b[1] and a[n]>b[m]){
		f[1][1]=true;
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
			if((i==1 and j==1) or a[i]<=b[j])continue;
			f[i][j]=f[i-1][j]|f[i][j-1]|f[i-1][j-1];
		}
	}
	else if(a[1]<b[1] and a[n]<b[m]){
		f[1][1]=true;
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
			if((i==1 and j==1) or a[i]>=b[j])continue;
			f[i][j]=f[i-1][j]|f[i][j-1]|f[i-1][j-1];
		}
	}
	return f[n][m];
}
inline void solveA(void){
	/*
	考虑到这个特殊性质
	先判断一下有没有大于等于b[m]的，如果有的话肯定答案为0
	否则的话其实b[m]可以匹配所有上面的，上面不需要做完就可以退出
	相当于是上面要有一个展开后能覆盖1~m-1的一段
	如果对于一个a，下面b有上升的，肯定能走就走
	如果一个不行，找到目前最远可以走到的位置中可以走的最后一个位置并把它拉出来
	*/
}
inline int solve(){
	if(ID<=7)return solvebf();
	// else if(ID<=14)return solveA();
	return 0;
}
signed main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>ID>>n>>m>>q;
	for(int i=1;i<=n;i++)cin>>a[i],oa[i]=a[i];	
	for(int i=1;i<=m;i++)cin>>b[i],ob[i]=b[i];
	cout<<solve();
	while(q--){
		int ka,kb;
		cin>>ka>>kb;
		cga.clear();
		cgb.clear();
		for(int i=1;i<=ka;i++){
			cin>>x>>y;
			cga.emplace_back(x);
			a[x]=y;
		}
		for(int i=1;i<=kb;i++){
			cin>>x>>y;
			cgb.emplace_back(x);
			b[x]=y;
		}
		cout<<solve();
		for(auto i:cga)a[i]=oa[i];
		for(auto i:cgb)b[i]=ob[i];
	}
	cout<<"\n";
}