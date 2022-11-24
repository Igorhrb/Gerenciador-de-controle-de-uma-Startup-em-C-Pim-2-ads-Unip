#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>

#define ANSI_COLOR_RED      "\x1b[31m"	//cria a cor vermelha
#define ANSI_COLOR_RESET   "\x1b[0m"	//cria a cor pradrao

char nome[200][50]; //variaveis de cadastro de pessoas
char email[200][50];
char cpf[200][50];
char idade[200][50];
char cadastrado[200][50];
char registro[200][50];
char funcao[200][50];


char resposta; //op��o em char dos usuarios

int op,opp;//op��es que o usuario escolhe

int j,i; //contadores

int validar(char l1[30],char l2[30]){ //valida��o de login e senha
	
	char log[30] = "admin"; //Denifi��o de administrador: possiveis gestores da startup
	char sen[30] = "admin123"; //login e senha do administrador
	
	char fun[30] = "funcionario"; //Defini��o de funcionario: possiveis empregados com menores autoridades (exemplo: secretaria responsavel por cadastro no sistema)
	char sfun[30] = "funci123"; //login e senha do funcionario
	
		if((strcmp(log,l1) == 0) && (strcmp(sen,l2) ==0)){ //compara��o de parametro do usuario com o login administrador
			printf(ANSI_COLOR_RED"\n\t\tAdministrador do sistema Logado!\n"ANSI_COLOR_RESET);
			j=3;
			return menu(); //retorna menu de administrador e j=3
			}
			
		if((strcmp(fun,l1) == 0) && (strcmp(sfun,l2) ==0)){ //compara��o de parametro do funcionario com o login funcionario
			printf(ANSI_COLOR_RED"\n\t\tFuncionario Logado!\n"ANSI_COLOR_RESET);
			j=2;
			return menufun(); //retorna menu de funcionario e j=2
		}
		else {
			system("cls"); 
			printf(ANSI_COLOR_RED"\n\t\tSenha incorreta, tente novamente: \n"ANSI_COLOR_RESET); //caso a senha esteja incorreta, retorne para a fun��o main (tela de login)
			return main();
		}
	}
int main(void){ //fun��o de login		
	setlocale(LC_ALL, "Portuguese");
	
	printf("\n\n----------------------------------------------------------------------------------\n\t\t"); 
	printf("\n\t\tBEM VINDO AO SISTEMA DE GERENCIAMENTO DA FREE-UP\n\n");
	printf("----------------------------------------------------------------------------------\n\n\n\t\t");   
	printf("\n\t\tMenu de op��es\n\n\t\t1-Login\n\n\t\t2-Fechar o programa\n\t\t");
	printf("\n\t\tInsira a op��o: ");
	scanf("%s", &resposta);//captura a resposta do usuario
	system("cls");
	do{
		switch(resposta){
		case '1':	return inicio();//se a resposta for 1 entao passa para o menu de login

		case '2':	printf("\n\t\tSaindo do programa...\n\t\tObrigado por usar nosso software, at� a proxima!\n\n");
					system("pause"); //se a resposta for 2 entao ele finaliza o programa
					return 0;

		default:	printf(ANSI_COLOR_RED"\n\t\tOp��o errada, tente novamente"ANSI_COLOR_RESET);
					return main(); //se a reposta for diferente de 1 e 2 ele recarrega a fun��o (a mesma tela)
	}
}while(resposta!=1 && resposta!=2); //enquanto a resposta for diferente de  1 e 2 ele recarrega a pergunta
}
void inicio(){
	char login[30]; //variaveis para login e senha
	char senha[30];
	
	printf("----------------------------------------------------------------------------------\n\n\t\t");   
	printf("Tela de login\n\n----------------------------------------------------------------------------------\n\n\n");
	printf("\n\n\n\t\tInforme seu login: "); //captura o login
	scanf("%s", &login);
	printf("\t\tInforme sua senha: "); //captura a senha
	fflush(stdin);
	for (i = 0;i<8;i++) { //conta at� 8 digitos de senha e transforma em "*"
		senha[i] = getch();
		printf("*");
		}
	senha[i] = '\0';
    printf("\n");
	system("cls");
	return validar(login, senha); //manda os parametros de login e senha para a fun��o de validar
	}
