Programming Assignment 5
========================

_Your description here_

The code for the similarities between PG4 and PG5 was taken from the course-provided solution to PG4 found in the PG4/solution 
directory. Changes that were made to this are commented in the source code.

For part 1, only slight changes were necessary (no change in data structures used). This was the change of geocode to populate a 
start node, the end node, and the position along that street.

Part 2 was implementing an adjacency list for the edges of the map. This was done using an unordered_map<int,unordered_set<edge> called 
edges, which was a data member of the street_map class. "edge" is a custom struct that contains 3 data members - a street name, a weight 
(length of the edge), and a destination node. The map has a key value that is equal to the start node, and that key maps to the unordered_set 
of edges that represent all of the edges coming out of the start node. An unordered_set was chosen to hold the edges for a few reasons. One is 
that it does not allow for multiple insertions. Sometimes in the map file, the same edges are represented multiple times, and that would have an 
undesireable effect on performance if they were allowed into the edges data structure. An unordered_map was chosen for the overarching data structure 
because of its fast lookup. For example, if I wanted all the neighbors of node 123, I could simply find 123 in the edges map and iterate through its
second member. 

For part 3, Dijkstra's algorithm was implemented. To do this, I chose to create another struct called "path", which held three data members - a current_node 
which was the end node of the path, a total_distance, which was the length of the path to get to the current_node from the start node, and a previous_node, 
which was a holder for the previous node on the path. These objects were stored in the marked structure, which was implemented as an unordered_map from int to 
path. This was chosen so that a path to a node could be quickly looked up - for example, if I wanted to know the shorest distance to node 123, I could find 123 in 
th map and examine the total_distance member of the associated path object. As for the frontier, I used a priority_queue of path objects. A prioirty_queue is the 
obvious choice for a frontier using Diklstra's, and < operator of the path struct was overloaded so that the priority_queue works as a min pq.
	
As for the algorithm implementation, it is very similar to the dfs and bfs performed in class. It took a path from the priority_queue, and determined if that was 
the target. If it was not the target, and it was not already in marked, its neighbors were added to the frontier with a total distance that reflects the current 
distance up to that point plus the additional distance to get to the neighbor. This continued until the frontier was empty, or the target node was found.

Parts 4 and 5 used similar methods to the algorithm described above. The only differnce is that to calculate the shortest path, two addtional nodes were simulated, 
and phantom nodes were created. Part 5 included an addtional algorthim, which navigated the marked map populated in Dijkstra's algorithm to get the path from the 
start node to the end node. This was done by finding the end node in the map by finding the node with a key of -1, which signaled the target. Then, as long as the 
current path was not the last leg, which has no previous node, another path struct 
kept track of a path somewhere ahead of the cursor. When the street names changed, the cursor was moved up, and the information was pushed inot the steps vector. 
This continued until the source path was analyzed, and then steps was reversed, because the algorithm went from the target to the source instead of the other way.

Through doing this program, I learned a lot about Dijkstra's algorithm and what data structures work well for it. The biggest learning points came from trying to 
get my test5b to run in less that 30 seconds: that required careful analaysis of what data structures were used. For example, I originally had edges be a map from 
int to vector of edge structs. This was a mistake, beucase vectors do not have fast lookup, and they allow duplicates, unlike an unordered_set. 

_Grader comments here_
