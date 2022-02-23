#include "ListaEncadeada.h"

ListaEncadeada::ListaEncadeada()
{
    tamanhoLista = 0;
	pPessoaPrim = nullptr;
	pPessoaAtual = nullptr;
}

ListaEncadeada::~ListaEncadeada()
{
    Pessoa* paux1, * paux2;

    paux1 = pPessoaPrim;
    paux2 = paux1;

    while (paux1 != NULL)
    {
        paux2 = paux1->proximo;
        delete (paux1);
        paux1 = paux2;
    }

	pPessoaPrim = nullptr;
	pPessoaAtual = nullptr;
}

void ListaEncadeada::setNome(Pessoa* pessoa, std::string nome)
{
   
	pessoa->nome = nome;  
    
}

void ListaEncadeada::setRg(Pessoa* pessoa, int rg)
{
	pessoa->rg = rg;
}

void ListaEncadeada::setProximo(Pessoa* pessoaAtual, Pessoa* pessoaProx)
{
	pessoaAtual->proximo = pessoaProx;
}

void ListaEncadeada::armazenaDados(std::string fileName)
{    
    auto tempo_inicial = std::chrono::high_resolution_clock::now();
    std::ifstream myfile(fileName);
    //std::string nome, tempString;
    int rg;
    size_t pos = 0;
    std::string line;

    if (myfile.is_open())
    {
        while (getline(myfile, line)) {      
            
            pos = line.find(',');
            //nome = line.substr(0, pos);
            //tempString = line.substr(pos + 1, line.length());
            //rg = stoi(tempString);
            Pessoa* pessoa = new Pessoa;
            pessoa->nome = line.substr(0, pos);
            pessoa->rg = stoi(line.substr(pos + 1, line.length()));
            //setNome(pessoa, nome);
            //setRg(pessoa, rg);

            if (pPessoaPrim == nullptr)
            {
                pPessoaPrim = pessoa;
                pPessoaAtual = pessoa;
            }
            else
            {
                setProximo(pPessoaAtual, pessoa);
                pPessoaAtual = pessoa;
            }
            tamanhoLista++;
        }        
        myfile.close();
    }
    else {
        std::cout << "Unable to open file" << std::endl;
    }

    auto tempo_final = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> ms_double = tempo_final - tempo_inicial;
    std::cout << "Tempo executado: " << ms_double.count() << "ms" << std::endl;
    system("pause");
}
void ListaEncadeada::inserirDadoInicio(std::string nome, int rg)
{
    auto tempo_inicial = std::chrono::high_resolution_clock::now();
    Pessoa* pessoa = new Pessoa;
    setNome(pessoa, nome);
    setRg(pessoa, rg);
    
    if (pPessoaPrim == nullptr)
    {
        pPessoaPrim = pessoa;
        pPessoaAtual = pessoa;
    }
    else
    {
        setProximo(pessoa, pPessoaPrim);
        pPessoaPrim = pessoa;
    }

    tamanhoLista++;
    std::cout << "Dado inserido na lista:" << std::endl;
    std::cout << "Nome: " << pessoa->nome << std::endl;
    std::cout << "Rg: " << pessoa->rg << std::endl;
    std::cout << "Posicao: 1" << std::endl;
    std::cout << "C(n): 1" << std::endl;
    std::cout << "M(n): 4" << std::endl;
    auto tempo_final = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> ms_double = tempo_final - tempo_inicial;
    std::cout << "Tempo executado: " << ms_double.count() << "ms" << std::endl;
    system("pause");
}

void ListaEncadeada::inserirDadoPosicaoN(std::string nome, int rg, int pos)
{
    auto tempo_inicial = std::chrono::high_resolution_clock::now();
    int i=1, m =0;    
    Pessoa* pessoaAux, *pessoaAnt = nullptr;
    pessoaAux = pPessoaPrim;

    while (i < pos) {
        if (pessoaAux == nullptr) {
            std::cout << "A lista não possui tantas posições" << std::endl;
            break;
        }
        else {
            pessoaAnt = pessoaAux;
            pessoaAux = pessoaAux->proximo;
            i++;
            m += 2;
        }
    }
    if (i == pos) {
        Pessoa* pessoa = new Pessoa;
        setNome(pessoa, nome);
        setRg(pessoa, rg);
        setProximo(pessoa, pessoaAux);
        pessoaAnt->proximo = pessoa;
        tamanhoLista++;
        m += 4;

        std::cout << "Dado inserido na lista:" << std::endl;
        std::cout << "Nome: " << pessoa->nome << std::endl;
        std::cout << "Rg: " << pessoa->rg << std::endl;
        std::cout << "Posicao: "<< pos << std::endl;
        std::cout << "C(n): "<< i+1 << std::endl;
        std::cout << "M(n): " << m << std::endl;
        auto tempo_final = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> ms_double = tempo_final - tempo_inicial;
        std::cout << "Tempo executado: " << ms_double.count() << "ms" << std::endl;
        system("pause");
    }
}

void ListaEncadeada::inserirDadoFinal(std::string nome, int rg)
{
    auto tempo_inicial = std::chrono::high_resolution_clock::now();
    int m = 0;
    Pessoa* pessoa = new Pessoa;
    setNome(pessoa, nome);
    setRg(pessoa, rg);
    m += 2;

    if (pPessoaPrim == nullptr) {
        pPessoaPrim = pessoa;
        pPessoaAtual = pessoa;
        m += 2;
    }
    else {
        setProximo(pPessoaAtual, pessoa);
        pPessoaAtual = pessoa;
        m += 2;
    }
    
    tamanhoLista++;


    std::cout << "Dado inserido na lista:" << std::endl;
    std::cout << "Nome: " << pessoa->nome << std::endl;
    std::cout << "Rg: " << pessoa->rg << std::endl;
    std::cout << "Posicao: " << tamanhoLista << std::endl;
    std::cout << "C(n): 1" << std::endl;
    std::cout << "M(n): " << m << std::endl;
    auto tempo_final = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> ms_double = tempo_final - tempo_inicial;
    std::cout << "Tempo executado: " << ms_double.count() << "ms" << std::endl;
    system("pause");
}


