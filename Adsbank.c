#include <stdio.h>

#define STR 100  // Define o tamanho máximo das strings para o nome e CPF do cliente

// Definição da estrutura Cliente, contendo nome, CPF e saldo inicial
typedef struct{
    char nome[STR];
    char cpf[STR];
    double saldoInicial;
}Cliente;

Cliente cliente;  // Declaração de uma variável global do tipo Cliente

// Função para coletar os dados do cliente
int dadosCliente(){
    getchar();  // Consome o caractere de nova linha pendente
    printf("Digite o nome do(a) cliente:\n");
    fgets(cliente.nome,STR, stdin);  // Coleta o nome do cliente
    printf("Digite o CPF do(a) cliente:\n");
    fgets(cliente.cpf,STR, stdin);  // Coleta o CPF do cliente
    printf("Digite o saldo inicial do(a) cliente %s",cliente.nome);
    scanf("%lf",&cliente.saldoInicial);  // Coleta o saldo inicial do cliente
    getchar();  // Limpa o buffer após a leitura do saldo
    return 0;
}

// Função para listar os dados do cliente
void listarClientes(){
    printf("Clientes:\n\n");
    printf("Cliente: %sCPF: %sSaldo: %.2lf R$\n",cliente.nome,cliente.cpf,cliente.saldoInicial);  // Exibe os dados do cliente
}

// Função para atualizar o saldo do cliente
void NovoSaldo() {
    printf("Digite o novo saldo do(a) cliente:\n");
    scanf("%lf", &cliente.saldoInicial);  // Atualiza diretamente o saldo do cliente
    printf("Saldo alterado com sucesso!\n\n");
}

// Função para alterar o nome do cliente
void MudarNome() {
    printf("Digite o nome a ser alterado:\n");
    getchar(); 
    fgets(cliente.nome,STR,stdin);  // Coleta o novo nome do cliente
    printf("Nome alterado!\n\n");
}

// Função para alterar o CPF do cliente
void MudarCpf() {
    printf("Digite o cpf a ser alterado\n");
    getchar();  
    fgets(cliente.cpf,STR,stdin);  // Coleta o novo CPF do cliente
    printf("CPF alterado!\n\n");
}

// Função para alterar os dados do cliente
int alterarDados(){
    int op;
    do{
        printf("Qual dado deseja alterar?\nDigite:\n1 - Saldo\n2 - Nome do(a) cliente\n3 - CPF\n0 - Encerrar alteracao\n\n");
        scanf("%d",&op);

        // Menu de opções para alteração dos dados do cliente
        switch(op){
            case 0:
                printf("OK..\n");
                break;

            case 1:
                NovoSaldo();  // Altera o saldo
                break;

            case 2:
                MudarNome();  // Altera o nome
                break;

            case 3:
                MudarCpf();  // Altera o CPF
                break;
        }
    }while(op != 0);  // Continua no loop até que a opção 0 seja escolhida
    return 0;
}

// Função para excluir os dados do cliente
void excluirClientes(){
    cliente.nome[0] = '\0';  // Apaga o nome do cliente
    cliente.cpf[0] = '\0';   // Apaga o CPF do cliente
    cliente.saldoInicial = 0.0;  // Reseta o saldo do cliente

    printf("Cliente excluido com sucesso!\n\n");
}

// Função para visualizar o saldo do cliente
void VisualizarSaldo() {
    printf("Saldo: %.2lf R$\n",cliente.saldoInicial);
}

// Função para depositar dinheiro na conta do cliente
void Depositar() {
    double deposito;
    printf("Quanto deseja depositar?\n\n");
    scanf("%lf", &deposito);  
    cliente.saldoInicial += deposito;  // Adiciona o valor depositado ao saldo do cliente
    printf("Deposito realizado com sucesso!\n\n");
}

// Função para sacar dinheiro da conta do cliente
void Sacar() {
    double sacar;
    printf("Quanto deseja sacar?\n");
    scanf("%lf", &sacar);  
    cliente.saldoInicial -= sacar;  // Subtrai o valor sacado do saldo do cliente
    printf("Saque realizado com sucesso!\n\n");
}

// Função para transferir dinheiro da conta do cliente
void Transferir() {
    int conta;
    double transferir;
    printf("Digite o numero da conta.\n");
    scanf("%d",&conta);  // Coleta o número da conta de destino (número fictício)
    printf("quanto deseja transferir?\n");
    scanf("%lf", &transferir);  
    cliente.saldoInicial -= transferir;  // Subtrai o valor transferido do saldo do cliente
    printf("Transferencia realizada com sucesso!\n\n");
}

// Função principal do programa
int main(){
    int opcoes;
    do{
        // Menu de opções para o usuário escolher
        printf("0 - Sair\n1 - Inserir Clientes\n2 - Listar Clientes\n3 - Alterar dados do cliente\n4 - Excluir Cliente\n\n");
        printf("5 - Visualizar Saldo\n6 - Depositar\n7 - Sacar\n8 - Transferir\n\n");
        scanf("%d",&opcoes);

        // Escolha da operação com base na entrada do usuário
        switch (opcoes){
            case 0:
                printf("Saindo..");
                break;

            case 1:
                dadosCliente();  // Chama a função para inserir dados do cliente
                break;
            
            case 2:
                listarClientes();  // Chama a função para listar dados do cliente
                break;

            case 3:
                alterarDados();  // Chama a função para alterar dados do cliente
                break;

            case 4:
                excluirClientes();  // Chama a função para excluir o cliente
                break;

            case 5:
                VisualizarSaldo();  // Chama a função para visualizar o saldo do cliente
                break;

            case 6:
                Depositar();  // Chama a função para depositar
                break;

            case 7:
                Sacar();  // Chama a função para sacar
                break;

            case 8:
                Transferir();  // Chama a função para transferir
                break;

            default:
                printf("Opcao invalida\n");
                break;
        }
    }while (opcoes != 0);  // Continua no loop até que a opção 0 seja escolhida
    return 0;
}
