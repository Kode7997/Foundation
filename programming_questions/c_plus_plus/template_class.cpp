#include<iostream>
#include<string>
#include<vector>

using namespace std;

template <typename T>
class Box {
    public:
        vector<T> arr;

        Box(const vector<T> &itms): arr(itms){
            
        }

        void add_item(const T& ele){
            arr.push_back(ele);
        }

        void delete_item() {
            arr.pop_back();
        }

        void display(){
            for(auto item: arr) {
                cout<<"element: "<<item<<endl;
            }
        }
};

int main(){

    vector<int> intVec = {1,2,3};
    Box<int> intBox(intVec);

    intBox.display();
    intBox.add_item(10);
    intBox.display();

}