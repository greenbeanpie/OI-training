#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int f=1,s=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=(s<<1)+(s<<3)+(ch^48);ch=getchar();}
	return f*s;
}
struct str{
	string p;
	int id;
}a[3005];
bool cmp(char u,char v){
	return u>v;
}
string z[3005],d[3005];
char b[3005],k[3005];
int n,m;
bool t[3005];
signed main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	n=read(),m=read();
	for(register int i=0;i<m;i++) k[i]='z';
	for(register int i=1;i<=n;i++){
		cin>>a[i].p;
		string tmp=a[i].p;
		for(register int j=0;j<m;j++){
			b[j]=tmp[j];
		}
		sort(b,b+m,cmp);
		for(register int j=0;j<m;j++){
			if(b[j]<k[j]){
				for(register int p=0;p<m;p++){
					k[p]=b[p];
				}
				break;
			}
			else if(b[j]>k[j]){
				break;
			}
		}
	}
	for(register int i=1;i<=n;i++){
		string tmp=a[i].p;
		for(register int j=0;j<m;j++){
			b[j]=tmp[j];
		}
		sort(b,b+m);
		bool bl=false;
		for(register int j=0;j<m;j++){
			if(b[j]>k[j]){
				bl=true;
				break;
			}
			else if(b[j]<k[j]){
				t[i]=true;
				break;
			}
		}
		if(bl==false) t[i]=true;
	}
	for(register int i=1;i<=n;i++){
		cout<<t[i];
	}
	puts("");
	return 0;
}
//保佑我0.98s卡过去！！！