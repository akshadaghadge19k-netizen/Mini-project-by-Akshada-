## Algorithm
1. Start the program.

2. Read the number of water tanks and candidate pipelines.
   
3. Create an adjacency matrix to store the pipeline costs.

4. Enter the endpoints and cost of each pipeline.
   
5. Apply Prim’s algorithm, starting from the first tank.
 
6. Find the minimum-cost edge connecting a visited tank to an unvisited tank.
  
7. Select the edge, display its cost, and calculate the running total cost.
   
8. Repeat Steps 6–7 until all tanks are connected or no valid edge is available.
   
9. If all tanks are connected, display the minimum total cost and report that a spanning tree can be formed. Otherwise, report that the graph is disconnected and a spanning tree cannot be formed.
 
10. Ask the user to enter the endpoints of an existing pipeline and its new cost.

11. Update the pipelineDisplay the updated  in  adjacency matrix.

12. Apply Prim’s algorithm again to calculate the updated minimum-cost network.

13. Display the updated selected edges, their individual costs, and the running total cost.
    
14. Check connectivity again and report whether a spanning tree can be formed.

15. Stop the program.
