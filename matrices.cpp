//Calculadora de matrices
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

void suma();
void resta();
void multi();
void divi();

int main(){
	int selec;
	char seles;
	do{
		cout<<"Bienbenido a la calculadora de matrices\n\n";
		cout<<"Menu de opociones\n";
		cout<<"1.Sumar matrices\n";
		cout<<"2.Restar matrices\n";
		cout<<"3.Multiplicar matrices\n";
		cout<<"4.Dividir matirces\n";
		cin>>selec;
		 switch(selec){
		 	case 1:
		 		suma();
		 	break;
			case 2:
				resta();
			break;
			case 3:
				multi();
			break;
			case 4:
				divi();
			break;
			
			cout<<"Quieres hacer otra operacion? s/n";
			cin>>seles;	
		 }
	}while(seles=='S' || seles=='s');
}


void suma(){
	int filas, columnas;

    cout << "Introduzca el número de filas de las matrices: ";
    cin >> filas;
    cout << "Introduzca el número de columnas de las matrices: ";
    cin >> columnas;

    int matriz1[filas][columnas], matriz2[filas][columnas], suma[filas][columnas];

    cout << "Ingrese los elementos de la primera matriz:\n";
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << "Elemento [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matriz1[i][j];
        }
    }

    cout << "Ingrese los elementos de la segunda matriz:\n";
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << "Elemento [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matriz2[i][j];
        }
    }

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            suma[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }

    cout << "La matriz resultante es:\n";
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << suma[i][j] << " ";
        }
        cout << "\n";
    }
}


void resta(){
	int filas, columnas;

    cout << "Introduzca el número de filas de las matrices: ";
    cin >> filas;
    cout << "Introduzca el número de columnas de las matrices: ";
    cin >> columnas;

    int matriz1[filas][columnas], matriz2[filas][columnas], resta[filas][columnas];

    cout << "Ingrese los elementos de la primera matriz:\n";
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << "Elemento [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matriz1[i][j];
        }
    }

    cout << "Ingrese los elementos de la segunda matriz:\n";
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << "Elemento [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matriz2[i][j];
        }
    }

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            resta[i][j] = matriz1[i][j] - matriz2[i][j];
        }
    }

    cout << "La matriz resultante es:\n";
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << resta[i][j] << " ";
        }
        cout << "\n";
    }
}


void multi(){
	int F1, C1, F2, C2;

    cout << "Introduzca el número de filas de la primera matriz: ";
    cin >> F1;
    cout << "Introduzca el número de columnas de la primera matriz: ";
    cin >> C1;
    cout << "Introduzca el número de filas de la segunda matriz: ";
    cin >> F2;
    cout << "Introduzca el número de columnas de la segunda matriz: ";
    cin >> C2;

    if (C1 != F2) {
        cout << "No se pueden multiplicar estas matrices.\n";
    }


    int matriz1[F1][C1], matriz2[F2][C2], resultado[F1][C2];

    for (int i = 0; i < F1; i++) {
        for (int j = 0; j < C2; j++) {
            resultado[i][j] = 0;
        }
    }

    cout << "Ingrese los elementos de la primera matriz:\n";
    for (int i = 0; i < F1; i++) {
        for (int j = 0; j < C1; j++) {
            cout << "Elemento [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matriz1[i][j];
        }
    }

    cout << "Ingrese los elementos de la segunda matriz:\n";
    for (int i = 0; i < F2; i++) {
        for (int j = 0; j < C2; j++) {
            cout << "Elemento [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matriz2[i][j];
        }
    }

    for (int i = 0; i < F1; i++) {
        for (int j = 0; j < C2; j++) {
            for (int k = 0; k < C1; k++) {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }

    cout << "La matriz resultante es:\n";
    for (int i = 0; i < F1; i++) {
        for (int j = 0; j < C2; j++) {
            cout << resultado[i][j] << " ";
        }
        cout << "\n";
    }
}

const int MAX = 10;


float determinant(float matrix[MAX][MAX], int n) {
    float det = 0;
    float submatrix[MAX][MAX];
    if (n == 2)
        return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
    else {
        for (int x = 0; x < n; x++) {
            int subi = 0;
            for (int i = 1; i < n; i++) {
                int subj = 0;
                for (int j = 0; j < n; j++) {
                    if (j == x)
                        continue;
                    submatrix[subi][subj] = matrix[i][j];
                    subj++;
                }
                subi++;
            }
            det = det + (pow(-1, x) * matrix[0][x] * determinant(submatrix, n - 1));
        }
    }
    return det;
}


void inverse(float matrix[MAX][MAX], float inverseMatrix[MAX][MAX], int n) {
    float det = determinant(matrix, n);
    float adj[MAX][MAX];
    if (det == 0) {
        cout << "La matriz no tiene inversa\n";
        return;
    }
    if (n == 1) {
        inverseMatrix[0][0] = 1 / matrix[0][0];
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            float submatrix[MAX][MAX];
            int subi = 0;
            for (int k = 0; k < n; k++) {
                if (k == i)
                    continue;
                int subj = 0;
                for (int l = 0; l < n; l++) {
                    if (l == j)
                        continue;
                    submatrix[subi][subj] = matrix[k][l];
                    subj++;
                }
                subi++;
            }
            adj[j][i] = pow(-1, i + j) * determinant(submatrix, n - 1);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inverseMatrix[i][j] = adj[i][j] / det;
        }
    }
}


void multiply(float matrix1[MAX][MAX], float matrix2[MAX][MAX], float result[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}


void divi() {
    int n;
    cout << "Introduzca el tamaño de las matrices cuadradas: ";
    cin >> n;

    float matriz1[MAX][MAX], matriz2[MAX][MAX], inversa[MAX][MAX], resultado[MAX][MAX];


    cout << "Ingrese los elementos de la primera matriz:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Elemento [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matriz1[i][j];
        }
    }


    cout << "Ingrese los elementos de la segunda matriz:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Elemento [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matriz2[i][j];
        }
    }


    inverse(matriz2, inversa, n);

 
    multiply(matriz1, inversa, resultado, n);


    cout << "La matriz resultante es:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << resultado[i][j] << " ";
        }
        cout << "\n";
    }
}
