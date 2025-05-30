#include<sstream>
#include<iostream>
#include<string> //string lib for string opetations


using namespace std;

vector<string> splitBySpace(string& str) {

    stringstream ss(str); // stringstream, split by space. 
    vector<string> words;
    string word;
    
    while (ss >> word)
    {
        words.push_back(word);
    }

    string sentence;
    ostringstream oss;      // join string of words. ostringstream oss;

    for(string word : words) {
        if (word != words[0]) {
            oss << " ";
        }
        oss << word;
    }
    
    // stream to string
    sentence = oss.str(); // another way is to use std::to_string(int_number)
    cout << "sentence is: "<< sentence << endl;
    return words;

}
void stringOperations() {

    string fName = "keshav";
    string lName = "_n";
    string fullName = fName + lName;            //concate strings
    
    cout << "full name: " << fullName << endl;

    cout << "size or lenght of full name: " << fullName.length() << " or use size: " << fullName.size() <<endl;

    //access strings
    for(int i=0;i<fullName.length();i++){
        cout << i <<"th char is: "<< fullName[i] << endl; 
    }


    // convert lower to upper of char c: c = c - 'a' + 'A';

    // string and char array
    char name[] = "hello"; //array of characters
    string name1 = "hello"; // regular string

    //extraction operator
    string naam = "keshav is a bad boy";
    vector<string> words = splitBySpace(naam);
    cout << "string stream\n";
    for(int i=0;i<words.size();i++){
        cout<< words[i] << endl;
    }

    return;
}


void mathFunc(){

    // math methods: max, min, sqrt, log 
    return;
}


void loopsInCpp() {
    int i=0;
    for(; ; i++){
        cout << i << endl;
        if (i == 5){
            break;
        }
    }

    int arr[3] = {1,2,3};
    for(int num : arr){
        cout << num << endl;
    }
}

void vectorAndArray() {
    /*
    vector are resizable arrays. it's size grows and shrinks. and each element can be accessed by the indexing
    */

    vector<string> vObj;
    vObj.push_back("hello");
    vObj.push_back("world");
    vObj.pop_back(); // pops last element
    cout << "vector obj: " << vObj[0] << endl; // vObj cannot be printed directly w/o indexing 
}


void func_parameters(int &a, char c, string name = "keshav") { // here we reference the variable a
    // default value should be end when clubbed with the other regular variables
    cout << "func default parameters: " << name << endl;
    a = 20;
    cout << "char c: " << c << endl;

}


void pass_array_to_func(int *myArray, int size){

    for(int i=0; i<size; i++) {
        cout << myArray[i] << endl;                             // here it prints only first two elements
    }

    /*
    Note: In C and C++, when array is passed to the function, "array decays into pointer". so 
        size of "myArray" will be 8 if it is 64bit machine and 4 if 32bit machine.
        Therefore it is required to pass the size where array is declared. 
    */
}

void string_methods(string& str) {
    // substr, strcmp, strcpy, strcat, strtok(tokenise the string), strstr(check if substring present)

    //check if substr is present in the string
    string substr1 = "load";
    int len = substr1.length();
    vector<string> words;


    char *cstr = new char[str.length()+1]; //to convert c++ string to c string
    strcpy(cstr, str.c_str());  // copy to cstr from converting string in c++ to c string using str.c_str()
    char *token = strtok(cstr, " "); //tokenize with delimeter.

    while (token != NULL)   // this is how tokens are generated in C
    {
        words.push_back(token);
        token = strtok(NULL, " "); // tell controller from where it left. basically start from null which it stop at the end of first iteration
    }
    
    for(auto w: words) {
        cout<< " word is: "<<w<<endl;
    }

    if(str.find(substr1) != string::npos) { // find used to substring 
        cout<<"YES "<<endl;
        int pos = str.find(substr1);
        cout << "pos: "<<pos<<endl;
        str = str.substr(pos+len);
        cout<<"new str: "<<str<<endl;
    }else{
        cout<<"NO"<<endl;
    } 

    return;
}

int main() {

    cout << "first cpp program\n";

    cout <<"end of line" << endl;
    cout <<"number," << 3*3 << " is 3 * 3," << endl;
    // To insert double quote and backslash. idea is to add backslash if any char wants to appear in the string
    cout << "exampl of \"double quote\" " << endl;
    cout << "to add slash \\ in the text" << endl;

    //string and bool are new types added to the C++
    string text = "hello world";
    bool myBool = true;
    cout << "string type \"" << text << "\" and bool type " << myBool << endl;


    //input to the functions
    // int x;
    // cout <<"Enter the value of X\n";
    // cin >> x;
    // cout << "value of X is " << x << endl;


    //string operations
    stringOperations();

    // loops in cpp
    cout << "loops in CPP" << endl;
    loopsInCpp();


    // vectors vs array
    cout << "vectors and array" << endl;
    vectorAndArray();
    

    // func parameters, pass by reference
    int b = 10;
    cout << "before change: " << b << endl;
    func_parameters(b, 'c');                // here, we dont pass the address of b, we pass value instead and compiler internally will handle dereference
    cout << "after change: " << b << endl;
    
    // arrays in cpp and C
    int myArray[] = {1,2,3,4,5};
    int size = (sizeof(myArray)/sizeof(myArray[0])); // here size will will be 5
    pass_array_to_func(myArray, size); // important concept

    // function overloading is supported in c++ where same func name is used to define two different data types
    // plusFunc(int x, int y)
    // plusFunc(double x, double y) polymorphism - func overloading

    string str1 = "load balancer will distribute the traffic accross server to minimize the load on specific server";
    string_methods(str1);
    return 0;
}