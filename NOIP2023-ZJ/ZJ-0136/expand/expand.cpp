#include<bits/stdc++.h>
using namespace std;
int c,n,m,q,kx,ky;
long long ox[500005],oy[500005],x[500005],y[500005],a[500005][2],p;
bool f[2005][2005];
void sol1(){
	memset(f,0,sizeof(f));
	f[0][0]=1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(x[i]>y[j]){
				f[i][j]|=f[i][j-1];
				f[i][j]|=f[i-1][j];
				f[i][j]|=f[i-1][j-1];
			}
		}
	}
	if(f[n][m])cout << "1";
	else cout << "0";
}

void sol(){
	int curn = n;
	int curm = m;
	if(c==1){
		if(x[1]!=y[1])cout << "1";
		else cout << "0";
	}else if(c==2){
		if((x[1]-y[1])*(x[n]-y[m]) > 0)cout << "1";
		else cout << "0";
	}else{
	//	cout << x[1] << " " << y[1] << " " << x[n] << " " << y[n] << endl;
		if((x[1]-y[1])*(x[n]-y[m]) <= 0)cout << "0";
		else{
			for(int i = 1; i <= n; i++)a[i][0]=x[i];
			for(int i = 1; i <= m; i++)a[i][1]=y[i];
			if(a[1][0] > a[1][1])p=0;
			else{
				p=1;
				for(int i = 1; i <= m; i++)x[i]=a[i][1];
				for(int i = 1; i <= n; i++)y[i]=a[i][0];
				swap(n,m);
			}
			if(c <= 7)sol1();
			else cout << "1";
		}
	}
	n = curn;
	m = curm;
}

int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	for(int i = 1; i <= n; i++)scanf("%lld",&ox[i]);
	for(int i = 1; i <= m; i++)scanf("%lld",&oy[i]);
	for(int i = 1; i <= n; i++)x[i]=ox[i];
	for(int i = 1; i <= m; i++)y[i]=oy[i];
	sol();
	while(q--){
		for(int i = 1; i <= n; i++)x[i]=ox[i];
		for(int i = 1; i <= m; i++)y[i]=oy[i];
		scanf("%d%d",&kx,&ky);
		while(kx--){
			int p,v;
			scanf("%d%d",&p,&v);
			x[p]=v;
		}
		while(ky--){
			int p,v;
			scanf("%d%d",&p,&v);
			y[p]=v;
		}
		sol();
	}
	return 0;
}