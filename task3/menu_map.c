#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char encrypt(char c){
    if(c>=0x41 && c<=0x7a)
        return c+2;
    else
        return c;
}

char decrypt(char c){
    if(c>=0x41 && c<=0x7a)
        return c-2;
    else
        return c;
}

char dprt(char c){
    printf("%d\n",c);
    return c;
}

char cprt(char c){
    if(c>=0x41 && c<=0x7a)
        printf("%c\n",c);
    else
        printf("*\n");
    return c;
}

char my_get(char c){
    return fgetc(stdin);
}

char quit(char c){
    if(c=='q')
        exit(0);
    else
        return c;
}


char censor(char c) {
    if(c == '!')
        return '*';
    else
        return c;
}

char* map(char *array, int array_length, char (*f) (char)){
    char* mapped_array = (char*)(malloc(array_length*sizeof(char)));
    /* TODO: Complete during task 2.a */
    for(int i=0;i<array_length;i++){
        mapped_array[i] = f(array[i]);
    }
    return mapped_array;
}

struct fun_desc {
    char *name;
    char (*fun)(char);
};

int main(int argc, char **argv){
    char charArray[5]="";
    char* carray = charArray;
    struct fun_desc menu[] = { {"Censor",censor},
                               {"Encrypt", encrypt},
                               {"Decrypt", decrypt},
                               {"Print dec", dprt},
                               {"Print string", cprt},
                               {"Get string", my_get},
                               {"Quit", quit},
                               {NULL, NULL}};
    int bound = 0;
    while(menu[bound+1].name!=NULL)
        bound++;
    int command;
    char c;
    while(1) {
        printf("Please choose a function:\n");
        for (int i = 0; i <= bound; i++) {
            printf("%d) %s\n", i, menu[i].name);
        }
        printf("Option: ");
        scanf("%d",&command);
        c = fgetc(stdin);
        if (command != 10) {
            if (command >= 0 && command <= bound) {
                printf("Within bounds\n");
                carray = map(carray, 5,menu[command].fun);
                printf("DONE.\n");
            }
            else {
                printf("Not within bounds\n");
                exit(1);
            }
        }
    }
}
