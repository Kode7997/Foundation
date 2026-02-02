"program to convert long url to id"
"""
Assuming that we use database and primary unique id as INT
"""
class TinyUrl:

    def __init__(self):
        # base 62 
        self.map = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
        self.shortUrl = ""
    def idToShortURL(self, n):

        while n:
            self.shortUrl += self.map[n%62]
            n = n//62
        print("short URL: ",self.shortUrl)
        #return self.shortUrl[len(self.shortUrl):: -1]
        return self.shortUrl 

    def shortURLToId(self, tinyStr):
        
        id = 0
        for i in tinyStr:
            val_i = ord(i)
            if(val_i >= ord('a') and val_i <= ord('z')):
                id = id*62 + val_i - ord('a')
            elif(val_i >= ord('A') and val_i <= ord('Z')):
                id = id*62 + val_i - ord('A') + 26
            else:
                id = id*62 + val_i - ord('0') + 52
        return id

if __name__ == '__main__':
    dbId = 64
    tinyUrl = TinyUrl()

    print("dbid: ",dbId)
    url = tinyUrl.idToShortURL(dbId)
    print("url: ",url)
    uid = tinyUrl.shortURLToId(url)
    print("uid: ",uid)  


