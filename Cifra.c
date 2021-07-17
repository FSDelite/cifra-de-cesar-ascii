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
    
    
    char kString[255];
    char value, replacement;
    int opr, key;
    
    printf("insert the key: ");
    scanf("%s", &kString);

    genareteKey(kString, &opr, &key);

    if(opr == 0){
        while((value = getc(arq)) != EOF){
            replacement =  value + key;
            fprintf(newArq, "%c", replacement);
        }
    }

    if(opr == 1){
        while((value = getc(arq)) != EOF){
            replacement =  value * key;
            fprintf(newArq, "%c", replacement);
        }
    }

    if(opr == 2){
        while((value = getc(arq)) != EOF){
            replacement =  value - key;
            fprintf(newArq, "%c", replacement);
        }
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
    
    char kString[255];
    char value, replacement;
    int opr, key;
    
    printf("insert the key: ");
    scanf("%s", &kString);

    genareteKey(kString, &opr, &key);

    if(opr == 0){
        while((value = getc(arq)) != EOF){
            replacement =  value - key;
            fprintf(newArq, "%c", replacement);
        }
    }

    if(opr == 1){
        while((value = getc(arq)) != EOF){
            replacement =  value / key;
            fprintf(newArq, "%c", replacement);
        }
    }

    if(opr == 2){
        while((value = getc(arq)) != EOF){
            replacement =  value + key;
            fprintf(newArq, "%c", replacement);
        }
    }

    fclose(arq);
    fclose(newArq);

    printf("decode complete!");
}

void genareteKey(char kString[], int *opr, int *key){

    switch(kString[0]){
        case 'w':
            *opr = 1; //MULTIPLICACAO
            break;
        case 'r':
            *opr = 2; //SUBTRACAO
            break;
        default:
            *opr = 0; // SOMA

    }
    int a=0;
    for(int i = kString[0], j = 0;i != 63; j++, i = kString[j]){
        a= a + kString[j];
    }
    *key = a;
}
