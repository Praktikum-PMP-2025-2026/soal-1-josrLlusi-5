/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : 5 Foundation of Algorithm
 *   Hari dan Tanggal    : Rabu 13 Mei 2026
 *   Nama (NIM)          : Jose Luis Fernando Saragi (13224013)
 *   Nama File           : soal1.c
 *   Deskripsi           : mencari jumlah kombinasi kurung dan print kombinasinya
 * 
 */
//https://prepinsta.com/c-program/generate-all-combinations-of-balanced-parentheses/

#include <stdio.h>
#include <string.h>


void trigger(int n, int pos, int open, int close){
    static char str[100];

    if(close == n){
        printf("%s \n", str);
        return;
    }
    else{
        if(open > close){
            str[pos] = ')';
            trigger(n, pos+1, open, close+1);
        }
        if(open < n){
            str[pos] = '(';
            trigger(n, pos+1, open+1, close);
        }
    }
}

int main() {
    int n;
    //int trigger = 0;

    scanf("%d", &n);
    if(n > 0){
        trigger(n, 0, 0, 0);
    }
    //print(n);
    getchar();
    return 0;
}
 
