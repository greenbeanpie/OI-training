#include<iostream>
#include<cstring>
using namespace std;

int c,n,m,q;
int X[100005];
int Y[100005];
int Xp[100005];
int Yp[100005];

void sinit(){
	for(int i=1;i<=n;i++) X[i] = Xp[i];
	for(int i=1;i<=m;i++) Y[i] = Yp[i];
	
}
bool checkXYSame(){
	if(X[1] <= Y[1]) return false;
	if(X[n] <= Y[n]) return false;
	return true;
}

bool checkXY(){
	if(n == m) return checkXYSame();
	if(X[1] <= Y[1]) return false;
	//if(X[m] <= Y[n]) return false;
	return true;
	 
}

int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	
	scanf("%d%d%d%d",&c,&n,&m,&q);
	
	for(int i=1;i<=n;i++) {
		scanf("%d",&Xp[i]);
		X[i] = Xp[i];
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&Yp[i]);
		Y[i] = Yp[i];
	} 
	

	for(int lll=0;lll<=q;lll++){
		if(lll == 0){
			if(checkXY()) printf("1");
			else printf("0");
			continue;
		}
		sinit();
		int Kx,Ky,p,v;
		scanf("%d%d",&Kx,&Ky);
		
		for(int i=1;i<=Kx;i++){
			scanf("%d%d",&p,&v);
			X[p] = v;
		}
		
		for(int i=1;i<=Ky;i++){
			scanf("%d%d",&p,&v);
			Y[p] = v;
		}
		
		
		
		if(checkXY()) printf("1");
		else printf("0");
		
		
	}
	
	
	
	
	
	return 0;
}
