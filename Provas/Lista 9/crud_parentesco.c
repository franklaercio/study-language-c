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
            printf("Identificador %i duplicado!", p.id);
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

bd_irmaos inserir_irmão(bd_pessoas pessoas, bd_irmaos irmaos, int id1, int id2) {
    bool isParentescoCadastrado = false;
    
    for(int i = 0; i < 50; i++) {
        if((irmaos.irmaos[i].id1 == id1 && irmaos.irmaos[i].id2 == id2) || (irmaos.irmaos[i].id1 == id2 && irmaos.irmaos[i].id2 == id1)) {
            printf("Parentesco %i %i já cadastrado!", id1, id2);
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

void imprimir_irmãos(bd_irmaos irmaos, bd_pessoas pessoas, int id) {
    bool isPossuiIrmaos = false;
    
    for(int i = 0; i < 50; i++) {
        if((irmaos.irmaos[i].id1 = id) || (irmaos.irmaos[i].id2 == id)) {
            isPossuiIrmaos = true;
            
            if(irmaos.irmaos[i].id1 != id) {
                printf("%s é irmão de %s", pessoas.pessoas[irmaos.irmaos[i].id1].nome, pessoas.pessoas[id].nome);
            }
            
            if(irmaos.irmaos[i].id2 != id) {
                printf("%s é irmão de %s", pessoas.pessoas[irmaos.irmaos[i].id2].nome, pessoas.pessoas[id].nome);
            }
        }
    }
    
    if(!isPossuiIrmaos) {
        printf("%s não tem irmãos cadastrados", pessoas.pessoas[id].nome);
    }
}

int main() {
    char operacao = ' ';
    char dados[256] = "";
    int id1, id2;
    bd_pessoas pessoas;
    pessoa p;
    irmao i;
    bd_irmaos irmaos;

    for(int i = 0; i < 20; i++) {
      pessoas.pessoas[i].id = 0;
    }

    for(int i = 0; i < 50; i++) {
      irmaos.irmaos[i].id1 = 0;
      irmaos.irmaos[i].id2 = 0;
    }
    
    while(operacao != SAIR){
        char nome[21];
        int id;
        scanf("%c[^\n]", &operacao);
        
        switch(operacao){
            case INSERIR:
                fgets(dados, 256, stdin);
                dados[strcspn(dados, "\n")] = 0;
                sscanf(dados, "%[^,],%d", nome, &id);
                pessoa pessoa = {.id = id};
                strcpy(pessoa.nome, nome);

                printf("%s\n", nome);
                printf("%i\n", id);

                pessoas = inserir_pessoa(pessoas, pessoa);
                break;
            case PARENTESCO:
                scanf("%i %i", &id1, &id2);
                irmaos = inserir_irmão(pessoas, irmaos, id1, id2);
                break;
            default:
                break;
        }
    }
    
    return 0;
}