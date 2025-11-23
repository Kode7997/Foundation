import grp
import heapq
import math

def eu_distance(p1, p2):
    distance = math.sqrt((p1[0] - p2[0])**2 + (p1[1] - p2[1])**2)
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

    distances = {vertex:float('infinity') for vertex in graph}
    distances[start] = 0
    priority_queue = [(0, start)] #heapq always use the first element if the tupple to determine the minimum value. if order is reverse (vertex, distance) then it fails.

    while priority_queue:
        current_distance, vertex = heapq.heappop(priority_queue)

        if current_distance > distances[vertex]:
            continue

        for neighbor, weight in graph[vertex]:
            distance = distances[vertex] + weight

            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(priority_queue, (distance, neighbor))


    return distances


if __name__ == '__main__':

    distances = shortest_path(graph, 0)
    print(distances)