const ll INF = 1e18;

void dijkstra(vector<vector<pair<ll,ll>>>&edges,ll source, vector<ll>& dist, vector<ll>& parent) {
    int n = edges.size();
    dist.assign(n, INF);
    parent.assign(n, -1);

    dist[source] = 0;
    set<pair<ll, ll>>st;
    st.insert({0, source});
    while (!st.empty()) {
        ll u = st.begin()->second;
        st.erase(st.begin());

        for (auto it : edges[u]) {
            ll v = it.first;
            ll weight = it.second;

            if (dist[u] + weight < dist[v]) {
                st.erase({dist[v], v});
                dist[v] = dist[u] + weight;
                parent[v] = u;
                st.insert({dist[v], v});
            }
        }
    }
}

vector<ll> restore_path(ll source, ll target, vector<ll> const& parent) {
    vector<ll> ans;

    for (ll x = target; x != source; x = parent[x])
        ans.push_back(x+1);
    ans.push_back(source+1);

    reverse(ans.begin(), ans.end());
    return ans;
}
