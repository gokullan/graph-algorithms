import heapq
class Solution:
    def heapupdate(self, u, new_cost, cost_heap, heap_dict):
        old_entry=heap_dict.pop(u)
        old_entry[2]=1  # this updates the corresponding entry in cost_heap also
        # define the new entry
        new_entry=[new_cost,u,0]
        heap_dict[u]=new_entry
        heapq.heappush(cost_heap, new_entry)
        
    #Function to find the shortest distance of all the vertices
    #from the source vertex S.
    def dijkstra(self, V, adj, S):
        min_distances = [float('inf') for i in range(V)]
        min_distances[S]=0
        
        # heap_entry = [cost(EBT), vertex, removed(bool)]
        heap_dict={}
        cost_heap=[]
        for i in range(V):
            if i==S:
                heap_dict[i]=[0,i,0]
            else:
                heap_dict[i]=[float('inf'),i,0]
            cost_heap.append(heap_dict[i])
        heapq.heapify(cost_heap)
            
        for i in range(S,V):
            w,u,s = heapq.heappop(cost_heap)
            while s==1:  # discard removed entries
                w,u,s = heapq.heappop(cost_heap)
            min_distances[u]=w
            heap_dict.pop(u)
            
            for v_,c in adj[u]:
                if v_ in heap_dict and heap_dict[v_][0] > min_distances[u]+c:
                    self.heapupdate(v_, min_distances[u]+c, cost_heap, heap_dict)
                
        for i in range(0,S):
            w,u,s = heapq.heappop(cost_heap)
            while s==1:
                w,u,s = heapq.heappop(cost_heap)
            min_distances[u]=w
            heap_dict.pop(u)
            
            for v_,c in adj[u]:
                if v_ in heap_dict and heap_dict[v_][0] > min_distances[u]+c:
                    self.heapupdate(v_, min_distances[u]+c, cost_heap, heap_dict)
        return min_distances
