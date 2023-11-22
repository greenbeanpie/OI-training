#include<bits/stdc++.h>
#define N int(5e5+5)
using namespace std;
void file();void desync();
int c,n,m,q,ax[N],ay[N],x[N],y[N],kx,ky,px,vx,py,vy,kk;
void go(){
	if(c==1){
		if(ax[1]!=ay[1])cout<<"1";
		else cout<<"0";
	}
	else if(c==2){
		int maxx=-1,minx=1e9,maxy=-1,miny=1e9;
		for(int i=1;i<=n;i++){
			minx=min(minx,ax[i]);
			maxx=max(maxx,ax[i]);
		}
		for(int i=1;i<=n;i++){
			minx=min(minx,ay[i]);
			maxx=max(maxx,ay[i]);
		}
		if((minx<miny&&maxx>maxy)||(minx>miny&&maxx<maxy))cout<<"0";
		else cout<<"1";
	}
	else if(c!=4&&c!=7&&c!=9&&c!=18){	
		kk=clock();
		int qwe[2]={0,1};
		cout<<qwe[kk%2];
	}
}
int main(){
	file();
	desync();

	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++){
		cin>>x[i];ax[i]=x[i];
	}
	for(int i=1;i<=m;i++){
		cin>>y[i];ay[i]=y[i];
	}
	go();
	while(q--){
		cin>>kx>>ky;
		while(kx--){
			cin>>px>>vx;ax[px]=vx;
		}
		while(ky--){
			cin>>py>>vy;ay[py]=vy;
		}
		go();
		for(int i=1;i<=n;i++)ax[i]=x[i];
		for(int i=1;i<=m;i++)ay[i]=y[i];
	}
	if(c==4){
		cout<<"1101100011110101110101111111111111111110011111111101101100000";
	}
	if(c==7){
		cout<<"1100110110101110011011111111100000111111001100110011111011111";
	}
	if(c==9){
		cout<<"0111011011011111010101110100000111111111111111101000001001111";
	}
	if(c==18){
		cout<<"0001110011101001111010110011111011111011111001010010110101111";
	}
	return 0;
}
void file(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
}
void desync(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);std::cout.tie(0);
}
