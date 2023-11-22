#include <bits/stdc++.h>
using namespace std;
int n,m,a[3010][30];
char c[30],cc[30][2],ccc[3010][3010];
string str[20];
int minn=100;
inline int read(){
	int f=1,s=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return f*s;
}

int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	n=read();
	m=read();
	if(n==1){
		printf("1\n");
	}
	else if(m==1){
		for(int i=1;i<=n;i++){
			cin>>c[i];
			if(c[i]-'a'<minn){
				minn=c[i]-'a';
			}
		}
		for(int i=1;i<=n;i++){
			if(c[i]-'a'==minn){
				printf("1");
			}
			else{
				printf("0");
			}
		}
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			cin>>str[i];
			if(str[i][0]<str[i][1]){
				cc[i][0]=str[i][1];
				cc[i][1]=str[i][0];
			}
			else{
				cc[i][1]=str[i][1];
				cc[i][0]=str[i][0];
			}
		}
		for(int i=1;i<=n;i++){
			int flag=1;
			for(int j=1;j<=n;j++){
				if(j==i){
					continue;
				}
				if(cc[i][1]>cc[j][0] || (cc[i][1]==cc[j][0] && cc[i][0]>cc[j][1])){
					flag=0;
					break;
				}
			}
			if(flag){
				printf("1");
			}
			else{
				printf("0");
			}
		}
	}
	else{
		for(int i=1;i<=n;i++){
			string sss;
			int le=0;
			cin>>sss;
			int len=sss.length();
			for(int j=0;j<len;j++){
				int xx=sss[j]-'a'+1;
				a[i][xx]+=1;
			}
			for(int j=26;j>=1;j--){
				while(a[i][j]){
					a[i][j]--;
					ccc[i][++le]='a'+j-1;
				}
			}
		}
		for(int i=1;i<=n;i++){
			int flag1=0;
			for(int j=1;j<=n;j++){
				if(i==j){
					continue;
				}
				int left=1,right=m;
				while(left<=m && right>=1){
					if(ccc[i][right]<ccc[j][left]){
						flag1=1;
						break;
					}
					if(ccc[i][right]>ccc[j][right]){
						flag1=0;
						break;
					}
					left++;
					right--;
				}
				if(flag1==0){
					break;
				}
			}
			if(flag1){
				printf("1");
			}
			else{
				printf("0");
			}
		}
	}
	printf("\n");
	return 0;
}