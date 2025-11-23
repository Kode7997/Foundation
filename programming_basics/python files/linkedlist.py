class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class singleLL:

    def __init__(self):
        self.head = None
    
    def insertLast(self, data=None):
        
        if not data:
            return 
        
        if self.head == None:
            node = Node(data)
            self.head = node

        elif self.head != None:
            temp = self.head
            node = Node(data)
            while temp.next:
                temp = temp.next
            
            temp.next = node
    
    def insertFront(self, data):

        if self.head == None:
            node = Node(data)
            self.head = node
        else:
            node  = Node(data)
            node.next = self.head
            self.head = node

    def display(self):
        temp = self.head
        while temp:
            print(temp.data)
            temp = temp.next

    def delete(self, data):
        temp = self.head
    
    def search(self, data):
        pass
    
    def arrayWindow(self,arr):
        #pass by assignment[which is basically a reference but it has value]
        print("print from last")
        print(arr[::-1])
        print("print last element")
        print(arr[-1])
        print("print form index 1 to 3")
        print(arr[1:4])
        print("print last three elements")
        print(arr[:-4])


    def listcomprehension(self):

        l1 = [1,2,3,4]
        l2 = [5,6,7,8]

        l3 = [a*b for a,b in zip(l1,l2) if a<b]

        print("enumerate")
        for i,v in enumerate(l2):
            print(i,v)

    def dictcomprehension(self):

        d = dict({"1":1, "2":2, "3":3})
        d1 = {k:v*v for k,v in d.items()}


        print(d1)

        



if __name__ == '__main__':

    arr = [1,2,3,4,5,6]

    linkedList = singleLL()
    linkedList.insertLast("2")
    linkedList.insertLast("3")
    linkedList.insertLast("5")
    #linkedList.display()
    #print("insert front\n")
    linkedList.insertFront("1")
    #linkedList.display()

    linkedList.arrayWindow(arr)
    linkedList.listcomprehension()
    print("dict comp: ")
    linkedList.dictcomprehension()
    