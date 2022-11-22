#include <vector>
#include <iostream>
#include <queue>
 
#define MAX 100        // 최�?? ?��?��?�� 개수 
#define INF 99999999
 
using namespace std;
  
vector<int> dijkstra(int start, int V, vector<pair<int,int> > adj[]) {
    vector<int> dist(V, INF);    // ?���? INF�? 초기?�� 
    priority_queue<pair<int, int> > pq;
    
    dist[start] = 0;
    pq.push(make_pair(0, start));    // ?��?�� ?��?�� 방문 
 
    while (!pq.empty()) {
        int cost = -pq.top().first;    // 방문?�� ?��?��?�� dist �? 
        int cur = pq.top().second;    // ?��?�� 방문?�� ?��?�� 
        pq.pop();
 
        for (int i = 0; i < adj[cur].size(); i++) {    // ?��?�� 방문?�� ?��?��?�� 주�?? ?��?�� 모두 조사 
            int next = adj[cur][i].first;    // 조사?�� ?��?�� ?��?�� 
            int nCost = cost + adj[cur][i].second;    // ?��?�� 방문?�� ?��?��?�� 거쳐?�� ?��?�� ?��?��?�� 갈때?�� 비용 
            if (nCost < dist[next] ) {     // 기존 비용보다 ?��?�� 방문?�� ?��?��?�� 거친 비용?�� ?�� ?��?���? 
                dist[next] = nCost;    // 갱신 
                pq.push(make_pair(-nCost, next));    // pq?�� ????�� 
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
        cout << "�׷��� �Է� [���� ���� ����ġ]: ";
        cin >> from >> to >> cost;
        adj[from].push_back(make_pair(to, cost));    // ?��방향 그래?�� 
        adj[to].push_back(make_pair(from, cost));
    }
    cout<<endl;
    cout<<"===��������Ʈ�� ���==="<<endl;
    vector<int> dist = dijkstra(0, V, adj);
    for (int i = 0; i < V; i++) {
        printf("0���� %d���� �ִܰŸ� : %d\n", i, dist[i]);
    }
    return 0;
}