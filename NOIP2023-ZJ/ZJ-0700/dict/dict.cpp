#include<bits/stdc++.h>

using namespace std;

inline int read(){
	int s=0;char ch=getchar();
	while((ch<'a'||ch>'z')&&(ch<'0'||ch>'9'))ch=getchar();
	if(ch>='a'&&ch<='z'){
		s=ch-'a'+1;
		return s;
	}
	while(ch>='0'&&ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s;
}

int n,m,i,j,k,a[3010][3010],tmp;

int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	n=read();m=read();
	if(n==1){
		printf("1");
		return 0;
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			a[i][j]=read();
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			for(k=1;k<m-j;k++){
				if(a[i][j+k]>a[i][j])swap(a[i][j+k],a[i][j]);
			}
		}
	}
	for(i=0;i<n;i++){
		tmp=0;
		for(k=0;k<n;k++){
			if(k!=i){
				for(j=0;j<m;j++){
					if(a[i][m-j-1]<a[k][j]){
						tmp=1;
						break;
					}else if(a[i][m-j-1]==a[k][j]){
						continue;
					}else{
						tmp=2;
						break;
					}
				}
			}else{
				continue;
			}
			if(tmp==2){
				printf("0");
				break;
			}else if(tmp==1&&k==n-1){
				printf("1");
				break;
			}else if(tmp==1&&k<n-1){
				tmp=0;
				continue;
			}
		}
	}
	
	return 0;
}
