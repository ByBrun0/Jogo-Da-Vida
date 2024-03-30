#include "LifeGame.hpp"
#include "File.hpp"
#include <fstream>

LifeGame::LifeGame()
{
}

void LifeGame::Play()
{
    File f;

    ofstream arq2 = f.apagarRelatorio(); // resetar o geracoes.mps

    f.fecharRelatorioEscrever(&arq2);

    cout << "Digite o numero de gerações que deseja: ";
    cin >> quant;
    analisarInput();
    for (int b = 0; b < quant; b++)
    {
        if (EndOfGame())
        {
            cout << "Fim Do Jogo, Obrigado Por Jogar\n";
            imprimirMatrizAtual();
            LimparVetor();
            exit(0);
        }
        cout << "Gerando " << numeroGeracao << " geração...\n\n";
        imprimirMatrizAtual();
        gerarProxGeracao();
        numeroGeracao++;
    }

    LimparVetor();
}

void LifeGame::setTam(int tam)
{
    this->tam = tam;
}

void LifeGame::analisarInput()
{
    File f = File();
    ifstream arq = f.abrirArquivoDeEntrada();

    arq.get(aux);
    setTam(aux - '0');
    arq.get(aux); // retirar o \n
    if (tam < 5)
    {
        cout << "O tamanho da matriz é menor do que o minimo exigido\n"; // verificar tamanho esta ideal
        exit(0);
    }

    string linha;

    while (getline(arq, linha))
    {
        vector<int> linha_matriz;
        istringstream iss(linha);
        int numero;

        // Lê números da linha e adiciona à matriz
        while (iss >> numero)
        {
            linha_matriz.push_back(numero);
        }

        matriz.push_back(linha_matriz);
    }

    preencherRelatorio();

    f.fecharArquivoDeEntrada(&arq);
}

void LifeGame::preencherRelatorio()
{
    File f;
    ofstream arq2 = f.abrirRelatorioEscrever();

    int elemento;
    arq2 << "Geracao " << numeroGeracao << ": \n";
    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
        {
            elemento = matriz[i][j];
            arq2 << elemento << " ";
        }
        arq2 << endl;
    }
    arq2 << endl;

    f.fecharRelatorioEscrever(&arq2);
}

void LifeGame::imprimirMatriz(vector<vector<int> > m)
{
    cout << "Matriz " << tam << "X" << tam << ":\n\n";

    for (int i = 0; i < tam; i++)
    {
        cout << "|";
        for (int j = 0; j < tam; j++)
        {
            cout << m[i][j] << " ";
        }
        cout << "|\n";
    }
    cout << endl;
}

void LifeGame::imprimirMatrizAtual()
{
    imprimirMatriz(matriz);
}

void LifeGame::gerarProxGeracao()
{
    int vizinhos = 0;
    for (int i = 0; i < tam; i++) // analise de numero de vizinhos //preenchendo o vetor auxiliar
    {
        for (int j = 0; j < tam; j++)
        {
            if (i > 0 && matriz[i - 1][j] == 1)
            {
                vizinhos++;
            }

            if (i < tam - 1 && matriz[i + 1][j] == 1)
            {
                vizinhos++;
            }

            if (j > 0 && matriz[i][j - 1] == 1)
            {
                vizinhos++;
            }

            if (j < tam - 1 && matriz[i][j + 1] == 1)
            {
                vizinhos++;
            }

            if (i > 0 && j > 0 && matriz[i - 1][j - 1] == 1)
            {
                vizinhos++;
            }

            if (i > 0 && j < tam - 1 && matriz[i - 1][j + 1] == 1)
            {
                vizinhos++;
            }

            if (i < tam - 1 && j > 0 && matriz[i + 1][j - 1] == 1)
            {
                vizinhos++;
            }

            if (i < tam - 1 && j < tam - 1 && matriz[i + 1][j + 1] == 1)
            {
                vizinhos++;
            }

            if (matriz[i][j] == 1)
            {
                if (vizinhos < 2 || vizinhos > 3)
                {

                    auxPop.push_back(0);
                }
                else
                {

                    auxPop.push_back(1);
                }
            }
            else
            {
                if (vizinhos == 3)
                {

                    auxPop.push_back(1);
                }
                else
                {
                    auxPop.push_back(0);
                }
            }

            vizinhos = 0;
        }
    }
    int k = 0;
    for (int i = 0; i < tam; i++) // atualizar a matriz

    {
        for (int j = 0; j < tam; j++)
        {

            matriz[i][j] = auxPop[k];
            k++;
        }
    }

    preencherRelatorio();

    auxPop.clear();
}

void LifeGame::LimparVetor()
{
    auxPop.clear();
    vetorPopulacao.clear();
    matriz.clear();
    matrizAux.clear();
}

bool LifeGame::EndOfGame()
{
    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
        {
            if (matriz[i][j] == 1)
            {
                return false;
            }
        }
    }

    return true;
}