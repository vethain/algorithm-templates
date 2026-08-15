pair<int, int> get(int root, vector<vector<int>>& g) 
{
    int n = g.size();
    vector<int> dist(n, -1);
    queue<int> q;
    q.push(root);
    dist[root] = 0;
    int u = root;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        if (dist[node] > dist[u]) u = node;
        for (int nei : g[node]) {
            if (dist[nei] == -1) {
                dist[nei] = dist[node] + 1;
                q.push(nei);
            }
        }
    }
    fill(dist.begin(), dist.end(), -1);
    vector<int> parent(n, -1);
    q.push(u);
    dist[u] = 0;
    int v = u;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        if (dist[node] > dist[v]) v = node;
        for (int nei : g[node]) {
            if (dist[nei] == -1) {
                dist[nei] = dist[node] + 1;
                parent[nei] = node;
                q.push(nei);
            }
        }
    }
    vector<int> path;
    for (int cur = v; cur != -1; cur = parent[cur]) {
        path.push_back(cur);
    }
    reverse(path.begin(), path.end());
    return {path[path.size() / 2], path.size() - 1};
}