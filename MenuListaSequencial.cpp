#include "MenuListaSequencial.h"

MenuListaSequencial::MenuListaSequencial()
{
    listaSequencial.iniciar();
	Inicializar();
}

MenuListaSequencial::~MenuListaSequencial()
{
}

void MenuListaSequencial::armazenaDados(ListaSequencial* listaSeq, string fileName, unsigned int fileSize)
{
	listaSeq->armazenaDados(fileName, fileSize);
}

void MenuListaSequencial::Inicializar()
{
    int opt = -1;
    system("cls");
    cout << "   Qual opcao de menu deseja abrir?" << endl;
    cout << "   1 - Armazenar arquivo na lista" << endl;
    cout << "   2 - Inserir dados no inicio" << endl;
    cout << "   3 - Inserir dados em posicao N" << endl;
    cout << "   4 - Inserir dados no final" << endl;
    cout << "   5 - Remover dados do inicio" << endl;
    cout << "   6 - Remover dados da posicao N" << endl;
    cout << "   7 - Remover dados do final" << endl;
    cout << "   8 - Procurar rg na lista" << endl;
    cout << "   9 - Printar lista" << endl;
    cout << "   10 - Sortear lista" << endl;
    cout << "   11 - Reiniciar lista" << endl;
    cout << "   12 - Fechar programa" << endl;
    cout << endl;
    cin >> opt;

    switch (opt)
    {
    case 1:
        menuArmazenar();
        break;
    case 2:
        menuInserirDadoInicio();
        break;
    case 3:
        menuInserirDadoPosicao();
        break;
    case 4:
        menuInserirDadoFinal();
        break;
    case 5:
        menuRemoverDadoInicio();
        break;
    case 6:
        menuRemoverDadoPosicao();
        break;
    case 7:
        menuRemoverDadoFinal();
        break;
    case 8:
        menuProcurarDado();
        break;
    case 9:
        menuPrintar();
        break;
    case 10:
        menuSort();
        break;
    case 11:
        system("cls");
        listaSequencial.clearList();
        Inicializar();
        break;
    case 12:
        break;
    default:
        Inicializar();
        break;
    }
}

void MenuListaSequencial::inserirDadoInicio(ListaSequencial* listaSeq, string nome, int rg)
{
    listaSeq->inserirDadoInicio(nome, rg);
}

void MenuListaSequencial::inserirDadoPosicaoN(ListaSequencial* listaSeq, string nome, int rg, int pos)
{
    listaSeq->inserirDadoPosicaoN(nome, rg, pos);
}

void MenuListaSequencial::inserirDadoFinal(ListaSequencial* listaSeq, string nome, int rg)
{
    listaSeq->inserirDadoFinal(nome, rg);
}

void MenuListaSequencial::removerDadoInicio(ListaSequencial* listaSeq)
{
    listaSeq->removerDadoInicio();
}

void MenuListaSequencial::removerDadoPosicaoN(ListaSequencial* listaSeq, int pos)
{
    listaSeq->removerDadoPosicaoN(pos);
}

void MenuListaSequencial::removerDadoFinal(ListaSequencial* listaSeq)
{
    listaSeq->removerDadoFinal();
}

void MenuListaSequencial::print(ListaSequencial* listaSeq)
{
    listaSeq->print();
}

void MenuListaSequencial::menuArmazenar()
{
    int opt = -1;


    system("cls");
    cout << "   Qual lista deseja armazenar?" << endl;
    cout << "   1 - NomeRG10" << endl;
    cout << "   2 - NomeRG100 " << endl;
    cout << "   3 - NomeRG10K" << endl;
    cout << "   4 - NomeRG1M " << endl;
    cout << "   5 - NomeRG100M " << endl;
    cout << "   6 - Voltar" << endl;
    cin >> opt;

    switch (opt)
    {
    case 1:
        armazenaDados(&listaSequencial, "NomeRG10.txt", 10);
        break;
    case 2:
        armazenaDados(&listaSequencial, "NomeRG100.txt", 100);
        break;
    case 3:
        armazenaDados(&listaSequencial, "NomeRG10K.txt", 1000);
        break;
    case 4:
        armazenaDados(&listaSequencial, "NomeRG1M.txt", 1000000);
        break;
    case 5:
        armazenaDados(&listaSequencial, "NomeRG100M.txt", 11900000);
        break;

    default:
        break;
    }


    system("cls");
    Inicializar();
}

