#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int MAXN = 3010;
int n,m;
string s[MAXN];
bool cmp(const char &l,const char &r){
	if(l > r) return true;
	else return false;
}
int main(){
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
	cin>>n>>m;
    if(n == 1){
    	cin>>s[1];
        cout<<"1";
        return 0;
    }// 10 pts
	if(m == 1){
        char c = 'z';
        int pos = 0;
        for(int i = 1;i <= n;i++){
            cin>>s[i];
            if(s[i][0] <= c){
                c = s[i][0];
                pos = i;
            }
        }
        for(int i = 1;i <= n;i++){
            if(i == pos){
                cout<<"1";
            }else{
                cout<<"0";
            }
        }
        return 0;
    }// 30 pts
    for(int i = 1;i <= n;i++){
    	cin>>s[i];
	}
    for(int i = 1;i <= n;i++){
        string ans[MAXN];
        string pd;
        for(int j = 1;j <= n;j++){
            ans[j] = s[j];
            if(j == i){
                sort(ans[j].begin(), ans[j].end());
                pd = ans[j];
            }else{
                sort(ans[j].begin(), ans[j].end(), cmp);
            }
        }
        sort(ans + 1,ans + n + 1);
        if(ans[1] == pd){
            printf("1");
        }else{
            printf("0");
        }
    }//80 pts
	return 0;
}