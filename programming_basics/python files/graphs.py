

def dfs(graph, start, visited = None):

    if visited is None:
        visited = set()
    
   
    visited.add(start)
    print("recursive: ",start)
    for neighbor in graph[start]:
        if neighbor not in visited:
            dfs(graph, neighbor, visited)
    
    return visited


def dfs_using_stack(graph, start, visited=None):

    if visited is None:
        visited = set()
    
    stack = [start]

    while stack:
        node = stack.pop()
       
        if node not in visited:
            visited.add(node)
            print("stack: ",node)
            for node in reversed(graph[node]):
                if node not in visited:
                    stack.append(node)

#get path from src to dest using destination
def dfs_from_src_to_dst(graph, src, dest, visitied=None):

    
    stack = []
    visitied = set()
    stack.append((src, [src]))
    while stack:
        node, curr_path = stack.pop()
        if node not in visitied:
            if node == dest:
                #print("path", curr_path)
                return curr_path
            visitied.add(node)
            for neighbhor in reversed(graph[node]):
                if neighbhor not in visitied:
                    stack.append((neighbhor, curr_path + [neighbhor]))
    return -1



if __name__ == '__main__':

    graph = { 'A': ['B'], 'B': ['D', 'E'], 'C': ['F'], 'D': [], 'E': ['F'], 'F': ['C'] }  

    #dfs_list = dfs(graph, 1)
    #dfs_stack = dfs_using_stack(graph, 1)
    print(dfs_from_src_to_dst(graph, 'A','C'))
    #print(dfs_list)

    visited = set()
    visited.add('E')
    print(graph['B'] - list(visited))