#include<iostream>
#include<fstream>
#include<sstream>
#include<string>


using namespace std;


void read_number_from_file(){

    ifstream file("smpl1.txt");

    if (!file.is_open()){
        cout<<"failed to open smpl1.txt file"<<endl;
    }

    string line;

    while(getline(file, line)){
        cout<<"line: "<<line<<endl;
    }

    return;
}

int main() {

    int a, b;
    ifstream file;
    stringstream buffer;

    file.open("smpl.txt");

    if(file.fail()){
        cout<<"failed to open file\n";
        return 1;
    }

    string filename = "smple.txt";
    buffer << file.rdbuf();

    string info;
    info = buffer.str();

    stringstream ss(info);
    string line;

    while(ss >> line){
        cout<<"read line: "<<line<<endl;
    }

    cout<< "file content: "<<info;
    

    read_number_from_file();


    return 0;
}