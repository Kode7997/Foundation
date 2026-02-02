
def get_trios(graph):

    trios = []
    for key, val in graph.items():
        if len(val) == 2:
            trios.append([key,val[0], val[1]])
    return trios


def get_friendship_score(trios, bigraph):
    scores = []
   
    for trio in trios:
        s = 0
        for friend in trio:
            l = len(list(set(bigraph[friend]) - set(trio)))
            print("l",l)
            s += l
        scores.append(s)
    return scores


if __name__ == '__main__':
    
    friends_node= 6
    friends_from = [1,2,2,3,4,5]
    friends_to = [2,4,5,5,5,6]

    #actual grpah
    graph = {}
    for i in range(len(friends_from)):

        if friends_from[i] in graph.keys():
            graph[friends_from[i]].append(friends_to[i])
        else:
            graph[friends_from[i]] = [friends_to[i]]
    

    #bi-directional graph
    bigraph = {}
    for i in range(len(friends_from)):
        
        if friends_from[i] in bigraph.keys():
            bigraph[friends_from[i]].append(friends_to[i])
        else:
            bigraph[friends_from[i]] = [friends_to[i]]
        
        if friends_to[i] in bigraph.keys():
            bigraph[friends_to[i]].append(friends_from[i])
        else:
            bigraph[friends_to[i]] = [friends_from[i]]
    
    trios = get_trios(graph)
    print(graph)
    print(bigraph)
    scores = get_friendship_score(trios, bigraph)
    print("minimum of trios: ",min(scores))