#ifndef FILE_HPP
#define FILE_HPP
#include <fstream>
#include <iostream>
#include <stdlib.h>
using namespace std;
class File
{
public:
    ifstream abrirArquivoDeEntrada();
    ofstream abrirRelatorioEscrever();
    ifstream abrirRelatorioLer();
    ofstream apagarRelatorio();
    void fecharArquivoDeEntrada(ifstream *arq);
    void fecharRelatorioLer(ifstream *arq2);
    void fecharRelatorioEscrever(ofstream *arq2);
};

#endif