void MenuListaSequencial::menuInserirDadoInicio()
{
    int opt = -1;
    string _nome = "";
    int _rg = 0;

    system("cls");

    cout << "Digite o nome que deseja inserir" << endl;
    cin >> _nome;
    cout << "Digite o rg que deseja inserir" << endl;
    cin >> _rg;
    inserirDadoInicio(&listaSequencial, _nome, _rg);

    system("cls");

    Inicializar();
}

void MenuListaSequencial::menuInserirDadoPosicao()
{
    string _nome = "";
    int _rg = 0, pos = 0;

    system("cls");

    cout << "Digite o nome que deseja inserir" << endl;
    cin >> _nome;
    cout << "Digite o rg que deseja inserir" << endl;
    cin >> _rg;
    cout << "Digite a posicao que deseja inserir" << endl;
    cin >> pos;

    inserirDadoPosicaoN(&listaSequencial, _nome, _rg, pos);
    system("cls");

    Inicializar();
}

void MenuListaSequencial::menuInserirDadoFinal()
{
    int opt = -1;
    string _nome = "";
    int _rg = 0;

    system("cls");

    cout << "Digite o nome que deseja inserir" << endl;
    cin >> _nome;
    cout << "Digite o rg que deseja inserir" << endl;
    cin >> _rg;
    inserirDadoFinal(&listaSequencial, _nome, _rg);

    system("cls");

    Inicializar();
}

void MenuListaSequencial::menuRemoverDadoInicio()
{
    removerDadoInicio(&listaSequencial);

    system("cls");

    Inicializar();
}

void MenuListaSequencial::menuRemoverDadoPosicao()
{
    int pos;

    system("cls");
    cout << "Qual posicao deseja remover?" << endl;
    cin >> pos;

    removerDadoPosicaoN(&listaSequencial, pos);

    system("cls");

    Inicializar();
}

void MenuListaSequencial::menuRemoverDadoFinal()
{
    removerDadoFinal(&listaSequencial);

    system("cls");

    Inicializar();
}

void MenuListaSequencial::menuProcurarDado()
{
    int rg, opt;

    system("cls");

    cout << "Qual rg deseja procurar" << endl;

    cin >> rg;

    system("cls");

    cout << "   Qual busca deseja fazer?" << endl;
    cout << "   1 - Busca sequencial" << endl;
    cout << "   2 - Busca binaria " << endl;    

    cin >> opt;

    system("cls");

    switch (opt)
    {
    case 1:
        listaSequencial.procurarDado(rg);
        break;
    case 2:
        listaSequencial.iniciarBuscaBinaria(rg);
        break;   

    default:
        break;
    }  
 
    Inicializar();
}

void MenuListaSequencial::menuPrintar()
{
    system("cls");
    print(&listaSequencial);

    cout << endl;
    system("pause");

    Inicializar();
}

void MenuListaSequencial::menuSort()
{
    int opt = -1;


    system("cls");
    cout << "   Qual tipo de ordenacao deseja usar?" << endl;
    cout << "   1 - Selection Sort" << endl;
    cout << "   2 - Insertion Sort" << endl;
    cout << "   3 - Bubble Sort" << endl;
    cout << "   4 - Shell Sort" << endl;
    cout << "   5 - Quick Sort" << endl;
    cout << "   6 - Merge Sort" << endl;
    cout << "   7 - Voltar" << endl;
    cin >> opt;

    switch (opt)
    {
    case 1:
        listaSequencial.selectionSort();
        break; 
    case 2:
        listaSequencial.insertionSort();
        break;
    case 3:
        listaSequencial.bubbleSort();
        break;
    case 4:
        listaSequencial.shellSort();
        break;
    case 5:
        listaSequencial.initQuickSort();
        break;
    case 6:
        listaSequencial.initMergeSort();
        break;
    default:
        break;
    }


    system("cls");
    Inicializar();
}
