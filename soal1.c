/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : 5 Foundation of Algorithm
 *   Hari dan Tanggal    : Rabu 13 Mei 2026
 *   Nama (NIM)          : Jose Luis Fernando Saragi (13224013)
 *   Nama File           : soal1.c
 *   Deskripsi           : mencari jumlah kombinasi kurung dan print kombinasinya
 * 
 */
//https://prepinsta.com/c-program/generate-all-combinations-of-balanced-parentheses/
//https://www.w3resource.com/c-programming-exercises/practice/c-programming-practice-exercises-11.php

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


static char** printhasil(int n, int* givesize)
{
    int left, right, cap = 5000, ctr = 0;
    char *stack = malloc(2 * n + 1);
    char** parentes = malloc(cap * sizeof(char *));

    char *p = stack;
    left = right = 0;
    stack[2 * n] = '\0';

    while(p != stack || ctr == 0){
        if(left == n && right == n){
            parentes[ctr] = malloc(2 * n + 1);
            strcpy(parentes[ctr], stack);
            ctr++;

            while(--p != stack){
                if(*p == '('){
                    if(--left > right){
                        *p++ = ')';
                        right++;
                        break;
                    }
                }
                else{
                    right--;
                }
            }
        }
        else{
            while (left < n)
            {
                *p++ = '(';
                left++;
            }
            while(right < n){
                *p++ = ')';
                right++;
            }  
        }
    }
    *givesize = ctr;
    return parentes;
}

int main() {
    int n;
    int ctr;
    int total = 0;

    scanf("%d", &n);

    if(n == 0){
        printf("TOTAL %d", total+1);
        return 0;
    }
    char ** list = printhasil(n, &ctr);

    for(n = 0; n<ctr; n++){
        printf("%s\n", list[n]);
        total++;
    }
    getchar();
    printf("TOTAL %d", total);
    return 0;
}
 
