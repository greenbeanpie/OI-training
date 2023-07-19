#include <bits/stdc++.h>
#define int long long
using namespace std;
const int M=1<<26; 
const int g=3;
const int gi=332748118;
const int MOD=998244353;

int n,m,len,inv,mov,rev[M],a[M],b[M];
string s1,s2;

int expow(int b,int p){
	if(p==0)return 1;
	if(p==1)return b;
	int temp=expow(b,p/2)%MOD;
	if(p%2==0)return temp*temp%MOD;
	return temp*temp%MOD*b%MOD;
}

void NTT(int a[],int n,int type){
	for(int i=0;i<n;i++){
		if(i<rev[i]){
			swap(a[i],a[rev[i]]);
		}
	}
	int gn,g0,x,y;
	for(int i=1;i<n;i<<=1){
		gn=expow(type?g:gi,(MOD-1)/(i<<1));
		for(int j=0;j<n;j+=(i<<1)){
			g0=1;
			for(int k=0;k<i;k++,g0=g0*gn%MOD){
				x=a[j+k],y=g0*a[i+j+k]%MOD;
                a[j+k]=(x+y)%MOD;
                a[i+j+k]=(x-y+MOD)%MOD;
			}
		}
	}
} 

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>s1>>s2;
	n=s1.size()-1,m=s2.size()-1;
	for(int i=0;i<=n;i++){
		a[i]=s1[i]-'0';
	}
	for(int i=0;i<=m;i++){
		b[i]=s2[i]-'0';
	}
	mov=max((int)ceil(log2(n+m)),1ll);
	len=1<<mov;
	for(int i=0;i<len;i++){
		rev[i]=(rev[i>>1]>>1)|((i&1)<<(mov-1));
	}
	NTT(a,len,1);
	NTT(b,len,1);
	for(int i=0;i<=len;i++){
		a[i]=a[i]*b[i]%MOD;
	}
	NTT(a,len,0);
	inv=expow(len,MOD-2);
	int last=0;
	for(int i=n+m;i>=0;i--){
		a[i]=a[i]*inv%MOD+last;
		last=a[i]/10;
		if(i!=0)a[i]%=10;
	}
	for(int i=0;i<=n+m;i++){
		cout<<a[i];
	}
	return 0;
}