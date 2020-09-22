#include <stdio.h>

int main() {
    int meses;
    int macho = 1, femea = 1, paresCoelhos;
    
    scanf("%i", &meses);
    
    for (int i = 3; i <= meses; i = i + 1){                                        
        paresCoelhos = macho + femea;                    
        macho = femea;                           
        femea = paresCoelhos;                           
    }   
    
    printf("%i", paresCoelhos);
    
    return 0;
}