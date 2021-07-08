#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

int menu() // Menu principal
{

int X;
cout << "Qual problema voce deseja resolver (1/2/3)?" << endl;
cout << "Se deseja sair do programa digite 4!" << endl;
cin >> X;

switch(X)
{
case 1: system ("cls"); cout << "Problema A: Gauss na Escola Primaria" << endl; break;
case 2: system ("cls"); cout << "Problema C: Falta um!" << endl; break;
case 3: system ("cls"); cout << "Problema B: A Pontuacao do Campeonato Mudou!" << endl; break;
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
void Problema1() //Resolução problema 1
{
    int A, B, soma, casos, a;
    long total;
    char M;
    cout << "\nQuantos casos voce deseja analisar? ";
    cin >> casos;

    int caso = 1;
    do{
    cout << "\nForneca o primeiro e o ultimo numero inteiro do intervalo " << caso << ":" << endl;
    cin >> A >> B;

    total = 0;
    do{
        soma = total + A;
        A = A + 1;
        total = soma;
    }while (A <= B);

    cout << "\nA soma de todos os numeros do caso " << caso << ": " << total << endl;

    caso = caso + 1;
    }while(caso <= casos);
}
void Problema2() // REsolução problema 2
{
    int A,B,falta,x,z;

    cout << "\nOs valores presentes na faixa devem estar em ordem crescente e separados por um espaco!" << endl;
    cout << "Um dos valores nao deve ser inserido para o programa identificar qual!" << endl;
    cout << "Para finalizar digite 0 0!" << endl;

    do{
        cout << "\nDigite o primeiro e ultimo numero da faixa:" << endl;
        cin >> A >> B;
        if( A == 0 && B == 0) break;
        cout << "\nAgora digite os valores presentes da faixa:\n";

    x = A;
    do{
     cin >> z;
       if(z > x)
       {
         falta = z - 1;
         x = x + 1;
       }
     x = x + 1;
    }while(z < B);
    cout << "\nO valor que esta faltando e o " << falta << "!" << endl;
    }while(1);
}
int placar (int i, int j) // Pontos de cada partida
{
    int resultadoPartida = i - j;
    if (resultadoPartida < 0)
        resultadoPartida = 0;
    else
        resultadoPartida = resultadoPartida;
return resultadoPartida;
}
int jogo(int n) // Resultado dos jogos e placar final do time
{
    int J = 1, resultado = 0, total, i, j;
    char x;
    do{
        cin >> i; cin >> x; cin >>j;
        J = J + 1;
        resultado = resultado + placar(i,j);
    }while (J < n);

return resultado;
}
int times(int n) //  Cada time e resultado final do campeonato
{
    int time = 1, pontos, MaiorPont = 0, MenorPont = 0, MaiorTime, MenorTime;
    do {
        pontos = (jogo(n));
        if (time == 1)
        {
            MaiorTime = time;
            MenorTime = time;
            MaiorPont = pontos;
            MenorPont = pontos;
        }
        else if(pontos > MaiorPont)
             {
              MaiorPont = pontos;
              MaiorTime = time;
              }
             if (pontos < MenorPont)
              {
              MenorPont = pontos;
              MenorTime = time;
              }
        time = time + 1;
    }while (time <= n);
    cout << "\nO time " << MaiorTime << " foi o melhor com " << MaiorPont << " pontos" << endl;
    cout << "O time " << MenorTime << " foi o pior com " << MenorPont << " pontos" << endl;
}
void Problema3() //Resolução principal problema 3
{
    int m;
    cout << "\nQuantos times estavam no campeonato?  ";
    cin >> m;

    if (m >= 1 && m <= 16)
        cout << "\nCada time disputou " << m-1 << " jogos!" << endl;
        cout << "Escreva os resultados como (PxP) e separe os jogos por espaco!" << endl;
        cout << "Forneca os resultados dos jogos, sendo cada linha referente a um time:" << endl << endl;

times(m);
}
int main () // Função principal
{
    int Usuario, Saida;

    do{
    Usuario = menu();

    switch(Usuario){
    case 1: Problema1(); break;
    case 2: Problema2(); break;
    case 3: Problema3(); break;
    case 4: return 0;
    }
    Saida = menuSaida();
    }while(Saida == 1);
}
