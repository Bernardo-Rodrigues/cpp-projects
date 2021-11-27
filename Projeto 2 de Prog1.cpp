#include <iostream>
#include <cmath>
#include <cstdlib>
#include <time.h>
using namespace std;

int menu() // Menu principal
{

int X;
cout << "Qual problema voce deseja resolver (1/2/3)?" << endl;
cout << "Se deseja sair do programa digite 4!" << endl;
cin >> X;

switch(X)
{
case 1: system ("cls"); cout << "Problema 1: Bingo!" << endl; break;
case 2: system ("cls"); cout << "Problema 2: Sala de prova!" << endl; break;
case 3: system ("cls"); cout << "Problema 3: Jogo dos palitinhos!" << endl; break;
case 4: system ("cls"); cout << "Saindo do programa!" << endl; break;
}

return X;
}
int menuSaida()  // Menu para finalizar os problemas
{
    char X;
    cout << "\nDeseja voltar para o menu (S/N)?  ";
    cin >> X;

    if(X == 'S')
    {
        system("cls");
        return 1;
    }
    else
    {
        system("cls");
        cout << "Saindo do programa!" << endl;
        return 0;
    }
}
void bingo(int VETC[], int VETS[], int C, int S) // Verifica se foi bingo
{
    int cont = 0, ultimo;
    for(int i = 0; i < S; i ++)
    for(int j = 0; j < C; j ++)
        if(VETS[i] == VETC[j])
        {
        cont++;
        ultimo = i+1;
        }

    if(cont == C)
         cout << "\nBingo " << ultimo << endl;
    else
        cout << "\nLost" << endl;
}
void sorteio(int VETS[], int S) // Números do sorteio
{
    int sorteados[S];
    for(int i = 0; i < S; i ++)
    {
        VETS[i] = rand() % 80 + 1; // Sorteia um número
        for(int j = 0; j < i; j ++)
        do{
            if(VETS[i] == sorteados[j]) // Confere se já foi sorteado
            {
            VETS[i] = rand() % 80 + 1; // Sorteia de novo
            j = 0; // Volta todos os numeros para garantir que o numero resorteado não seja repetido
            }
            else j++;
        }while(j < i); // Garante que passara por todos os numeros ja sorteados
        sorteados[i] = VETS[i]; // Guarda o número que já foi sorteado
    }

     for(int i = 0; i < S; i ++)
            cout << VETS[i] << " "; // Mostra os números do sorteio
}
void cartela(int VETC[], int C) // Números da cartela
{
    int sorteados[C];
    for(int i = 0; i < C; i ++)
    {
        VETC[i] = rand() % 80 + 1; // Sorteia um número
        for(int j = 0; j < i; j ++)
        do{
            if(VETC[i] == sorteados[j]) // Confere se já foi sorteado
            {
            VETC[i] = rand() % 80 + 1; // Sorteia de novo
            j = 0;  // Volta todos os numeros para garantir que o numero resorteado não seja repetido
            }
            else j++;
        }while(j < i); // Garante que passara por todos os numeros ja sorteados
        sorteados[i] = VETC[i]; // Guarda o número que já é sorteado
    }

     for(int i = 0; i < C; i ++)
            cout << VETC[i] << " "; // Mostra os números da cartela
}
void Problema1() //Resolução problema 1
{
    int C, S;
    cout << "\nPara finalizar o problema forneça 0/0!" << endl;
    do{
    cout << "\nQuantos números terão na sua cartela? (0 < C <= 20)" << endl;
    cin >> C;
    int VETC[C];
    cout << "Quantos números serão sorteados? (C < S <= 80 " << endl;
    cin >> S;
    int VETS[S];

        if((C < 0 || C > 20) || (C > S || S > 80) || (C == 0 && S > 0)) // Valida os valores
        cout << "\nValores inválidos!" << endl;
        else if (C > 0 && S > 0)
        {
            cout << "\nSeus números: " << endl;
            cartela(VETC, C);
            cout << "\nNúmeros sorteados: " << endl;
            sorteio(VETS, S); cout << endl;
            bingo(VETC, VETS, C, S);
        }
    }while(C != 0 || S !=0); // Finaliza quando o usuario digitar 0/0

}
void novaSala(int matriz[100][100], int m, int n) // Reorganiza a sala
{
    cout << "\nSala organizada considerando o máximo de cadeiras:" << endl;
    matriz[100][100] = matriz[m][n];
    for(int i = 0; i < m; i++)
    {
    cout << endl;
    for(int j = 0; j < n; j++)
    {
    if((i+10)%2 == 0)
    {
    if((j+10)%2 == 0)
    cout << 1 << " " ;
    else
    cout << 0 << " ";
    }
    else
    {
    if((j+10)%2 == 0)
    cout << 0 << " " ;
    else
    cout << 1 << " ";
    }}}cout << endl;
}
bool reorganiza(int matriz[100][100], int m, int n) // Confere se a sala pode ser reorganizada
{
    matriz[100][100] = matriz[m][n];
    int cont = 0;

    for(int i = 0; i < m; i++) // Conta quantas cadeiras tem na sala
    for(int j = 0; j < n; j++)
        if(matriz[i][j] == 1)
            cont++;

    if((m*n)% 2 == 0) // Matriz par
    {
    if(cont <= ((m*n)/2))
        return 1;
    else return 0;
    }
    else // Matriz ímpar
    {
    if(cont <= ((m*n)/2)+1)
        return 1;
    else return 0;
    }
}
void sala(int matriz[100][100], int m, int n) // Recebe a sala
{
    matriz[100][100] = matriz[m][n];
    for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++)
        cin >> matriz[i][j];
}
void Problema2() // Resolução problema 2
{
    int m, n;
    cout << "\nPara sair do problema digite 0/0!" << endl;
    do{
    cout << "\nQuantas linhas de cadeiras tem a sala (2 <= m <= 100)?   ";
    cin >> m;
    cout << "Quantas colunas de cadeiras tem a sala (2 <= n <= 100?   ";
    cin >> n;

    if(m != 0 && n != 0)
    if((m < 2 || m > 100)||(n < 2 || n > 100)) // Valida os dados
        cout << "\nDados inválidos!" << endl;
    else
    {
    int matriz[100][100];

    cout << "\n\nForneça a matriz que representa a sala atual!" << endl;
    sala(matriz,m, n);

        if(reorganiza(matriz, m, n) == 1)
        {
            cout << "\nÉ possível reorganizar a sala!" << endl;
            novaSala(matriz, m, n);
        }
        else
            cout << "\nNão é possível reorganizar a sala" << endl;
    }
    }while(m != 0 && n !=0); // Verifica se o usuario quer sair do problema
}
bool vidas(int vida[]) // Confere se um dos jogadores ganhou
{
    if(vida[0] == 0){
        cout << "\n\njoao venceu" << endl << endl;
        return 1;
        }
    if(vida[1] == 0){
        cout << "\n\njose venceu" << endl << endl;
        return 1;
        }
    if(vida[2] == 0){
        cout << "\n\nmaria venceu" << endl << endl;
        return 1;
        }
    return 0;
}
void resultado(int MP[100][3], int MA[100][3], int N, int &A) // Resultado da rodada
{
    int palitos;
    int vida[3] = {3,3,3};

    for(int i = 0; i <= N; i ++)
    {
    palitos = 0;
    for(int j = 0; j < 3; j++)
    palitos = palitos + MP[i][j];

    for(int j = 0; j < 3; j++)
    if(MA[i][j] == palitos)
        vida[j]--;

    if(vidas(vida) == 1)
        A = A + 1;
    }

}
int rodadas(int N, int &A) //Recebe os valores dos palitos e das apostas
{
    int MP[N][3], MA[N][3], r = 0; // Matrizes dos palitos e das apostas
    for(int i = 0; i < N; i ++)
    {
    cout << "\nRodada " << i+1 << endl;
    for(int j = 0; j < 3; j++)
    {
    do{
    cout << "\nQuantos palitos estavam na mão do jogador " << j+1 << ": ";
    cin >> MP[i][j];
    if(MP[i][j] < 0 || MP[i][j] > 3) // Validação dos palitos
        cout << "Dado inválido" << endl;
    }while(MP[i][j] < 0 || MP[i][j] > 3);
    do{
    cout << "Qual foi a aposta do jogador " << j+1 << ": ";
    cin >> MA[i][j];
    if(MA[i][j] < 0 || MA[i][j] > 9) // Validação das apostas
        cout << "Dado inválido";
    }while(MA[i][j] < 0 || MA[i][j] > 9);
    }
    resultado(MP, MA, i, A);
    if(A == 1) // Condição de vitoria
    break;
    }
    if(A != 1) // Condição de final das rodadas sem vitoria
    A = 2;
}
void Problema3() //Resolução problema 3
{
    int N, r;
    do{
    int A = 0;
    cout << "\nQuantas rodadas terá o jogo? (1 < N < 101)    ";
    cin >> N;

    if(N != 0)
    if(N < 3 || N > 100) // Valida os dados
    cout << "\nDados inválidos!" << endl;
    else
    {
    do{
        rodadas(N, A);
    }while(A == 0);
    if(A == 2) // Condição de final das rodadas sem vitoria
    cout << "\nninguém venceu" << endl;
    }
    }while(N != 0); // Verifica se o usuario deseja finalizar o problema
}
int main () // Função principal
{
    setlocale(LC_ALL, "Portuguese");
    int Usuario, Saida;

    do{
    Usuario = menu(); // Escolha do usuario

    switch(Usuario){
    case 1: Problema1(); break;
    case 2: Problema2(); break;
    case 3: Problema3(); break;
    case 4: return 0;
    default: cout << "\nInválido!\n"; return 0; // Valor invalido no menu
    }
    Saida = menuSaida(); // Usuario escolhe se quer voltar para o menu
    }while(Saida == 1);
}
