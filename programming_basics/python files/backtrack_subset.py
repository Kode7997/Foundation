
from os import stat


def subsets_backtrack(nums):
    curr_set = []
    start = 0
    res = []
   
    
    def backtrack(start, curr_set):
    
        res.append(list(curr_set))
        print(res)
        for i in range(start, len(nums)):
            curr_set.append(nums[i])
            backtrack(i+1, curr_set)

            num = curr_set.pop()
            print("pop: ",num)
    
    backtrack(start, curr_set)
    
    print("res: ",res)

def permutation(name):

    res = []
    start = 0

    def swap(i,j, name):
        name[i], name[j] = name[j], name[i]
        print("after swap: ",name)
        return

    def bt_permute(start, name):

        if start == len(name):
            res.append(''.join(name))
            print('bt_permute: ',res)
            return
        
        for i in range(start, len(name)):
            print("swap by 1st: ",i,start)
            swap(i, start, name)
            bt_permute(start+1, name)
            print("rev swap by 2nd", i, start)
            swap(i,start, name)
        
        

        return res
    
    bt_permute(start, list(name))
            


if __name__ == '__main__':
    nums = [0,1,2]
            #0,1,2
    name = "ABCD"
    subsets_backtrack(nums)
    #permutation(name)