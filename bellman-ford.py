#User function Template for python3

class Solution:
    # Function to construct and return cost of MST for a graph
    # represented using adjacency matrix representation
    '''
    V: nodes in graph
    adj: adjacency list for the graph
    S: Source
    '''
    def bellman_ford(self, V, adj, S):
        adj_new=[[] for i in range(V)]
        for triple in adj:
            adj_new[triple[0]].append([triple[1],triple[2]])
            
        min_distances = [100000000 for i in range(V)]
        min_distances[S]=0
        for i in range(V-1):
            for u in range(S,V):
                for v,w in adj_new[u]:
                    min_distances[v]=min(min_distances[v],min_distances[u]+w)
            for u in range(0,S):
                for v,w in adj_new[u]:
                    min_distances[v]=min(min_distances[v],min_distances[u]+w)
        return min_distances
