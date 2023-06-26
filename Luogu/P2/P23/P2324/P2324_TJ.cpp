#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cctype>
#define ll long long
#define R register
using namespace std;
template<typename T>inline void read(T &a){
    char c=getchar();T x=0,f=1;
    while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
    while(isdigit(c)){x=(x<<1)+(x<<3)+c-'0';c=getchar();}
    a=f*x;
}
int n,m,t,mp[7][7],stx,sty,success;
char ch;
const int dx[]={0,1,1,-1,-1,2,2,-2,-2};
const int dy[]={0,2,-2,2,-2,1,-1,1,-1};
const int goal[7][7]={
    {0,0,0,0,0,0},
    {0,1,1,1,1,1},
    {0,0,1,1,1,1},
    {0,0,0,2,1,1},
    {0,0,0,0,0,1},
    {0,0,0,0,0,0}
};
inline int evaluate(){
    R int cnt=0;
    for(R int i=1;i<=5;i++)
        for(R int j=1;j<=5;j++)
            if(mp[i][j]!=goal[i][j])cnt++;
    return cnt;
}
inline int safe(R int x,R int y){
    if(x<1||x>5||y<1||y>5)return 0;
    return 1;
}
inline void A_star(R int dep,R int x,R int y,R int maxdep){
    if(dep==maxdep){
        if(!evaluate())success=1;
        return;
    }
    for(R int i=1;i<=8;i++){
        R int xx=x+dx[i];
        R int yy=y+dy[i];
        if(!safe(xx,yy))continue;
        swap(mp[x][y],mp[xx][yy]);
        int eva=evaluate();
        if(eva+dep<=maxdep)
            A_star(dep+1,xx,yy,maxdep);
        swap(mp[x][y],mp[xx][yy]);//回溯
    }
}
int main(){
    freopen("P2324.in","r",stdin);
    read(t);
    while(t--){
        success=0;
        for(R int i=1;i<=5;i++){
            for(R int j=1;j<=5;j++){
                cin>>ch;
                if(ch=='*')mp[i][j]=2,stx=i,sty=j;//记录起点即为空白格子
                else mp[i][j]=ch-'0';
            }
        }
        if(!evaluate()){printf("0\n");continue;}
        for(R int maxdep=1;maxdep<=15;maxdep++){
            A_star(0,stx,sty,maxdep);
            if(success){printf("%d\n",maxdep);goto ZAGER;}
        }
        printf("-1\n");
        ZAGER:;
    }
    return 0;
}