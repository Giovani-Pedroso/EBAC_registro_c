/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : First steps
 ******************************************************************************
 */
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

int registarNome();
int consultarNome();
int deletarNome();
int errorMessage();

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
  /* printf("Digite um nome para registar: "); */
  printf("Você escolheu registar um nome");
  /* char nome[30]; */
  /* scanf("%s", nome); */
  // To avoid the buffer overfollow
  /* char c = getchar(); */
  // Does not works on linux
  /* system("pause"); */
  linuxPause();

  return 0;
}

int consultarNome() {
  printf("Você escolheu consultar os nomes");

  // Does not works on linux
  /* system("pause"); */
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
