// Problem: https://www.hackerrank.com/challenges/ctci-bfs-shortest-reach/problem
// Score: 45


#include <iostream>
#include <vector>
#include <deque>
using namespace std;


struct node{
    bool visited = false;
    int path = -1;
    vector<node*> kids;
};


int main(){
    int t;
    cin >> t;
    for (int k = 0; k < t; k++){
        int n, m;
        cin >> n >> m;

        vector<node*> nodes(n);
        for (int i = 0; i < n; i++){
            nodes[i] = new node();
        }

        for (int i = 0; i < m; i++){
            int a, b;
            cin >> a >> b;
            nodes[a-1]->kids.push_back(nodes[b-1]);
            nodes[b-1]->kids.push_back(nodes[a-1]);
        }

        int start;
        cin >> start;

        deque<node*> q;
        q.push_back(nodes[start - 1]);

        int path = 0;
        q.front()->path = 0;
        q.front()->visited = true;

        while (!q.empty()){
            path = q.front()->path + 6;

            for (node * el: q.front()->kids){
                if (!el->visited){
                    el->path = path;
                    el->visited = true;
                    q.push_back(el);
                }
            }
            q.pop_front();
        }

        for (node* el: nodes){
            if (el->path != 0) cout << el->path << " ";
        }
        cout << '\n';
    }
    return 0;
}