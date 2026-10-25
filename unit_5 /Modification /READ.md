## Problem Statement
Develop a C++ program to represent water tanks as vertices and candidate pipelines as weighted edges in an undirected graph. Apply Prim’s algorithm to construct a minimum-cost spanning tree connecting all water tanks with minimum pipeline installation cost.
## Approach
- Graph representation: An adjacency matrix stores the cost of pipelines between water tanks. The graph is undirected, so each pipeline cost is stored in both directions.
- Prim’s algorithm: Start from the first tank and repeatedly choose the lowest-cost edge connecting the existing network to an unvisited tank.
- Running total: Add the cost of every selected edge to the previous total and display the updated amount.
- Pipeline modification: Update the cost of an existing pipeline and run Prim’s algorithm again using the modified graph.
- Disconnected graph detection: If no valid edge can connect the remaining tanks, the graph is disconnected and a spanning tree cannot be formed.
- Result: Display the selected pipelines and minimum total cost for both the original and updated networks.
## Time Complexity
Let V be the number of water tanks (vertices) and E be the number of pipelines (edges).
1. Adjacency Matrix Initialization: O(V²)
2. Entering Pipeline Data: O(E)
3. Prim’s Algorithm: O(V²), because the program uses an adjacency matrix to find the minimum-cost edge.
4. Updating an Edge Weight: O(1), because only one edge cost is updated in both directions.
5. Recalculating Prim’s Algorithm: O(V²), after updating the pipeline cost.
Overall Time Complexity: O(V²) for each execution of Prim’s algorithm.
Space Complexity: O(V²), because the adjacency matrix stores the pipeline costs between all pairs of tanks.
## Conclusion
The modified C++ program uses Prim’s algorithm to construct a minimum-cost water pipeline network. It updates an existing pipeline’s cost and recalculates the network, displays each selected edge with its individual cost and running total, and detects disconnected graphs. Thus, it determines whether all water tanks can be connected through a minimum-cost spanning tree.
