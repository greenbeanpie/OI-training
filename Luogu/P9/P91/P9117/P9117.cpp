#include <bits/stdc++.h>
using namespace std;

struct abc{
    int opt,x,c;
};
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int a = 0; a < t; a++)
    {
        int n, m, q;
        cin >> n >> m >> q;
        int paint[n][m];
        memset(paint, -1, sizeof(paint));
        int opt, x, c;
        stack<abc> o;
        bool line[n]={0},row[m]={0};
        int linemax=-1,rowmax=-1;
        abc temp;
        for (int i = 0; i < q; i++)
        {
            cin >> opt >> x >> c;
            x--;
            temp.opt=opt;
            temp.x=x;
            temp.c=c;
            o.push(temp);
        }
        for (;!o.empty();)
        {
            if(o.top().opt==0){
                if(line[o.top().x]){
                    o.pop();
                    continue;
                }
                line[o.top().x]=1;
                for(int j=0;j<m;j++){
                    if(paint[o.top().x][j]==-1){
                        paint[o.top().x][j]=o.top().c;
                    }
                }
                while(line[linemax+1]&&linemax<n){
                    linemax++;
                }
                if(linemax>=n){
                    break;
                }
            }
            else{
                if(row[o.top().x]){
                    o.pop();
                    continue;
                }
                row[o.top().x]=1;
                for(int j=0;j<n;j++){
                    if(paint[j][o.top().x]==-1){
                        paint[j][o.top().x]=o.top().c;
                    }
                }
                while(row[rowmax+1]&&rowmax<m){
                    rowmax++;
                }
                if(rowmax>=m){
                    break;
                }
            }
            o.pop();
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(paint[i][j]==-1){
                    cout << 0 << " ";
                    continue;
                }
                cout << paint[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}