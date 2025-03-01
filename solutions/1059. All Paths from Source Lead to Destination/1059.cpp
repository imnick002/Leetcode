enum class State { kInit, kVisiting, kVisited };

class Solution {
 public:
  bool leadsToDestination(int n, vector<vector<int>>& edges, int source,
                          int destination) {
    vector<vector<int>> graph(n);
    vector<State> state(n);

    for (const vector<int>& e : edges)
      graph[e[0]].push_back(e[1]);

    return acyclic(graph, source, destination, state);
  }

 private:
  bool acyclic(const vector<vector<int>>& graph, int u, int dest,
               vector<State>& state) {
    if (graph[u].empty())
      return u == dest;
    if (state[u] == State::kVisiting)
      return false;
    if (state[u] == State::kVisited)
      return true;

    state[u] = State::kVisiting;
    for (const int v : graph[u])
      if (!acyclic(graph, v, dest, state))
        return false;
    state[u] = State::kVisited;

    return true;
  }
};
