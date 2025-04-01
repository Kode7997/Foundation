#include<iostream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

/// @brief parent method
class Parent{

    public:
        Parent(){
            cout << "parent contructor"<<endl;
        }

        virtual ~Parent(){
            cout<<"parent destructor is called "<<endl;
        }

        void parent_method() {
            cout<<"called parent method, this is parent class method"<<endl;
        }
};

class Child: public Parent {

    public:
        Child() {
            cout<<"child contructor"<<endl;
        }

        ~Child(){
            cout<<"child destructor"<<endl;
        }

    void child_method() {
        cout<<"child method is called"<<endl;
    }

    void parent_method(){ // polymorphism = function override
        cout<<"this is child class parent method\n";
    }
};

char isAlphaNum(char c) {
    return ((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9'));
}

string clean_string(string str1) {
    cout<<"input string: "<<str1<<endl;

    string cleaned_string;
    
    for(int i=0;i<str1.length();i++) {
        if(isAlphaNum(str1[i])){
            cleaned_string += str1[i];
        }else if(str1[i] == ' '){
            cleaned_string += ' ';
        }
    }

    cout<<"cleaned string: "<<cleaned_string<<endl;
    return cleaned_string;
}

vector<string> get_list_of_words(string &str) {

    vector<string> words;
    stringstream ss(str);
    string word;

    while(ss >> word){
        words.push_back(word);
    }

    return words;
}

void pass_array(int *arr){
    cout<<"arr elements: "<<arr[0]<<arr[1]<<"\t"<<endl;
}

class Sub {

    public:
        double a;

        Sub(double a): a(a){
            cout<<"constructor called\n";
        }

        //copy constructor. does it perform deep copy or shallow copy?

        Sub(Sub &obj){
            cout<<"copy constructor is called\n";
            this->a = obj.a;
        }

        // operator override
        double operator-(Sub& obj){
            double res = a - obj.a;
            cout<<"res: "<<res<<endl;
            return res;
        }
};


class Add{
    public:
        Add(){
            cout<<"add constructor is called\n";
        }

        ~Add(){
            cout<<"add destructor is called\n";
        }
};

int main() {

    // create object of the class parent
    // Parent *p = new Parent();
    // p->parent_method();
    // delete the destructor

    //Child *c = new Child();
    // c->child_method();
    // c->parent_method();

    // Parent *p1 = new Child; // p1 is pointing to child class but c1 type is parent class
    // c1->parent_method();
    // delete p1; if virtual, then call child destructor and parent destructor. if not then only calls parent dest bcz of type.

    //delete p; // only parent destructor is called bcz there is no inheretance. but if there is inheritance with virtual destructor then derived and base destructor is called.
    //delete c; // first child destructor is called followed by parent destructor

    // string str1 = "are!, strings immutable."; // No strings are mutable
    // int len = str1.length();

    // string cleaned_string = clean_string(str1);
    // vector<string> words = get_list_of_words(cleaned_string);

    // for(auto word: words){
    //     cout<<"words: "<<word<<endl;
    // }

    // string w = "ar23";
    // if (words[0].find(w) != string::npos){
    //     cout<<"substring found"<<endl;
    // }else{
    //     cout<<"substring not found"<<endl;
    // }

    // words.pop_back();
    // for(auto word: words){
    //     cout<<"after pop of words: "<<word<<endl;
    // }

    // int arr[] = {1,12,3,5};
    // pass_array(arr);

    // Sub *s1 = new Sub(12);
    // Sub *s2 = new Sub(13);

    // double s3 = *s1 - *s2; // dereference(*) is mandatory. if only pointers are passed, then operator override function is not called
    // cout<<"s1 - s2: "<<s3<<endl;

    // Sub s4 = *s2;
    // cout<<"value of s4: "<<s4.a<<endl;

    // delete s1;
    // delete s2;

    Add a;

    return 0;
}