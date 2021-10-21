#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Cliente
{
    char nome[20], telefone[15], placa[10], procedimento[10];
    float valor_procedimento;
} Cliente;

typedef struct Agenda
{
    int dia;
    int quantidade;
    Cliente *clientes;
} Agenda;

Agenda *aloca_agenda(int quantidadeDias)
{
    Agenda *agenda = malloc(sizeof(Agenda) * quantidadeDias);
    if (agenda != NULL)
    {
        printf("\nAgenda com %d posicoes foi alocada com sucesso!\n", quantidadeDias);
        int i;
    }
    else
    {
        printf("\nErro ao alocar agenda ._.\n");
    }
    return agenda;
}

aloca_atendimento(Agenda *agenda, int quantidadeDias)
{
    int diaAtendimento, quantidadeClientes, i, filled;
    Agenda *agendaSelecionada = NULL;
    clear();
    printf("Insira o dia do atendimento: \n");
    scanf("%d", &diaAtendimento);

    for (i = 0; i < quantidadeDias; i++)
    {
        if ((agenda + i)->dia == diaAtendimento || !(agenda + i)->dia)
        {
            filled = i;
            agendaSelecionada = agenda + filled;
            printf("%d", filled);
            break;
        }
    }
    printf("\nInsira a quantidade de clientes atendidos: \n");
    scanf("%d", &quantidadeClientes);
    Cliente *clientes = (Cliente *)malloc(sizeof(Cliente) * quantidadeClientes);
    if (clientes)
    {
        agendaSelecionada->clientes = clientes;
        agendaSelecionada->dia = diaAtendimento;
        agendaSelecionada->quantidade = quantidadeClientes;
        *(agenda + filled) = *agendaSelecionada;
        printf("Atendimento alocado para o dia %d na memoria %x", agendaSelecionada->dia, (agenda + filled));
    }
    else
    {
        printf("Dia ja cadastrado");
    }
}

void armazena_cliente(Agenda *agenda, int quantidadeDias)
{
    int diaAtendimento, i;
    Agenda *agendaDia = NULL;
    Cliente cliente;
    printf("Digite o dia do atendimento do cliente:\n");
    scanf("%d", &diaAtendimento);
    for (i = 0; i < quantidadeDias; i++)
    {
        printf("\n%d\n", (agenda + i)->dia);
        if ((agenda + i)->dia == diaAtendimento)
        {
            agendaDia = (agenda + i);
        }
    }
    if (agendaDia == NULL)
    {
        printf("Atendimento nao alocado");
        return;
    }
    int index = 0;
    for (i = 0; i < agendaDia->quantidade; i++)
    {
        if ((agendaDia->clientes + i)->valor_procedimento == 0.0)
        {
            index = i;
        }
    }
    printf("\nDigite as informaçoes do cliente: \n");
    fflush(stdin);
    printf("\nNome: \n");
    fflush(stdin);
    fgets(cliente.nome, 20, stdin);
    printf("\nTelefone: \n");
    fgets(cliente.telefone, 15, stdin);
    printf("\nPlaca do veiculo: \n");
    fgets(cliente.placa, 10, stdin);
    printf("\nDescricao do procedimento: \n");
    fgets(cliente.procedimento, 60, stdin);
    printf("\nValor: \n");
    scanf("%f", &cliente.valor_procedimento);
    for (i = 0; i < index; i++)
    {
        if (strcmp((agendaDia->clientes + i)->placa,cliente.placa) && strcmp((agendaDia->clientes + i)->nome,cliente.nome))
        {
            printf("Esse veiculo ja foi alocado nesse dia");
            return;
        }
    }
    *(agendaDia->clientes + index) = cliente;
    printf("%d", (agendaDia->clientes + index)->placa == cliente.placa);
}

void imprime_cliente(Agenda *agenda, int quantidadeDias)
{
    int diaSelecionado, i;
    Agenda *agendaDia = NULL;
    printf("Listar os clientes do dia: \n");
    scanf("%d", &diaSelecionado);
    for (i = 0; i < quantidadeDias; i++)
    {
        if ((agenda + i)->dia == diaSelecionado)
        {
            agendaDia = (agenda + i);
        }
    }
    if (agendaDia != NULL)
    {
        for (i = 0; i < agendaDia->quantidade; i++)
        {
            if ((agendaDia->clientes + i)->valor_procedimento > 0)
            {
                printf("Nome: %s\n", (agendaDia->clientes + i)->nome);
                printf("Telefone: %s\n", (agendaDia->clientes + i)->telefone);
                printf("Placa: %s\n", (agendaDia->clientes + i)->placa);
                printf("Procedimento: %s\n", (agendaDia->clientes + i)->procedimento);
                printf("Valor: R$%.2f\n", (agendaDia->clientes + i)->valor_procedimento);
                printf("==============================");
            }
        }
    }
    else
    {
        printf("Nenhum cliente para o dia %02d", diaSelecionado);
    }
}

void imprime_menu()
{
    printf("\n1 - Alocar agenda");
    printf("\n2 - Alocar atendimentos");
    printf("\n3 - Armazenar cliente");
    printf("\n4 - Imprimir clientes");
    printf("\n5 - Desalocar agenda/atendimentos");
    printf("\n6 - Sair");
    printf("\n");
}

Cliente constroiCliente()
{
    Cliente cliente;
    int diaAtendimento;
    printf("Digite o dia do atendimento do cliente: ");
    scanf("%d", &diaAtendimento);
    printf("\nDigite as informaçoes do cliente: \n");
    printf("Nome: ");
    scanf("%s", cliente.nome);
    printf("Telefone: ");
    scanf("%s", cliente.telefone);
    printf("Placa do veiculo: ");
    scanf("%s", cliente.placa);
    printf("Descricao do procedimento: ");
    scanf("%s", cliente.procedimento);
    printf("Valor: ");
    scanf("%f", cliente.valor_procedimento);
    return cliente;
}

void clear()
{
    //clear terminal
    // printf("\e[1;1H\e[2J");
    printf("\n\n\n\n\n");
}

void desaloca_atendimentos(Agenda *arr)
{
    free(arr);
    arr = NULL;
}

int main()
{
    clear();
    int tamanhoAgenda, operacao = 0;
    char skip[1];
    Agenda *agenda = NULL;
    printf("Informe a quantidade de dias na agenda: ");
    scanf("%d", &tamanhoAgenda);
    while (operacao != 6)
    {
        imprime_menu();
        scanf("%d", &operacao);
        switch (operacao)
        {
        case 1:
            agenda = aloca_agenda(tamanhoAgenda);
            break;
        case 2:
            if (!agenda)
            {
                printf("Agenda nao alocada, aperte 1 antes de iniciar");
            }
            aloca_atendimento(agenda, tamanhoAgenda);
            break;
        case 3:
            clear();
            armazena_cliente(agenda, tamanhoAgenda);
            break;
        case 4:
            imprime_cliente(agenda, tamanhoAgenda);
            break;
        case 5:
            clear();
            desaloca_atendimentos(agenda);
            break;
        case 6:
            clear();
            printf("\nObrigado por utilizar esse programa!\n");
            break;
        default:
            printf("\nOpcao invalida, selecione uma das opçoes abaixo:\n");
            break;
        }
    }
    return 0;
}