#include <stdio.h>
#include <string.h>
#include <stdbool.h>

enum instrucoes {TAMANHO_MAXIMO = 20, IDADE_INEXISTENTE = -1};

typedef struct pessoa {
    char nome[TAMANHO_MAXIMO + 1];
    int idade;
    char sexo;
} Pessoa;

struct pessoa pessoas[TAMANHO_MAXIMO];

Pessoa lerDados(char * dados, Pessoa pessoa);

void create(int pessoaId, Pessoa pessoa, char *dados);

void delete(Pessoa pessoa);

void imprimirPessoas();

bool equals(char * a, char *b);

int main() {
  int pessoaId = 0;

  for (int i = 0; i < TAMANHO_MAXIMO; i++){
      strcpy(pessoas[i].nome, "NULL");
      pessoas[i].idade = IDADE_INEXISTENTE;
      pessoas[i].sexo = 'N';
  }

  while(1) {
      char comando[100];
      char dados[256];
      Pessoa pessoa;

      fgets(comando, 256, stdin);
      comando[strcspn(comando, "\n")] = 0;

      if(equals(comando, "inserir")) {
          create(pessoaId, pessoa, dados);
          pessoaId++;
      }else if(equals(comando, "deletar")) {
          pessoa = lerDados(dados, pessoa);
          delete(pessoa);
      }else if (equals(comando, "imprimir")){
          imprimirPessoas();
          break;
      }
  }

  return 0;
}

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

Pessoa lerDados(char *dados, Pessoa pessoa) {
  char nomeDigitado[256];
  int idadeDigitada;
  char sexoDigitado;

  fgets(dados, 256, stdin);
  dados[strcspn(dados, "\n")] = 0;
  sscanf(dados, "%[^,],%d,%c", nomeDigitado, &idadeDigitada, &sexoDigitado);

  strcpy(pessoa.nome, nomeDigitado);
  pessoa.idade = idadeDigitada;
  pessoa.sexo = sexoDigitado;

  return pessoa;
}

void create(int pessoaId, Pessoa pessoa, char *dados) {
  pessoa = lerDados(dados, pessoa);
  pessoas[pessoaId] = pessoa;
}

void delete(Pessoa pessoa) {
  for (int i = 0; i < TAMANHO_MAXIMO; i++){
    if (equals(pessoas[i].nome, pessoa.nome) && pessoas[i].idade == pessoa.idade && pessoas[i].sexo == pessoa.sexo) {
      strcpy(pessoas[i].nome, "NULL");
      pessoas[i].idade = IDADE_INEXISTENTE;
      pessoas[i].sexo = 'N';
    }
  }  
}

void imprimirPessoas() {
  for (int i = 0; i < TAMANHO_MAXIMO; i++){
      if(pessoas[i].idade > 0) {
          printf("%s,%i,%c\n", pessoas[i].nome, pessoas[i].idade, pessoas[i].sexo);
      }
  }
}