/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : First steps
 ******************************************************************************
 */
#include <dirent.h>
#include <errno.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#define SEPARATOR "\\"
#define CLEAR "cls"
#endif

#ifdef _WIN64
#define SEPARATOR "\\"
#define CLEAR "cls"
#endif

#ifdef __APPLE__
#define SEPARATOR "/"
#define CLEAR "clear"
#endif

#ifdef __linux__
#define SEPARATOR "/"
#define CLEAR "clear"
#endif

// Function's declaration
int registarNome();
int consultarNome();
int deletarNome();
int errorMessage();
void linuxPause();
char *getPath(char *cpf);

int main() {
  setlocale(LC_ALL, "Portuguese");
  system(CLEAR);

  char answer[5];
  char password[20] = "";
  /*
  printf("### Cartorio da EBAC ### \n\n");
  printf("\nDigite a senha para assesar o banco de dados: ");
  scanf("%s", password);
  char x = getchar();

  // Verify if the user has the password
  // to access the database, if not
  // the program will close itself
  if (strcmp(password, "admin")) {
    printf("\nSenha incorreta\n");
    linuxPause();
    return 0;
  }
  */

  // super loop
  while (1) {

    system(CLEAR);

    // Menu
    printf("### Cartorio da EBAC ### \n\n");
    printf("Escolha a opção desejada \n\n");
    printf("\t 1 - Registrar nome \n");
    printf("\t 2 - Consultar nome \n");
    printf("\t 3 - Deletar nome \n");
    printf("\n\t 0 - Fechar o programa \n");

    printf("\nOpção: ");
    scanf("%s", answer);
    // To avoid the buffer overfollow
    char ans = getchar();

    // Select the option
    switch (answer[0]) {
    case '1':
      registarNome();
      break;
    case '2':
      consultarNome();
      break;
    case '3':
      deletarNome();
      break;
    case '0':
      return 0;
    default:
      errorMessage();
    }
  }
  return 0;
}

// Generic function to pause the execution of the program
// the system("pause") wasn't working on the linux
void linuxPause() {
  printf("\n\nPressonie ENTER para continuar...");
  int c = getchar();
}

int registarNome() {
  // student information
  // TODO convert to a struc
  char cpf[40]; // It will be the primary key
  char nome[40];
  char sobrenome[40];
  char cargo[40];

  char arquivo[40];

  printf("Digite o CPF: ");
  scanf("%s", cpf);
  // To avoid the buffer overfollow
  char c = getchar();

  // Checks withe the data directory exits
  DIR *dir = opendir("data");
  // If not creates the directory
  if (ENOENT == errno) {
    // Ignore the warning message
    mkdir("data");
  }

  // Create a file with the same name that the cpf
  // in the folder data you must create the folder
  FILE *file;

  // create the file ./data/[cpf].csv
  // You need to create the folder "data" in your system
  char path[100] = "";
  strcat(path, ".");
  strcat(path, SEPARATOR);
  strcat(path, "data");
  strcat(path, SEPARATOR);
  strcat(path, cpf);
  strcat(path, ".csv");
  file = fopen(path, "w");

  // Add a ","
  strcat(cpf, ",");
  // Print the cpf in the file
  fprintf(file, cpf);

  /* // pirnt the name in the file */
  printf("Digite o nome: ");
  scanf("%s", nome);
  c = getchar();

  fprintf(file, strcat(nome, ","));

  /* // pirnt the sobrenome in the file */
  printf("Digite o sobrenome: ");
  scanf("%s", sobrenome);
  c = getchar();
  fprintf(file, strcat(sobrenome, ","));

  /* // pirnt the sobrenome in the file */
  printf("Digite o cargo: ");
  scanf("%s", cargo);
  c = getchar();
  fprintf(file, cargo);
  fclose(file);

	//Ask for the user if them want to add another person
  printf("\n\nDeseja inserir outro nome [s/n] ?: ");
  char resposta[10]="";
  scanf("%s", resposta);
  char y = getchar();
  if(resposta[0] == 's' || resposta[0] == 'S') registarNome();
  else if (resposta[0] == 'n' || resposta[0] == 'N') return 0;
  else{
    printf("Resposta invalida, retornando ao menu");
    linuxPause();
    return 0;
  }
  //linuxPause();

  return 0;
}

int consultarNome() {
  setlocale(LC_ALL, "Portuguese");

  char cpf[40];
  char conteudo[240];

  printf("\n\nDigite o CPF a ser cosultado: ");
  scanf("%s", cpf);
  char c = getchar();

  FILE *file;
  char path[40] = "";

  strcat(path, ".");
  strcat(path, SEPARATOR);
  strcat(path, "data");
  strcat(path, SEPARATOR);
  strcat(path, cpf);
  strcat(path, ".csv");

  file = fopen(path, "r");

  if (file == NULL) {
    printf("\nCPF não encontrado");
    linuxPause();
    return 0;
  }

  while (fgets(conteudo, 240, file) != NULL) {
    printf("\nEssas são as informações do usuario: ");
    printf("%s\n\n", conteudo);
    printf("");
  }

  fclose(file);
  linuxPause();
  return 0;
}

int deletarNome() {
  char cpf[40] = "";
  printf("\n\nDigite o CPF a ser deletado: ");
  scanf("%s", cpf);
  char c = getchar();

  FILE *file;
  char path[40] = "";
  strcat(path, ".");
  strcat(path, SEPARATOR);
  strcat(path, "data");
  strcat(path, SEPARATOR);
  strcat(path, cpf);
  strcat(path, ".csv");

  file = fopen(path, "r");

  if (file == NULL) {
    printf("\nO arquivo não se encontar no sistema");
  } else {
    fclose(file);
    printf("\nO usuario foi deletado");
    remove(path);
  }

  linuxPause();
  return 0;
}

int errorMessage() {
  printf("Opção invalida");
  // Does not works on linux
  /* system("pause"); */
  linuxPause();
  return 0;
}
