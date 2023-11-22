#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
using namespace std;
const int N=3005;
int n,m,p[N],q[N],occ[N][28];
char s[N];
inline bool check(int x,int y){
	if(!x)return 1;
	per(i,25,0)if(occ[x][i]!=occ[y][i])
		if(occ[x][i]>occ[y][i])return 1;
		else return 0;
	return 0;
}
inline int check2(int x,int y){
	int t1=0,t2=0;
	rep(i,0,25)rep(j,1,occ[x][i])p[++t1]=i;
	per(i,25,0)rep(j,1,occ[y][i])q[++t2]=i;
	rep(i,1,t1)if(p[i]!=q[i])return p[i]<q[i];
	return 0;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	if(n==1)return cout<<"1\n",0;
	rep(i,1,n){
		cin>>s+1;
		rep(j,1,m)occ[i][s[j]-'a']++;
	}
	int id=1,id2=0;
	rep(i,2,n){
		if(check(id,i))id2=id,id=i;
		else if(check(id2,i))id2=i;
	}
	rep(i,1,n){
		int ans;
		if(i==id)ans=check2(i,id2);
		else ans=check2(i,id);
		cout<<ans;
	}
	return 0;
}