//Silvia Tran
//Silvia Tran
//CECS 325-01
//Prog 4 - Sorting Contest Using PThreads
//03/27/2024
//I certify that this program is my own original work.
//I did not copy any part of this program from any other source.
//I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <fstream>
using namespace std;

int main(int arg_c, char *arg_v[])
{
    if (arg_c < 4)
    {
        cout << "Enter 3 parameters:\n";
        cout << "Parameter 1: total count of numbers to generate\n";
        cout << "Parameter 2: minimum value\n";
        cout << "Parameter 3: maximum value\n";
        cout << "Example: generate 10000000 100000 999999\n";
        exit (EXIT_SUCCESS);
    }

    for (int i = 0; i < arg_c; i++)
    {
        cout << "arg_v["<< i <<"] = " << arg_v[i] << endl;
    }

    int COUNT = stoi(arg_v[1]);     //stoi : string to integer
    int MIN = stoi(arg_v[2]);
    int MAX = stoi(arg_v[3]);

    ofstream fout;

    fout.open("numbers.dat");
    for (int i = 0; i < COUNT; i++)
    {
        fout << (rand() % (MAX - MIN + 1) + MIN) << endl;
    }

    fout.close();
    return 0;
    
}