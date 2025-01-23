#include<iostream>
#include<string>
#include<sstream>
#include<map>


using namespace std;

int main(){

    string line;
    string str("my name is keshav");
    cout << "my name: "<< str<< endl;
    map<char, int> freq;
    map<string, int> word_freq;

    while(getline(cin, line)){
        
        cout << line <<endl;

        stringstream ss(line);    // add something to stringstream
        string word;
        int totalChars;
        
        while (ss >> word)      // >> get something from string stream
        {
            cout << word << endl;
            word_freq[word]++;

            for(char c: word){
                if (freq.find(c) != freq.end()){
                    freq[c] = freq[c] + 1;
                }else{
                    cout<< "first entry into map char: "<<c<< endl;
                    freq[c] = 1;
                }
            }
        }

        for(auto i = freq.begin(); i != freq.end(); i++){
            cout << i->first<<" "<< i->second<< endl;
        }

        for(map<string, int>::iterator it=word_freq.begin(); it != word_freq.end(); ++it){
            cout << it->first <<"->"<< it->second<<endl;
        }

    }
    
}