#include <bits/stdc++.h>
using namespace std;
const int N=3020;
int n,m;
char ans[N];
char maxx,minx;
int maxn[N],minn[N];
string op[N];
struct node{
	string s;
	int id;
	friend bool operator<(node x,node y){
		return x.s<y.s;
	}
}maxa[N],mina[N];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>op[i];maxx='a'-1;
		minx='z'+1;
		for(int j=0;j<m;j++){
			if(op[i][j]>=maxx){
				maxx=op[i][j];
				maxn[i]=j;
			}
			if(op[i][j]<minx || 
			(op[i][j]<=minx && j!=0)){
				minx=op[i][j];
				minn[i]=j;
			}
		}
		int l=0;
		if(maxn[i]!=0){
			while(op[i][l]==maxx) l++;
			if(l!=maxn[i]){
				swap(op[i][l],op[i][maxn[i]]);
				maxa[i].s=op[i];
				swap(op[i][l],op[i][maxn[i]]);
			}
			else maxa[i].s=op[i];
		}
		else maxa[i].s=op[i];
		l=0;maxa[i].id=i;
		if(minn[i]!=0){
			while(op[i][l]==minx) l++;
			if(l!=minn[i]){
				swap(op[i][l],op[i][minn[i]]);
				mina[i].s=op[i];
				swap(op[i][l],op[i][minn[i]]);				
			}
			else mina[i].s=op[i];
		}
		else mina[i].s=op[i];
	}
	if(n==1){cout<<1;return 0;}
	sort(maxa+1,maxa+n+1);
	for(int i=1;i<=n;i++){
		int ol=lower_bound(maxa+1,maxa+n+1,mina[i])-maxa;
		if(ol==1 || maxa[ol-1].id==i) ans[i]='1';
		else ans[i]='0';
	}
	for(int i=1;i<=n;i++) cout<<ans[i];
	return 0;
}
