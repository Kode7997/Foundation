'''
1. list
2. string
3. dict/hashmap
4. tupple
5. set
'''

import re, pdb

def set_operations():
    """
    - unorderred collection of unique ele
    - can be created by set() or {}

    1. add elements - add()
    2. remove/delete - set.remove(ele) or set.pop()- pops first ele, no indexing in pop

    """
    #create set
    set1 = set([2,3])
    set2 = {1}

    #add ele
    set1.add(1)
    set2.add('a')
    print(f'set1: {set1}\n set2: {set2}')

    #delete - pop(index), remove
    set1.remove(3)
    set2.remove('a')
    print(f'after delete, set1: {set1} and set2: {set2}')
    set2.add('b')
    print(f'delete using pop: ',set2.pop()) # pops first ele



def tupple_operations():
    """
    - immutable, efficient and semantic collection of data
    - use case: fixed semantics like co-ordinates (x,y), weekdays, database, connection (localhost, 8080), db urls/queries
    1. indexing
    2. count method - count occurence of ele in a tupple
    3. get the index of an ele - tupple.index(index)
    4. basic iteration
    """
    
    tupple = (1,1,2,3,4)

    tupple_list = list(tupple)
    tupple_list.append(5)
    
    tupple = tuple(tupple_list)

    print("added 5 to the tuple: ",tupple)
    #cannot add directly add ele to tupple. convert to list, append ele and convert back to tupple
    print("indexing tupple: 1st element: ",tupple[0])
    
    #count the occurence of ele in tupple
    print(" ocuurence of ele 1 in a tupple: ",tupple.count(1))

    #index
    print("get the index of an ele 3 in a tupple: ", tupple.index(3))

    #normal iteration over tupple ele
    for ele in tupple:
        print("index: ",tupple.index(ele),"ele: ",ele)


def hashmap_operations():
    """
    In python dict and hashmap often mean the same but differ in some ways
    """
    pass


def dict_with_freq():
    #dict using get
    #dict key and values as list.
    d = {}
    l = [1,1,2,2,3]
    for key in l:
        if key in d.keys():
            d[key].append(key)
        else:
            d[key] = [1]

    print(d)

def dict_operations():
    "types of dict methods available to check: if ele, key-value, items(), get value"
    
    dictionary = {}
    #key-value
    print("Dict",type(dictionary))
    dictionary = {1: "keshav", 2: "software Engineer", 3:"BE"}
    
    #insert: direct assignment and update()
    dictionary[4] = "Cisco"
    dictionary.update({5 : "bangalore"})
    for key, value in dictionary.items():
        print(key,"-->",value)
    
    #delete element: pop(), del
    del dictionary[5]
    dictionary.pop(4) #pass key

    print("after delete 4 and 5 ele")
    for key, value in dictionary.items():
        print(key,"->", value)
    

    #frequencies of character in the string
    


def string_operations(string=None):
    #immutable stirngs - which cannot be changed
    '''
    string - operations
    1. slicing s[1:]  s[start: stop: steps]
    2. negative slicing s[-4] 4 char from last, s[-1] last char, s[:-2] start at 0 and stop at before 2nd char from last
        s[-4:-2] 4th char from last and stop before 2nd char from last. 
    3. reverse string s[::-1]
    4. substring "si" in singam
    5. combining indexing and slicing eg: 's' + s[1:]

    '''
    s = str("abcdefg")
    print("access char at index ",2, s[2])
    s = s[1:]
    print("slice: ",s)

    """
    String operations:
    1. join:  suppose s = ["keshav", "nimmagadda]. then for w in s:
    2. replace: s.replace(source, destination)
    3. strip: remove white spaces
    4. split: split by space. doesn't remove spaces between words but rather only 
    5. re.sub(): substitute characters
    """
    s1 = ["keshav", "nimmagadda"]
    s2 = s1.copy()
    s2 = " ".join(s2)
    
    print("join words/char: ",s2)

    s2 = s2.replace("keshav","latha")
    print("replaced: ",s2)

    s2 = s2.strip()
    print("stripped string: ",s2)

    s3 = s2.split(' ')
    print("split string by space: ",s3)

    s4 = re.sub(r'[^a-zA-Z]','',s2)
    print("regex subsitute: ",s4)



def list_operations(arr=None):

    "types of list operations"
    arr = [13,14,15,16,17, 10,19]
    for i, ele in enumerate(arr):
        print("Array Enumerator: ",i, ele)
    
    for i, ele in enumerate(arr):
        if i == 4:
            print("pop 5th array element: ", i, arr.pop(i))
    
    for i in range(len(arr)):
        print("array range: ",arr[i])
    
    for num in arr:
        print("direct values: ",num)
    
    arr.insert(0, 10)
    print("insert ele in arr at index 0: ", arr)

    arr.remove(10)
    print("remove ele 10 by value: ", arr.remove(10))

    print("pop ele of an arr at index: 0: ", arr.pop(0))
    print("pop ele w/o index: ",arr.pop())
    

    # append(add to end of list), remove(value), pop(index), insert(index, value)


    

if __name__ == '__main__':
    
    #list_operations()
    #dict_operations()
    #string_operations()
    #tupple_operations()
    #dict_with_freq()
    set_operations()
