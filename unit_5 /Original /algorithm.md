## Algorithm
Step 1: Start.

Step 2: Read the number of tanks V and candidate pipelines.

Step 3: Create a weighted adjacency list for the graph.

Step 4: Initialize:
- key[] = ∞
- parent[] = -1
- inMST[] = false
  
Step 5: Set key[0] = 0 to start from Tank.

Step 6: Find the unvisited vertex havin. the smallest key.

Step 7: If its key is ∞, the graph is disconnected. Display:
Graph is disconnected. A spanning tree cannot connect all tanks.
Then stop.

Step 8: Mark the selected vertex as part of the MST.

Step 9: Update the key values of its adjacent vertices if a cheaper pipeline is found.

Step 10: Repeat Steps 6–9 until all vertices are included.

Step 11: Display the selected pipeline connections and total minimum cost.

Step 12: Stop.
