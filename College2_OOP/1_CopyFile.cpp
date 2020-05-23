#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char const *argv[])
{
    //命令参数确认，并提示用法
    if (argc <= 2)
    {
        printf("command <Source File> <Destination File>\n");
        exit(1);
    }
    ifstream infile(argv[1], ios::in);
    ofstream outfile(argv[2], ios::out);
    // ofstream outfile(argv[2], ios::app);//追加模式
    //文件打开确认
    if (!infile.is_open() && !infile.is_open())
    {
        printf("files don't exist!\n");
        exit(2);
    }
    string line;
    while (getline(infile, line))
        outfile << line << endl;
    return 0;
}
