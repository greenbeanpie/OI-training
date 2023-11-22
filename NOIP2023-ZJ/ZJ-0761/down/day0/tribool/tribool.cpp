#include <bits/stdc++.h>

using namespace std;

const int INF = 998114514;

struct Edge{
    int sourc_e;
    int w;
};

/*class DSU{
public:
    DSU(int size) : parent(size+1)
    {
        for(int i=1;i<=size;i++)
            parent[i]=i;
    }
    int Xfind(int x){
        return parent[x]==x?x:Xfind(parent[x]);
    }
    void Xmerge(int pa_rent,int s_on){
        parent[s_on]=Xfind(pa_rent);
    }
private:
    vector<int> parent;
};*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int c,t;
    cin >> c >> t;
    while(t--){
        cout << "第" << t << "组" << endl;
        int n,m;
        cin >> n >> m;
        vector<Edge> graph(n+1);
        for(int i=1;i<=m;i++){
            char v;
            cin >> v;
            if(v=='+'||v=='-'){
                int i,j;
                cin >> i >> j;
                if(v=='+'){
                    if(graph[j].sourc_e==0){
                        graph[i].sourc_e=j;
                        graph[i].w=1;
                    }
                    else if(graph[j].sourc_e==j){
                        graph[i].sourc_e=i;
                        graph[i].w=graph[j].w;
                    }
                    else{
                        graph[i].sourc_e=graph[j].sourc_e;
                        graph[i].w=graph[j].w;
                    }
                }
                else
                {
                    if(graph[j].sourc_e==0){
                        graph[i].sourc_e=j;
                        graph[i].w=-1;
                    }
                    else if(graph[j].sourc_e==j){
                        graph[i].sourc_e=i;
                        graph[i].w=-graph[j].w;
                    }
                    else{
                        graph[i].sourc_e=graph[j].sourc_e;
                        graph[i].w=-graph[j].w;
                    }
                }
                    
            }
            else{
                int i;
                cin >> i;
                if(v=='T')
                {
                    graph[i].sourc_e=i;
                    graph[i].w=1;
                }
                if(v=='F')
                {
                    graph[i].sourc_e=i;
                    graph[i].w=-1;
                }
                if(v=='U')
                {
                    graph[i].sourc_e=i;
                    graph[i].w=0;
                }

            }
        }
        int result=0;
        for(int i=1;i<=n;i++){
            if(graph[i].sourc_e==i&&graph[i].w==0)
                result++;
            else{
                int qw=graph[i].w;
                int nowPos=graph[nowPos].sourc_e;
                while(graph[nowPos].sourc_e!=i&&graph[nowPos].sourc_e!=nowPos&&graph[nowPos].sourc_e!=0){
                    qw*=graph[nowPos].w;
                    nowPos=graph[nowPos].sourc_e;
                }
                if(qw<0)
                    result++;
            }
        }
        cout << result;
        /*for(int i=1;i<=n;i++){
            cout << "点" << i << ": " << endl;
            cout << "Source: " << graph[i].sourc_e << ": " << endl;
            cout << "W: " << graph[i].w << ": " << endl;
        }*/
        /*DSU qwqDSU(n);
        vector<int> relationSeq(n,0);
        vector<int> valueSeq(n,0);
        for(int i=1;i<=m;i++){
            char v;
            cin >> v;
            if(v=='+'||v=='-'){
                int i,j;
                cin >> i >> j;
                if(v=='+'){
                    qwqDSU.Xmerge(j,i);
                    relationSeq[i]=1;
                }
                else
                {
                    qwqDSU.Xmerge(j,i);
                    relationSeq[i]=-1;
                }
                    
            }                    graph[i].sourc_e=j;
                    graph[i].w=-1; i;
                if(v=='T')
                {
                    valueSeq[i]=1;
                }
                if(v=='F')
                {
                    valueSeq[i]=-1;
                }
                if(v=='U')
                {
                    valueSeq[i]=0;
                }

            }
        }*/
        /*vector<int> seq(n,-INF);
        for(int qwq=1;qwq<=1;qwq++)
        {
            char v;
            cin >> v;
            if(v=='+'||v=='-'){
                int i,j;
                cin >> i >> j;
                if(v=='+')
                    seq[i-1]=j;
                else
                    seq[i-1]=-j;
            }
            else{
                int i;
                cin >> i;
                if(v=='T')
                    seq[i-1]=1;
                if(v=='F')
                    seq[i-1]=-1;
                if(v=='U')
                    seq[i-1]=0;

            }
        }
        for(int qwq=1;qwq<m;qwq++)
        {
            char v;
            cin >> v;
            if(v=='+'||v=='-'){
                int i,j;
                cin >> i >> j;
                if(v=='+')
                    seq[i-1]=seq[j-1];
                else
                    seq[i-1]=-seq[j-1];
            }
            else{
                int i;
                cin >> i;
                if(v=='T')
                    seq[i-1]=1;
                if(v=='F')
                    seq[i-1]=-1;
                if(v=='U')
                    seq[i-1]=0;

            }
        }
        for(auto &k:seq){
            cout << k << " ";
        }
        cout << endl;*/
    }
    return 0;
}
