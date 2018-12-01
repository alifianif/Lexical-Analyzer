#include "hasil.h"

address alokasi(string x, string y,string z)
{
    address P = new element;
    P->token = x;
    P->jenis = y;
    P->info  = z;
    P->next = NULL;
    return P;
}
void createlist(List &L){
    L.first=NULL;
}
void insertKetentuan(List &l, address P){
    if (l.first==NULL)
    {
        P->next=l.first;
        l.first=P;
    }
    else{
        address q=l.first;
        while(q->next!=NULL)
        {
            q=q->next;
        }
        q->next=P;
    }
}
void gotoxy(int x, int y){
    COORD coordinate;
    coordinate.X=x;
    coordinate.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinate);
}

string checkValid (List L){
    string stack[100];
    string stnot[10];
    address P = L.first;
    int i = 0;
    int j = 0;
    int cekifthen = 0;
    int cekkurung = 0;
    string valid = "";

    if (P!=NULL){
        while (P!=NULL && valid == ""){
            if (P->token == "1"){
                if (i == 0 || i == 1){
                    stack[i] = "1";
                    i++;
//                }else if (i == 1){
//                    stack[i] = "";
//                    i--;
                }
                else if (i > 1){
                    valid = "tidak valid";
                }
                if (P->next != NULL
                    ){
                    P = P->next;
                    if ((P->token == "3") || (P->token == "4") || (P->token == "5")){
                        if (i == 0){
                            valid == "tidak valid";
                        }
                        else{
                            stack[i] = "";
                            i--;
                            if (P->next != NULL){
                                P = P->next;
                                if (P->token == "1"){}
                                else if (P->token == "7"){}
                                else if (P->token == "9"){}
                                else{valid = "tidak valid";}
                            }
                            else {
                                if ((i == 0 || i == 1) && (j == 0) && (cekifthen == 0 && cekkurung == 0)){
                                    valid = "valid";
                                }else{valid = "tidak valid";}
                            }
                        }
                    }
                    else if (P->token == "1"){}
                    else if (P->token == "7"){}
                    else if (P->token == "9"){}
                    else if (P->token == "10"){}
                    else{valid = "tidak valid";}
                }
                else {
                    if ((i == 0 || i == 1) && (j == 0) && (cekifthen == 0 && cekkurung == 0)){
                        valid = "valid";
                    }else {valid = "tidak valid";}
                }
            }
            else if (P->token == "2"){
                stnot[j] = "2";
                j++;
                if (P->next != NULL){
                    P = P->next;
                    if (P->token == "1"){
                        stnot[j] = "";
                        j--;
                        if (P->next != NULL){
                            P = P->next;
                            if (P->token == "10"){
                                cekkurung--;
                                stack[i] = "10";
                                i--;
                                if (P->next != NULL){
                                    P = P->next;
                                }
                                else if ((i == 0 || i == 1) && (j == 0) && (cekifthen == 0 && cekkurung == 0)){
                                    valid = "valid";
                                }else{valid = "tidak valid";}
                            }else{valid = "tidak valid";}
                        }
                        else if ((i == 0 || i == 1) && (j == 0) && (cekifthen == 0 && cekkurung == 0)){
                            valid = "valid";
                        }else{valid = "tidak valid";}
                    }
                    else if(P->token == "9"){
                        cekkurung++;
                        stack[i] = "9";
                        stnot[j] = "";
                        i++;
                        j--;
                        if (P->next != NULL){
                            P = P->next;
//                            if (P->token == "10"){
//                                cekkurung--;
//                                stack[i] = "10";
//                                i--;
//                                if (P->next != NULL){
//                                    P = P->next;
//                                }
//                                else if ((i == 0 || i == 1) && (j == 0) && (cekifthen == 0 && cekkurung == 0)){
//                                    valid = "valid";
//                                }else{valid = "tidak valid";}
                            }else if (P->token == "1"){}
                            else if (P->token == "2"){}
                            else {valid = "tidak valid";}
                        }
                        else if ((i == 0 || i == 1) && (j == 0) && (cekifthen == 0 && cekkurung == 0)){
                            valid = "valid";
                        }else{valid = "tidak valid";}
                    }
                    else{valid = "tidak valid";}
                }
                else{valid = "tidak valid";}
            }
            else if (P->token == "3"){
                if (i == 0){
                    valid = "tidak valid";
                }
                else{
                    stack[i] = "";
                    i--;
                    if (P->next != NULL){
                        P = P->next;
                        if (P->token == "1"){}
                        else if (P->token == "9"){}
                        else{valid = "tidak valid";}
                    }
                    else{valid = "tidak valid";}
                }
            }
            else if (P->token == "4"){
                if (i == 0){
                    valid = "tidak valid";
                }
                else{
                    stack[i] = "";
                    i--;
                    if (P->next != NULL){
                        P = P->next;
                        if (P->token == "1"){}
                        else if (P->token == "9"){}
                        else{valid = "tidak valid";}
                    }
                    else{valid = "tidak valid";}
                }
            }
            else if (P->token == "5"){
                if (i == 0){
                    valid = "tidak valid";
                }
                else{
                    stack[i] = "";
                    i--;
                    if (P->next != NULL){
                        P = P->next;
                        if (P->token == "1"){}
                        else if (P->token == "9"){}
                        else{valid = "tidak valid";}
                    }
                    else{valid = "tidak valid";}
                }
            }
            else if (P->token == "6"){
                cekifthen++;
                stack[i] = "6";
                i++;
                if (P->next != NULL){
                    P = P->next;
                    if (P->token == "1"){
                        stack[i] = "1";
                        i++;
                        if (P->next != NULL){
                            P = P->next;
                        }else{valid = "tidak valid";}
                    }
                    else if (P->token == "2"){}
                    else if (P->token == "9"){}
                    else{valid = "tidak valid";}
                }
                else{valid = "tidak valid";}
            }
            else if (P->token == "7"){
                cekifthen--;
                stack[i] = "";
                i--;
                if (P->next != NULL){
                    P = P->next;
                    if (P->token == "1"){
                        stack[i] = "";
                        i--;
                        if (P->next != NULL){
                            valid = "tidak valid";
                        }else{valid = "valid";}
                    }
                    else if (P->token == "2"){}
                    else if (P->token == "9"){}
                    else if (P->token == "10"){}
                    else{valid = "tidak valid";}
                }
                else{valid = "tidak valid";}
            }
            else if (P->token == "8"){
                if (i == 0){
                    valid = "tidak valid";
                }
                else{
                    stack[i] = "";
                    i--;
                    if (P->next != NULL){
                        P = P->next;
                        if (P->token == "1"){}
                        else if (P->token == "9"){}
                        else{valid = "tidak valid";}
                    }
                    else{valid = "tidak valid";}
                }
            }
            else if (P->token == "9"){

                cekkurung++;
                stack[i] = "9";
                i++;
                if (P->next != NULL){
                    P = P->next;
                    if (P->token == "1"){}
                    else if (P->token == "2"){}
                    else if (P->token == "6"){}
                    else if (P->token == "9"){}
                    else if (P->token == "10"){}
                    else{valid = "tidak valid";}
                }
                else{valid = "tidak valid";}
            }
            else if (P->token == "10"){
                cekkurung--;
                stack[i] = "";
                i--;
                if (P->next != NULL){
                    P = P->next;
                    if (P->token == "2"){}
                    else if (P->token == "3"){}
                    else if (P->token == "4"){}
                    else if (P->token == "5"){}
                    else if (P->token == "7"){}
                    else if (P->token == "8"){}
                    else if (P->token == "10"){}
                    else{valid = "tidak valid";}
                }
                else {
                    if ((i == 0 || i == 1) && (j == 0) && (cekifthen == 0 && cekkurung == 0)){
                        valid = "valid";
                    }
                    else{valid = "tidak valid";}
                }
            }
            else if (P->token == "error"){
                valid = "tidak valid";
            }
            else {valid = "tidak valid";}
        }
    }
    else {valid = "tidak valid";}

    return valid;
}