void ListaEncadeada::removerDadoInicio()
{
    auto tempo_inicial = std::chrono::high_resolution_clock::now();
    Pessoa* paux= nullptr;
    int m = 0;

    if (pPessoaPrim != nullptr) {
        std::cout << "Dado removido da lista:" << std::endl;
        std::cout << "Nome: " << pPessoaPrim->nome << std::endl;
        std::cout << "Rg: " << pPessoaPrim->rg << std::endl;
        std::cout << "Posicao: 1" << std::endl;

        paux = pPessoaPrim->proximo;
        delete(pPessoaPrim);
        pPessoaPrim = paux;
        tamanhoLista--;        
        m += 2;
    }
    else {
        std::cout << "A lista nao possui dados." << std::endl << std::endl;
    }

    std::cout << "C(n): 1" << std::endl;
    std::cout << "M(n): " << m << std::endl;

    auto tempo_final = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> ms_double = tempo_final - tempo_inicial;
    std::cout << "Tempo executado: " << ms_double.count() << "ms" << std::endl;
    system("pause");
}

void ListaEncadeada::removerDadoPosicaoN(int pos)
{
    auto tempo_inicial = std::chrono::high_resolution_clock::now();
    Pessoa* paux1 = nullptr, * paux2 = nullptr;
    int i = 0, m=0, c= 0;
    paux1 = pPessoaPrim;

    while (i<pos-1 && paux1!=nullptr)
    {
        paux2 = paux1;
        paux1 = paux2->proximo;
        i++;
        c++;
        m += 2;
    }
    if (paux1!=nullptr) {
        paux2->proximo = paux1->proximo;
        m++;
        if (paux1 == pPessoaAtual) {
            pPessoaAtual = paux2;
            m++;
        }
        c++;

        std::cout << "Dado removido da lista:" << std::endl;
        std::cout << "Nome: " << paux1->nome << std::endl;
        std::cout << "Rg: " << paux1->rg << std::endl;
        std::cout << "Posicao: "<< pos << std::endl;

        delete(paux1);

        tamanhoLista--;

        
    }
    else {
        std::cout << "A lista nao possui tantos dados." << std::endl;
    }
    c++;
    std::cout << "C(n): " << c << std::endl;
    std::cout << "M(n): " << m << std::endl;

    auto tempo_final = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> ms_double = tempo_final - tempo_inicial;
    std::cout << "Tempo executado: " << ms_double.count() << "ms" << std::endl;
    system("pause");
}


void ListaEncadeada::removerDadoFinal()
{
    auto tempo_inicial = std::chrono::high_resolution_clock::now();
    Pessoa* paux1=nullptr, * paux2 = nullptr;    
    int c=0, m=0;
    if (pPessoaPrim != nullptr){
        paux1 = pPessoaPrim;
        m++;
        while (paux1 != pPessoaAtual)
        {
            paux2 = paux1;
            paux1 = paux2->proximo;
            m += 2;
            c++;
        }

        std::cout << "Dado removido da lista:" << std::endl;
        std::cout << "Nome: " << paux1->nome << std::endl;
        std::cout << "Rg: " << paux1->rg << std::endl;
        std::cout << "Posicao: " << tamanhoLista << std::endl;

        delete(paux1);
        tamanhoLista--;

        if (paux2 != nullptr) {
            paux2->proximo = nullptr;
            pPessoaAtual = paux2;
            m += 2;
        }
    }
    else {
        std::cout << "A lista nao possui dados." << std::endl;
    }
    c++;

    std::cout << "C(n): " << c << std::endl;
    std::cout << "M(n): " << m << std::endl;
    auto tempo_final = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> ms_double = tempo_final - tempo_inicial;
    std::cout << "Tempo executado: " << ms_double.count() << "ms" << std::endl;
    system("pause");

}

void ListaEncadeada::procurarRg(int r)
{
    auto tempo_inicial = std::chrono::high_resolution_clock::now();
    Pessoa* paux=nullptr;
    int i = 1, c = 0, m = 0;
    if (pPessoaPrim != nullptr) {
        paux = pPessoaPrim;
        m++;
        while (paux != nullptr) {
            if (paux->rg == r) {
                std::cout << "Rg encontrado:" << std::endl;
                std::cout << "Nome: " << paux->nome << std::endl;
                std::cout << "Rg: " << paux->rg << std::endl;
                std::cout << "Posicao: " << i << std::endl;
                break;
            }
            else {
                paux = paux->proximo;
                m++;
            }
            i++;
            c += 2;
        }
       
    }
    c++;
    if (paux == nullptr) {
        std::cout << "Rg nao encontrado:" << std::endl;
    }
    c++;

    std::cout << "C(n): " << c << std::endl;
    std::cout << "M(n): " << m << std::endl;
    auto tempo_final = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> ms_double = tempo_final - tempo_inicial;
    std::cout << "Tempo executado: " << ms_double.count() << "ms" << std::endl;
    system("pause");

}

void ListaEncadeada::printLista()
{
    Pessoa* paux1, * paux2;

    paux1 = pPessoaPrim;
    paux2 = paux1;

    while (paux1 != NULL)
    {
        paux2 = paux1->proximo;
        std::cout << paux1->nome << ", " << paux1->rg << std::endl;
        paux1 = paux2;
    }
}

