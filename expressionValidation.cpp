#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "signature.h"
#include "functions.h"

int main(){
	char ex[30];
	
	printf ("\n Digite uma expressao: ");
	gets (ex);
	
	if (verifica_expressao(ex)) printf ("Expressao valida ! \n");
	else  printf ("Expressao invalida !\n");
	
	system("pause");
	return 0;
}
