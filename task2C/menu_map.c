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
        *(mapped_array+i) = f(*(array+i));
    }
    return mapped_array;
}

int* filter(int *array, int array_length, bool (*f) (int)){
    int arraysize=0;
    for(int i=0;i<array_length;i++){
	if(f(array[i]))
        	arraysize++;
    }
   int* mapped_array = (int*)(malloc(arraysize*4));
   int count=0;
   for(int i=0;i<array_length;i++){
	if(f(array[i])){
	  mapped_array[count]=array[i];
	  count++;
  }	

}
    return mapped_array;
}



int main(int argc, char **argv){
    //char arr1[] = {'H','e','y','!'};
    //char* arr2 = map(arr1, 4, censor);
    //printf("%s\n", arr2);
    //free(arr2);

    //printf("%c",encrypt('C'));
    //printf("%c",encrypt('c'));
    int base_len = 5;
    char arr1[base_len];
    char* arr2 = map(arr1, base_len, my_get);
    char* arr3 = map(arr2, base_len, encrypt);
    char* arr4 = map(arr3, base_len, dprt);
    char* arr5 = map(arr4, base_len, decrypt);
    char* arr6 = map(arr5, base_len, cprt);
    free(arr2);
    free(arr3);
    free(arr4);
    free(arr5);
    free(arr6);



    return 0;
}
