#include <stdio.h>
#include <stdbool.h>
#include <string.h>

enum operacoes {INSERIR = 'i', PARENTESCO = 'b', SAIR = 'p'};

typedef struct pessoa_t{ 
  char nome[20]; 
  int id;
}pessoa;

typedef struct irmao_t{
  int id1;
  int id2;
}irmao;

typedef struct bd_pessoas_t{
 pessoa pessoas[20];
 int num_pessoas;
}bd_pessoas;

typedef struct bd_irmaos_t{
  irmao irmaos[50];
  int num_relacoes;
}bd_irmaos;

bd_pessoas inserir_pessoa (bd_pessoas pessoas, pessoa p) {
    bool isIdentificadorDuplicado = false;

    for(int i = 0; i < 20; i++) {
        if(pessoas.pessoas[i].id == p.id) {
            printf("Identificador %i duplicado!\n", p.id);
            isIdentificadorDuplicado = true;
            break;
        }
    }
    
    if(!isIdentificadorDuplicado) {
        pessoas.pessoas[pessoas.num_pessoas] = p;
        pessoas.num_pessoas++;
    }
    
    return pessoas;
}

bd_irmaos inserir_irmao(bd_pessoas pessoas, bd_irmaos irmaos, int id1, int id2) {
    bool isParentescoCadastrado = false;
    
    for(int i = 0; i < 50; i++) {
        if((irmaos.irmaos[i].id1 == id1 && irmaos.irmaos[i].id2 == id2) || (irmaos.irmaos[i].id1 == id2 && irmaos.irmaos[i].id2 == id1)) {
            printf("Parentesco %i %i já cadastrado!\n", id1, id2);
            isParentescoCadastrado = true;
            break;
        }
    }
    
    if(!isParentescoCadastrado) {
        irmao i;
        i.id1 = id1;
        i.id2 = id2;
        
        irmaos.irmaos[irmaos.num_relacoes] = i;
        irmaos.num_relacoes++;
    }
    
    return irmaos;
} 

void imprimir_irmaos(bd_irmaos irmaos, bd_pessoas pessoas, int id) {
    bool isPossuiIrmaos = false;
    
    for(int i = 0; i < 50; i++) {
        if((irmaos.irmaos[i].id1 == id) || (irmaos.irmaos[i].id2 == id)) {
            isPossuiIrmaos = true;
            
            if(irmaos.irmaos[i].id1 != id) {
                printf("%s é irmão de %s\n", strtok(pessoas.pessoas[irmaos.irmaos[i].id1].nome, "\n"), strtok(pessoas.pessoas[id].nome, "\n"));
            }
            
            if(irmaos.irmaos[i].id2 != id) {
                printf("%s é irmão de %s\n", strtok(pessoas.pessoas[irmaos.irmaos[i].id2].nome, "\n"), strtok(pessoas.pessoas[id].nome, "\n"));
            }
        }
    }
    
    if(!isPossuiIrmaos) {
        printf("%s não tem irmãos cadastrados\n", strtok(pessoas.pessoas[id].nome, "\n"));
    }
}

int main() {
    char operacao;
    char dados[256];
    int id1, id2, id;
    bd_pessoas pessoas;
    pessoa p;
    irmao i;
    bd_irmaos irmaos;

    pessoas.num_pessoas = 1;
    irmaos.num_relacoes = 1;

    for(int i = 0; i < 20; i++) {
      pessoas.pessoas[i].id = -1;
    }

    for(int i = 0; i < 50; i++) {
      irmaos.irmaos[i].id1 = -1;
      irmaos.irmaos[i].id2 = -1;
    }
    
    while(operacao != SAIR){
        char nome[21];
        int id;
        scanf("%c", &operacao);
        
        if(operacao == INSERIR) {
            scanf("%[^,], %i", nome, &id);
            pessoa pessoa = {.id = id};
            strcpy(pessoa.nome, nome);

            pessoas = inserir_pessoa(pessoas, pessoa);
        }else if(operacao == PARENTESCO) {
            scanf("%i %i", &id1, &id2);
            irmaos = inserir_irmao(pessoas, irmaos, id1, id2);
        }else if(operacao == SAIR) {
            scanf("%i", &id);
            imprimir_irmaos(irmaos, pessoas, id);
            break;
        }
    }
    
    return 0;
}