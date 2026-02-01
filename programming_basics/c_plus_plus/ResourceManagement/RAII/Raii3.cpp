// Program implements using fstream, implemented with RAII buit-in.

#include<fstream>               // file stream implemented with RAII in-built
#include<iostream>

int main()
{
    std::ifstream input("data.txt", std::ios::in);
    std::ofstream output("output.txt", std::ios::out);

    std::string line;
    while(std::getline(input, line))
    {
        output<<line;
    }

    // resource is released even if exception occurs.
    // no need to remember fclose or call destructor

    return 0;
} 