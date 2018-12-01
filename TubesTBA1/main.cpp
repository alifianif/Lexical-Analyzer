#include <iostream>
#include <string.h>
#include <windows.h>
#include "hasil.h"
/*Kelompok TBA
Kelas IF-38-07
Tubes TBA Bagian Pertama
1. Ramanti Dwi 1301144267
2. Alifiani Fauzia	1301140417
3. Fadhil Mulia	1301140347
4. Andreas Jonathan	1301140427
hasil.cpp = tempat dimana proses terbentuk.
*/

using namespace std;

int main()
{
    string input;
    gotoxy(0,1); cout<<"Selamat datang!!";
    gotoxy(0,2);cout<<"Masukan Inputan  : ";
    getline(cin,input);
    CheckString(input);
    return 0;
}
