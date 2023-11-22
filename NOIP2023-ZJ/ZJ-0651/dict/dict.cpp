#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,zm[30][3000],minzm[30],r,cminzm[30];
inline ll read(){
	ll x=0,w=1;char ch;ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-'){w=-1;}ch=getchar();}
	while(ch>='0'&&ch<='9'){x=10*x+ch-'0';ch=getchar();}
	return x*w;
}
void strread(ll q){
	char ch=getchar();
	while(ch<'a'||ch>'z'){ch=getchar();}
	for(ll i=0;i<m;i++){zm[ch-'a'][q]++;ch=getchar();}
	int pd=0,cpd=0;
	for(ll i=25;i>=0;i--){
		if(zm[i][q]){
			for(ll k=i+1;k<=25;k++){
				if(minzm[k]){
					pd=1;
					break;
				}
			}
			break;
		}
	}
	if(q==0){pd=1;}
	if(pd){
	r=q;
	for(ll i=0;i<26;i++){cminzm[i]=minzm[i];minzm[i]=zm[i][q];}
	}else{
		for(ll i=25;i>=0;i--){
			if(zm[i][q]){
				for(ll k=i+1;k<=25;k++){
					if(cminzm[k]){
						cpd=1;
						break;
					}
				}
				break;
			}
		}
		if(cpd){for(ll i=0;i<26;i++){cminzm[i]=zm[i][q];}}
	}
	return ;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	n=read();m=read();
	for(ll q=0;q<n;q++){
		strread(q);
	}
	for(ll q=0;q<n;q++){
		int out=0;
		if(q!=r){
			for(ll i=0;i<=25;i++){
				if(minzm[i]){
					for(ll k=0;k<=i-1;k++){
						if(zm[k][q]){
							out=1;
							break;
						}
					}
				}
				if(out==1)break;
			}
		}else{
			for(ll i=0;i<=25;i++){
				if(cminzm[i]){
					for(ll k=0;k<=i-1;k++){
						if(zm[k][q]){
							out=1;
							break;
						}
					}
				}
				if(out==1)break;
			}
		}
		cout<<out;
	}
	return 0;
}
