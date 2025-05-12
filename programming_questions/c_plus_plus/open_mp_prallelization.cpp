#include<iostream>
#include<omp.h>

/*
C/C++ provide directives to perform parallel computation

1. openMP is one lib which help perform this task.
2. MPI - message passing interface => helpful when we have multiple cores in cluster environment
*/

void parallel_allowed() {
    int size  = 20;
    int x[size];

    #pragma omp parallel for
    for (int i=0;i<size; i++) {
        x[i] = i;
        for (int j=0; j<10000000; j++) {
            x[i] = i + 1;
        }
    }
}

void parallel_not_allowed() {
    /*
    There is a subtle difference between above and below program.
    variable "j" is private in above program. so each thread created j is private and posses consistent value
    
    here, j is shared among multiple thread can have inconsistent data/value.
    */

    int size  = 20;
    int x[size];
    int j;      // DON'T DO THIS
    #pragma omp parallel private for
    for (int i=0;i<size; i++){
        x[i] = i;
        for (j=0; j<10000000; j++){
            x[i] = i + 1;
        }
    }


    /*
    1. we can also specify what variables are shared and private
        e.g:  #pragma omp parallel for private(i,j) shared(x, size)
    
    2. article: http://computing.stat.berkeley.edu/tutorial-parallelization/parallel-C.html#3-mpi
    */

}


void parallelCompute(int numThreads) {

    #pragma omp parallel for num_threads(numThreads) //set number of thread
    for (int i = 0; i < 1000000; i++) {
        // Perform computation
    }
}


int main() {

    // lets apply parallelism for nested for loop. outer for loop is executed parallely and inner for loop executes in 
    // a synchronse way in  a given thread.
    
    parallel_allowed();

    parallel_not_allowed();

    int numberOfThreads = 4; // number of threads
    parallelCompute(numberOfThreads);

    return 0;
}