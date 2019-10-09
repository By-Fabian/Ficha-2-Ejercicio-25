#include <iostream>
#include <vector>
#include <random>

using namespace std;

int main() {
    int filas=0;
    int columnas=0;
    int menor=0;


    cout<<"N=";
    cin>>filas;
    cout<<"M=";
    cin>>columnas;

    int **matriz=0;
    matriz=new int*[filas];
    for (int i = 0; i <filas; ++i) {
        matriz[i]=new int [columnas];
    }

    random_device dev;
    uniform_int_distribution<int> dis(1,10);

    for (int j = 0; j <filas; ++j) {
        for (int i = 0; i <columnas ; ++i) {
            matriz[j][i]=dis(dev);
        }
    }

    cout<<endl;

    cout<<"Matriz"<<endl;
    for (int k = 0; k <filas ; ++k) {
        for (int i = 0; i <columnas ; ++i) {
            cout<<matriz[k][i];
            cout<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    for (int j = 0; j <filas; ++j) {
        for (int i = 0; i <columnas ; ++i) {
            if(matriz[j][i]<matriz[j][i+1]){
                swap(matriz[j][i],matriz[j][i+1]);
            }
        }
    }

    cout<<"Matriz Ordenada"<<endl;
    for (int k = 0; k <filas ; ++k) {
        for (int i = 0; i <columnas ; ++i) {
            cout<<matriz[k][i];
            cout<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    vector<int> repetidos;

    for (int l = 0; l <filas ; ++l) {
        repetidos.push_back(matriz[l][columnas-1]);
    }

    cout<<endl;

    for (int i1 = 0; i1 <filas ; ++i1) {
        cout<<repetidos[i1];
    }

    cout<<endl;

    for (int m = 0; m <filas-1 ; ++m) {
        if(repetidos[m]<repetidos[m+1]){
            swap(repetidos[m],repetidos[m+1]);
        }
    }

    cout<<endl;

    for (int i1 = 0; i1 <filas ; ++i1) {
        cout<<repetidos[i1];
    }

    cout<<endl;
    menor=repetidos[filas-1];

    vector<int> columnas_repetidas;

    int veces_repetidas=0;

    for (int n = 0; n <filas ; ++n) {
        if(matriz[n][columnas-1]==menor){
            columnas_repetidas.push_back(n+1);
            veces_repetidas=veces_repetidas+1;
        }
    }

    cout<<"Respuesta"<<endl;
    cout<< "Minimo Valor: "<<menor<<endl;
    cout<<"COLUMNAS: ";

    for (int k1 = 0; k1 <veces_repetidas ; ++k1) {
        cout<<columnas_repetidas[k1];
        cout<<" ";
    }
    cout<<endl;


    return 0;
}