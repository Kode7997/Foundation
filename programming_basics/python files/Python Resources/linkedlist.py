class Node:

    def __init__(self, val=None):
        self.val = val
        self.next = None
    
class LinkedList:

    def __init__(self):
        self.head = None
    
    def insert(self, val):

        if self.head is None:
            self.head = Node(val)
        else:
            node = self.head

            while node.next != None:
                node = node.next
            
            node.next = Node(val)

    def print_ll(self):
        node = self.head

        while node:
            print("node: ",node.val)
            node = node.next

    def delete_nth_node_from_end(self, n):

        '''
        concept of fast pointer and slow pointers
        '''

        if self.head is None:
            return 
        # 1->2->3->4->5->6
        fp = self.head
        for i in range(n):
            fp = fp.next
        
        sp = self.head
        prev = None
        while fp:
            prev = sp
            fp = fp.next
            sp = sp.next
        
        prev.next = sp.next

def median_of_two_sorted_list(ll1, ll2):
    # convert to list
    if ll1.head is None or ll2.head is None:
        return 
    
    arr1, arr2 = [], []

    node1 = ll1.head
    node2 = ll2.head

    while node1:
        arr1.append(node1.val)
        node1 = node1.next
    
    while node2:
        arr2.append(node2.val)
        node2 = node2.next
    
    print(arr1, arr2)


if __name__ == '__main__':
    ll1 = LinkedList()

    ll1.insert(10)
    ll1.insert(20)
    ll1.insert(30)
    ll1.insert(40)
    ll1.insert(50)
    ll1.delete_nth_node_from_end(2)
    ll1.print_ll()

    ll2 = LinkedList()
    ll2.insert(1)
    ll2.insert(2)
    ll2.insert(3)
    ll2.insert(4)
    ll2.insert(5)
    
    ll2.print_ll()
    median_of_two_sorted_list(ll1, ll2)


        