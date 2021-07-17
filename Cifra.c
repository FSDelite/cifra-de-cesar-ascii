#include <stdio.h>
#include <stdlib.h>

void code();
void decode();
void genareteKey(char kString[], int *opr, int *key);

int main (void){

    char c;
    printf("c -  code file\nd - decode file\nchoose an option: ");
    scanf(" %c", &c);
    if(c == 'c'){
        code();
    }
    if(c == 'd'){
        decode();
    }

    return 0;
}

void code(){

    FILE *arq =  NULL;
    char name[255];
    printf("insert the file's name: ");
    scanf("%s", &name);

    arq = fopen(name,"r+");
    if(arq == NULL){
        printf("the file doesen't exist");
        exit(0);
    }

    FILE *newArq = NULL;
    newArq = fopen("codeFile.txt", "wt");
    int key;
    char value, replacement;
    printf("insert the key: ");
    scanf("%d", &key);

    while((value = getc(arq)) != EOF){
          replacement =  value + key;
          fprintf(newArq, "%c", replacement);
    }
    fclose(arq);
    fclose(newArq);

    printf("code complete!");
}
void decode(){

    FILE *arq =  NULL;
    char name[255];
    printf("insert the file's name: ");
    scanf("%s", &name);

    arq = fopen(name,"r+");
    if(arq == NULL){
        printf("the file doesen't exist");
        exit(0);
    }

    FILE *newArq = NULL;
    newArq = fopen("decodedFile.txt", "wt");
    int key;
    char value, replacement;
    printf("insert the key: ");
    scanf("%d", &key);

    while((value = getc(arq)) != EOF){
          replacement =  value - key;
          fprintf(newArq, "%c", replacement);
    }
    fclose(arq);
    fclose(newArq);

    printf("decode complete!");
}

void genareteKey(char kString[], int *opr, int *key){
    
    key = 0;

    switch(kString[0]){
        case 'w':
            *opr = 1; //SOMA
            break;
        case 'r':
            *opr = 2; //SUBTRACAO
            break;
        case 'f':
            *opr = 3; //MULTIPLICACAO
            break;
    }
    
    for(int i = kString[1], int j = 1;i != 63; j++, i = kString[j]){
        *key = key + kString[j];
    }
}










