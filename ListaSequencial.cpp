#include "ListaSequencial.h"


ListaSequencial::ListaSequencial(): numElem(0), sizeList(0)
{     
}
ListaSequencial::~ListaSequencial()
{
    if(lista) delete[] lista;
}

void ListaSequencial::iniciar()
{
    int tam;
    cout << "Qual tamanho da lista deseja iniciar?" << endl;
    cin >> tam;
    sizeList = tam;
    lista = new Pessoa[tam];
}

void ListaSequencial::expandList(unsigned int size)
{
    Pessoa* listaTemp = new Pessoa[size];
    for (unsigned int i = 0; i < sizeList; i++) {
        listaTemp[i] = lista[i];
    }
    
    delete[] lista;
    lista = listaTemp;
    sizeList = size;
}

void ListaSequencial::checkSize(int n)
{
    if (numElem + n > sizeList) {  //Checa se é necessario alocar mais memoria pra lista        
        expandList(numElem + n);
        cout << "Aumentando lista" << endl;
    }
}


void ListaSequencial::armazenaDados(string fileName, unsigned int fileSise)
{
    ifstream myfile(fileName);
    string nome, tempString;
    int rg, i = numElem;
    size_t pos = 0;
          

   checkSize(fileSise);        
    
   auto tempo_inicial = chrono::high_resolution_clock::now();
    if (myfile.is_open())
    {
        cout << "Armazenando" << endl;
        string line;
        
        while (getline(myfile, line)) {
            pos = line.find(',');         
            lista[i].nome = line.substr(0, pos);
            lista[i].rg = stoi(line.substr(pos + 1, line.length()));   
            numElem++;
            i++;
        }
        myfile.close();
    }
    else {
        cout << "Unable to open file" << endl;
    }
    
    auto tempo_final = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> ms_double = tempo_final - tempo_inicial;
    cout << "Tempo executado: " << ms_double.count() << "ms" << endl;
    system("pause");
}


void ListaSequencial::inserirDadoPosicaoN(string nome, int rg, int pos)
{
    int m = 0, c=0;
    auto tempo_inicial = chrono::high_resolution_clock::now();

    checkSize(1);

    int i;

    numElem++;

    for (i = numElem; i > pos; i--) {
        lista[i-1] = lista[i-2];
        m++;
        c++;
    }
    cout << "Dados inseridos na lista, " << endl;
    cout << "Nome: " << nome << endl;
    cout << "Rg: " << rg << endl;
    cout << "Posicao: " << pos << endl;    

    lista[pos-1].nome = nome;
    m++;
    lista[pos-1].rg = rg;
    m++;

    cout << "C(n): " << c << endl;
    cout << "M(n): " << m << endl;
    auto tempo_final = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> ms_double = tempo_final - tempo_inicial;
    cout << "Tempo executado: " << ms_double.count() << "ms" << endl;
    system("pause");
}

void ListaSequencial::inserirDadoInicio(string nome, int rg)
{
    inserirDadoPosicaoN(nome, rg, 1);
}

void ListaSequencial::inserirDadoFinal(string nome, int rg)
{
    inserirDadoPosicaoN(nome, rg, numElem + 1);
}

void ListaSequencial::removerDadoPosicaoN(int pos)
{
    int i, m=0, c=0;
    auto tempo_inicial = chrono::high_resolution_clock::now();
    if (pos <= numElem && numElem>0) {
        

        cout << "Dados removidos da lista, " << endl;
        cout << "Nome: " << lista[pos-1].nome << endl;
        cout << "Rg: " << lista[pos - 1].rg << endl;
        cout << "Posicao: " << pos << endl;

        if (numElem > 1 && pos<numElem) {
            for (i = pos; i < numElem; i++) {
                lista[i - 1] = lista[i];
                m++;
            }
            c++;
        }        
        numElem--;                      

    }
    else {
        cout << "A lista nao possui tantos elementos" << endl;
    }
    c++;

    cout << "C(n): " << c << endl;
    cout << "M(n): " << m << endl;

    auto tempo_final = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> ms_double = tempo_final - tempo_inicial;
    cout << "Tempo executado: " << ms_double.count() << "ms" << endl;

    system("pause");
}

void ListaSequencial::removerDadoInicio()
{
    removerDadoPosicaoN(1);
}

