/*Escrever um código para para exibir os vetores explícitos: string nome [] =
{“Jeguinaldo Santos”,”Risoleta Gomes”} , double salario [] = {12000, 10243.20} e int 
idade[]={30, 45}; O salário deverá ser exibido com 10% de aumento. Faça um menu de controle.*/

#include <iostream>
#include <string>
#include <limits>
using namespace std;

int main() {
    string nome[] = {"Jeguinaldo Santos", "Risoleta Gomes"};
    double salario[] = {12000.00, 10243.20};
    int idade[] = {30, 45};
    
    int escolha;
    // Menu com repetição 
    do {
    	cout << "\n*************************" << endl;
        cout << " -- Menu de Controle -- " << endl;
        cout << "*************************" << endl;
        cout << "1. Exibir informacoes dos funcionarios" << endl;
        cout << "2. Aplicar aumento de 10% nos salarios atuais" << endl;
        cout << "3. Encerrar" << endl;
        cout << "***********************" << endl;
        cout << "Escolha uma opcao: ";
    	
		// Verifica se a entrada é ou não um número inteiro pra não entrar em loop infinito    
        if (!(cin >> escolha)) {
            cout << "\n-----------------------" << endl;
			cout << "Opcao invalida. Por favor, insira um numero inteiro." << endl;
            cout << "-----------------------" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta qualquer entrada inválida
            continue;
        }
        
        switch (escolha) {
            case 1: //exibe os funcionarios e seus salariso atuais
            	cout << "\n-----------------------" << endl;
                cout << "Funcionarios:" << endl;
                for (int i = 0; i < 2; i++) {
                    cout << "Nome: " << nome[i] << ", Idade: " << idade[i] << ", Salario: R$ " << salario[i] << endl;
                }
                cout << "-----------------------" << endl;
                break;
            case 2: // Aumenta o salario armazenado em 10% (multiplicando por 1.1)
            	cout << "\n-----------------------" << endl;
                cout << "Aplicando aumento de 10%..." << endl;
                for (int i = 0; i < 2; i++) {
                    salario[i] *= 1.1; // Aumento de 10%
                }
                cout << "O valor do salario foi aumentado" << endl;
                cout << "-----------------------" << endl;
				break;
            case 3: //encerrar
            	cout << "-----------------------" << endl;
                cout << "Saindo do programa." << endl;
                cout << "-----------------------" << endl;
                break;
            default:
                cout << "\n-----------------------" << endl;
				cout << "Opcao invalida. Por favor, escolha um numero de 1 a 3." << endl;
                cout << "-----------------------" << endl;
				break;                
        }
        
    } while (escolha != 3);

    return 0;
}
