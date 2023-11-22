#include<bits/stdc++.h>
using namespace std;
const int TRUE_VALUE=100001;
const int FALSE_VALUE=-TRUE_VALUE;
const int UNKNOWN_VALUE=0;

int n,m;

/*
 * FALSE_VALUE 表示 false
 * TRUE_VALUE 表示 true
 * UNKNOWN_VALUE 表示 unknown
 * x > 0 表示 w[x]
 * x < 0 表示 !w[x]
 */
int v[100001];

int _fa[200010],*fa=_fa+100005;
int find(int x){
    if(fa[x]==x)return x;
    else return fa[x]=find(fa[x]);
}

int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int T; scanf("%*d%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)v[i]=i;
        for(int i=1;i<=m;i++){
            char ch; scanf(" %c",&ch);
            int x,y;
            switch(ch){
                case 'T':
                    scanf("%d",&x);
                    v[x]=TRUE_VALUE;
                    break;
                case 'F':
                    scanf("%d",&x);
                    v[x]=FALSE_VALUE;
                    break;
                case 'U':
                    scanf("%d",&x);
                    v[x]=UNKNOWN_VALUE;
                    break;
                case '+':
                    scanf("%d%d",&x,&y);
                    v[x]=v[y];
                    break;
                case '-':
                    scanf("%d%d",&x,&y);
                    v[x]=-v[y];
                    break;
            }
        }
        for(int i=1;i<=n;i++)
            fa[i]=i,fa[-i]=-i;
        fa[UNKNOWN_VALUE]=UNKNOWN_VALUE;
        fa[TRUE_VALUE]=TRUE_VALUE;
        fa[FALSE_VALUE]=FALSE_VALUE;
        for(int i=1;i<=n;i++){
            int x=i,y=v[i];
            {
                int fx=find(x),fy=find(y);
                if(fx!=fy)fa[fx]=fy;
                // printf("merge %d %d\n",x,y);
            }
            {
                int fx=find(-x),fy=find(-y);
                if(fx!=fy)fa[fx]=fy;
                // printf("merge %d %d\n",-x,-y);
            }
        }
        for(int i=1;i<=n;i++){
            if(find(i)==find(-i)){
                int fx=find(i),fy=find(UNKNOWN_VALUE);
                if(fx!=fy)fa[fx]=fy;
                // printf("merge %d %d\n",i,UNKNOWN_VALUE);
            }
        }
        int true_id=find(TRUE_VALUE);
        int false_id=find(FALSE_VALUE);
        int unknown_id=find(UNKNOWN_VALUE);
        int total=0;
        for(int i=1;i<=n;i++)
            if(find(i)==unknown_id)total++;
        printf("%d\n",total);
    }
    // fprintf(stderr,"%lf\n",clock()*1.0/CLOCKS_PER_SEC);
    return 0;
}