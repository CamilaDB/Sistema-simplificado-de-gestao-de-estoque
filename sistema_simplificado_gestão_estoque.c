#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

/*
  simulação de um sistema simplificado de gestão de estoque utilizado por uma farmácia
*/

struct autentificacao
{
    char usuario[12];
    int senha;
};
struct autentificacao autentificacaoPadrao = {"meu usuario",123456};

struct produto
{
    char nome[60];
    float preco;
    int estoque;
    int codigo;
    char fornecedor[30];
    int validade;
};
struct produto pd[100];

int quantidadeProdutos=0;

void cabecalho(char descricao[]);
void validaUsuario(char padraoUsuario[], char entradaUsuario[]);
void validaSenha(int padraoSenha, int entradaSenha);
void controleEstoque();
void verificaOpcao();
void chamaOpcao(int opcaoEscolhida);
void cadastro();
void busca();
void estoque();
void sair();
void voltaControleEstoque(char resposta);

int main()
{
    struct autentificacao autentificacaoEntrada;

    setlocale(LC_ALL,"Portuguese");

    cabecalho("AUTENTICAÇÃO DE USUÁRIO");
    validaUsuario(autentificacaoPadrao.usuario, autentificacaoEntrada.usuario);
    validaSenha(autentificacaoPadrao.senha, autentificacaoEntrada.senha);
    
    system("cls");

    controleEstoque();

    return 0;
}

void cabecalho(char descricao[])
{
    printf("**************************************************************************\n");
    printf("\n               SISTEMA DE GESTÃO DE ESTOQUE – FARMÁCIA XWY\n");
    printf("\n**************************************************************************\n");
    printf("\n\n                      %s\n\n", descricao);
}

void validaUsuario(char padraoUsuario[], char entradaUsuario[])
{
    while(strcmp(padraoUsuario,entradaUsuario)!=0)
    {
        printf("\nInforme seu usuário: ");
        fgets(entradaUsuario,12,stdin);
        if(strcmp(padraoUsuario,entradaUsuario)!=0)
        {
            printf("\nUsuário não encontrado, tente novamente.\n");
        }
    }
}

void validaSenha(int padraoSenha, int entradaSenha)
{
    while(padraoSenha!=entradaSenha)
    {
        printf("\nInforme sua senha: ");
        scanf("%d",&entradaSenha);
        if(padraoSenha!=entradaSenha)
        {
            printf("\nSenha inválida, tente novamente.\n");
        }
    }
}

void controleEstoque()
{
    cabecalho("  CONTROLE DE ESTOQUE");
    printf("\n1- Cadastro de produto");
    printf("\n2- Busca de produto");
    printf("\n3- Exibir estoque de produtos");
    printf("\n4- Sair do programa");

    printf("\n\n");

    verificaOpcao();
}

void verificaOpcao()
{
    int opcaoEscolhida;
    while (opcaoEscolhida!=1 || opcaoEscolhida!=2 || opcaoEscolhida!=3 || opcaoEscolhida!=4)
    {
        printf("Escolha uma opção: ");
        scanf("%d",&opcaoEscolhida);

        if(opcaoEscolhida==1 || opcaoEscolhida==2 || opcaoEscolhida==3 || opcaoEscolhida==4)
            break;
        else
            printf("\nOpção inválida\n\n");
    }

    chamaOpcao(opcaoEscolhida);
}


void chamaOpcao(int opcaoEscolhida)
{
    system("cls");
    switch(opcaoEscolhida)
    {
    case 1:
        cadastro();
        break;
    case 2:
        busca();
        break;
    case 3:
        estoque();
        break;
    case 4:
        sair();
        break;
    }
}

void cadastro()
{
    char resposta;
    for(int i=quantidadeProdutos; i<100; i++)
    {
        getchar();
        printf("Informe nome do produto: ");
        fgets(pd[i].nome,60,stdin);
        printf("Informe preço do produto: ");
        scanf("%f",&pd[i].preco);
        printf("Informe a quantidade em estoque do produto: ");
        scanf("%d",&pd[i].estoque);
        printf("Informe código do produto: ");
        scanf("%d",&pd[i].codigo);
        getchar();
        printf("Informe fornecedor do produto: ");
        fgets(pd[i].fornecedor,30,stdin);
        printf("Informe validade do produto (ano): ");
        scanf("%d",&pd[i].validade);
        printf("\n\n");
	quantidadeProdutos++;
        printf("Cadastro do produto %d realizado com sucesso",quantidadeProdutos);
        printf("\n\n");
        printf("Deseja cadastrar mais produtos(S ou N)?  ");
        scanf("%s",&resposta);
        voltaControleEstoque(resposta);
    }
}

void voltaControleEstoque(char resposta)
{
    if(resposta=='n'||resposta=='N')
    {
        system("cls");
        controleEstoque();
    }
    else
    	printf("\n\n");
}

void busca()
{
    char nomeProduto[60],resp;
    for(int i=0; i<100; i++)
    {
        int produtoExiste=0;
        getchar();
        printf("Informe nome do produto para busca: ");
        fgets(nomeProduto,60,stdin);
        for(int i=0; i<100; i++)
        {
            if((strcmp(nomeProduto, pd[i].nome))==0)
            {
                produtoExiste=1;
                printf("Produto: %s ",pd[i].nome);
                printf("Preço: %.2f",pd[i].preco);
                printf("\n");
                printf("Estoque: %d",pd[i].estoque);
                printf("\n");
                printf("Código do produto: %d",pd[i].codigo);
                printf("\n");
                printf("Nome do fornecedor: %s",pd[i].fornecedor);
                printf("Validade:  %d",pd[i].validade);
                printf("\n");
                break;
            }
        }
        if(produtoExiste==0)
        {
            printf("\nPRODUTO NÃO ENCONTRADO\n");
        }
	   
        printf("\nDeseja procurar mais produtos(S ou N)? ");
        scanf("%s",&resp);

        voltaControleEstoque(resp);
    }
}

void estoque()
{
    char res;

    if(quantidadeProdutos!=0)
    {
        for(int i=0; i<quantidadeProdutos; i++)
        {
            printf("Produto: %s",pd[i].nome);
            printf("\n");
            printf("Estoque: %d",pd[i].estoque);
            printf("\n\n");
        }
    }
    else
        printf("Não há produtos cadastrados!");

    printf("\n\n");
    printf("Deseja retornar ao controle de estoque?(S ou N)");
    scanf("%s",&res);

    if(res=='S' || res=='s')
    {
        system("cls");
        controleEstoque();
    }
    else
    	sair();
 }
  
 void sair()
 {
    char respsaida;
    getchar();
    printf("Você realmente deseja sair?(S ou N)");
    scanf("%c",&respsaida);

    if(respsaida=='s'||respsaida=='S')
        exit(1);
    else
	voltaControleEstoque(respsaida);
 }
