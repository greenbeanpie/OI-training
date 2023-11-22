#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	int p=0,o=1;char po=getchar();
	while(!(po>='0'&&po<='9')){if(po=='-')o=-1;po=getchar();}
	while(po>='0'&&po<='9'){p=p*10+po-'0';po=getchar();}
	return p*o;
}
int pl,lp,a,s,ans,d[100005];
int zhan[100005][2],tt,f[100005];
void qiuqiu(int z){
	tt=0;zhan[++tt][0]=z;zhan[tt][1]=1;f[z]=1;
	while(!(abs(d[zhan[tt][0]])<=1||f[abs(d[zhan[tt][0]])-1]>0)){
		++tt;zhan[tt][0]=abs(d[zhan[tt-1][0]])-1;
		if(d[zhan[tt-1][0]]<0)zhan[tt][1]=-zhan[tt-1][1];
		else zhan[tt][1]=zhan[tt-1][1];
		f[zhan[tt][0]]=tt;
	}
	if(abs(d[zhan[tt][0]])<=1){
		for(int i=1;i<=tt;i++)f[zhan[i][0]]=0;
		if(d[zhan[tt][0]]==0)for(int i=1;i<=tt;i++)d[zhan[i][0]]=0;
		else if(d[zhan[tt][0]]==zhan[tt][1])for(int i=1;i<=tt;i++)d[zhan[i][0]]=zhan[i][1];
		else if(d[zhan[tt][0]]!=zhan[tt][1])for(int i=1;i<=tt;i++)d[zhan[i][0]]=-zhan[i][1];
		return;
	}
	if(f[abs(d[zhan[tt][0]])-1]>0){
		if(d[zhan[tt][0]]<0&&zhan[f[abs(d[zhan[tt][0]])-1]][1]==zhan[f[zhan[tt][0]]][1])for(int i=1;i<=tt;i++)d[zhan[i][0]]=0;
		else if(d[zhan[tt][0]]>0&&zhan[f[abs(d[zhan[tt][0]])-1]][1]==-zhan[f[zhan[tt][0]]][1])for(int i=1;i<=tt;i++)d[zhan[i][0]]=0;
		else if(d[zhan[tt][0]]<0&&zhan[f[abs(d[zhan[tt][0]])-1]][1]==-zhan[f[zhan[tt][0]]][1])for(int i=1;i<=tt;i++)d[zhan[i][0]]=zhan[i][1];
		else if(d[zhan[tt][0]]>0&&zhan[f[abs(d[zhan[tt][0]])-1]][1]==zhan[f[zhan[tt][0]]][1])for(int i=1;i<=tt;i++)d[zhan[i][0]]=zhan[i][1];
		for(int i=1;i<=tt;i++)f[zhan[i][0]]=0;
		return;
	}
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	pl=read();lp=read();
	while(lp--){
		a=read();s=read();ans=0;
		memset(d,0,sizeof(d));
		for(int i=1;i<=a;i++)d[i]=i+1;
		for(int i=1;i<=s;i++){
			char z;cin>>z;
			if(z=='T'){int x=read();d[x]=1;}
			if(z=='F'){int x=read();d[x]=-1;}
			if(z=='U'){int x=read();d[x]=0;}
			if(z=='+'){int x=read(),c=read();d[x]=d[c];}
			if(z=='-'){int x=read(),c=read();d[x]=-d[c];}
		}
		for(int i=1;i<=a;i++){
			if(d[i]>1||d[i]<-1)qiuqiu(i);
			if(d[i]==0)ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
1 3
3 3
- 2 1
- 3 2
+ 1 3
3 3
- 2 1
- 3 2
- 1 3
2 2
T 2
U 2
*/