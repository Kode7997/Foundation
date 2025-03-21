
from tkinter.messagebox import NO
from traceback import print_tb


class Node:
    def __init__(self, key, value) -> None:
        self.key = key
        self.val =  value
        self.next = None

class HashMap:
    def __init__(self, cap) -> None:
        self.cap = cap
        self.bucket = [None] * cap
    
    def get_hash(self, key):
        hash = 0
        for c in key:
            hash += ord(c)

        return hash % self.cap

    def insert(self, key, value):
        hash = self.get_hash(key)

        if self.bucket[hash] == None:
            self.bucket[hash] = Node(key, value)
        elif self.bucket[hash]:
            node = self.bucket[hash]
            prev = node
            while node != None:
                prev = node
                if node.key == key:
                    node.value = value
                    return True
                node = node.next
            prev.next = Node(key, value)
    
    def display(self):
        for i in range(self.cap):
            if self.bucket[i] is not None:
                node = self.bucket[i]
                while node:
                    print(f'index: {i} key: {node.key} value: {node.val}')
                    node = node.next
            else:
                print(f'index {i} is None')


   

if __name__ == '__main__':
    
    hmap = HashMap(10)
    hmap.insert("abc","keshab")
    hmap.insert("cab", "manas")
    hmap.insert("bca","latha")
    hmap.insert("cba","arjun")
    hmap.display()