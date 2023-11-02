/* Faça um código contendo vetores não explícitos, para armazenar o nome, a 
situação do empregado que poderá ser: “efetivo” ou “estagiário” e a idade. A leitura 
deverá ser feita através de um menu de controle, coloque também uma opção para 
exibir somente os nomes dos estagiários e outra opção para exibir somente o nome 
dos efetivos, finalmente uma opção para exibir os funcionários menores de idade. */

#include <iostream>
#include <string>
#include <vector>
#include <limits>  // Pra evitar loops infinitos
#include <windows.h>  //sleep e cls

using namespace std;

struct Funcionario {
    string nome;
    int situacao; 
    int idade;
};

int main() {
    vector<Funcionario> funcionarios;

    funcionarios.push_back({"Jeguinaldo Santos", 1, 30});
    funcionarios.push_back({"Risoleta Gomes", 2, 45});

    int escolha;
    
    //laço para o código não parar até que o usuário escolha sair
    do {
    	// Menu principal
        //system("cls");
        cout << "\n*************************" << endl;
		cout << " -- Menu de Controle -- " << endl;
		cout << "***********************" << endl;
        cout << "1. Adicionar funcionario" << endl;
        cout << "2. Exibir nomes dos estagiarios" << endl;
        cout << "3. Exibir nomes dos efetivos" << endl;
        cout << "4. Exibir funcionarios menores de idade" << endl;
        cout << "5. Sair" << endl;
        cout << "***********************" << endl;
        cout << "Escolha uma opcao: ";


		//escolha 
        if (!(cin >> escolha)) {
            cout << "\n-----------------------" << endl;
			cout << "Opcao invalida. Por favor, Escolha uma das opcoes acima!" << endl;
            cout << "-----------------------" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            Sleep(2000);
            system("cls");
			continue;
        }

        switch (escolha) {
            case 1: //adicionar cadastro 
                {
                    Funcionario novoFuncionario;
                    cout << "\n-----------------------" << endl;
                    cout << "Nome: ";
                    cin.ignore();
                    getline(cin, novoFuncionario.nome);
                
                   do {
                    cout << "Situacao (1 para efetivo, 2 para estagiario): ";
                        if (!(cin >> novoFuncionario.situacao)) {
                            cout << "Erro.Por favor, insira um numero." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        } else if (novoFuncionario.situacao != 1 && novoFuncionario.situacao != 2) {
                            cout << "Opcao invalida. Insira 1 para funcionarios efetivos ou 2 para estagiarios." << endl;
                        }
                    } while (novoFuncionario.situacao != 1 && novoFuncionario.situacao != 2);
                    
                    cout << "Idade: ";
                    if (!(cin >> novoFuncionario.idade)) {
                        cout << "Opcao invalida. Por favor, insira um numero." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        continue;
                    }
                    funcionarios.push_back(novoFuncionario);
                    cout << "-----------------------" << endl;
                    cout << "Cadastro feito com sucesso!" << endl;
                    cout << "Carregando...";
                    Sleep(2000);
                    system("cls");
                }
                break;
            case 2: //Mostrar somente os esgiarios
                cout << "\nNomes dos estagiarios:" << endl;
                cout << "-----------------------" << endl;
                for (size_t i = 0; i < funcionarios.size(); i++) {
                    if (funcionarios[i].situacao == 2) {
                        cout << funcionarios[i].nome << endl;
                    }
                }
                cout << "-----------------------" << endl;
                system("pause");
                system("cls");
                break;
            case 3: //Mostrar somente os efetivos
                cout << "\nNomes dos efetivos:" << endl;
                cout << "-----------------------" << endl;
                for (size_t i = 0; i < funcionarios.size(); i++) {
                    if (funcionarios[i].situacao == 1) {
                        cout << funcionarios[i].nome << endl;
                    }
                }
                cout << "-----------------------" << endl;
				system("pause");
                system("cls");
                break;
            case 4: //mostrar os menores de idade
                cout << "\nFuncionarios menores de idade:" << endl;
                cout << "-----------------------" << endl;
                for (size_t i = 0; i < funcionarios.size(); i++) {
                    if (funcionarios[i].idade < 18) {
                        cout << funcionarios[i].nome << endl;
                    }
                }
                cout << "-----------------------" << endl;
				system("pause");
                system("cls");	
                break;
            case 5: //finalizar
                cout << "\nEncerrando..." << endl;
                break;
            default:
            	cout << "\n-----------------------" << endl;
                cout << "Opcao invalida. Tente novamente." << endl;
            	cout << "-----------------------" << endl;
                Sleep(2000);
                system("cls");
        }
    } while (escolha != 5);

    return 0;
}
