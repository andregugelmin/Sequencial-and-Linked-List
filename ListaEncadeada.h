#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>  
#include <chrono>

class ListaEncadeada
{
private:
    struct Pessoa {
        std::string nome = "";
        int rg = 0;
        Pessoa* proximo = nullptr;
    };

    Pessoa* pPessoaPrim;
    Pessoa* pPessoaAtual;
    int tamanhoLista;

public:
    ListaEncadeada();
    ~ListaEncadeada(); 

    void setNome(Pessoa* pessoa, std::string nome);
    void setRg(Pessoa* pessoa, int rg);
    void setProximo(Pessoa* pessoaAtual, Pessoa* pessoaProx);
    void armazenaDados(std::string fileName);
    void inserirDadoInicio(std::string nome, int rg);
    void inserirDadoPosicaoN(std::string nome, int rg, int pos);
    void inserirDadoFinal(std::string nome, int rg);
    void removerDadoInicio();
    void removerDadoPosicaoN(int pos);
    void removerDadoFinal();
    void procurarRg(int r);
    void printLista();
};

