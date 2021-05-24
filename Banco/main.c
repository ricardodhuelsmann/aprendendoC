#include <stdio.h>
#include <stdlib.h>

char usuario[] = "Ricardo";
int agencia = 123;
int conta = 1234;
int senha = 12345;
double saldo = 5000.00;

void verSaldo(){
	printf("\nSeu saldo e de: R$%.2f\n", saldo); //O termo saldo é arredondado para duas casas decimais com uso de "%.2f"
	entrarConta();
}

void sacar(){
	printf("\nQuanto voce deseja sacar?\n");
	float saque;
	scanf("%f", &saque);
	if (saque>0 && saldo>=saque){
		saldo = saldo - saque;
		entrarConta();
	}
	else{
		printf("\nOperacao nao realizada, tente novamente com um valor valido\n");
		sacar();
	}
}

void depositar(){
	printf("\nQuanto voce deseja depositar?\n");
	float deposito;
	scanf("%f", &deposito);
	if (deposito>0){
		saldo = saldo + deposito;
		entrarConta();
	}
	else{
		printf("\nOperacao nao realizada, tente novamente com um valor valido\n");
		depositar();
	}
}

void entrarConta(){
	printf("\nO que voce deseja fazer agora? \n1 - Ver saldo\n2 - Sacar\n3 - Depositar\n4 - Sair\n");
	int resposta;
	scanf("%d", &resposta);
	if (resposta == 1){
		verSaldo();
	}
	else if (resposta == 2){
		sacar();
	}
	else if (resposta == 3){
		depositar();
	}
	else if (resposta == 4){
		printf("\n\nObrigado por usar nosso programa\n\n");
		iniciaCaixa();
	}
	else{
		printf("\n\nDigite uma opcao valida\n\n");
		entrarConta();
	}
}

void testaLogin(){
	printf("\nDigite sua agencia: ");
	int agenciaRecebida;
	scanf("%d", &agenciaRecebida);
	if (agenciaRecebida == agencia) {
		printf("\nDigite sua conta: ");
		int contaRecebida;
		scanf("%d", &contaRecebida);
		if (contaRecebida == conta){
			printf("\nDigite sua senha: ");
			int senhaRecebida;
			scanf("%d", &senhaRecebida);
			if (senhaRecebida == senha){
				printf("\nBem-vindo, %s!", usuario);
				entrarConta();
									
			}
			else {
				printf("\nSenha incorreta, vamos recomecar...\n");
				testaLogin();
				}
		}
		else {
			printf("\nConta nao encontrada, vamos recomecar...\n");
			testaLogin();
			}
	}
	else {
		printf("\nAgencia nao encontrada, vamos recomecar...\n");
		testaLogin();
	}
}

void iniciaCaixa(){
	printf("Bem-vido! \nDeseja entrar? S ou N\n");
	char resposta;
	scanf("%s", &resposta); 
	if (resposta == 'S' || resposta == 's') {
		testaLogin();
	}
	else if (resposta == 'N' || resposta == 'n'){
		exit(1);
	}
	else  {
		printf("\n\n");
		iniciaCaixa();
	}
}

void main(){
	iniciaCaixa();
}
