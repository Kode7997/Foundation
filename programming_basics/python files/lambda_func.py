
def sample_lambda():

    power = lambda x,y: x ** y
    print(power(2,3))



nums =  [1,2,3,4]
def func(a):
    return a*2

def map_sample():
    print("map")
    m = list(map(func, nums))
    print(m)


def dict_comp():

    nums = [1,2,3]
    dev = [{"name":"keshav"},{"name":"keshav"},{"name":"keshav"}]
    final = {n:name for n in nums for name in dev}

    print(final)

def list_comp():

    nums1 = [2,3,4,5,6]
    nums2 = [6,7,8,9,2]
    
    nums3 = [n1 for n1 in nums1 for n2 in nums2 if n1 == n2]
    print(nums3)

    return 0


if __name__ == '__main__':

    sample_lambda()

    map_sample()

    print("comp: ",dict_comp())
    print("lst compr: ",list_comp())
