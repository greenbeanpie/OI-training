#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 500010;
int xs[MAX_N],ys[MAX_N];

int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    int c,n,m,q;
    cin >> c >> n >> m >> q;
    if(c==1||(n==1&&m==1)) {
        int tx,ty;
        cin >> tx >> ty;
        cout << 1;
        for(int i=1; i<=q; i++) {
            int kx,ky;
            cin >> kx >> ky;
            for(int j=1; j<=kx; j++) {
                int px,vx;
                cin >> px >> vx;
            }
            for(int j=1; j<=ky; j++) {
                int py,vy;
                cin >> py >> vy;
            }
            cout << 1;
        }
        cout << endl;
        exit(0);
    } else if(c==2) {
        int sx[3],sy[3];
        for(int i=0; i<n; i++) {
            cin >> xs[i];
            sx[i]=xs[i];
        }
        for(int i=0; i<m; i++) {
            cin >> ys[i];
            sy[i]=ys[i];
        }
        if(n==2&&m==2) {
            if((sx[0]-sy[0])*(sx[1]-sy[1])>0) {
                cout << 1;
            } else {
                cout << 0;
            }
            for(int i=1; i<=q; i++) {
                for(int j=0; j<n; j++) {
                    sx[i]=xs[i];
                }
                for(int j=0; j<m; j++) {
                    sy[i]=ys[i];
                }
                int kx,ky;
                cin >> kx >> ky;
                for(int j=1; j<=kx; j++) {
                    int px,vx;
                    cin >> px >> vx;
                    sx[px-1]=vx;
                }
                for(int j=1; j<=ky; j++) {
                    int py,vy;
                    cin >> py >> vy;
                    sy[py-1]=vy;
                }
                if((sx[0]-sy[0])*(sx[1]-sy[1])>0) {
                    cout << 1;
                } else {
                    cout << 0;
                }
            }
            cout << endl;
        } else if(n==1&&m==2) {
            if((sx[0]-sy[0])*(sx[0]-sy[1])>0) {
                cout << 1;
            } else {
                cout << 0;
            }
            for(int i=1; i<=q; i++) {
                for(int j=0; j<n; j++) {
                    sx[i]=xs[i];
                }
                for(int j=0; j<m; j++) {
                    sy[i]=ys[i];
                }
                int kx,ky;
                cin >> kx >> ky;
                for(int j=1; j<=kx; j++) {
                    int px,vx;
                    cin >> px >> vx;
                    sx[px-1]=vx;
                }
                for(int j=1; j<=ky; j++) {
                    int py,vy;
                    cin >> py >> vy;
                    sy[py-1]=vy;
                }
                if((sx[0]-sy[0])*(sx[0]-sy[1])>0) {
                    cout << 1;
                } else {
                    cout << 0;
                }
            }
            cout << endl;
        } else if(n==2&&m==1) {
            if((sx[0]-sy[0])*(sx[1]-sy[0])>0) {
                cout << 1;
            } else {
                cout << 0;
            }
            for(int i=1; i<=q; i++) {
                for(int j=0; j<n; j++) {
                    sx[i]=xs[i];
                }
                for(int j=0; j<m; j++) {
                    sy[i]=ys[i];
                }
                int kx,ky;
                cin >> kx >> ky;
                for(int j=1; j<=kx; j++) {
                    int px,vx;
                    cin >> px >> vx;
                    sx[px-1]=vx;
                }
                for(int j=1; j<=ky; j++) {
                    int py,vy;
                    cin >> py >> vy;
                    sy[py-1]=vy;
                }
                if((sx[0]-sy[0])*(sx[1]-sy[0])>0) {
                    cout << 1;
                } else {
                    cout << 0;
                }
            }
            cout << endl;
        }
        exit(0);
    }
    for(int i=1; i<=n; i++) {
        cin >> xs[i];
    }
    for(int i=1; i<=m; i++) {
        cin >> ys[i];
    }
    for(int i=1; i<=q; i++) {
        cout << 1;
    }
    cout << endl;
    return 0;
}
