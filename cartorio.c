#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por registro
#include <string.h> //biblioteca responsavel por cuidar das string

int registro() //fun��o para cadastrar os usu�rios no sostema
{
	//inicio cria��o de vari�veis/string
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da cria��o de vari�veis/string
    printf("-Digite o cpf desejado para cadastrar: ");
    scanf("%s" , cpf); //%s refere-se a string
    
    strcpy(arquivo, cpf); //respons�vel por copiar os valores das string
    
    FILE *file; //cria o arquivo
    file = fopen(arquivo, "w"); //cria o arquivo
    fprintf(file,cpf); //salva o valor da variavel
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("-Digite o nome desejado para cadastrar:" );//coletando informa��o do usu�rio
    scanf("%s", nome);
    
    file = fopen(arquivo, "a"); //criando arquivo para cadastrar o nome do usu�rio
    fprintf(file,nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("-Digite o sobrenome desejado para cadastrar: ");
    scanf("%S",sobrenome);
    
    file = fopen(arquivo, "a"); ////criando arquivo para cadastrar o sobrenome do usu�rio
    fprintf(file,sobrenome);
	fclose(file);
	  
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("-Digite o cargo desejado para cadastrar: ");
    scanf("%s",cargo);
    
    file = fopen(arquivo, "a"); ////criando arquivo para cadastrar o cargo do usu�rio
    fprintf(file,cargo);
    fclose(file);
    
    system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cpf [40]; //colocando limite de n�meros para o cpf
	char conteudo[200];
	
	printf("-Digite o CPF para consultar: ");
	scanf("%s", cpf);
	
	FILE *file; //buscando o arquivo para consultar o cpf 
	file = fopen(cpf,"r");
	
	if(file == NULL)	
{
	printf("-Arquivo inexistente, n�o localizado!\n"); //quando o cpf for excluido ou n�o cadastrado
}

while(fgets(conteudo, 200, file) != NULL) //buscando pelos dados do usu�rio
{
	printf("\n-Essas s�o a informa��o do usu�rio: ");
	printf("%s", conteudo);
	printf("\n\n");
	
}

system("pause");

}

int deletar()
{
	char cpf[40]; //limite de n�meros do cpf
	
	printf("-Digite o CPF desejado para deletar: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file; //buscando o cpf para remover ele
	file = fopen(cpf,"r");
	
	if(file == NULL)
{
    printf("-Este usu�rio n�o existe!.\n"); //quando o cpf for excluido
    system("pause");
}

}

int main() //inicio do menu
{
	int opcao=0; //definindo as variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
{
	
	system("cls"); //"cls" � para limpar a tela
	
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem

	printf("\t*Cart�rio da EBAC*\t\n\n");
	printf("-Escolha a op��o desejada do menu:\n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n"); 
	printf("op��o: "); //fim do menu
	
	scanf("%d", &opcao); //armazenando a escolha do usuario 
	
	system("cls");
	
	switch(opcao) //todas as op��es do menu
{
	case 1:
	registro(); //chamando as fun��es
	break;
		
	case 2:
	consulta();
	break;
	    
	case 3:
	deletar();
	break;
	    
	default:
	printf("-Essa op��o n�o est� dispon�vel!\n"); //quando o usu�rio digitar uma op��o n�o existente no menu
	system("pause"); 
	break;
	    
}// fim da sele��o
	
}
  
  
  
}


