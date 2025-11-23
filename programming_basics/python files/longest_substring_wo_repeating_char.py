

def longest_sub():

    s = 'skldfjhsifduhsidfuhaisdfuhqwertyuiopasdfghjklzxcvbnm'
    start = 0
    end = 0
    qu = []
    longest = 0
    subtring = []
    fci = 0
    lci = 0
    
    while end < len(s):

        if s[end] not in qu:
            qu.append(s[end])
        else:
            while s[end] in qu:
                qu.pop(0)
                start += 1
            qu.append(s[end])
    
        if longest <= len(qu):
            longest = len(qu)
            fci = start
            lci = end
        
        end += 1

    print("Str;",longest, fci, lci, s[fci:lci+1])
if __name__ == '__main__':
    longest_sub()