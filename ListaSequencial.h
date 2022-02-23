#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

using namespace std;

class ListaSequencial
{
private:
	struct Pessoa {
		std::string nome = "";
		unsigned int rg = 0;
	};
	unsigned int numElem;
	unsigned int sizeList;
public:
	ListaSequencial();
	~ListaSequencial();
	Pessoa* lista = nullptr;
	
	void iniciar();
	void expandList(unsigned int size);
	void checkSize(int n);
	void armazenaDados(string fileName, unsigned int fileSise);
	void inserirDadoInicio(string nome, int rg);
	void inserirDadoPosicaoN(string nome, int rg, int pos);
	void inserirDadoFinal(string nome, int rg);
	void removerDadoInicio();
	void removerDadoPosicaoN(int pos);
	void removerDadoFinal();
	void procurarDado(int rg);
	void iniciarBuscaBinaria(int rg);
	int procuraBinariaDado(int rg, int low, int high);
	void print();

	void clearList();


	//Sorts

	void selectionSort();
	void insertionSort();
	void bubbleSort();
	void shellSort();
	void initQuickSort();
	void quickSort(int iniV, int finalV, int& m, int& c);
	void initMergeSort();
	void merge(int left, int mid, int right, Pessoa paux[], unsigned int& m, unsigned int& c);
	void mergeSort(int low, int high, Pessoa paux[], unsigned int& m, unsigned int& c);
};

