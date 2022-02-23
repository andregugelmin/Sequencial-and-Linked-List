#pragma once
#include"ListaEncadeada.h"
using namespace std;

class MenuListaEncadeada
{
private:

	ListaEncadeada listaEncadeada;

public:
	MenuListaEncadeada();
	~MenuListaEncadeada();


	void armazenaDados(ListaEncadeada* lista, string fileName);

	void Inicializar();

	void inserirDadoInicio(ListaEncadeada* lista, string nome, int rg);
	void inserirDadoPosicaoN(ListaEncadeada* lista, string nome, int rg, int pos);
	void inserirDadoFinal(ListaEncadeada* lista, string nome, int rg);

	void removerDadoInicio(ListaEncadeada* lista);
	void removerDadoPosicaoN(ListaEncadeada* lista, int pos);
	void removerDadoFinal(ListaEncadeada* lista);

	void print(ListaEncadeada* lista);

	void menuArmazenar();
	void menuInserirDadoInicio();
	void menuInserirDadoPosicao();
	void menuInserirDadoFinal();
	void menuRemoverDadoInicio();
	void menuRemoverDadoPosicao();
	void menuRemoverDadoFinal();
	void menuProcurarRg();
	void menuPrintar();
	
	
	//Sort
	void menuSort();
};

