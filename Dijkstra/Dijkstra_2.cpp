#include <vector>
#include <iostream>
#include <queue>
 
#define MAX 100        // ìµœë?? ? •? ?˜ ê°œìˆ˜ 
#define INF 99999999
 
using namespace std;
  
vector<int> dijkstra(int start, int V, vector<pair<int,int> > adj[]) {
    vector<int> dist(V, INF);    // ? „ë¶? INFë¡? ì´ˆê¸°?™” 
    priority_queue<pair<int, int> > pq;
    
    dist[start] = 0;
    pq.push(make_pair(0, start));    // ?‹œ?‘ ? •?  ë°©ë¬¸ 
 
    while (!pq.empty()) {
        int cost = -pq.top().first;    // ë°©ë¬¸?•œ ? •? ?˜ dist ê°? 
        int cur = pq.top().second;    // ?˜„?¬ ë°©ë¬¸?•œ ? •?  
        pq.pop();
 
        for (int i = 0; i < adj[cur].size(); i++) {    // ?˜„?¬ ë°©ë¬¸?•œ ? •? ?˜ ì£¼ë?? ? •?  ëª¨ë‘ ì¡°ì‚¬ 
            int next = adj[cur][i].first;    // ì¡°ì‚¬?•  ?‹¤?Œ ? •?  
            int nCost = cost + adj[cur][i].second;    // ?˜„?¬ ë°©ë¬¸?•œ ? •? ?„ ê±°ì³?„œ ?‹¤?Œ ? •? ?„ ê°ˆë•Œ?˜ ë¹„ìš© 
            if (nCost < dist[next] ) {     // ê¸°ì¡´ ë¹„ìš©ë³´ë‹¤ ?˜„?¬ ë°©ë¬¸?•œ ? •? ?„ ê±°ì¹œ ë¹„ìš©?´ ?” ?‹¸?‹¤ë©? 
                dist[next] = nCost;    // ê°±ì‹  
                pq.push(make_pair(-nCost, next));    // pq?— ????¥ 
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
        adj[from].push_back(make_pair(to, cost));    // ?–‘ë°©í–¥ ê·¸ë˜?”„ 
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