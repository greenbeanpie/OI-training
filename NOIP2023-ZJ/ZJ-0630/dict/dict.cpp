#include<bits/stdc++.h>
using namespace std;
int n,m;
string s,ans;
int ss[3005][3005],sb[3005][3005],wz1=1,wz2=1,tot[30];
bool cmp(int xx,int yy){
	return xx>yy;
}
bool bi(int xx,int yy){
	for(int j=0;j<m;j++){
		if(sb[xx][j]>sb[yy][j])return false;
		if(sb[xx][j]<sb[yy][j])return true;
	}return true;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		memset(tot,0,sizeof(tot));
		cin>>s;
		for(int j=0;j<m;j++){
			tot[int(s[j]-'a')]++;
		}int hhh=0;
		for(int j=0;j<26;j++){
			for(int k=0;k<tot[j];k++)
			    ss[i][hhh++]=j;
		}
		for(int j=0;j<hhh;j++)
		    sb[i][j]=ss[i][hhh-j-1];
		/*sort(ss[i],ss[i]+m);
		sort(sb[i],sb[i]+m,cmp);*/
	}if(n==1){
		cout<<1;return 0;
	}
	for(int i=2;i<=n;i++){
		bool f1=bi(i,wz1),f2=bi(i,wz2);
		if(f1){
			wz2=wz1,wz1=i;
		}else if(f2){
			wz2=i;
		}
	}//cout<<wz1<<' '<<wz2<<endl;
	for(int i=1;i<=n;i++){
		bool big=true;
		if(wz1==i){
			for(int j=0;j<m;j++){
				if(ss[i][j]<sb[wz2][j])break;
				if(ss[i][j]>sb[wz2][j]){
					big=false;break;}
			}
		}
		else{
			for(int j=0;j<m;j++){
				if(ss[i][j]<sb[wz1][j])break;
				if(ss[i][j]>sb[wz1][j]){
					big=false;break;}
			}
		}ans+=char(int(big)+'0');
	}cout<<ans;
	/*
	for(int i=1;i<=n;i++){
		for(int j=0;j<m;j++)cout<<char(ss[i][j]+'a');
		cout<<endl;
		for(int j=0;j<m;j++)cout<<char(sb[i][j]+'a');
		cout<<endl;
	}*/
}