void cadastro(){
	static int linha;
	char emprego1[20]= "seguran�a"; 
	char emprego2[20]= "secret�ria(o)";
	char emprego3[20]= "servi�os gerais"; //listas de variaveis com os cargos da empresa
	char emprego4[20]= "gerente";
	char emprego5[20]= "gerente de marketing";
	do{ //cadastro de pessoa
		system("cls");
		printf("----------------------------------------------------------------------------------\n\n\n\t\t");   
		printf("Tela de cadastro de pessoas\n\n\n----------------------------------------------------------------------------------\n\n\n");
		printf("\nDigite o nome completo: ");
		fflush (stdin); gets(nome[linha]); strlwr(nome[linha]); //capturar " " dos nomes
		printf("\nDigite o Email: ");
		scanf("%s", &email[linha]); //atribui o email para o campo email[i(linha)]
		printf("\nDigite o CPF: ");
		scanf("%s", &cpf[linha]); //atribui o cpf para o campo cpf[i(linha)]
		printf("\nDigite a idade: ");
		scanf("%s", &idade[linha]); //atribui o idade para o campo idade[i(linha)]
			do{	//se digitar um numero diferente de 1, 2, 3, 4 ou 5 entra no loop do while
				printf("\nDigite a op��o referente ao emprego \n1- Seguran�a\n2- Secret�ria(o)\n3- Servi�os Gerais\n4- Gerente\n5- Gerente de marketing\n");
				printf("\n\t\tInsira a op��o: ");
				fflush(stdin);
				scanf("%s", &resposta);	
			switch(resposta){ //captura a op��o que o usuario escolher e atribui a op��o para a variavel resposta
		
			case '1':	strcpy(funcao[linha],emprego1); //adiciona seguran�a no scanf
						break;
			case '2':	strcpy(funcao[linha],emprego2); //adiciona secretaria no scanf
						break;
			case '3':	strcpy(funcao[linha],emprego3); //adiciona servi�os gerais no scanf
						break;
			case '4':	strcpy(funcao[linha],emprego4); //adiciona gerente no scanf
						break;
			case '5':	strcpy(funcao[linha],emprego5); //adiciona gerente de marketing no scanf
						break;			
			default:	system("cls"); 
						printf("\nOp��o invalida, tente novamente!\n");
			}
	}while(resposta!='1' && resposta!='2' && resposta!='3' && resposta!='4'&& resposta!='5'); 
	
		strcpy(cadastrado[linha], "1"); //registro de cadastro, caso o cadastro seja feito, ele recebe 1
		system("cls"); //limpa a tela
		printf("\n----------------------------------------------------------------------------------\n\n\t\t");  
		printf("Cadastro realizado com sucesso!\n\n");
		printf("----------------------------------------------------------------------------------\n\n\t\t");   
		printf("Digite 1 para continuar, ou qualquer tecla para voltar para o menu: ");
		printf("\n\t\tInsira a op��o: ");
		scanf("%d", &op); //captura a op��o
		linha++; //variavel linha recebe +1
		}while(op==1); //enquanto o usuario inserir 1 ele pode adicionar mais uma pessoa
			if(op!=1){
				system("cls");
			if(j==2){
				printf(ANSI_COLOR_RED"Retornando para o menu de Funcionario... \n"ANSI_COLOR_RESET);	
				return menufun(); //se inserir qualquer numero ele retorna para o menu do funcionario caso ele esteja na conta de funcionario
			}else if(j==3){
				printf(ANSI_COLOR_RED"Retornando para o menu de Administrador... \n"ANSI_COLOR_RESET);
				return menu(); //caso ele nao esteja na conta de funcionario entao ele retorna para o menu de administrador
			}
			}
}
void menu(){
 	printf("----------------------------------------------------------------------------------\n\n\n\t\t");   
	printf("Menu do Administrador\n\n\n----------------------------------------------------------------------------------\n\n\n");
	printf("\t\t1-Cadastrar pessoa\n\t\t2-Pesquisar pessoa\n\t\t3-Exibir pessoa\n\t\t4-Editar pessoa\n\t\t5-Excluir\n\t\t6-Deslogar\n\t\t7-Inicio\n\t\t8-Relatorios\n");
	printf("\n\t\tInsira a op��o: ");
   	scanf("%s", &resposta);//captura a op��o do usuario
   	system("cls");
   	switch(resposta){
		
		case '1':	return cadastro(); //executa o menu de cadastro (a tela de cadastro de pessoas)				
		case '2':	return pesquisa(); //executa a fun��o pesquisa (o menu de pesquisa)		
		case '3':	return exibir(); //executa a fun��o de exibi��o de pessoas criadas				
		case '4':	return edicao(); //executa a fun��o de alterar algum dado de alguma pessoa cadastrada				
		case '5':	return excluir(); //executa a fun��o exclusiva do administrador de excluir e retorna para o menu de exclus�o		
  		case '6':	return inicio(); //executa a fun��o de mostrar o inicio, alem de deslogar do sistema
        case '7':	return main(); //executa a fun��o de deslogar do sistema
		case '8':	return relatorio(); //executa a fun��o de menu de relatorios
        default:	system("cls");
      				printf(ANSI_COLOR_RED"\nOp��o inv�lida, retornando para o menu... \n"ANSI_COLOR_RESET);	
        			return menu(); 	//retorna para a propria tela e informa que a op��o escolhida foi a incorreta
	}
}
void menufun(){
	printf("----------------------------------------------------------------------------------\n\n\n\t\t");   
	printf("Menu do Funcionario\n\n\n----------------------------------------------------------------------------------\n\n\n");
	printf("\t\t1-Cadastrar pessoa\n\t\t2-Pesquisar pessoa\n\t\t3-Exibir pessoa\n\t\t4-Editar pessoa\n\t\t5-Deslogar\n\t\t6-Inicio");
	printf("\n\t\tInsira a op��o: ");
	scanf("%s", &resposta);//recebe a op��o escolhida pelo funcionario
	system("cls");
	switch(resposta){//fun��o de menu do funcionario
		case '1':	return cadastro();//executa o menu de cadastro (a tela de cadastro de pessoas)
		case '2':	return pesquisa(); //executa a fun��o pesquisa (o menu de pesquisa)
		case '3':	return exibir(); //executa a fun��o de exibi��o de pessoas criadas	
		case '4':	return edicao(); //executa a fun��o de alterar algum dado de alguma pessoa cadastrada	    
        case '5':	return inicio(); //executa a fun��o de mostrar o inicio, alem de deslogar do sistema    
    	case '6':	return main();	//executa a fun��o de deslogar do sistema			    
  		default:	system("cls");
       				printf(ANSI_COLOR_RED"\nOp��o inv�lida, retornando para o menu... \n"ANSI_COLOR_RESET);
       				return menufun();	//retorna para a propria tela e informa que a op��o escolhida foi a incorreta
	}
}
void relatorio(){
int totalCa = 0;
int totalEx = 0;

	char criado[200] = "1"; //variavel de parametro para comparar com os cadastros criados
	char excluido[200] = "3"; //variavel de parametro para comparar com os cadastros excluidos
	
		for(i=0;i<200;i++){
		if(strcmp(cadastrado[i],criado)==0){ //se a compara��o der certo ("1"="1" retornar� 0
		totalCa++; //total cadastrado recebe +1
		
		}else if(strcmp(cadastrado[i],excluido)==0){ //se a compara��o der certo ("0"="0" retornar� 0
		totalEx++;//total excluido recebe +1
		
		}else{
			printf(ANSI_COLOR_RED"\nTotal de pessoas cadastradas no sistema durante a execu��o do programa: %d\n"ANSI_COLOR_RESET,totalCa); 
			//imprime na tela usando totalCa de parametro para exibir o total de pessoas cadastradas em numero
			printf(ANSI_COLOR_RED"\nTotal de pessoas deletadas do sistema durante a execu��o do programa: %d\n"ANSI_COLOR_RESET,totalEx); 
			//imprime na tela usando totalCa de parametro para exibir o total de pessoas cadastradas em numero
			printf("\n\nRetornando para o menu principal...\n\n"); 
			//depois de mostrar quantas pessoas estao no sistema (cadastradas ou excluidas), ele retorna para o menu de administrador
			return menu();
		}
	
	}

}
void pesquisa(){ //fun��o de pesquisar
	int idadePesquisa; 
	char emailPesquisa[50];
	char cpfPesquisa[50]; //variaveis de guardar o parametro para compara��o das variaveis ja existentes na tela de cadastro
	char nomePesquisa[50];
	char funcaoPesquisa[50];
	
		printf("----------------------------------------------------------------------------------\n\n\n\t\t");   
		printf("Menu de Pesquisa de pessoas cadastradas\n\n\n----------------------------------------------------------------------------------\n\n\n");
		printf("\n 1- Para pesquisar por email\n 2- Para pesquisar por CPF\n 3- Menu \n");
		printf("\n\t\tInsira a op��o: ");
		scanf("%s", &resposta);
			switch(resposta){// se a resposta for 1, entao abre o case 1
		case '1':	system("cls");
					printf("\nDigite E-mail: "); 
					scanf("%s", &emailPesquisa); 
					for(i=0;i<200;i++){	//o email que o usuario inserir � comparado com os 200 espa�os para email no sistema
						if(strcmp(email[i],emailPesquisa) == 0){ //caso exista um email igual ao inserido pelo usuario, sera impresso na tela a pessoa com o email igual ao inserido
						printf("\nNome: %s\nEmail: %s\nCPF: %s\nIdade: %s \nFun��o: %s\n\n", nome[i], email[i], cpf[i], idade[i],funcao[i]);
						return pesquisa(); //e depois de imprimir na tela a busca, ele retorna para o menu de pesquisam e tem a op��o de escolher de novo
						}else{
						printf(ANSI_COLOR_RED"\n\n***************N�o encontrado no sistema***************\n\n"ANSI_COLOR_RESET);
						return pesquisa(); //caso n�o encontre nada igual, ele retorna para o menu de pesquisa
						}
					}
				
			case '2':	system("cls");
						printf("\nDigite o CPF: ");
						scanf("%s", &cpfPesquisa);
						for(i=0;i<200;i++){ //o cpf que o usuario inserir � comparado com os 200 espa�os para cpf no sistema
							if(strcmp(cpf[i],cpfPesquisa) == 0){ //caso exista um cpf igual ao inserido pelo usuario, sera impresso na tela a pessoa com o cpf igual ao inserido
							printf("\nNome: %s\nEmail: %s\nCPF: %s\nIdade: %s \nFun��o: %s\n\n", nome[i], email[i], cpf[i], idade[i],funcao[i]); 
							return pesquisa(); //e depois de imprimir na tela a busca, ele retorna para o menu de pesquisam e tem a op��o de escolher de novo
							}else{
							system("cls");
							printf(ANSI_COLOR_RED"\n\n***************N�o encontrado no sistema***************\n\n"ANSI_COLOR_RESET);
							return pesquisa();	//caso n�o encontre nada igual, ele retorna para o menu de pesquisa
						}
						}
			
					case '3':	if(j==2){ //caso j estiver valendo 2, retornar� para o menu de funcionario
									system("cls");
									printf(ANSI_COLOR_RED"Retornando para o menu de Funcionario... \n"ANSI_COLOR_RESET);
									return menufun();
								}else if(j==3){ //caso j estiver valendo 3, retornar� para o menu de administrador
									system("cls");
									printf(ANSI_COLOR_RED"Retornando para o menu de Administrador... \n"ANSI_COLOR_RESET);
									return menu();
								}
					default:	system("cls"); 
								printf(ANSI_COLOR_RED"\nOp��o inv�lida, retornando para o menu de pesquisa... \n"ANSI_COLOR_RESET);
								return pesquisa();	//caso inserir algo diferente cair� de novo no menu de pesquisa
			}
}
void exibir(){
	printf("----------------------------------------------------------------------------------\n\n\n\t\t");   
	printf("Exibindo todas as pessoas cadastradas no sistema\n\n\n----------------------------------------------------------------------------------\n\n\n");
	char cadastrocmp[200] = "1"; //variavel para comparar
		for(i=0;i<200;i++){
			if(strcmp(cadastrado[i],cadastrocmp)==0){ //compara se o cadastro esta valendo 1 (que significa cadastrado)
				printf(	"Nome: %s\nEmail: %s\nCPF: %s\nIdade: %s \nFun��o: %s\n\n\n----------------------------------------------------------------------------------\n\n\n", nome[i], email[i], cpf[i], idade[i],funcao[i]);
			} //caso encontre algum cadastro que tenha valor 1, printa na tela a pessoa com todos os seus dados
		}
		printf("----------------------------------------------------------------------------------\n\n\n\t\t"); 
		printf("Insira qualquer n�mero para voltar para o menu principal ");
		printf("\n\t\tInsira a op��o: ");
		scanf("%d", &opp);
		if(opp!=""){ //se for inserido no scanf qualquer valor, a tela ser� limpa e retornar� o seu menu correspondente � conta logada
			system("cls");
			if(j==2){
				printf(ANSI_COLOR_RED"Retornando para o menu de Funcionario... \n"ANSI_COLOR_RESET);
				return menufun();
			}else if(j==3){
				printf(ANSI_COLOR_RED"Retornando para o menu de Administrador... \n"ANSI_COLOR_RESET);	
				return menu();
			}
			}
}
void edicao(){
	//variaveis do tipo char para armazenar a altera��o do nome, email,cpf,idade ou cargo na empresa
	char nomeEditar[200][50]; 
	char emailEditar[200][50];
	char cpfEditar[200][50];
	char idadeEditar[200][50];
	char funcaoEditar[200][50];
	
	//listas de variaveis com os cargos da empresa
	char emprego1[20]= "seguran�a";
	char emprego2[20]= "secret�ria(o)";
	char emprego3[20]= "servi�os gerais";
	char emprego4[20]= "gerente";
	char emprego5[20]= "gerente de marketing";
	
	 
	printf("----------------------------------------------------------------------------------\n\n\n\t\t");
	printf("Menu de Edi��o\n\n\n----------------------------------------------------------------------------------\n\n\n");
	printf("\n\t\tO que deseja alterar\n\t\t1- Nome\n\t\t2- E-mail\n\t\t3- CPF\n\t\t4- Idade\n\t\t5- Fun��o na empresa\n\t\t6- Menu\n ");
	printf("\n\t\tInsira a op��o: ");
	scanf("%s", &resposta);
	do{ //enquanto a resposta for diferente de 1, 2, 3, 4, 5 ou 6 a fun��o menu de edi��o ser� chamada novamente
	switch(resposta){
		case '1':	printf("\nDigite o CPF da pessoa que deseja alterar\n"); //caso a resposta for 1 pedir� um cpf para ser comparado com um cpf ja existente
					printf("\nInsira o CPF:");
					scanf("%s", &cpfEditar);//recebe a infroma��o e atribui para variavel cpfEditar
					system("cls");
					for(i=0;i<200;i++){ //o cpf que o usu�rio inserir � comparado com os 200 espa�os para cpf no sistema
						if(strcmp(cpf[i],cpfEditar) == 0){ //se encontrar um cpf igual, ser� printado a pessoa referente a posi��o do cpf comparado
							system("cls");
							printf("\nNome: %s\nEmail: %s\nCPF: %s\nIdade: %s \nFun��o: %s\n", nome[i], email[i], cpf[i], idade[i], funcao[i]);
							printf("----------------------------------------------------------------------------------\n\t\t");   
							printf("\nQual o nome para alterar: ");
							scanf("%s", nome[i]); //ap�s ter validado os dados, o nome inserido vai substituir o nome que foi informado anteriormente
							system("cls");
							printf("\nA altera��o ficou: \nNome: %s\nEmail: %s\nCPF: %s\nIdade: %s \nFun��o: %s \n", nome[i], email[i], cpf[i], idade[i], funcao[i]);
							return edicao(); //printa a pessoa com os dados dela e retorna para o menu de edi��o
						}else{
							printf(ANSI_COLOR_RED"\n\n***************N�o encontrado no sistema***************\n\n"ANSI_COLOR_RESET);
							return edicao(); //caso as compara��es n�o encontrem nada no sistema a tela de edi��o ser� retornada na tela 
						}
					}
	
			case '2':	printf("\nDigite o CPF da pessoa que deseja alterar\n");
						printf("\nInsira o CPF:");
						scanf("%s", &cpfEditar);
						system("cls");
						for(i=0;i<200;i++){//o cpf que o usu�rio inserir � comparado com os 200 espa�os para cpf no sistema
							if(strcmp(cpf[i],cpfEditar) == 0){
								printf("\nNome: %s\nEmail: %s\nCPF: %s\nIdade: %s \nFun��o: %s\n", nome[i], email[i], cpf[i], idade[i], funcao[i]);
								printf("----------------------------------------------------------------------------------\n\t\t");   
								printf("\nQual o email para alterar: ");
								scanf("%s", email[i]);//ap�s ter validado os dados, o email inserido vai substituir o email que foi informado anteriormente
								system("cls");
								printf("\nA altera��o ficou: \nNome: %s\nEmail: %s\nCPF: %s\nIdade: %s \nFun��o: %s \n", nome[i], email[i], cpf[i], idade[i], funcao[i]);
								return edicao(); //apos alterar, retorna para o menu de edi��o
							}else{
								printf(ANSI_COLOR_RED"\n\n***************N�o encontrado no sistema***************\n\n"ANSI_COLOR_RESET);
								return edicao();//caso as compara��es n�o encontrem nada no sistema a tela de edi��o ser� retornada na tela
						}
						}
		
		case '3':	printf("digite o CPF da pessoa que deseja alterar\n");
					printf("\nInsira o CPF:");
					scanf("%s", cpfEditar);
					system("cls");
					for(i=0;i<200;i++){//o cpf que o usu�rio inserir � comparado com os 200 espa�os para cpf no sistema
					if(strcmp(cpf[i],cpfEditar) == 0){//o cpf que o usu�rio inserir � comparado com os 200 espa�os para cpf no sistema
						printf("\nNome: %s\nEmail: %s\nCPF: %s\nIdade: %s \nFun��o: %s\n", nome[i], email[i], cpf[i], idade[i], funcao[i]);
						printf("----------------------------------------------------------------------------------\n\t\t"); 		
						printf("\nQual o email para alterar: ");
						scanf("%s", cpf[i]); //ap�s ter validado os dados, o cpf inserido vai substituir o cpf que foi informado anteriormente
						system("cls");
						printf("\nA altera��o ficou: \nNome: %s\nEmail: %s\nCPF: %s\nIdade: %s \nFun��o: %s \n", nome[i], email[i], cpf[i], idade[i], funcao[i]);
						return edicao(); //ap�s alterar, retorna para o menu de edi��o
					}else{
						printf(ANSI_COLOR_RED"\n\n***************N�o encontrado no sistema***************\n\n"ANSI_COLOR_RESET);
						return edicao();//caso as compara��es n�o encontrem nada no sistema a tela de edi��o ser� retornada na tela
					}
					}
		case '4':	printf("\nDigite o CPF da pessoa que deseja alterar\n");
					printf("\nInsira o CPF:");
					scanf("%s", &cpfEditar);
					system("cls");
					for(i=0;i<200;i++){//o cpf que o usu�rio inserir � comparado com os 200 espa�os para cpf no sistema
					if(strcmp(cpf[i],cpfEditar) == 0){ //fun��o de comparar cpf
						printf("\nNome: %s\nEmail: %s\nCPF: %s\nIdade: %s \n", nome[i], email[i], cpf[i], idade[i]);
						printf("----------------------------------------------------------------------------------\n\t\t");   
						printf("\nQual a idade para alterar: ");
						scanf("%s", idade[i]); //transforma o que o usuario inserir para idade da pessoa cadastrada
						system("cls");
						printf("\nA altera��o ficou: \nNome: %s\nEmail: %s\nCPF: %s\nIdade: %s \nFun��o: %s \n", nome[i], email[i], cpf[i], idade[i], funcao[i]);
						return edicao();//caso as compara��es n�o encontrem nada no sistema a tela de edi��o ser� retornada na tela
					}else{
						printf(ANSI_COLOR_RED"\n\n***************N�o encontrado no sistema***************\n\n"ANSI_COLOR_RESET);
						return edicao();//caso as compara��es n�o encontrem nada no sistema a tela de edi��o ser� retornada na tela
					}
					}
		case '5':	printf("\nDigite o CPF da pessoa que deseja alterar\n");
					printf("\nInsira o CPF:");
					scanf("%s", &cpfEditar);
					system("cls");
					for(i=0;i<200;i++){//o cpf que o usu�rio inserir � comparado com os 200 espa�os para cpf no sistema
						if(strcmp(cpf[i],cpfEditar) == 0){ //fun��o de comparar cpf
							printf("\nNome: %s\nEmail: %s\nCPF: %s\nIdade: %s \nFun��o: %s \n", nome[i], email[i], cpf[i], idade[i], funcao[i]);
							printf("----------------------------------------------------------------------------------\n\t\t"); 
					do{
						printf("\nDigite a op��o referente ao emprego \n1- Seguran�a\n2- Secret�ria(o)\n3- Servi�os Gerais\n4- Gerente\n5- Gerente de marketing\n");
						printf("\nInsira a op��o: ");
						fflush(stdin);
						scanf("%s", &resposta);	 //recebe a resposta do usuario e se aplica em algum dos case e caso nao for igual as op�oes, cair� dentro do default
						switch(resposta){
						case '1':	strcpy(funcao[i],emprego1); //fun��o de inserir emprego 1 para a string de funcao(cargo na empresa)
									break;
						case '2':	strcpy(funcao[i],emprego2); //fun��o de inserir emprego 2 para a string de funcao(cargo na empresa)
									break;
						case '3':	strcpy(funcao[i],emprego3); //fun��o de inserir emprego 3 para a string de funcao(cargo na empresa)
									break;
						case '4':	strcpy(funcao[i],emprego4); //fun��o de inserir emprego 4 para a string de funcao(cargo na empresa)
									break;
						case '5':	strcpy(funcao[i],emprego5); //fun��o de inserir emprego 5 para a string de funcao(cargo na empresa)
									break;
						default:	system("cls"); //caso a op��o inserida nao exista ele retornar� a perguntar
									printf("\nOp��o invalida, tente novamente!\n");
					}
					}while(resposta!='1' && resposta!='2' && resposta!='3' && resposta!='4'&& resposta!='5');
						system("cls");
						printf("\nA altera��o ficou \nNome: %s\nEmail: %s\nCPF: %s\nIdade: %s \nFun��o: %s \n", nome[i], email[i], cpf[i], idade[i], funcao[i]);
						return edicao();//depois da altera��o ser concluida, ela aparecer� na tela e retornar� para o menu de fun��o de editar
					}else{
						printf(ANSI_COLOR_RED"\n\n***************N�o encontrado no sistema***************\n\n"ANSI_COLOR_RESET);
						return edicao();//caso as compara��es n�o encontrem nada no sistema a tela de edi��o ser� retornada na tela
					}
					}
		case '6':	if(j==2){ //fun��o de reotrnar ao menu
						system("cls");
						printf(ANSI_COLOR_RED"Retornando para o menu de Funcionario... \n"ANSI_COLOR_RESET);
						return menufun();//caso j for igual a 2 ele retorna para o menu de funcionario
					}else if(j==3){
						system("cls");
						printf(ANSI_COLOR_RED"Retornando para o menu de Administrador... \n"ANSI_COLOR_RESET);
						return menu();//caso j for igual a 3 ele retorna para o menu de administrador
					}
	
		default:	system("cls");
					printf(ANSI_COLOR_RED"\nOp��o invalida, digite novamente \n"ANSI_COLOR_RESET);
					return edicao();//caso as compara��es n�o encontrem nada no sistema a tela de edi��o ser� retornada na tela
		}
	}while(resposta!='1' && resposta!='2' && resposta!='3' && resposta!='4'&& resposta!='5' && resposta!='6');
	}
