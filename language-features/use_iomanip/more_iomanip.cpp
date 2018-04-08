#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;

    fin.open("rawdata.txt");
    fout.open("neatdata.txt");

    int number_after_decimalpoint =5;
    int field_width = 12;

    fout.setf(ios::fixed);
    fout.setf(ios::showpoint);
    fout.setf(ios::showpos);
    fout.precision(number_after_decimalpoint);

    double next;
    while (fin >> next)
    {
        fout << setw(field_width) << next << "\n";
    }
    fin.close( );
    fout.close( );
    cout << "End of program.\n";
    return 0;
}
