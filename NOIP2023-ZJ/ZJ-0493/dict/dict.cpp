#include<bits/stdc++.h>

using namespace std;

const int N=3005;

inline int read(){
	int t=1,x=0;
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') t=-1;
	for(;isdigit(ch);ch=getchar()) x=(x<<3)+(x<<1)+(ch^48);
	return t*x;
}

int n,m;
string a[N];
string maxx[N],minn[N];
int num[3005];
int flag=1;

int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		cout<<"1";
		return 0;
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=0;j<m;j++){
				num[a[i][j]-'a']++;
			}
			for(int j=0;j<26;j++){
				for(int k=1;k<=num[j];k++){
					minn[i]+=(j+'a');
				}
			}
			for(int j=25;j>=0;j--){
				for(int k=1;k<=num[j];k++){
					maxx[i]+=(j+'a');
				}
				num[j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			flag=1;
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				if(minn[i]>=maxx[j]){
					flag=0;
					break;
				}
			}
			printf("%d",flag);
		}
	}
	return 0;
}
