#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int f=1,w=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		w=w*10+ch-'0';
		ch=getchar();
	}
	return w*f;
}
inline bool cmp(char x,char y){
	return x>y;
}
inline bool cmp2(char x,char y){
	return x<y;
}
int n,m;
char a[3001][3001],b[3001][3001];//a->zuidaxu,b->zuixiaoxu
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	n=read(),m=read();
	//cout<<n;
	//cout<<m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			char k;
			cin>>k;
			a[i][j]=k;
			b[i][j]=k;
		}
		sort(a[i],a[i]+m,cmp);
		sort(b[i],b[i]+m,cmp2);
	}
	//cout<<3;
	if(n==1){
		cout<<1;
	}else{
		bool flag=false;
		for(int i=0;i<n;i++){
			flag=false;
			for(int j=0;j<n;j++){
				if(i==j){
					continue;
				}
				int l=0;
				while(b[i][l]==a[j][l]){
					l++;
				}
				if(b[i][l]>a[j][l]){
					flag=true;
					break;
				}
			}
			if(flag){
				printf("0");
			}else{
				printf("1");
			}
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

