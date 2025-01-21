



'''
note: In a complete binary tree of n nodes, last non-leaf node si n//2 - 1.  

'''

class heap:

    def __init__(self) -> None:
        self.heap = []
    
    def parent(self,i):
        return (i-1) // 2

    def left_child(self, i):
        return (i * 2) + 1
    
    def right_child(self, i):
        return (i * 2) + 2

    
    def insert(self, val):
        self.heap.append(val)
        self.heapify_up(len(self.heap)-1)

    #heapify up is suitable when new element is inserted to heap
    #idea, start from bottom to up,where need to swap the values if condition fails until i becomes 0(bcz root is zero)
    def heapify_up(self, i):
        while i != 0 and self.heap[self.parent(i)] > self.heap[i]:
            self.heap[i], self.heap[self.parent(i)] = self.heap[self.parent(i)], self.heap[i]
            i = self.parent(i)
    
    #when min or max element is extracted, heap down is suitable approach
    def extract_ele(self):

        if len(self.heap) == 0:
            return float('inf')
        
        root = self.heap[0]
        self.heap[0] = self.heap[-1]
        self.heap.pop()
        self.heapify_down(0)
        return root
    
    def heapify_down(self, i):
        smallest = i
        left = i * 2 + 1
        right = i * 2 + 2

        if left < len(self.heap) and self.heap[left] < self.heap[smallest]:
            smallest = left
        
        if right < len(self.heap) and self.heap[right] < self.heap[smallest]:
            smallest = right
        
        if smallest != i:
            self.heap[i], self.heap[smallest] = self.heap[smallest], self.heap[i]
            self.heapify_down(smallest)



if __name__ == '__main__':
    heap = heap()
    heap.insert(5)
    heap.insert(4)
    heap.insert(3)
    heap.insert(2)
    heap.insert(1)

    print(heap.heap)



    

        







