#ifndef HASIL_H_INCLUDED
#define HASIL_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <String.h>
#include <windows.h>
using namespace std;

typedef struct element *address;
struct element{
    string info;
    string token;
    string jenis;
    address next;
};
struct List{
    address first;
};
//struct stack{
//    int st[100];
//};
address alokasi(int x); //alokasi address
void createlist(List &L); //procedure untuk membuat suatu list
void insertKetentuan(List &L, address P); //procedure untuk menambahkan address baru
void gotoxy(int x, int y); //procedure untuk menempatkan kursor
void viewHasil(List L); // procedure untuk melihat hasil
void CheckString(string input); //procedure untuk pengecekan karakter di string yang ada dan membahkan jenis dan token sesuai dengan aturan yang ada.
string checkValid(List L);
#endif // HASIL_H_INCLUDED
