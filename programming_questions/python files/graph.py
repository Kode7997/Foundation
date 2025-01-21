

def dfs(graph, root,  order = None, visited = None):

    if visited is None:
        visited = set()
        order = []
    
    visited.add(root)
    order.append(root)
    
    for neighbor in graph[root]:
        if neighbor not in visited:
            dfs(graph, neighbor, order, visited)
    
    return order


if __name__ == '__main__':

    connections = [{"manasa","keshav"},{"arjun","manasa"},{"latha","arjun"}]

    node = dict()

    #construct graph
    for p1, p2 in connections:
        if p1 not in node.keys():
            node[p1] = [p2]
        elif p1 in node.keys():
            node[p1].append(p2)
        
        if p2 not in node.keys():
            node[p2] = [p1]
        elif p2 in node.keys():
            node[p2].append(p1)
    
    #dfs of graph
    relation = dfs(node, "latha")
    print("relaton: ",relation)

        


        