void ListaSequencial::removerDadoFinal()
{
    removerDadoPosicaoN(numElem);
}

void ListaSequencial::procurarDado(int rg)
{
    int i, c= 0, m=0;

    auto tempo_inicial = chrono::high_resolution_clock::now();
    for (int i = 0; i < numElem; i++) {
        if (lista[i].rg == rg) {
            cout << "Rg encontrado na lista, " << endl;
            cout << "Nome: " << lista[i].nome << endl;
            cout << "Rg: " << lista[i].rg << endl;
            cout << "Posicao: " << i+1 << endl;          
            break;
        }
        c++;
    }

    cout << "C(n): " << c << endl;
    cout << "M(n): " << m << endl;
    auto tempo_final = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> ms_double = tempo_final - tempo_inicial;
    cout << "Tempo executado: " << ms_double.count() << "ms" << endl;
    system("pause");

}

void ListaSequencial::iniciarBuscaBinaria(int rg)
{
    int b = procuraBinariaDado(rg, 0, numElem - 1);
}


int ListaSequencial::procuraBinariaDado(int rg, int low, int high) {
	int l = low;
	int h = high;
	while (l<=h) {
        int mid;
        mid = l + (h - l) / 2;
        if (lista[mid].rg == rg) {
            cout << "Rg encontrado na lista, " << endl;
            cout << "Nome: " << lista[mid].nome << endl;
            cout << "Rg: " << lista[mid].rg << endl;
            cout << "Posicao: " << mid + 1 << endl;
            system("pause");
            return 1;
        }
        else if (lista[mid].rg < rg) {
            l = mid+1;
        }
		else{
			h = mid-1;
		}        
    }
    
    cout << "Elemento não encontrado" << endl;
    system("pause");
    return 1;
}

void ListaSequencial::print()
{
    if (lista != nullptr) {
        for (int i = 0; i < numElem; i++) {
            std::cout << lista[i].nome << ", " << lista[i].rg << endl;
        }
    }
    else {
        cout << "Lista nula" << endl;        
    }
    
}

void ListaSequencial::clearList()
{
    int tam;
    Pessoa* paux = nullptr;
    if (lista) {
        paux = lista;
        delete[] paux;
    }
    numElem = 0;
    lista = nullptr;
    cout << "Qual o novo tamanho da lista?" << endl;
    cin >> tam;
    sizeList = tam;
    lista = new Pessoa[tam];
}

void ListaSequencial::selectionSort()
{
    int i, j, indiceMenor;
    int c, m;
    i = 0;
    c = 0;
    m = 0;

    auto tempo_inicial = chrono::high_resolution_clock::now();
    
    while (lista[i].rg) {
        indiceMenor = i;
        m++;
        for (j = i + 1; j < numElem; j++) {
            if (lista[j].rg < lista[indiceMenor].rg) {
                indiceMenor = j;
                
                m++;
            }
            c+=2;
        }
        if (indiceMenor != i) {
            swap(lista[i], lista[indiceMenor]);
            m += 3;
        }
        c+=2;
        i++;
    }
    

    cout << "C(n): " << c << endl;
    cout << "M(n): " << m << endl;
    auto tempo_final = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> ms_double = tempo_final - tempo_inicial;
    cout << "Tempo executado: " << ms_double.count() << "ms" << endl;
    system("pause");

}

void ListaSequencial::insertionSort()
{
    int i, j, m, c;
    c = 0;
    m = 0;
    auto tempo_inicial = chrono::high_resolution_clock::now();

    for (i = 1; i < numElem; i++) {
        j = i;
        m++;

        while (j > 0 && lista[j - 1].rg > lista[j].rg) {
            swap(lista[j], lista[j - 1]);
            j--;
            m += 3;
            c++;
       }        
        c++;
    }

    cout << "C(n): " << c << endl;
    cout << "M(n): " << m << endl;
    auto tempo_final = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> ms_double = tempo_final - tempo_inicial;
    cout << "Tempo executado: " << ms_double.count() << "ms" << endl;
    system("pause");

}

