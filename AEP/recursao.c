#include <stdio.h>
#include <stdlib.h>

int fatorial(int n){
    printf("%d", n);
    
    if(n == 0 || n == 1)
        return 1;
    else
        return fatorial(n-1) * n;
}

int main(){
    int n = 3;

    printf("fatorial de %d: %d", n, fatorial(n));

}