void viewHasil(List L, string valid)
{
    address P = L.first;
    int i=4;
    int data=0;
    address Q=L.first;

    gotoxy(1,3);cout<<"Inputan   ";
    gotoxy(11,3);cout<<"Jenis    ";
    gotoxy(22,3);cout<<"Token    ";
//    gotoxy(33,3);

    while (P!=NULL){
               gotoxy(1,i);cout<<P->info;
               gotoxy(11,i);cout<<P->jenis;
               gotoxy(22,i);cout<<P->token;
               if (P->info=="error"){
                while(Q!=NULL){
                    Q=Q->next;
                }
                P=Q;
               }else {P = P->next; i++;}
        }

        cout<<endl;
        cout<<" Data yang dimasukan adalah "<<valid<<endl;
}

void CheckString(string input){
List l;
createlist(l);
int i=0;

while(i<=input.length()){
    if(((input[i]=='p') or (input[i]=='q') or (input[i]=='r') or (input[i]=='s')) and ((input[i-1]=' ') or (input[i-1]!=' ')))
    {
        string x="";
        x=x+input[i];
        insertKetentuan(l,alokasi("1","Operand",x));
        i++;


    }else if(input[i]=='n'){
        i++;
        if (input[i]=='o'){
            i++;
            if (input[i]=='t')
            {
                insertKetentuan(l,alokasi("2","Operator","not"));
                i++;
            }else  {insertKetentuan(l,alokasi("error","error","error"));}
        }else  {insertKetentuan(l,alokasi("error","error","error"));}
    } else if(input[i]=='a'){
        i++;
        if (input[i]=='n'){
            i++;
            if (input[i]=='d')
            {
                insertKetentuan(l,alokasi("3","Operator","and"));
                i++;
            }else  {insertKetentuan(l,alokasi("error","error","error"));}
        }else  {insertKetentuan(l,alokasi("error","error","error"));}

    }else if(input[i]=='o'){
        i++;
        if (input[i]=='r'){
            insertKetentuan(l,alokasi("4","Operator","or"));
            i++;

        }else  {insertKetentuan(l,alokasi("error","error","error"));}

    }else if(input[i]=='x'){
        i++;
        if (input[i]=='o'){
            i++;
            if (input[i]=='r')
            {
                insertKetentuan(l,alokasi("5","Operator","xor"));
                i++;
            }else  {insertKetentuan(l,alokasi("error","error","error"));}
        }else  {insertKetentuan(l,alokasi("error","error","error"));}
    }else if(input[i]=='i'){
        i++;
        if (input[i]=='f' ){
            i++;
            if (input[i]=='f')
            {
                insertKetentuan(l,alokasi("8","Operator","iff"));
                i++;
            }else if (input[i]==' ') {
                insertKetentuan(l,alokasi("6","Operator","if"));
            }else insertKetentuan(l,alokasi("error","error","error"));
        }else {insertKetentuan(l,alokasi("error","error","error"));}
    }else if(input[i]=='('){
        insertKetentuan(l,alokasi("9","Grouping","("));
        i++;
    }else if(input[i]==')'){
        insertKetentuan(l,alokasi("10","Grouping",")"));
        i++;
    }else if (input[i]=='t'){
        i++;
        if(input[i]=='h'){
            i++;
            if(input[i]=='e'){
                i++;
                if(input[i]=='n'){
                    i++;
                    insertKetentuan(l,alokasi("7","Operator","then"));
                }else  insertKetentuan(l,alokasi("error","error","error"));
            }else insertKetentuan(l,alokasi("error","error","error"));
        }else insertKetentuan(l,alokasi("error","error","error"));
    }else i++;

}
 string valid = checkValid(l);
 viewHasil(l, valid);
}
