#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

struct autentificacao
{
    char usuario[12];
    int senha;
};

struct autentificacao a1 = {"meu usuario",123456};

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

void controleEstoque();
void op1();
void op2();
void op3();

int main()
{
    struct autentificacao a;

    setlocale(LC_ALL,"Portuguese");

    printf("**************************************************************************\n");
    printf("\n           SISTEMA DE GESTÃO DE ESTOQUE – FARMÁCIA XWY                    \n");
    printf("\n**************************************************************************\n");

    printf("\n\n---------- AUTENTICAÇÃO DE USUÁRIO --------------\n");

    do
    {
        a.senha=0;

        printf("\nInforme seu usuário: ");
        fgets(a.usuario,12,stdin);

        printf("\nInforme sua senha: ");
        scanf("%d",&a.senha);
        printf("\n");

        getchar();

    }
    while((strcmp(a.usuario,a1.usuario)==0)&&(a.senha==a1.senha));

    system("cls");

    controleEstoque();

    return 0;
}

void controleEstoque()
{
    int op;
    char respsaida;

    printf("\n**************************************************************************\n");
    printf("\n           SISTEMA DE GESTÃO DE ESTOQUE – FARMÁCIA XWY                    \n");
    printf("\n**************************************************************************\n");

    printf("\n\n---------- CONTROLE DE ESTOQUE --------------\n");

    printf("\n1- Cadastro de produto");
    printf("\n2- Busca de produto");
    printf("\n3- Exibir estoque de produtos");
    printf("\n4- Sair do programa");

    printf("\n\n");

    for(int i=0; i<100; i++)
    {
        printf("Escolha uma opção: ");
        scanf("%d",&op);

        if(op==1 || op==2 || op==3 || op==4)
            break;
        else
            printf("\nOpção inválida\n\n");
    }


    switch(op)
    {
    case 1:
        system("cls");
        op1();
        break;
    case 2:
        system("cls");
        op2();
        break;
    case 3:
        system("cls");
        op3();
        break;
    case 4:
        system("cls");
        getchar();
        printf("você realmente deseja sair?(S ou N)");
        scanf("%c",&respsaida);

        if(respsaida=='n'||respsaida=='N')
        {
            system("cls");
            getchar();
            controleEstoque();
        }
        else
        {
            exit(1);
            return 0;
        }

    }

}

void op1()
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
        if(resposta=='n'||resposta=='N')
        {
            system("cls");
            getchar();
            controleEstoque();
        }
        printf("\n\n");
    }
}

void op2()
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

        if(resp=='n'||resp=='N')
        {
            system("cls");
            getchar();
            controleEstoque();
        }
        printf("\n\n");
    }
}

void op3()
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











