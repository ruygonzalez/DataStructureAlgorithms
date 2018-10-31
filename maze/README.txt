BFS may be faster than DFS if one path is infinitely long and thus the DFS never reaches a solution, while BFS would. Alternatively, if DFS happens to encounter a really long path before it finds the solution, then BFS might be faster. BFS might also be faster than DFS if one of the paths reaches the solution rather quickly and particularly if that wouldn't be one of the first paths explored by DFS. 

DFS may be faster than BFS if one of the first paths explored by BFS (especially if any paths explored prior to finding the solution lead to a dead-end quickly) leads to the solution or if every path that BFS explores is very long. 

A real life example of a task that can be accomplished with a stack is white-ing out words typed with a typewriter, since the typewriter can keep track of the last word typed and remove it, so it's last in first out. Similarly, "undo" buttons in word processors or just "ctrl-z".

A real life example of a task that can be accomplished with a queue is placing milk in refrigerators at grocery stores, because you want the first milk cartons in to be the first out since they expire the quickest. And the front milk cartons are quickly replaced by the next milk carton up when they are removed. 
