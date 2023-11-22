#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c,t;
    while(t--){
        int n,m,k,d;
        cin >> n >> m >> k >> d;
        vector<pair<int,int>> activities(n+1);
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(2)));
        for(int i=1;i<=m;i++){
            int x_i,y_i,v_i;
            cin >> x_i >> y_i >> v_i;
            activities[x_i]={y_i,v_i};
        }
        int getActivities=[](int nowDay,int lastDays){
            if(lastDays>=activities[nowDay].first)
                return activities[nowDay].second;
            return 0;
        };
        dp[1][0][0]=0;
        dp[1][1][1]=-d+getActivities(1,1);
        for(int i=2;i<=n;i++){
            for(int j=0;j<=min(i,k);j++){
                dp[i][j][0]=;
                dp[i][j+1][1]=;
            }
        }
    }
    return 0;
}