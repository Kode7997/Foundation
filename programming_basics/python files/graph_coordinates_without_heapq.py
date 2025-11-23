
import math


def eu_distance(p1, p2):
    distance = math.sqrt(((p1[0] - p2[0])**2 + (p1[1] - p2[1])**2))
    return distance

points  = [(0,0), (1,0), (2,9), (3,0),(5,0)]
graph = {i:[] for i in range(len(points))}

for i in range(len(points)):
    for j in range(len(points)):
        if i != j:
            distance = eu_distance(points[i], points[j])
            graph[i].append((j, distance))
            graph[j].append((i, distance)) # bidirectional graph


def shortest_path(graph, start):

    visited = {vertex: False for vertex in graph}
    distances = {i:float('infinity') for i in range(len(graph))}
    distances[start] = 0

    for _ in range(len(graph)):
        minimum_dist = float('infinity')
        minimum_vertex = None
        
        for vertex in graph:
            if not visited[vertex] and distances[vertex] < minimum_dist:
                minimum_dist = distances[vertex]
                minimum_vertex = vertex
        
        
        if minimum_vertex is None:
            break

        visited[minimum_vertex] = True

        for neighbor, distance in graph[minimum_vertex]:
            
            if not visited[neighbor] and (distances[minimum_vertex] + distance) < distances[neighbor]:
                distances[neighbor] = distances[minimum_vertex] + distance
    
    return distances

if __name__ == '__main__':
    distances = shortest_path(graph, 0)
    print(distances)