#include "File.hpp"

using namespace std;

ifstream File::abrirArquivoDeEntrada()
{
    ifstream arquivo;
    arquivo.open("datasets/input.mps"); // abrir arquivo

    if (!arquivo)
    {
        cerr << "Erro ao abrir o arquivo." << endl;
        exit(0);
    }

    return arquivo;
}

ofstream File::apagarRelatorio()
{
    ofstream arquivo2;
    arquivo2.open("datasets/geracoes.mps");
    if (!arquivo2)
    {
        cerr << "Erro ao abrir o arquivo 2." << endl; // verificar o arquivo
        exit(0);
    }
    return arquivo2;
}

ofstream File::abrirRelatorioEscrever()
{
    ofstream arquivo2;

    arquivo2.open("datasets/geracoes.mps", ios::app);

    if (!arquivo2)
    {
        cerr << "Erro ao abrir o arquivo 2." << endl; // verificar o arquivo
        exit(0);
    }
    return arquivo2;
}
ifstream File::abrirRelatorioLer()
{
    ifstream arquivo2;

    arquivo2.open("datasets/geracoes.mps");

    if (!arquivo2)
    {
        cerr << "Erro ao abrir o arquivo 2." << endl; // verificar o arquivo
        exit(0);
    }
    return arquivo2;
}
void File::fecharArquivoDeEntrada(ifstream *arq)
{
    arq->close();
}

void File::fecharRelatorioLer(ifstream *arq2)
{
    arq2->close();
}
void File::fecharRelatorioEscrever(ofstream *arq2)
{
    arq2->close();
}