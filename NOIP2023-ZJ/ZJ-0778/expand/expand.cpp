#include <bits/stdc++.h>
#define rep(i,j,k) for(int i = (j);i <= (k);i++)
#define per(i,j,k) for(int i = (j);i >= (k);i--)
#define ll long long
#define pii pair<int,int>
#define SZ(S) (int)S.size()
#define mkp make_pair
#define uint unsigned int
#define inf 0x3f3f3f3f
using namespace std;

template <class P>
void chkmax(P &x,P y){
	if(x < y) x = y;
}

template <class Q>
void chkmin(Q &x,Q y){
	if(x > y) x = y;
}

void qread(int &x){
	char ch = getchar();
	while(ch < '0' && ch > '9') ch = getchar();
	x = 0;
	while(ch >= '0' && ch <= '9'){
		x = x * 10 + ch - '0';
		ch = getchar();
	}
}

int testid,n,m,nn,mm,q;
int aa[500005],bb[500005],a[500005],b[500005],Mx[500005],Mn[500005];

//int cnt;
//int _tmp[1500005];
vector <pii> ext[500005][2];
//void fix(int &val){
//	val = lower_bound(_tmp + 1,_tmp + cnt + 1,val) - _tmp;
//}

int sp(){
	Mx[0] = -inf;
	rep(i,1,n) Mx[i] = max(Mx[i - 1],a[i]);
	Mn[0] = inf;
	rep(i,1,n) Mn[i] = min(Mn[i - 1],a[i]);

	int j = 0,Mxx = -inf,Mnn = inf;
	rep(i,1,m){
		chkmin(Mnn,b[i]);
		if(b[i] <= Mxx) continue;
		Mxx = b[i];
		while(j < n && Mx[j + 1] <= b[i]) j++;
		if(Mn[j] <= Mnn) return 0;
	}
	if(Mn[n] <= Mnn) return 0;
	if(Mxx >= Mx[n]) return 0;
	return 1;
}

int solve(){
	if(a[1] <= b[1]){
		swap(n,m);
		rep(k,1,max(n,m)) swap(a[k],b[k]);
	}
	if(!sp()) return 0;
	reverse(a + 1,a + n + 1);reverse(b + 1,b + m + 1);
	return sp();
}

int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&testid,&n,&m,&q);
	rep(i,1,n){
		scanf("%d",&aa[i]);
//		_tmp[++cnt] = aa[i];
	}
	rep(i,1,m){
		scanf("%d",&bb[i]);
//		_tmp[++cnt] = bb[i];
	}
	rep(i,1,q){
		int kx,ky,ppos,vval;
		scanf("%d%d",&kx,&ky);
		ext[i][0].resize(kx);
		ext[i][1].resize(ky);
		rep(k,1,kx){
			scanf("%d%d",&ppos,&vval);
			ext[i][0][k - 1] = mkp(ppos,vval);
//			_tmp[++cnt] = vval;
		}
		rep(k,1,ky){
			scanf("%d%d",&ppos,&vval);
			ext[i][1][k - 1] = mkp(ppos,vval);
//			_tmp[++cnt] = vval;
		}
	}
/*	sort(_tmp + 1,_tmp + cnt + 1);
	rep(i,1,n) fix(aa[i]);
	rep(i,1,m) fix(bb[i]);
	rep(i,1,q){
		rep(k,0,SZ(ext[i][0]) - 1) fix(ext[i][0][k].second);
		rep(k,0,SZ(ext[i][1]) - 1) fix(ext[i][1][k].second);
	}*/

	copy(aa + 1,aa + n + 1,a + 1);
	copy(bb + 1,bb + m + 1,b + 1);
	nn = n;mm = m;
	printf("%d",solve());
	n = nn;m = mm;
	rep(i,1,q){
		copy(aa + 1,aa + n + 1,a + 1);
		copy(bb + 1,bb + m + 1,b + 1);		
		rep(k,0,SZ(ext[i][0]) - 1) a[ext[i][0][k].first] = ext[i][0][k].second;
		rep(k,0,SZ(ext[i][1]) - 1) b[ext[i][1][k].first] = ext[i][1][k].second;
		nn = n;mm = m;
		printf("%d",solve());
		n = nn;m = mm;
	}
	printf("\n");
	return 0;
}
//g++ C.cpp -o C -Wall -Wshadow -O2 -std=c++14 -Wno-unused-result -fsanitize=address,undefined