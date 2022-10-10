class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<int>> g;
    vector<string> words;
    vector<int> dis;
    int pos1, pos2;
    void rec(int i, int end, int len, vector<string> &path, vector<int> &used) {
        path.push_back(words[i]);
        if(path.size() + dis[i] > len) {
            return;
        }
        if(i == end) { 
            ans.push_back(path);
            return;
        }
        for(auto x : g[i]) {
            if(!used[x]) {
                used[x] = 1;
                rec(x, end, len, path, used);
                path.pop_back();
                used[x] = 0;
            }
        }
    }
    vector<vector<string>> findLadders(string st, string en, vector<string>& wl) {
        g.resize(wl.size() + 10);
        bool f1 = false, f2 = false;
        for(int i = 0; i < wl.size(); i++) {
            if(wl[i] == st) {
                pos1 = i;
                f1 = true;
            }
            if(wl[i] == en) {
                pos2 = i;
                f2 = true;
            }
        }
        if(!f1) {
            wl.push_back(st);
            pos1 = wl.size() - 1;
        }
        if(!f2) {
            return ans;
        }
        for(int i = 0; i < wl.size(); i++) {
            for(int j = i + 1; j < wl.size(); j++) {
                int cnt = 0;
                for(int k = 0; k < wl[i].size(); k++) {
                    if(wl[i][k] != wl[j][k]) cnt++;
                }
                if(cnt == 1) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        int n = wl.size();
        vector<int> vis(n + 1);
        dis.resize(n + 1);
        queue<int> q;
        q.push(pos2);
        vis[pos2] = 1;
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            for(auto u : g[v]) {
                if(!vis[u]) {
                    vis[u] = 1;
                    q.push(u);
                    dis[u] = dis[v] + 1;
                }
            }
        }
        if(dis[pos1] == 0) {
            return ans;
        }
        words = wl;
        vector<string> path;
        vector<int> used(n + 1);
        rec(pos1, pos2, dis[pos1] + 1, path, used);
        return ans;
    }
};