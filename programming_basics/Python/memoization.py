
import time

def fibonacci(n, mem = {}):

    if n == 1:
        return 1
    elif n == 0:
        return 0
    
    if n in mem:
        return mem[n]
    
    mem[n] = fibonacci(n-1, mem) + fibonacci(n-2, mem) 

    return mem[n]


def measure_time(func, n, iterations=100):
    times = []
    for _ in range(iterations):
        start = time.time()
        func(n)
        end = time.time()
        times.append(end - start)
    return sum(times) / len(times)


if __name__ == '__main__':

    #Example usage with your memoized Fibonacci function
    average_time_small = measure_time(fibonacci, 10)
    average_time_large = measure_time(fibonacci, 30000)

    print(f"Average time for small input: {average_time_small} seconds")
    print(f"Average time for large input: {average_time_large} seconds")