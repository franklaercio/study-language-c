#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char matricula[256];
    char nome[256];
} Aluno;

typedef struct {
    int tamanho;
    Aluno alunos[50];
} BancoDados;

bool equals(char * a, char *b) {
  int index = 0;
 
  while(a[index] == b[index]){
    if(a[index] == '\0' || b[index] == '\0' ){
      break;
    }

    ++index;
  }

  if(a[index] == '\0' && b[index] == '\0' ){
    return true;
  }else{
    return false;
  }
}

void inserir(Aluno *aluno, BancoDados *bancoDados) {
    fgets((*aluno).matricula, 256, stdin);
    (*aluno).matricula[strcspn((*aluno).matricula, "\n")] = 0;

    fgets((*aluno).nome, 256, stdin);
    (*aluno).nome[strcspn((*aluno).nome, "\n")] = 0;
            
    (*bancoDados).alunos[(*bancoDados).tamanho] = (*aluno);
    (*bancoDados).tamanho += 1;
    
    printf("inserido %s\n", (*aluno).matricula);
}

void imprimir(BancoDados *bancoDados) {
    printf("Alunos\n");
    
    for(int i = 0; i < (*bancoDados).tamanho; i++) {
        printf("matricula: %s\n", (*bancoDados).alunos[i].matricula);
        printf("nome: %s\n", (*bancoDados).alunos[i].nome);
    }
}

void status(int memoriaDisponivel, int memoriaOcupada) {
    float porcentagemUso = (float) memoriaDisponivel/memoriaOcupada;

    printf("memoria ocupada: %i/%i ou %2.f%%\n", memoriaDisponivel, memoriaOcupada, porcentagemUso*100);
}

void ordenar(BancoDados *bancoDados) {
    Aluno alunoAux;

    for (int i = (*bancoDados).tamanho - 1; i > 0; i--){
        for (int k = 0; k < i; k++){
            if((*bancoDados).alunos[k].nome[0] > (*bancoDados).alunos[k + 1].nome[0]) {
                alunoAux = (*bancoDados).alunos[k];
                (*bancoDados).alunos[k] = (*bancoDados).alunos[k+1];
                (*bancoDados).alunos[k+1] = alunoAux;                     
            }
        }
    }
    
    printf("ordenacao completa\n");
}

int main() {
    int tamanhoBanco;
    char comando[100];
    BancoDados bancoDados;
    bancoDados.tamanho = 0;
    
    scanf("%i", &tamanhoBanco);
    
    while(1) {
        fgets(comando, 100, stdin);
        comando[strcspn(comando, "\n")] = 0;
        
        if(comando[0] == 's' && comando[1] == 'a') {
            break;
        }
        
        if(equals(comando, "inserir")) {
            Aluno aluno;
            inserir(&aluno, &bancoDados);
        }
        
        if(equals(comando, "imprimir")) {
            imprimir(&bancoDados);
        }
        
        if(equals(comando, "status")) {
            status(bancoDados.tamanho, tamanhoBanco);
        }
        
        if(equals(comando, "ordenar")) {
            ordenar(&bancoDados);
        }
    }    
    
    return 0;
}