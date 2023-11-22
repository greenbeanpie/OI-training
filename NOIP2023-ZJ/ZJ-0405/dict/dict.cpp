#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
	return s*w;
}
const int N=3050;
char s[N][N];
char mx[N][N];
int mn;
//char mn[N][N];
//string s[N],mx[N];
bool cmp(char x,char y){
	return x>y;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int n=read(),m=read();
//	scanf("%s %s",s,s2);
//	if(s>s2) cout<<1;
//	else cout<<2;
//	scanf("%s",s[1]);
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]);
//		mx[i]=s[i];
		for(int j=0;j<m;j++){
			mx[i][j]=s[i][j];
		}
		sort(s[i],s[i]+m);
		sort(mx[i],mx[i]+m,cmp);
	}
	int mn=1;
	for(int i=2;i<=n;i++){
		for(int j=0;j<m;j++){
			if(mx[i][j]<mx[mn][j]){
				mn=i;
//				cout<<i<<endl;
				break;
			}
			else if(mx[i][j]>mx[mn][j]) break;
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=0;j<m;j++){
//			cout<<s[i][j];
//		}
//		cout<<endl;
//	}
//	cout<<"_______________"<<endl;
//	for(int i=1;i<=n;i++){
//		for(int j=0;j<m;j++){
//			cout<<mx[i][j];
//		}
//		cout<<endl;
//	}
//	cout<<s[4]<<" "<<mx[2]<<" "<<(s[4]>mx[2])<<endl;
//	cout<<mn<<endl;
//	for(int j=0;j<m;j++){
//		cout<<s[4][j];
//	}
//	cout<<endl;
//	for(int j=0;j<=m;j++){
//		cout<<mx[mn][j];
//	}
//	cout<<endl;
	for(int i=1;i<=n;i++){
		bool f=1;
		if(i==mn){
			printf("1");
			continue;
		}
		for(int j=0;j<m;j++){
			if(s[i][j]>mx[mn][j]){
				f=0;
				break;
			}
			else if(s[i][j]<mx[mn][j]){
				f=1;
				break;
			}
		}
		if(!f) printf("0");
		else printf("1");
	}
	return 0;
}
