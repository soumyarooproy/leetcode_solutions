# Date  : 03/20/2018
# Time  : O(V+E)
# Space : O(V)

class Solution:
    def isBipartite(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: bool
        """
        color = 0
        q = collections.deque() # for BFS
        unvisited = set(range(len(graph)))
        
        while unvisited:
            # Start BFS from a new node
            q.append(unvisited.pop())
            colored = {}
            while q:
                # Attempt to color all the nodes in the current BFS frontier using color
                num_nodes = len(q)
                for i in range(num_nodes):
                    v = q.popleft()
                    if not v in colored: # v is being visited for the first time
                        colored[v] = color
                        unvisited.discard(v)
                        q.extend([x for x in graph[v]])
                    else: # v has been colored
                        if colored[v] != color:
                            return False
                # Toggle color
                color = (color + 1) % 2
        
        return True
