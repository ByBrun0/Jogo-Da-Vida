#ifndef LIFEGAME_HPP
#define LIFEGAME_HPP
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class LifeGame
{
private:
    int quant;
    int numeroGeracao = 1;
    vector<vector<int> > matriz;
    vector<vector<int> > matrizAux;
    vector<int> vetorPopulacao;
    vector<int> auxPop;
    int tam;
    char aux;

public:
    LifeGame();
    void setTam(int tam);
    void analisarInput();
    void preencherRelatorio();
    void imprimirMatriz(vector<vector<int> > m);
    void imprimirMatrizAtual();
    void gerarProxGeracao();
    void LimparVetor();
    bool EndOfGame();
    void Play();
};

#endif