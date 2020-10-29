#include <stdio.h>
#include <string.h>

void diadasemana(char *entrada, int *bissexto, int *status) {
    int d, m, y;

    if(entrada[2] == '/'){
      d = entrada[0] + entrada[1];
      m = entrada[3] + entrada[4];
    }else{
      d = entrada[3] + entrada[4];
      m = entrada[0] + entrada[1];
    }

    y = entrada[6] + entrada[7] + entrada[8] + entrada[9];

    if(d > 31 || m > 12){
      *status =  -1;
    }else{
      *status = (23*m/9+d+4+(m<3?y--:y-2)+y/4-y/100+y/400)%7;
    }
}

int main(){
    int status=0, bissexto=0;
    char entrada[11]={0}, *saida=NULL;
    fgets(entrada,11,stdin);
        
    diadasemana(entrada, &bissexto, &status);
        
    if (status>0){
      switch (status){
      case 0:
        strcpy(saida, "Domingo");
        break;
      case 1:
        strcpy(saida, "Segunda");
      case 2:
        strcpy(saida, "Terça");
      case 3:
        strcpy(saida, "Quarta");
      case 4:
        strcpy(saida, "Quinta");
      case 5:
        strcpy(saida, "Sexta");
      case 6:
        strcpy(saida, "Sábado");     
        break;
      default:
        break;
    }

      printf("%s.%s\n", saida, bissexto? " Ano bissexto." : "");
    }else {
        if (status==-1)
            printf("Data inexistente.\n");
        else
            printf("Entrada invalida.\n");
        return 1;
    }

    return 0;
}