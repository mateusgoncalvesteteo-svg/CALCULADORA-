#include <iostream> // cin e cout
#include <cmath> // operacoes matematicas
#include <cctype> // tolower e outros
#include <limits> // apenas numeros nao letras

using namespace std;//estou mais acostumado a usar assim, talvez mais pra frente eu mude 13/05/2026

// 06/05/2026 19:34 , quero adicionar mais operacoes [:)]

double soma(double num1, double num2) {
    // criei uma funcao para cada operacao da calculadora, assim a main fica bem mais limpa

    return num1 + num2;
}

double subtracao(double num1, double num2) {
    return num1 - num2;
}

double multiplicacao(double num1, double num2) {
    return num1 * num2;
}

double divisao(double num1, double num2) {

    if (num2 != 0) {
        return num1 / num2;

    } else {
        cout << "Erro divisao por 0!\n";
        return 0;
    }
}

double potenciacao(double base, double expoente) {

    // em vez de deixar: digite o primeiro numero e o segundo
    // irei deixar:  digite a base e o expoente

    return pow(base, expoente);
}

double logaritmo(double num1, double num2) {

    // log(base) do logaritmando

    if (num1 <= 0 || num1 == 1 || num2 <= 0) {
        cout << "Logaritmo invalido\n";
        return 0;
    }

    return log(num2) / log(num1);
}

double lerNumero() {

    double num;

    while (true) {

        if (cin >> num) {
            return num;

        } else {

            cout << "Digite apenas numeros: ";

            cin.clear();
            
            cin.ignore(
                numeric_limits<streamsize>::max(),
                '\n'
            );
        }
    }
}

void pedirNumeros(char operacao, double &num1, double &num2) {

    // funcao criada para evitar muitos ifs na main()

    switch (operacao) {

        case '5': // potenciacao

            cout << "Digite a base: ";
            num1 = lerNumero();

            cout << "Digite o expoente: ";
            num2 = lerNumero();

            break;

        case '6': // logaritmo

            cout << "Digite a base: ";
            num1 = lerNumero();

            cout << "Digite o logaritmando: ";
            num2 = lerNumero();

            break;

        default: // demais operacoes

            cout << "Digite o primeiro numero: ";
            num1 = lerNumero();

            cout << "Digite o segundo numero: ";
            num2 = lerNumero();

            break;
    }
}

double operacao(char op, double num1, double num2) {

    switch (op) {

        case '1':
            return soma(num1, num2);

        case '2':
            return subtracao(num1, num2);

        case '3':
            return multiplicacao(num1, num2);

        case '4':
            return divisao(num1, num2);

        case '5':
            return potenciacao(num1, num2);

        case '6':
            return logaritmo(num1, num2);

        default:
            cout << "Operacao invalida!\n";
            return 0;
    }
}

void limparTela() {//finalmente , hoje( 14/05/2026 ) é o dia que criarei a funçao de limpar a tela, depois de muito estudo

#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
    
}

// agora irei criar a funcao menu :)

char menu() {

    char operacao;

    do {

        cout << "================================\n";
        cout << "Calculadora Simples em C++\n";
        cout << "================================\n";

        cout << "Selecione uma operacao:\n";

        cout << "1. Adicao [+]\n";
        cout << "2. Subtracao [-]\n";
        cout << "3. Multiplicacao [*]\n";
        cout << "4. Divisao [/]\n";
        cout << "5. Potencia [^]\n";
        cout << "6. Logaritmo [log]\n";
        cout << "7. Sair\n";

        cout << "Opcao: ";
        cin >> operacao;

        if (operacao < '1' || operacao > '7') {
            cout << "Apenas numeros da lista!\n";
        }

    } while (operacao < '1' || operacao > '7');

    return operacao;
}

// 07/05/2026 07:32
// hora de fazer as modificacoes [:)]

int main() {

    // hoje 11/05/2026 irei criar
    // uma funcao pra cada operacao matematica

    double num1, num2, resultado;

    char opcao;
    char continuar;

    do {

        limparTela();//finalmente ela foi adicionada ao codigo :) 14/05/2026.
        //minha maquina usa o sistema operacional do windows 11, mas eu adicionei um else na funçao pra caso tenha linux tbm ;)
        
        opcao = menu();

        if (opcao == '7') {
            break;
        }

        // antes aqui existiam varios ifs
        // agora apenas uma funcao

        pedirNumeros(opcao, num1, num2);

        //antes existia um swicht(op) aqui
        resultado = operacao(opcao, num1, num2);

        cout << "Resultado: " << resultado << endl;

        // validacao do char (s/n)

        do {

            cout << "Deseja rodar o codigo novamente? (s/n): ";
            cin >> continuar;

            continuar = tolower(continuar);

            if (continuar != 's' && continuar != 'n') {

                cout << "Entrada invalida!"
                     << " Digite apenas 's' ou 'n'.\n";
            }

        } while (continuar != 's' && continuar != 'n');

    } while (continuar == 's');

    cout << "Programa encerrado...\n";

    return 0;
}
