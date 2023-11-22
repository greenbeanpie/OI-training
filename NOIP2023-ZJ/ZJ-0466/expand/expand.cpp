#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	int p=0,o=1;char po=getchar();
	while(!(po>='0'&&po<='9')){if(po=='-')o=-1;po=getchar();}
	while(po>='0'&&po<='9'){p=p*10+po-'0';po=getchar();}
	return p*o;
}
int pl,a,s,d,f[500005],g[500005],m[500005],n[500005],kkl=1;
bool ans=true;
int q[500005],w[500005],qq1,qq2,ww1,ww2;
void qiuqiu(){
	if(a==s&&s==1){ans=1;return;}
	memset(q,0,sizeof(q));memset(w,0,sizeof(w));
	q[++q[0]]=f[1];w[++w[0]]=g[1];
	for(int i=2;i<a;i++)if(f[i]>f[i-1]&&f[i]>f[i+1]||f[i]<f[i-1]&&f[i]<f[i+1])q[++q[0]]=f[i];
	for(int i=2;i<s;i++)if(g[i]>g[i-1]&&g[i]>g[i+1]||g[i]<g[i-1]&&g[i]<g[i+1])w[++w[0]]=g[i];
	q[++q[0]]=f[a];w[++w[0]]=g[s];
	if(q[1]<w[1])for(int i=0;i<=max(q[0],w[0]);i++)swap(q[i],w[i]);
	qq1=1e9;ww1=1e9;
	for(int i=1;i<=q[0];i++)qq1=min(qq1,q[i]),qq2=max(qq2,q[i]);
	for(int i=1;i<=w[0];i++)ww1=min(ww1,w[i]),ww2=max(ww2,w[i]);
	if(qq1<ww1||qq2<ww2)ans=false;
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	pl=read();a=read();s=read();d=read();
	for(int i=1;i<=a;i++)f[i]=read(),m[i]=f[i];
	for(int i=1;i<=s;i++)g[i]=read(),n[i]=g[i];
	if((ll)(f[1]-g[1])*(ll)(f[a]-g[s])<=0)ans=false;
	else qiuqiu();
	if(ans==true)printf("1");else printf("0");
	for(int o=1;o<=d;o++){
		int q=read(),w=read();kkl=1;ans=true;
		for(int i=1;i<=q;i++){int z=read(),x=read();f[z]=x;}
		for(int i=1;i<=w;i++){int z=read(),x=read();g[z]=x;}
		if((ll)(f[1]-g[1])*(ll)(f[a]-g[s])<=0)ans=false;
		else qiuqiu();
		if(ans==true)printf("1");else printf("0");
		for(int i=1;i<=a;i++)f[i]=m[i];
		for(int i=1;i<=s;i++)g[i]=n[i];
	}
	return 0;
}