#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//Using no Universal Variables
int* shiftTable(int stable[], char pattern[], int plen){
        int i;
        for(i=0; i<256; i++)
                stable[i] = plen;
        printf("\n\tShift Table::\n\tchar = shift");
        for(i=0; i<plen-1; i++){
                stable[pattern[i]] = plen-i-1;
                printf("\n\t%c = %d", pattern[i], stable[pattern[i]]);
        }
        return stable;
}

void horspool(int stable[], char pattern[], char str[], int slen, int plen){
        int i, k, oh;
        i = plen-1;
        oh = 0;
        while(oh <= slen-plen){
                k=0;
                i=plen-1;
                while(k<plen && pattern[i] == str[oh+i]){
                        i--;
                        k++;
                }
                if(k == plen)
                        printf("\n\tThe pattern occurs at position %d.\n", oh+1);
                oh += stable[str[oh+plen-1]];
        }
}

int main(){
        int i, slen, plen;
        char pattern[100], str[1000];
        int st[256];
        int* stable;
        printf("The input string = ");
        scanf("%[^\n]c", str);
        printf("The pattern = ");
        scanf("  %[^\n]c", pattern);
        slen = strlen(str);
        plen = strlen(pattern);
        stable = shiftTable(st, pattern, plen);
        horspool(stable, pattern, str, slen, plen);
        return 0;
}
