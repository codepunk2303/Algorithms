int bellman_ford(vector<vector<pair<int,int>>>&edges,int source, int dest){

	int n = edges.size(); // n = no. of nodes
	//edges[i] contains incoming nodes at i

	vector<vector<ll>>dp(n,vector<ll>(n,INF));
    //dp[i][j] = min distance from source to i using <=j nodes

    dp[source][0] = 0;
    for(int i = 1;i<=n-1;i++){
        for(int j = 0;j<n;j++){
            for(auto it:edges[j]){
                int x = it.first;
                int y = it.second;
                dp[j][i] = min(dp[j][i],min(dp[j][i-1],dp[it.first][i-1]+y));
            }
        }
    }
    return dp[dest][n-1]==INF?-1:dp[dest][n-1];

}

int bellman_ford_opt(vector<pair<int,pair<int,int>>>&edges, int source, int dest, int no_of_nodes){

	int n = no_of_nodes;
	vector<ll>dp(n,INF);

	dp[source] = 0;
	for(int i = 1;i<=n-1;i++){
		vector<ll>temp = dp;
		for(auto it:edges){
			int from = it.first;
			int to = it.second.first;
			int cost = it.second.second;
			if(temp[from]<1e18)dp[to] = min(dp[to],temp[from]+cost);
		}
	}

    return dp[dest]==INF?-1:dp[dest];
}
