#include <stdio.h>

char usuario[] = "Ricardo";
int agencia = 123;
int conta = 1234;
int senha = 12345;
double saldo = 5000.00;


void main(){
	printf("\nBem-vindo, %s!", usuario);
	printf("\nO que você deseja fazer agora? \n1 - Ver saldo\n2 - Sacar\n3 - Depositar\n4 - Sair");
}
