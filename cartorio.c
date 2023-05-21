#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de memória
#include <locale.h> //biblioteca de alocações de texto por registro
#include <string.h> //biblioteca responsavel por cuidar das string

int registro() //função para cadastrar os usuários no sostema
{
	//inicio criação de variáveis/string
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da criação de variáveis/string
    printf("-Digite o cpf desejado para cadastrar: ");
    scanf("%s" , cpf); //%s refere-se a string
    
    strcpy(arquivo, cpf); //responsável por copiar os valores das string
    
    FILE *file; //cria o arquivo
    file = fopen(arquivo, "w"); //cria o arquivo
    fprintf(file,cpf); //salva o valor da variavel
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("-Digite o nome desejado para cadastrar:" );//coletando informação do usuário
    scanf("%s", nome);
    
    file = fopen(arquivo, "a"); //criando arquivo para cadastrar o nome do usuário
    fprintf(file,nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("-Digite o sobrenome desejado para cadastrar: ");
    scanf("%S",sobrenome);
    
    file = fopen(arquivo, "a"); ////criando arquivo para cadastrar o sobrenome do usuário
    fprintf(file,sobrenome);
	fclose(file);
	  
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("-Digite o cargo desejado para cadastrar: ");
    scanf("%s",cargo);
    
    file = fopen(arquivo, "a"); ////criando arquivo para cadastrar o cargo do usuário
    fprintf(file,cargo);
    fclose(file);
    
    system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cpf [40]; //colocando limite de números para o cpf
	char conteudo[200];
	
	printf("-Digite o CPF para consultar: ");
	scanf("%s", cpf);
	
	FILE *file; //buscando o arquivo para consultar o cpf 
	file = fopen(cpf,"r");
	
	if(file == NULL)	
{
	printf("-Arquivo inexistente, não localizado!\n"); //quando o cpf for excluido ou não cadastrado
}

while(fgets(conteudo, 200, file) != NULL) //buscando pelos dados do usuário
{
	printf("\n-Essas são a informação do usuário: ");
	printf("%s", conteudo);
	printf("\n\n");
	
}

system("pause");

}

int deletar()
{
	char cpf[40]; //limite de números do cpf
	
	printf("-Digite o CPF desejado para deletar: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file; //buscando o cpf para remover ele
	file = fopen(cpf,"r");
	
	if(file == NULL)
{
    printf("-Este usuário não existe!.\n"); //quando o cpf for excluido
    system("pause");
}

}

int main() //inicio do menu
{
	int opcao=0; //definindo as variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
{
	
	system("cls"); //"cls" é para limpar a tela
	
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem

	printf("\t*Cartório da EBAC*\t\n\n");
	printf("-Escolha a opção desejada do menu:\n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n"); 
	printf("opção: "); //fim do menu
	
	scanf("%d", &opcao); //armazenando a escolha do usuario 
	
	system("cls");
	
	switch(opcao) //todas as opções do menu
{
	case 1:
	registro(); //chamando as funções
	break;
		
	case 2:
	consulta();
	break;
	    
	case 3:
	deletar();
	break;
	    
	default:
	printf("-Essa opção não está disponível!\n"); //quando o usuário digitar uma opção não existente no menu
	system("pause"); 
	break;
	    
}// fim da seleção
	
}
  
  
  
}


