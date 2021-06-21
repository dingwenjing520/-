#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstdlib>
using namespace std;

const int maxn = 1e4 + 10;

struct Edge{ 
    int u, v, w;
    Edge(){}
    Edge(int u, int v, int w):u(u), v(v), w(w){}
    bool operator<(Edge tmp){ 
        return w < tmp.w;
    }
}e[maxn];

int n, m, fa[maxn];

void init(){ 
    for(int i = 1; i <= n; i++)fa[i] = i;
}

int Find(int x){ 
    return x == fa[x] ? x : fa[x] = Find(fa[x]);
}

void Union(int x, int y){ 
    int fx = Find(x);
    int fy = Find(y);
    fa[fx] = fy;
}

int Kruskal(){
    int cnt = 0, res = 0;
    init();
    sort(e, e + m);
    for(int i = 0; i < m; i++){
        if(Find(e[i].u) != Find(e[i].v)){ 
            Union(e[i].u, e[i].v);
            cnt++;
            res += e[i].w;
        }
        if(cnt == n - 1)break;
    }
    return res;
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        e[i] = Edge(u, v, w);
    }
    printf("%d\n", Kruskal());
    system("pause");
    return 0;
}
