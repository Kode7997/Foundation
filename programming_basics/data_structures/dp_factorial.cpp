#include<iostream>
#include<vector>
#include<chrono>

using namespace std::chrono;

long int factorial_recursive(long int n){
    // time and splace, O(n)[linear], O(n)[stack memory]

    if (n == 0){
        return 1;
    }else{
        n = n * factorial_recursive(n-1);
    }

    return n;
}

int dp_memoization(const int number){

    std::vector<int> dp(number+1,1); // 

    dp[0] = 1; // memoization? // bottom-up appraoch

    if (number == 0){
        return dp[number];
    }

    int n = 1; // initialization
    while(n <= number) {
        dp[n] =  dp[n-1] * n;
        n++;
    }
    // consumes O(n) space though we need solution for only number n. rest can be ignored.
    // therefore as a optmisation O(1), use variable to store the results and use the same
    return dp[number-1];
}

long int dp_tabulation(const int number){
    long int res = 0;
    return res;
}


int main(){

    long int number;
    

    std::cout<<"Enter the number\n";
    std::cin>>number;

    auto start = high_resolution_clock::now();
    long int res = factorial_recursive(number);
    std::cout<<"factorial : "<<res<<std::endl;
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    std::cout << "Computation time: " << duration.count() << " microseconds" <<std::endl;

    auto start1 = high_resolution_clock::now();
    long int res1 = dp_memoization(number);
    std::cout<<"factorial : "<<res1<<std::endl;
    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(end1 - start1);
    std::cout << "Computation time: " << duration1.count() << " microseconds" <<std::endl;
    

}