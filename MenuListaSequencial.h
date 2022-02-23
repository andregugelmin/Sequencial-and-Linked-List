#pragma once
#include "ListaSequencial.h"

class MenuListaSequencial
{
private:
	
	ListaSequencial listaSequencial;

public:
	MenuListaSequencial();
	~MenuListaSequencial();


	void armazenaDados(ListaSequencial* listaSeq, string fileName, unsigned int fileSize);

	void Inicializar();

	void inserirDadoInicio(ListaSequencial* listaSeq, string nome, int rg);
	void inserirDadoPosicaoN(ListaSequencial* listaSeq, string nome, int rg, int pos);
	void inserirDadoFinal(ListaSequencial* listaSeq, string nome, int rg);

	void removerDadoInicio(ListaSequencial* listaSeq);
	void removerDadoPosicaoN(ListaSequencial* listaSeq, int pos);
	void removerDadoFinal(ListaSequencial* listaSeq);

	void print(ListaSequencial* listaSeq);

	void menuArmazenar();
	void menuInserirDadoInicio();
	void menuInserirDadoPosicao();
	void menuInserirDadoFinal();
	void menuRemoverDadoInicio();
	void menuRemoverDadoPosicao();
	void menuRemoverDadoFinal();
	void menuProcurarDado();
	void menuPrintar();


	//Sort
	void menuSort();
};

