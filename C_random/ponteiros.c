#include <stdio.h>

int main(){
    /*int arr[]= {1, 2, 3, 4, 5}, arr2[]={5, 4, 3, 2, 1}, *p, *q;
    p= arr2;
    q=arr;
    for(int i=0; i<5; i++){
        printf("%d\n", *(q+i)+*(p+i));
    }
    */
   int arr[]={1, 2, 3, 4, 5}, *p, var=0;
   p = arr;
   for(int i=0; i<5; i++){
    var+=*(p+i);
   }
   printf("%d", var);
    return 0;
}