#include <stdio.h>
int hipo();

int mdc2();

int mdc3();

int main(){
    int a, b, c, maior;
    while(scanf("%d %d %d", &a, &b, &c) != EOF){

    maior = hipo(a, b, c);

    if (a == maior){
        if (maior * maior == (b * b) + (c * c)){
            if(mdc3(a, b, c) == 1){

                printf("tripla pitagorica primitiva\n");
            }
            else{
                printf("tripla pitagorica\n");
            }
        }
        else{
            printf("tripla\n");
        }

    }
    else if(b == maior){
        if (maior * maior == (a * a) + (c * c)){
            if(mdc3(a, b, c) == 1){

                printf("tripla pitagorica primitiva\n");
            }
            else{
                printf("tripla pitagorica\n");
            }
        }
        else{
            printf("tripla\n");
        }

    }
    else{
        if (maior * maior == (b * b) + (a * a)){
            if(mdc3(a, b, c) == 1){
            
                printf("tripla pitagorica primitiva\n");
            }
            else{
                printf("tripla pitagorica\n");
            }
        }
        else{
            printf("tripla\n");
        }

    }
}
    return 0;
}





int hipo(int a, int b, int c){


    if(a>b){
        if(a > c){
            
            return a;
        }
        else if(a < c){
            return c;
        }
    }
    else if (b>a)
    {
        if(b > c){
            
            return b;
        }
        else if(b < c){
           
            return c;
        }
    }
}


int mdc2(int a, int b){
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int mdc3(int a, int b, int c ){

    return mdc2(mdc2(a, b), c);
}