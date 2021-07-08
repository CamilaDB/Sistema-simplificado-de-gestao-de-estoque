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

int indice;

void cabecalho(char descricao);
void validaUsuario(char padraoUsuario, char entradaUsuario);
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

void cabecalho(descricao)
{
    printf("**************************************************************************\n");
    printf("\n               SISTEMA DE GESTÃO DE ESTOQUE – FARMÁCIA XWY\n");
    printf("\n**************************************************************************\n");
    printf("\n\n                      %s\n\n", descricao);
}

void validaUsuario(padraoUsuario, entradaUsuario)
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

void validaSenha(padraoSenha, entradaSenha)
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


void chamaOpcao(opcaoEscolhida)
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
    for(int i=0; i<100; i++)
    {
        indice=i+1;
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
        printf("Cadastro do produto %d realizado com sucesso",i=i+1);
        printf("\n\n");
        printf("Deseja cadastrar mais produtos(S ou N)?  ");
        scanf("%s",&resposta);
        voltaControleEstoque(resposta);
    }
}

void voltaControleEstoque(resposta)
{
    if(resposta=='n'||resposta=='N')
    {
        system("cls");
        controleEstoque();
    }
    printf("\n\n");
}

void busca()
{
    char infnome[60],resp;
    for(int i=0; i<100; i++)
    {
        int cont=0;
        getchar();
        printf("Informe nome do produto para busca: ");
        fgets(infnome,60,stdin);
        for(int i=0; i<100; i++)
        {
            if((strcmp(infnome, pd[i].nome))==0)
            {
                cont++;
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
        if(cont==0)
        {
            printf("\nPRODUTO NÃO ENCONTRADO\n");
        }

        getchar();
        printf("\nDeseja procurar mais produtos(S ou N)? ");
        scanf("%s",&resp);

        voltaControleEstoque(resp);
    }
}

void estoque()
{
    char respret;

    if(indice!=0)
    {
        for(int i=0; i<indice; i++)
        {
            printf("Produto: %s ",pd[i].nome);
            printf("\n");
            printf("Estoque: %d",pd[i].estoque);
            printf("\n\n");
        }
    }
    else
        printf("Não há produtos cadastrados!");

    printf("\n\n");
    printf("Deseja retornar ao controle de estoque?(S ou N)");
    scanf("%s",&respret);

    if(respret=='S' || respret=='s')
    {
        system("cls");
        controleEstoque();
    }
    else
    {
        exit(1);
        return 0;
    }
 }
  
 void sair()
 {
    char respsaida;
    getchar();
    printf("Você realmente deseja sair?(S ou N)");
    scanf("%c",&respsaida);

    if(respsaida=='s'||respsaida=='S')
    {
        exit(1);
        return 0;
    }
    else
	  voltaControleEstoque(respsaida);
 }
