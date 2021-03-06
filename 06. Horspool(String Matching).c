#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//Using no Universal Variables
// int flag;
int* shiftTable(int stable[], char pattern[]){
        int i, plen = strlen(pattern);
        for(i=0; i<256; i++)
                stable[i] = plen;
        printf("\n\tShift Table::\n\tchar = shift");
        for(i=0; i<plen-1; i++){
                stable[pattern[i]] = plen-i-1;
                printf("\n\t%c = %d", pattern[i], stable[pattern[i]]);
        }
        printf("\n");
        return stable;
}

int horspool(int stable[], char pattern[], char str[]){
        int i, k, oh, flag = 0;
        int slen = strlen(str), plen = strlen(pattern);
        oh = 0;
        while(oh <= slen-plen){
                k=0;
                i=plen-1;
                while(k<plen && pattern[i] == str[oh+i]){
                        i--;
                        k++;
                }
                if(k == plen){
                        flag = 1;
                        printf("\n\tThe pattern occurs at position %d.\n", oh+1);
                }
                oh += stable[str[oh+plen-1]];
        }
        return flag;
}

int main(){
        int flag, st[256];
        int* stable;
        char pattern[100], str[1000];
        printf("The input string = ");
        scanf("%[^\n]c", str);
        printf("The pattern = ");
        scanf("  %[^\n]c", pattern);
        stable = shiftTable(st, pattern);
        flag = horspool(stable, pattern, str);
        if(flag == 0)
                printf("\n\tThe key is not found :-(\n\n");
        return 0;
}
