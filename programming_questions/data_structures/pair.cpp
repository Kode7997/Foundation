// pair is part of the utility class

#include<iostream>
#include<utility>
#include<vector>



int main(){

    std::vector<std::pair<int, int> > vec;

    vec.push_back(std::make_pair(1,1));
    vec.push_back(std::make_pair(2,2));
    std::cout<<vec[1].first<<std::endl;
    


}