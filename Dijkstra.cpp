int dp[10004];
priority_queue<pii,vector<pii>,greater<pii> > q;
vector<pii > adj[10004];
void dijkstra(int src,int dest)
{
    for(int i=0;i<10004;i++)dp[i]=inf;
    while(!q.empty())q.pop();
    dp[src]=0;
    q.push(mp(0,src));
    while(!q.empty())
    {
        int u = q.top().se;
        if(u==dest)break;
        int ucost = q.top().fe;
        q.pop();
        if(ucost>dp[u])continue;
        for(int i=0; i<adj[u].size(); i++)
        {
            int v=adj[u][i].fe, vcost=adj[u][i].se;
            if(dp[v]>dp[u]+vcost)
            {
                dp[v]=dp[u]+vcost;
                q.push(mp(dp[v],v));
            }
        }

    }
}
