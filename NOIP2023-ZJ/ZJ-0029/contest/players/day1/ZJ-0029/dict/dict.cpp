#include<bits/stdc++.h>
#define fi first
#define se second
#define LB lower_bound
#define UB upper_bound
#define Me(x,y) memset(x,y,sizeof x)
#define Mc(x,y) memcpy(x,y,sizeof x)
using namespace std;using ll=long long;using LL=__int128;
const int N=3e3+5,M=N*4+5,K=1e7+5;mt19937 rnd(time(0));
int n,m,ans[N],ap[N];string s;
struct node{
	string a;
	int op;
}A[2*N];int H;
int main(){
	freopen("dict.in","r",stdin);freopen("dict.out","w",stdout);
	int i,j;scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) {
		cin>>s;
		sort(s.begin(),s.end());
		A[++H]=(node){s,i};
		reverse(s.begin(),s.end());
		A[++H]=(node){s,-i};
	}
	sort(A+1,A+H+1,[](node x,node y){return x.a<y.a;});
	int R=H,cnt=0;
	for(i=H;i;i--){
		while(A[i].a<A[R].a) {
			if(A[R].op<0) cnt++,ap[-A[R].op]=1;
			R--;
		}
		if(A[i].op>0&&cnt-ap[A[i].op]==n-1) ans[A[i].op]=1;
	}
	for(i=1;i<=n;i++) printf("%d",ans[i]);printf("\n");
	cerr<<clock()*1.0/CLOCKS_PER_SEC<<'\n';
}