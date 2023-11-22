#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#ifdef DEBUG
template<typename T>
ostream& operator << (ostream &out,vector<T> a){
	out<<'[';
	for(T x:a)out<<x<<',';
	return out<<']';
}
template<typename T>
vector<T> ary(T *a,int l,int r){
	return vector<T>{a+l,a+1+r};
}
template<typename T>
void debug(T x){
	cerr<<x<<endl;
}
template<typename T,typename...S>
void debug(T x,S...y){
	cerr<<x<<' ',debug(y...);
}
#else
#define debug(...) void()
#endif
const int N=3e3+10,V=26;
int n,m,mn[N],mx[N];
char str[N];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",str+1);
		mn[i]=V,mx[i]=-1;
		for(int j=1;j<=m;j++){
			mn[i]=min(mn[i],str[j]-'a');
			mx[i]=max(mx[i],str[j]-'a');
		}
	}
	for(int i=1;i<=n;i++){
		bool flag=1;
		for(int j=1;j<=n;j++)if(i^j){
			if(mx[j]<=mn[i]){
				flag=0;break;
			}
		}
		putchar(flag+48);
	}
	puts("");
	return 0;
}