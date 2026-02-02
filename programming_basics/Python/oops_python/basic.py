'''
Programming:
Sample program on Class+ inheritance+ method overriding.
Create a data frame of 5 rows and 6 columns.
Print Factorial of a number.
Create a Pyramid of stars.
Separate even and odd months from the list of Calendar months and print them
Create a basic list containing 100 numbers without using a loop.
Get the output of the routing table on this laptop(windows os) and from output create a dictionary containing Destination nw as key and values being the list of network mask, gateway.
Get dictionary info containing IP address and hostname from file (file operation).
Regex for any valid ipv4 address.
Lambda function usage
Create a data structure(dictionary) with elements as IP address and mac address from the output of the arp table
Read a file and print the occurrence of word searched for.
Read the HTML file and grep for information.
Extract the IP address from the output of “ipconfig /all” command.


Networking:
What are tagged and untagged vlans.
What does the IPV4 header consist of.
Explain the life of the packet with ARP and end to end flow.
Explain ipv4 classes.
Basic knowledge of networking concepts(Network protocols like ARP, ICMP, IP, TCP, UDP).
Like why and where the protocols are used.
Difference between TCP and UDP.
Diff between IPv4 and IPv6 address..
'''


import pandas as pd
import numpy as np
import os

def main():
    #dataframe operations
    lst = ["hi","how","are","there"]
    d = {"name":["k","m"],"loc":["m","r"],"age":["12","2"]}
    df = pd.DataFrame(lst)
    df1 = pd.DataFrame(d)
    print(df.loc[0])
    #print(df1)
    print(df1[["name"]])
    print("retrive row")
    print(df1.loc[0])

    print("create dataframe with 5rows 6col")
    print(pd.DataFrame(index=np.arange(2), columns=np.arange(2)))



def pyramid():

    ''' 
            *
        *       *
    *       *       *

    '''
    n = 8
    s = '*'
    for i in range(1,n+1):
        j = i
        st = ''
        while j>0:
            sp = n - j
            while sp>0:
                st += '\t'
                sp -= 1
            while j>0:
                st  += s+'\t\t'
                j -= 1
        print(st)
        

def get_arp():
    
    arp = os.popen('arp -a')
    s = arp.read()
    s = s.split(' ')
    print(s)
    arp.close()

def get_netstat():
    
    import io #a file like buffer
    a = os.popen('netstat -nr')
    s = a.read()
    df = pd.read_csv(s, )
    df = pd.DataFrame(df, header=None)
    print(df)


def regex():
    import re

    s = "geeks for geeks"
    match = re.search(r'for',s)     #search the first occurence
    #print("start: ",match.start()," end: ",match.end())

    string = ["Hello my Number is 123456789 and my friend's number is 987654321", "hey"]

    #m = re.findall(r'\d+',string)   #find one or more occurence
    #m = re.findall(r'\d*',string)   #find zero or more occurence
    for st in string:
        m = re.findall(r'\w+',st)
        print(m)



def lamda_func():
    
    func = [lambda arg=x: arg*10 for x in range(1,5)]
    for it in func:
        print(it())


def ip_regex():
    '''
    [1-9]?[0-9]

    0-9         [0-9]
    10-99       [1-9][0-9]
    100-199     1[0-9][0-9]
    200-255     2[0-5][0-5]
    '''
    import re
    oct = "255.255.255.255"
    pattern = r'^(([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-5][0-5])\.){3}([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-5][0-5])$'
    m = re.search(pattern, oct)
    if m:
        print("matched")
    else:
        print("invalid")


if __name__ == '__main__':
    #main()
    #pyramid()
    # get_arp()
    #get_netstat()
    #lamda_func()
    #regex()
    ip_regex()