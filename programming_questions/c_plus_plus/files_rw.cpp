#include<iostream>
#include<fstream>

using namespace std;

// ostream => to create and write to file
// istream => to read file


void anotherExample(){
    
    // Open the file in read/write mode (modifying it as "append" mode)
    fstream file("example.txt", ios::in | ios::out | ios::app);
    
    if (file.is_open()) {
        // Writing to the file
        file << "Appending this line to the file.\n";
        
        // Seeking to the beginning to read the file contents
        file.seekg(0, ios::beg);
        
    } else {
        cout << "Unable to open file.";
    }

    string line;
    while (getline(file, line)) {
        cout << line << '\n';
    }
    file.close();

}

int main(){

    fstream myFile("random_file.txt");

    myFile << "add text to the random file \n add another line to the text file";

    myFile.close();
    
    fstream readFile("random_file.txt");
    string txt;

    while (getline(readFile, txt))
    {
        cout << "file content: "<< txt << endl;
    }
    
    readFile.close();


    anotherExample();


    return 0;
}
