#include<bits/stdc++.h>
using namespace std;
int x[500000+5],y[500000+5];
int cx[500000+5],cy[500000+5];
int c,n,m,q;
int main(){
	ifstream fin("expand.in");
	ofstream fout("expand.out");
	fin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++)
		fin>>x[i];
	for(int i=1;i<=m;i++)
		fin>>y[i];
	if(n==1&&m==1){
		if(x[1]==y[1]) fout<<1;
		else fout<<0;
	}
	else if(n==2&&m==2){
		if(x[1]==y[1]&&x[2]==y[2]) fout<<1;
		else fout<<0;
	}
	else if(n==1&&m==2){
		if(y[2]==y[1]&&x[1]==y[1]) fout<<1;
		else fout<<0;
	}
	else if(n==2&&m==1){
		if(x[1]==x[2]&&y[1]==x[1]) fout<<1;
		else fout<<0;
	}
	else fout<<0;
	for(int i=1;i<=q;i++){
		int kx,ky,a1,a2;
		fin>>kx>>ky;
		for(int j=1;j<=n;j++) cx[j]=x[j];
		for(int j=1;j<=m;j++) cy[j]=y[j];
		for(int j=1;j<=kx;j++){
			fin>>a1>>a2;
			cx[a1]=a2;
		}
		for(int j=1;j<=ky;j++){
			fin>>a1>>a2;
			cy[a1]=a2;
		}
		if(n==1&&m==1){
			if(cx[1]==cy[1]) fout<<1;
			else fout<<0;
		}
		else if(n==2&&m==2){
			if(cx[1]==cy[1]&&cx[2]==cy[2]) fout<<1;
			else fout<<0;
		}
		else if(n==1&&m==2){
			if(cy[2]==cy[1]&&cx[1]==cy[1]) fout<<1;
			else fout<<0;
		}
		else if(n==2&&m==1){
			if(cx[1]==cx[2]&&cy[1]==cx[1]) fout<<1;
			else fout<<0;
		}
		else fout<<0;
	}
	fout.close();
	return 0;
}