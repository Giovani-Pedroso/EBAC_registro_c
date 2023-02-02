/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : First steps
 ******************************************************************************
 */
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function's declaration
int registarNome();
int consultarNome();
int deletarNome();
int errorMessage();
void linuxPause();

int main() {
  setlocale(LC_ALL, "Portuguese");

  char answer[5];

  // super loop
  while (1) {

    // This does not works on linux
    // system("cls");
    system("clear");

    printf("### Cartorio da EBAC ### \n\n");
    printf("Escolha a opção desejada \n\n");
    printf("\t 1 - Registrar nome \n");
    printf("\t 2 - Consultar nome \n");
    printf("\t 3 - Deletar nome \n");
    printf("\t 0 - Fechar o programa \n");

    scanf("%s", answer);
    // To avoid the buffer overfollow
    char ans = getchar();

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
    /* printf("\n\nSoftware open source\n"); */
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

  strcpy(arquivo, cpf);

  // Create a file with the same name that the cpf
  // in the folder data you must create the folder
  FILE *file;
  // create the file ./data/[cpf].csv
  char path[100];
  // You need to create the folder "data" in your system
  strcat(path, "./data/");
  strcat(path, cpf);
  strcat(path, ".csv");

  file = fopen(path, "w");

  // Print the cpf in the file

  strcat(cpf, ",");
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
  fprintf(file, strcat(cargo, ","));
  fclose(file);

  linuxPause();

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
  char path[40];
  strcat(path, "./data/");
  strcat(path, cpf);
  strcat(path, ".csv");

  file = fopen(path, "r");

  if (file == NULL) {
    printf("CPF não encontrado");
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
  printf("Você escolheu deletar um nome");

  // Does not works on linux
  /* system("pause"); */
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