void excluir(){ //fun��o de excluir
	char emailExcluido[200][50];
	char nomeExcluido[200][50];
	char cpfExcluido[200][50];
	
	printf("----------------------------------------------------------------------------------\n\n\n\t\t");   
	printf("Menu de Exclus�o\n\n\n----------------------------------------------------------------------------------\n\n\n");
	printf("1- Exclus�o por E-mail\n2- Exclus�o por nome\n3- Exclus�o por CPF\n4- Menu\n");
	printf("\nInserir op��o: ");
	scanf("%s", &resposta); //atribui a op��o que o usuario ecolher para a variavel resposta
	printf("\n");
	switch(resposta){ 
		case '1':	system("cls"); //op��o de exclus�o por email
					printf("\t\tE-mail da pessoa que ser� excluida: ");
					printf("\n\t\tInsira o e-mail: "); 
					scanf("%s", &emailExcluido); //atribui o email digitado para o campo emailExcluido
					for(i=0;i<200;i++){ //o email que o usuario inserir � comparado com os 200 espa�os para email no sistema
						if(strcmp(email[i],emailExcluido[i]) == 0){ //caso exista um email igual ao inserido pelo usuario, sera impresso na tela os dados da pessoa com o email igual ao inserido
							printf("\nNome: %s\nEmail: %s\nCPF: %s\nIdade: %s \nFun��o: %s", nome[i], email[i], cpf[i], idade[i],funcao[i]);
							printf("\n\nQuer excluir essa pessoa\n1- Sim \n2- N�o\n");
							scanf("%d", &opp); //captura a op��o escolhida "sim" ou "n�o"
							if(opp==1){ //caso a escolha seja "sim"
								strcpy(cadastrado[i], "3");
								system("cls");
								printf("\nExcluido com sucesso!\nRetornando para o menu de exclus�o\n");
								return excluir(); //retorna ao menu de exclus�o ap�s ter excluido a pessoa com sucesso
							}else{ //caso a escolha seja "n�o"
								system("cls");
								printf("\nExclus�o cancelada, retornando para o menu...\n\n");
								return excluir(); //retorna ao menu de exclus�o ap�s o cancelamento da exclus�o
							}
						}else{ //caso n�o encontre o email
							printf(ANSI_COLOR_RED"\n\n***************N�o encontrado no sistema***************\n\n"ANSI_COLOR_RESET);
							return excluir();//retorna ao menu de exclus�o ap�s n�o ter encontrado o email
						}
					}
		
		
		case '2': 	system("cls"); //op��o de exclus�o por nome
					printf("\t\tNome e sobrenome da pessoa que ser� excluida");
					printf("\n\t\tInsira o nome e sobrenome: ");
					scanf("%s", &nomeExcluido);	//atribui o nome digitado para o campo nomeExcluido
					for(i=0;i<200;i++){ //o nome que o usuario inserir � comparado com os 200 espa�os para nome no sistema
							if(strcmp(nome[i],nomeExcluido[i]) == 0){ //caso exista um nome igual ao inserido pelo usuario, sera impresso na tela os dados da pessoa com o nome igual ao inserido
								printf("\nNome: %s\nEmail: %s\nCPF: %s\nIdade: %s \nFun��o: %s", nome[i], email[i], cpf[i], idade[i],funcao[i]);
								printf("\n\nQuer excluir essa pessoa\n1- Sim \n2- N�o\n");
								scanf("%d", &opp); //captura a op��o escolhida "sim" ou "n�o"
								if(opp==1){ //caso a escolha seja "sim"
									printf("\nExcluindo essa pessoa...\n");
									strcpy(cadastrado[i], "3");
									system("cls");
									printf("\nExcluido com sucesso!\nRetornando para o menu de exclus�o\n");
									return excluir(); //retorna ao menu de exclus�o ap�s ter excluido a pessoa com sucesso
								}else{ //caso a escolha seja "n�o"
								system("cls");
								printf("\nExclus�o cancelada\nRetornando para o menu de exclus�o...\n");
								return excluir(); //retorna ao menu de exclus�o ap�s o cancelamento da exclus�o
								}
							}else{ //caso n�o encontre o nome
								printf(ANSI_COLOR_RED"\n\n***************N�o encontrado no sistema***************\n\n"ANSI_COLOR_RESET);
								return excluir(); //retorna ao menu de exclus�o ap�s n�o ter encontrado o nome
							}
					}
		
		case '3':	system("cls"); //op��o de exclus�o por cpf
					system("cls");	
					printf("\t\tCPF da pessoa que ser� excluida: ");
					printf("\n\t\tInsira CPF: ");
					scanf("%s", &cpfExcluido); //atribui o cpf digitado para o campo cpfExcluido
					for(i=0;i<200;i++){ //o cpf que o usuario inserir � comparado com os 200 espa�os para cpf no sistema
						if(strcmp(cpf[i],cpfExcluido[i]) == 0){ //caso exista um cpf igual ao inserido pelo usuario, sera impresso na tela os dados da pessoa com o cpf igual ao inserido
							printf("\nNome: %s\nEmail: %s\nCPF: %s\nIdade: %s \nFun��o: %s", nome[i], email[i], cpf[i], idade[i],funcao[i]);
							printf("\n\nQuer excluir essa pessoa\n1- Sim \n2- N�o\n");
							scanf("%d", &opp); //captura a op��o escolhida "sim" ou "n�o"
							if(opp==1){ //caso a escolha seja "sim", o cadastro da pessoa passa a valer 3 e some do sistema
								printf("\nExcluindo essa pessoa...\n");
								strcpy(cadastrado[i], "3");
								system("cls");
								printf("\nExcluido com sucesso!\nRetornando para o menu de exclus�o\n");
								return excluir();	
							}else{ //caso a escolha seja "n�o"
								system("cls"); 
								printf("\nExclus�o cancelada\nRetornando para o menu de exclus�o...\n");
								return excluir(); //retorna ao menu de exclus�o ap�s o cancelamento da exclus�o
							}
						}else{ //caso n�o encontre o cpf
							printf(ANSI_COLOR_RED"\n\n***************N�o encontrado no sistema***************\n\n"ANSI_COLOR_RESET);
							return excluir(); //retorna ao menu de exclus�o ap�s n�o ter encontrado o cpf
						}
				}
				
		case '4':	system("cls"); //op��o de limpar a tela e retornar menu do administrador
                  	return menu();
                  
		default:	system("cls"); //caso seja escolhida uma op��o diferente das permitidas, limpa a tela e informa que foi invalida a op��o
                 	printf("Opcao invalida, digite novamente \n");
                	 return excluir(); //retorna o mesmo menu apos printar na tela a op��o invalida
		}
}
