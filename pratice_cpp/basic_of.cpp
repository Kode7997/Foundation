#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<string>
#include<sstream>
#include<cstring>

using namespace std;

void call_by_reference(vector<int> &vec) { 
    vector<int> tvec(1,2); //creates a vector with size 1 and intialise it to 2

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    vec.pop_back();
    vec.pop_back();
    vec.push_back(5); //125
    
    cout << vec.empty() << vec.size() << " "<< endl;

    return;
}

string toLower(string str) {
    string s = str;
    for(char &c: s) {
        if ((c >= 'A') && (c <= 'Z' )){
            c = c + 'a' - 'A';
        }
    }
    cout << "toLower "<<s<<endl;
    return s;
}

void string_methods(string& str) {
    // substr, strcmp, strcpy, strcat, strstr

    //check if substr is present in the string
    string substr1 = "load";
    int len = substr1.length();
    vector<string> words;


    char *cstr = new char[str.length()+1]; //to convert c++ string to c string
    strcpy(cstr, str.c_str());  // copy to cstr from converting string in c++ to c string using str.c_str()
    char *token = strtok(cstr, " "); //tokenize with delimeter.

    while (token != NULL)
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

int main(){

    //vector<int> vec1 = {1, 2, 3, 4, 5}; // supports above c++11
    vector<int> vec1;
    vector<string> vec2;

    // call_by_reference(vec1);
    // for(int i=0; i<vec1.size(); i++) {
    //     cout << vec1[i] << " ";
    // }

    // cout << "\nentries: "<<endl;
    // for(auto entry: vec1) {
    //     cout<< entry << " ";
    // }


    // take the input string from each line 
    // string line;
    // unordered_map<string, int> map;
    // while(getline(cin, line)) { //  by default delimiter is newline. if delimiter is required then add ","
        
    //     stringstream ss(line);
    //     //cout<< "input string: "<<line<<endl;

    //     string word;
    //     while (ss >> word)
    //     {
    //         cout << word << endl;
    //         string w = toLower(word);
    //         cout << "lower: " << w << endl;
    //         if (map.find(w) != map.end()) {         //find is the saviour
    //             map[w]++;
    //         } else {
    //             map[w] = 1;
    //         }

            
    //     }

    //     for(auto it=map.begin(); it != map.end();it++) { 
    //             cout<< it->first << " "<<it->second<<endl;
    //     }

    // }

    string line1 = "load balancer is used to distribute the incoming traffic";
    string_methods(line1);


    
    return 0;
}