#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,d,cnt,maxx,T,C,c[1010][3];bool da[100050];string cha;
unordered_map <string,bool> ma;
inline ll read(){ll x=0,w=1;char ch;ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-'){w=-1;}ch=getchar();}while(ch>='0'&&ch<='9'){x=10*x+ch-'0';ch=getchar();}return x*w;}
void trytry(string chabool){
	if(ma[chabool]!=0){return ;}
	ll en=0;
	for(ll i=0;i<m;i++){
		if(chabool[i]=='1'){
			for(ll j=c[i][0];j<=c[i][1];j++){
				if(j>=0&&j<=n+1){
					if(da[j]==0){
						en-=d;
						da[j]=1;
					}
				}
			}
			en+=c[i][2];
		}
	}
	ll lxs=0,lg=0;
	for(ll j=1;j<=n+1;j++){
		if(da[j]==1){
			lg++;
			da[j]=0;
		}else{
			if(lg>0){
				lxs=max(lg,lxs);
				lg=0;
			}
		}
	}
	lxs=max(lg,lxs);
	if(lxs<=k){
		ma[chabool]=1;
		maxx=max(en,maxx);
		en=0;
	}
	for(ll i=0;i<m;i++){
		if(chabool[i]=='1'){
			chabool[i]='0';
			trytry(chabool);
			chabool[i]='1';
		}
	}
	return ;
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	C=read();T=read();
	for(ll o=0;o<T;o++){
		n=read();m=read();k=read();d=read();
		cnt=0;cha="";maxx=0;
		for(ll i=0;i<m;i++){
			ll x=read(),y=read(),V=read();

			if(y<=k){
				c[cnt][0]=x-y+1;c[cnt][1]=x;c[cnt][2]=V;
				cnt++;
				cha+="1";
			}
		}
		m=cnt;
		trytry(cha);
		cout<<maxx<<"\n";
	}
		
	return 0;
}
