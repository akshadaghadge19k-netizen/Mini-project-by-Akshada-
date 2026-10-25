## Problem Statement
Develop a C++ program to represent water tanks as vertices and candidate pipelines as weighted edges. Apply Prim's algorithm to build a minimum-cost network. Display the selected pipeline connections and report if the graph is disconnected and a spanning tree cannot connect all tanks.
## Approach
- Represent each water tank as a vertex.
- Represent each candidate pipeline as an undirected edge.
- Assign the construction cost of each pipeline as its weight.
- Start Prim’s algorithm from the first tank.
- Select the minimum-cost edge connecting a visited tank to an unvisited tank.
- Add that edge to the MST.
- Repeat until all tanks are included.
- If no unvisited tank can be reached, the graph is disconnected.
- Display the selected pipelines and their total cost.
## Time Complexity
For the implementation above, Prim’s algorithm uses an adjacency list, but it searches all vertices to find the minimum key.
Finding the minimum vertex: O(V) for each iteration.
This is repeated V times.
Updating adjacent vertices takes O(E) overall.
Therefore:
Time Complexity: O(V² + E)
For a connected simple graph where E can be as large as V², this is commonly stated as:
O(V²)
Space Complexity: O(V + E)
because the adjacency list stores all vertices and edges.
## Conclusion
The program successfully models water tanks as vertices and candidate pipelines as weighted edges. Prim’s algorithm selects the minimum-cost pipelines required to connect all tanks without forming cycles, producing a Minimum Spanning Tree and its total cost. If the graph is disconnected, the program correctly reports that a spanning tree cannot connect all the tanks.
