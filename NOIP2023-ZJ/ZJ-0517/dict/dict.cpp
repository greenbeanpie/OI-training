#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
bool cmp(char x,char y){
	return x>y;
}
vector<char> f[3010];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int n,m;
	scanf("%d%d\n",&n,&m);
    if(m == 1){
    	char minc = 'z';
    	int mini = 1;
    	for(int i = 1;i <= n;i++){
    	    char c = getchar();
    	    while(c<'a' || c>'z') c = getchar();
    	    if(c <= minc) {
    	    	mini = i;
    	    	minc = c;
			}
		}
		for(int i = 1;i <= n;i++){
			if(i == mini) printf("1");
			else printf("0");
		}
		return 0;
    }
    char min_dic[3010];
    char dic[3010];
    for(int i = 0;i < m;i++){
    	min_dic[i] = 'z';
	}
	for(int i = 1;i <= n;i++){
		for(int j = 0;j < m;j++){
			char c = getchar();
			while (c < 'a' || c >'z') c = getchar();
			dic[j] = c;
		}
		bool flag = true , aflag = false;
		sort(dic,dic+m,cmp);
		for(int j = 0;j < m;j++){
			f[i].push_back(dic[j]);           
			if(aflag || (flag && (f[i][j] <= min_dic[j]))){
		    	if(f[i][j] < min_dic[j]) aflag = true;
				min_dic[j] = f[i][j];
			} else flag = false;
		}
	}
	for(int i = 1;i <= n;i++){
		bool flag = true;
		int k = 0;
		while(f[i][m-k-1]>=min_dic[k]&&k < m){
			if(f[i][m-k-1] > min_dic[k]) {
				flag = false;
				break;
			}
			k++;
		}
		if(flag) printf("1");
		else printf("0");
	}
	return 0;
}