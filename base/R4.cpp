#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long int;
using pii = pair<int, int>;

struct trie {
    struct node {
        map<char, int> go;
        int cnt;
        int dp;
        node() = default;
    };
    vector<node> data;

    int create_node() {
        data.emplace_back();
        return data.size() - 1;
    }

    trie() {
        create_node();
    }

    bool can_go(int u, char c) {
        return data[u].go.count(c);
    }

    int  go (int u, char c) {
        return data[u].go[c];
    }

    void insert(const string& s) {
        int u = 0;
        for (char c : s) {
            if (!can_go(u, c)) {
                data[u].go[c] = create_node();
            }
            ++data[u].dp;
            u = go(u, c);
        }
        ++data[u].dp;
        ++data[u].cnt;
    }

    void erase(const string & s) {
        int u = 0;
        for (char c : s) {
            --data[u].dp;
            u = go(u, c);
        }
        --data[u].dp;
        --data[u].cnt;
    }

    int count(const string & s) {
        int u = 0;
        for (char c : s) {
            if (!can_go(u, c)) {
                return 0;
            }
            u = go(u, c);
        }
        return data[u].cnt;
    }

    using item = pair<char, int>;

    string lex_string(int k) {
        int u = 0;
        string s;
        while (1) {
            if (data[u].cnt >= k) {
                return s;
            } else {
                k-= data[u].cnt;
            }
            for (item elem : data[u].go) {
                char c = elem.first;
                int v = elem.second;
                if (data[v].dp < k) {
                    k -= data[v].dp;
                } else {
                    s.push_back(c);
                    u = v;
                    break;
                }
            }
        }
    }
};



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    trie t;
    int q;
    cin >> q;
    while (q--) {
        string s; 
        cin >> s;
        if ('0' <= s[0] and s[0] <= '9') {
            int k = stoi(s);
            string res = t.lex_string(k);
            cout << res << '\n';
            t.erase(res);
        } else {
            t.insert(s);
        }
    }
}