#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstdlib>
using namespace std;

const int maxn = 1e4 + 10;

struct Node{  
	int id, dist;
	Node(int id, int dist):id(id), dist(dist){}
	bool operator<(const Node & tmp)const{ 
		return tmp.dist < dist;
	}
};
int n, m, vis[maxn] = {0}; 
vector<Node>graph[maxn]; 
int Prim(int st){
	int cnt = 0, res = 0; 
	priority_queue<Node>q; 
    q.push(Node(st, 0)); 
    while(!q.empty()){
        int v = q.top().id;
        int w = q.top().dist;
        q.pop();
        if(vis[v] == 1)continue; 
        vis[v] = 1;
        res += w;
        for(int i = 0; i < graph[v].size(); i++){ 
            if(vis[graph[v][i].id] == 1)continue;
            q.push(Node(graph[v][i].id, graph[v][i].dist));
        }
    }

	return res;
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		graph[u].push_back(Node(v, w));
		graph[v].push_back(Node(u, w));
	}
	printf("%d\n", Prim(1));
	system("pause");
	return 0;
}
