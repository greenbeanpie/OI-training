#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int c,t;
const int MAXM = 1e5 + 5;
vector<int> g[MAXM];
int main(){
    freopen("tribool.in","r", stdin);
    freopen("tribool.out", "w", stdout);
    scanf("%d%d", &c, &t);
    for(int NumOfData = 1;NumOfData <= t;NumOfData++){
        int n,m;
        scanf("%d%d", &n, &m);
        if(c == 1 || c == 2){

        }
        if(c == 3 || c == 4){//20 pts
            
            int bo[MAXM];
            for(int i = 1;i <= n;i++){
                bo[i] = 0;
            }
            for(int i = 1;i <= m;i++){
                char p;
                cin>>p;
                int pos;
                scanf("%d", &pos);
                if(p == 'T'){
                    bo[pos] = 2;
                }else if(p == 'U'){
                    bo[pos] = 1;
                }else if(p == 'F'){
                    bo[pos] = 0;
                }
            }
            int ans = 0;
            for(int i = 1;i <= n;i++){
                if(bo[i] == 1){
                    ans++;
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
