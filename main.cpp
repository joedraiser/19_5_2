#include <iostream>
#include <string>
#include <fstream>

int main()
{
    std::cout << "Input path to file: ";
    std::string filename;
    std::cin >> filename;

    std::ifstream textFile;

    char buffer[1000];

    textFile.open(filename, std::ios::binary);

    if (!textFile.is_open())
    {
        std::cout << "file is not opened.";
        exit(EXIT_FAILURE);
    }

    do
    {
        textFile.read(buffer, sizeof(buffer)-1);
        buffer[textFile.gcount()]=0;

        std::cout << buffer;
    }
    while(!textFile.eof());


    textFile.close();
    return 0;
}