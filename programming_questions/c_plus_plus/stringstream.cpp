#include<iostream>
#include<string>
#include<string.h>
#include<sstream>
#include<map>
#include<cctype>

using namespace std;

int main(){

    string line;
    string str("my name is keshav");
    cout << "my name: "<< str<< endl;
    map<char, int> freq;
    map<string, int> word_freq;
    map<string, vector<int>> graph;

    char a = 'a';
    int b = (int)a;
    cout << "value of a: "<< b <<endl;

    string str1="keshav";
    string str2="keshav";
    string str3;

    if (strcmp(str1.c_str(), str2.c_str()) == 0){       // c_str => convert to c style string
        cout << "strings are equal\n";
    }
    

    //npos = no position in string. commonly used with find and strings
    string str4 = "hello world!";
    string substring = "world";

    size_t pos = str4.find(substring); // string.find(c) returns the position
    if (pos != string::npos){
        cout << "subtring at: "<<pos<<endl;
    }


    while(getline(cin, line, '.')){
        cout << "line: "<<line<<endl;
        stringstream ss(line);    // add something to stringstream
        string word;
        int totalChars;
        
        while (ss >> word)      // >> get something from string stream
        {
            word_freq[word]++;

            for(char c: word) {
                //count the freq of chars
                if (freq.find(c) != freq.end()) {
                    freq[c] = freq[c] + 1;
                } else {
                    freq[c] = 1;
                }

                if(isdigit(c)) {         // other way is to check if c>'0' && c<'9'
                    cout << c <<" is a numeric"<< endl;
                } else if(isalpha(c)) {   // other way is to check if c>'a' and c<'z' || c>'A' && c<'Z'
                    cout << c <<" is a aphabhet"<< endl;
                } else {
                    cout << c <<" not either"<< endl;
                }
            }
        }

        for(auto i = freq.begin(); i != freq.end(); i++){
            cout << i->first<<" "<< i->second<< "\t";
        }

        cout << endl;

        for(map<string, int>::iterator it=word_freq.begin(); it != word_freq.end(); ++it){
            cout << it->first <<"->"<< it->second<< "\t";
        }

        for(auto it = word_freq.begin(); it != word_freq.end(); it++) {
            if (it->first == "Hello") {
                it = word_freq.erase(it);
            }
        }

        cout << endl;

        for(map<string, int>::iterator it=word_freq.begin(); it != word_freq.end(); ++it){
            cout << it->first <<"->"<< it->second<< "\t";
        }


    }
    
}