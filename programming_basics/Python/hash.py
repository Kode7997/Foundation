
class HashTable:
    
    hashtable = None
    #strucutre of hash: size and table
    def __init__(self, size):

        self.size = size
        self.table = [None] * size
    
    def _get_hash_key(self, key):
        
        hash_val = 0
        for char in key:
            hash_val = (hash_val * 31 + ord(char)) % self.size
        
        return hash_val
    
    def insert(self, key, val):

        hash_key = self._get_hash_key(key)
        print("hash_key:",hash_key)
        if self.table[hash_key] == None:
            self.table[hash_key] = [(key, val)]
        else:
            for pair in self.table[hash_key]:
                if pair[0] == key:
                    pair = (key, val)
                    return
            self.table[hash_key].append((key, val))
    
    def search_key(self, key):

        hash_key = self._get_hash_key(key)

        if self.table[hash_key] is not None:
            for pair in self.table[hash_key]:
                if pair[0] == key:
                    return pair[1]
        else:
            print("key not present in the hash table")
            return


    def delete(self, key):

        hash_key = self._get_hash_key(key)

        if self.table[hash_key] is None:
            print("key not present")
            return
        else:
            for i, pair in enumerate(self.table[hash_key]):
                if pair[0] == key:
                    self.table[hash_key].pop(i)
                    print("key: {} deleted".format(key))
                    return 


    
if __name__ == '__main__':

    htable = HashTable(size=10)
    htable.insert("name","Alice")
    htable.insert("eman","Bob")
    #htable.insert("nam","john")
    print(htable.search_key("eman"))
    htable.delete("nam")


            
