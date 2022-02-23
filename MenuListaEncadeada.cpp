#include "MenuListaEncadeada.h"
MenuListaEncadeada::MenuListaEncadeada()
{
    Inicializar();
}

MenuListaEncadeada::~MenuListaEncadeada()
{
}

void MenuListaEncadeada::armazenaDados(ListaEncadeada* lista, string fileName)
{
    lista->armazenaDados(fileName);
}

void MenuListaEncadeada::Inicializar()
{
    int opt = -1;

    system("cls");
    cout << "   Qual opcao de menu deseja abrir?" << endl;
    cout << "   1 - Armazenar listas" << endl;
    cout << "   2 - Inserir dados no inicio" << endl;
    cout << "   3 - Inserir dados em posicao N" << endl;
    cout << "   4 - Inserir dados no final" << endl;
    cout << "   5 - Remover dados do inicio" << endl;
    cout << "   6 - Remover dados da posicao N" << endl;
    cout << "   7 - Remover dados do final" << endl;
    cout << "   8 - Procurar rg na lista" << endl;
    cout << "   9 - Printar listas" << endl;
    cout << "   10 - Sortear lista" << endl;
    cout << "   11 - Fechar programa" << endl;
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
        menuProcurarRg();
        break;
    case 9:
        menuPrintar();
        break;
    case 10:
        menuSort();
        break;
    case 11:
        break;
    default:
        Inicializar();
        break;
    }

}

void MenuListaEncadeada::inserirDadoInicio(ListaEncadeada* lista, string nome, int rg)
{
    lista->inserirDadoInicio(nome, rg);
}

void MenuListaEncadeada::inserirDadoPosicaoN(ListaEncadeada* lista, string nome, int rg, int pos)
{
    lista->inserirDadoPosicaoN(nome, rg, pos);
}

void MenuListaEncadeada::inserirDadoFinal(ListaEncadeada* lista, string nome, int rg)
{
    lista->inserirDadoFinal(nome, rg);
}

void MenuListaEncadeada::removerDadoInicio(ListaEncadeada* lista)
{

    lista->removerDadoInicio();
}

void MenuListaEncadeada::removerDadoPosicaoN(ListaEncadeada* lista, int pos)
{
    lista->removerDadoPosicaoN(pos);
}

void MenuListaEncadeada::removerDadoFinal(ListaEncadeada* lista)
{
    lista->removerDadoFinal();
}

void MenuListaEncadeada::print(ListaEncadeada* lista)
{
    lista->printLista();
}

void MenuListaEncadeada::menuArmazenar()
{
    int opt = -1;


    system("cls");
    cout << "   Qual lista deseja armazenar?" << endl;
    cout << "   1 - NomeRG10" << endl;
    cout << "   2 - NomeRG100 " << endl;
    cout << "   3 - NomeRG1K" << endl;
    cout << "   4 - NomeRG1M " << endl;
    cout << "   5 - NomeRG100M " << endl;
    cout << "   6 - Voltar" << endl;
    cin >> opt;

    switch (opt)
    {
    case 1:
        armazenaDados(&listaEncadeada, "NomeRG10.txt");
        break;
    case 2:
        armazenaDados(&listaEncadeada, "NomeRG100.txt");
        break;
    case 3:
        armazenaDados(&listaEncadeada, "NomeRG1K.txt");
        break;
    case 4:
        armazenaDados(&listaEncadeada, "NomeRG1M.txt");
        break;
    case 5:
        armazenaDados(&listaEncadeada, "NomeRG100M.txt");
        break;

    default:
        break;
    }


    system("cls");
    Inicializar();

}

void MenuListaEncadeada::menuInserirDadoInicio()
{
    int opt = -1;
    string _nome = "";
    int _rg = 0;

    system("cls");

    cout << "Digite o nome que deseja inserir" << endl;
    cin >> _nome;
    cout << "Digite o rg que deseja inserir" << endl;
    cin >> _rg;
    inserirDadoInicio(&listaEncadeada, _nome, _rg);

    system("cls");

    Inicializar();

}

void MenuListaEncadeada::menuInserirDadoPosicao()
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

    inserirDadoPosicaoN(&listaEncadeada, _nome, _rg, pos);
    system("cls");

    Inicializar();

}

void MenuListaEncadeada::menuInserirDadoFinal()
{
    int opt = -1;
    string _nome = "";
    int _rg = 0;

    system("cls");

    cout << "Digite o nome que deseja inserir" << endl;
    cin >> _nome;
    cout << "Digite o rg que deseja inserir" << endl;
    cin >> _rg;
    inserirDadoFinal(&listaEncadeada, _nome, _rg);

    system("cls");

    Inicializar();

}

void MenuListaEncadeada::menuRemoverDadoInicio()
{
    removerDadoInicio(&listaEncadeada);

    system("cls");

    Inicializar();
}

void MenuListaEncadeada::menuRemoverDadoPosicao()
{
    int pos;

    system("cls");
    cout << "Qual posicao deseja remover?" << endl;
    cin >> pos;

    removerDadoPosicaoN(&listaEncadeada, pos);

    system("cls");

    Inicializar();
}

void MenuListaEncadeada::menuRemoverDadoFinal()
{
    removerDadoFinal(&listaEncadeada);

    system("cls");

    Inicializar();
}

void MenuListaEncadeada::menuProcurarRg()
{
    int rg;
    system("cls");
    cout << "Qual rg deseja procurar?" << endl;
    cin >> rg;

    listaEncadeada.procurarRg(rg);

    system("cls");

    Inicializar();
}

void MenuListaEncadeada::menuPrintar()
{
    int opt = -1;


    system("cls");
    print(&listaEncadeada);

    cout << endl;
    system("pause");

    Inicializar();
}


void MenuListaEncadeada::menuSort()
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
        listaEncadeada.selectionSort();
        break; 
    case 2:
        listaEncadeada.insertionSort();
        break;
    case 3:
        listaEncadeada.bubbleSort();
        break;
    case 4:
        listaEncadeada.shellSort();
        break;
    case 5:
        listaEncadeada.initQuickSort();
        break;
    case 6:
        listaEncadeada.initMergeSort();
        break;
    default:
        break;
    }


    system("cls");
    Inicializar();
}
