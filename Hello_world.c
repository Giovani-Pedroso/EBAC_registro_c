/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : First steps
 ******************************************************************************
 */
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  setlocale(LC_ALL, "Portuguese");
  printf("### Cartorio da EBAC ### \n\n");
  printf("Escolha a opção desejada \n\n");
  printf("\t 1 - Registrar nome \n");
  printf("\t 2 - Consultar nome \n");
  printf("\t 3 - Deletar nome \n");

  printf("\n\nSoftware open source");
  return 0;
}
