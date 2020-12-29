#include <stdio.h>
#include <string.h>

#define line 256
#define word 30

int get_line(char s[]) {
    if(fgets(s, line, stdin)==NULL)
        return -1;
    return strlen(s);
}

int getword(char w[]) {
    char temp;
    for (int i = 0; i < word; ++i) {
        temp = fgetc(stdin);
        if(temp == EOF){
            return -1;
        }
        if (temp=='\n'||temp== ' '|| temp == '\t') {
            w[i]='\0';
            break;
        }
        w[i] = temp;
    }
    return strlen(w);
}

int substring(char *str1, char *str2) {
    int cmp = 0;
    if (strlen(str2) > strlen(str1))
        return 0;
    for (int i = 0, j = 0; i < strlen(str1) && cmp < strlen(str2); i++) {
        if (str1[i] == str2[j]) {
            cmp++;
            j++;
        }
    }

    return cmp==strlen(str2)?1 : 0;
}

int similar(char *s, char *t, int n){
    int cmp = 0;
    if (strlen(t) > strlen(s))
        return 0;
    for (int i = 0, j = 0; i < strlen(s) && cmp < strlen(t); i++) {
        if (s[i] == t[j]) {
            cmp++;
            j++;
        }
    }
    if(cmp!=strlen(t))
        return 0;
    if(cmp==strlen(t))
        return 1;
    return (cmp==strlen(s)-n)?1 : 0;
}

void print_lines(char *str){
    char text[line];
    while(get_line(text)!=-1){
        if(similar(text,str,1))
            printf("%s",text);
    }
}

void print_similar_words(char *str){
    char wrd[word];
    while(getword(wrd)!=-1){
        if(similar(wrd,str,1))
            printf("%s \n",wrd);
    }
}

char splitFirst (char* wrd){
    char* fl;
    fgets(fl,34,stdin);
    int i=0;
    while(fl[i]!=' '){
        wrd[i]=fl[i];
    }
    return fl[i+1];
}
int main(){
    char text[100];
    char* wrd;
    char oper=splitFirst(wrd);
    print_lines("cat");
    return 0;
}