#include<bits/stdc++.h>
#define int long long
using namespace std; constexpr int maxn(1e5+10);
int n,m,x[maxn],y[maxn],buc[maxn],bucnt;
signed main(){
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> x[i],buc[++bucnt]=x[i];
	}
	for(int i=1;i<=m;i++){
		cin >> y[i],buc[++bucnt]=y[i];
	}
	sort(buc+1,buc+1+bucnt),bucnt=unique(buc+1,buc+1+bucnt)-buc-1;
	for(int i=1;i<=n;i++) x[i]=lower_bound(buc+1,buc+1+bucnt,x[i])-buc;
	for(int i=1;i<=m;i++) y[i]=lower_bound(buc+1,buc+1+bucnt,y[i])-buc;
	for(int i=1;i<=n;i++) printf("%d ",x[i]); putchar(10);
	for(int i=1;i<=m;i++) printf("%d ",y[i]); putchar(10);
	return 0;
}
/*
6 6
195982977 303897138 437154869 81559605 365511323 302808478
342942401 297976421 445071632 83871721 304067809 427239638
*/