void ListaSequencial::bubbleSort()
{
    int i, j, m, c ;
    j = 1;
    c = 0;
    m = 0;

    auto tempo_inicial = chrono::high_resolution_clock::now();

    for(j=0; j<numElem; j++){
        for (i = 1; i < numElem-j; i++) {
            if (lista[i - 1].rg > lista[i].rg) {
                swap(lista[i], lista[i - 1]);
                m += 3;
            }
            c+=2;
        }   
        c++;
    }    

    cout << "C(n): " << c << endl;
    cout << "M(n): " << m << endl;
    auto tempo_final = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> ms_double = tempo_final - tempo_inicial;
    cout << "Tempo executado: " << ms_double.count() << "ms" << endl;
    system("pause");

}

void ListaSequencial::shellSort()
{
    int gap, j, i, c=0, m=0;
    Pessoa temp;

    auto tempo_inicial = chrono::high_resolution_clock::now();

    for (gap = numElem / 2; gap > 0; gap /= 2) {
        for (j = gap; j < numElem; j++) {
            temp = lista[j];
            m++;
            for (i = j; (i >= gap) && (lista[i - gap].rg > temp.rg); i -= gap) {
                lista[i] = lista[i - gap];
                m++;
                c++;
            }
            lista[i] = temp;
            m++;
            c++;
        }
        c++;
    }

    cout << "C(n): " << c << endl;
    cout << "M(n): " << m << endl;
    auto tempo_final = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> ms_double = tempo_final - tempo_inicial;
    cout << "Tempo executado: " << ms_double.count() << "ms" << endl;
    system("pause");
}

void ListaSequencial::initQuickSort()
{

    auto tempo_inicial = chrono::high_resolution_clock::now();

    int m = 0;
    int c = 0;

    quickSort(0, numElem-1, m, c);

    cout << "C(n): " << c << endl;
    cout << "M(n): " << m << endl;
    auto tempo_final = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> ms_double = tempo_final - tempo_inicial;
    cout << "Tempo executado: " << ms_double.count() << "ms" << endl;
    system("pause");
}

void ListaSequencial::quickSort(int iniV, int finalV, int& m, int& c)
{
    int i, j, pivo;
    i = iniV;
    j = finalV;
    pivo = lista[(i + j) / 2].rg;

    do {
        while (lista[i].rg < pivo) {
            i += 1;
            m++;
            c++;
        }
        while (lista[j].rg > pivo) {
            j -= 1;
            m++;
            c++;
        }
        if (i <= j) {
            swap(lista[i], lista[j]);
            i += 1;
            j -= 1;
            m += 5;
        }
        c += 2;
    } while (i < j);
    if (j > iniV) quickSort(iniV, j, m, c);
    c++;
    if (i < finalV) quickSort(i, finalV, m, c);
    c++;

}
void ListaSequencial::initMergeSort()
{
    auto tempo_inicial = chrono::high_resolution_clock::now();

    unsigned int m = 0;
    unsigned int c = 0;
    Pessoa* paux = nullptr;
    paux = new Pessoa[numElem];
    
    mergeSort(0, numElem-1 , paux, m, c);

    cout << "C(n): " << c << endl;
    cout << "M(n): " << m << endl;
    auto tempo_final = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> ms_double = tempo_final - tempo_inicial;
    cout << "Tempo executado: " << ms_double.count() << "ms" << endl;
    system("pause");    
    
    if(paux) delete[] paux;
}

void ListaSequencial::merge(int left, int mid, int right, Pessoa paux[], unsigned int& m, unsigned int& c) {
    int i, j, k;
    i = left;
    k = left;
    j = mid + 1;
    while (i <= mid && j <= right) {
        if (lista[i].rg < lista[j].rg) {
            paux[k] = lista[i];
            k++;
            i++;
            m += 3;
        }
        else {
            paux[k] = lista[j];
            k++;
            j++;
            m += 3;
        }
        c += 2;
    }
    while (i <= mid) {
        paux[k] = lista[i];
        k++;
        i++;
        m += 3;
        c++;
    }
    while (j <= right) {
        paux[k] = lista[j];
        k++;
        j++;
        m += 3;
        c++;
    }
    for (i = left; i < k; i++) {
        lista[i] = paux[i];
        m++;
        c++;
    }	
   
    
}

void ListaSequencial::mergeSort(int low, int high, Pessoa paux[], unsigned int& m, unsigned int& c) {
    int mid;
   
    if (low<high) {
        mid = (high + low) / 2;
        m++;
        mergeSort(low, mid, paux, m, c);
        mergeSort(mid+1, high, paux, m, c);
        merge(low, mid, high, paux, m, c);
    }
    c++;
}




