"""
1377. Frog Position After T Seconds

Companies	Google
Related Topics	Depth-first Search 

Test Cases:
7
[[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]]
2
4
7
[[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]]
1
7
7
[[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]]
20
6
3
[[2,1],[3,2]]
1
2
1
[]
1
1

https://leetcode.com/problems/frog-position-after-t-seconds/discuss/532769/c-post-order-dfs

Runtime: 88 ms, faster than 95.56% of Python3 online submissions for Frog Position After T Seconds.
Memory Usage: 12.8 MB, less than 100.00% of Python3 online submissions for Frog Position After T Seconds.
Next challenges:
Reconstruct Itinerary, Matchsticks to Square, Delete Tree Nodes
"""

class Solution:
    def frogPosition(self, n: int, edges: List[List[int]], t: int, target: int) -> float:
        nei = collections.defaultdict(set)
        for a, b in edges:
            nei[a].add(b)
            nei[b].add(a)
            
        
        def dfs( pre, cur, p, time):
            #nonlocal res
            if time == t:
                if cur == target:
                    self.res = p 
                return
            neighbors = nei[cur]
            nodes = len(neighbors) - ( 1 if pre!=-1 else 0)
            if nodes == 0:
                if cur == target: # avoid jumpping on same node
                    self.res = p 
                return
            for n in neighbors:
                if n != pre:
                    dfs( cur, n, p / nodes, time + 1)
    
        if n<2:
            return 1
        self.res = 0
        dfs( -1, 1, 1, 0)
        return self.res