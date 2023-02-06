#define N 16666
#define PID pair<int,double>
vector<PID>edge[N];
double dis[N];
int inque[N];
queue<int> q;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        for(int i=0;i<=n+10;i++) dis[i]=0,inque[i]=0,edge[i].clear();
        int m=edges.size();
        for(int i=0;i<m;i++){
            int a=edges[i][0];
            int b=edges[i][1];
            double w=succProb[i];
            edge[a].push_back(make_pair(b,w));
            edge[b].push_back(make_pair(a,w));
        }
        q.push(start);
        inque[start]=1;
        dis[start]=1.0;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            inque[u]=0;
            for(int i=0;i<edge[u].size();i++){
                int v=edge[u][i].first;
                double w=edge[u][i].second;
                if(dis[v]<dis[u]*w){
                    dis[v]=dis[u]*w;
                    if(!inque[v]){
                        inque[v]=1;
                        q.push(v);
                    }
                }
            }
        }
        return dis[end];
    }
};
