#include <vector>
#include <iostream>
#include <queue>
 
#define MAX 100        // ìµë?? ? ? ? ê°ì 
#define INF 99999999
 
using namespace std;
  
vector<int> dijkstra(int start, int V, vector<pair<int,int> > adj[]) {
    vector<int> dist(V, INF);    // ? ë¶? INFë¡? ì´ê¸°? 
    priority_queue<pair<int, int> > pq;
    
    dist[start] = 0;
    pq.push(make_pair(0, start));    // ?? ? ?  ë°©ë¬¸ 
 
    while (!pq.empty()) {
        int cost = -pq.top().first;    // ë°©ë¬¸? ? ? ? dist ê°? 
        int cur = pq.top().second;    // ??¬ ë°©ë¬¸? ? ?  
        pq.pop();
 
        for (int i = 0; i < adj[cur].size(); i++) {    // ??¬ ë°©ë¬¸? ? ? ? ì£¼ë?? ? ?  ëª¨ë ì¡°ì¬ 
            int next = adj[cur][i].first;    // ì¡°ì¬?  ?¤? ? ?  
            int nCost = cost + adj[cur][i].second;    // ??¬ ë°©ë¬¸? ? ? ? ê±°ì³? ?¤? ? ? ? ê°ë? ë¹ì© 
            if (nCost < dist[next] ) {     // ê¸°ì¡´ ë¹ì©ë³´ë¤ ??¬ ë°©ë¬¸? ? ? ? ê±°ì¹ ë¹ì©?´ ? ?¸?¤ë©? 
                dist[next] = nCost;    // ê°±ì  
                pq.push(make_pair(-nCost, next));    // pq? ????¥ 
            }
        }
    }
    
    return dist;
}
 
int main()
{
    int V,E;
    vector<pair<int, int> > adj[MAX];
    cout << "Vertex : ";
    cin >> V;
    cout << "Edge5 : ";
    cin >> E;
 
    for (int i = 0; i < E; i++) {
        int from, to, cost;
        cout << "±×·¡ÇÁ ÀÔ·Â [Á¤Á¡ Á¤Á¡ °¡ÁßÄ¡]: ";
        cin >> from >> to >> cost;
        adj[from].push_back(make_pair(to, cost));    // ?ë°©í¥ ê·¸ë? 
        adj[to].push_back(make_pair(from, cost));
    }
    cout<<endl;
    cout<<"===´ÙÀÌÁ÷½ºÆ®¶ó °á°ú==="<<endl;
    vector<int> dist = dijkstra(0, V, adj);
    for (int i = 0; i < V; i++) {
        printf("0¿¡¼­ %d±îÁö ÃÖ´Ü°Å¸® : %d\n", i, dist[i]);
    }
    return 0;
}