#include <iostream>
#include <vector>
#include <queue>
#include <climits> // Required for INT_MAX
#include <algorithm> // Required for reverse

using namespace std;

void dijkstra(vector<vector<int>> adj[], int n, int s, int e) {
    vector<int> distance(n, INT_MAX);
    vector<int> parent(n, 0);

    // Initialize the priority queue
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    distance[s] = 0;
    pq.push({0, s});

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    while (!pq.empty()) {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto i : adj[node]) {
            int adjnode = i[0];
            int weight = i[1];

            if (dis + weight < distance[adjnode]) {
                distance[adjnode] = dis + weight;
                pq.push({distance[adjnode], adjnode});
                parent[adjnode] = node;
            }
        }
    }

    // Prepare to output the path from s to e
    vector<int> ans;
    int node = e;
    while (parent[node] != node) {
        ans.push_back(node);
        node = parent[node];
    }
    ans.push_back(s);
    reverse(ans.begin(), ans.end());

    cout << "Shortest path from " << s << " to " << e << " is: ";
    for (int i : ans) {
        cout << i << " ";
    }
    cout << "\nTotal distance: " << distance[e] << endl;
}

int main() {
    int n;
    cout << "Enter Total Number of nodes/Stations:" << endl;
    cin >> n;
    cout << endl;

    vector<vector<int>> matrix(n, vector<int>(n, 0));

    vector<string> names;
    cout << "Enter name of nodes" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Enter " << i + 1 << " Station" << endl;
        string s;
        cin >> s;
        names.push_back(s);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cout << "Enter distance from " << names[i] << " to " << names[j] << endl;
            cout << "Enter 0 if direct distance is not present" << endl;
            int dist;
            cin >> dist;
            cout << endl;
            matrix[i][j] = matrix[j][i] = dist;
        }
    }

    vector<vector<int>> adj[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != 0)
                adj[i].push_back({j, matrix[i][j]});
        }
    }

    cout << "Enter Starting node (0-based index)" << endl;
    int s;
    cin >> s;

    cout << "Enter Ending node (0-based index)" << endl;
    int e;
    cin >> e;

    dijkstra(adj, n, s, e);
}
