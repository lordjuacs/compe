#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    bool respect = false;
    Node* parent = nullptr;
    set<int> children;
};

void pop(Node*& node, vector<Node*>& all) {
    int i = node->data;
    cout << i << ' ';
    // for (int pos : node->children) {
    //     node->parent->children.insert(pos);
    //     all[pos]->parent = node->parent;
    // }
    // node->parent->children.erase(i);
    // node->parent = nullptr;
    // node->children.clear();
    // delete all[i];
    // all[i] = nullptr;
}

void bfs(Node*& node, vector<Node*>& all) {
    set<int> possible;
    bool done = false;
    queue<int> q;
    q.push(node->data);

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        for (int child : all[current]->children) {
            q.push(child);
            if (all[child]->respect) {
                bool flag = true;
                for (int grandchild : all[child]->children) {
                    if (!all[grandchild]->respect) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    possible.insert(all[child]->data);
                }
            }
        }
    }

    for (int current : possible) {
        pop(all[current], all);
        done = true;
    }

    if (!done)
        cout << -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<Node*> all(n + 1, nullptr);
    for (int i = 1; i <= n; i++) {
        all[i] = new Node;
        all[i]->data = i;
    }
    int root;
    for (int i = 1; i <= n; i++) {
        int p;
        cin >> p;
        cin >> all[i]->respect;

        if (p != -1) {
            all[i]->parent = all[p];
            all[p]->children.insert(all[i]->data);
        } else
            root = i;
    }

    bfs(all[root], all);
    return 0;
}