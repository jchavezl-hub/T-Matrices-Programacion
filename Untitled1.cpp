#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main() {
    string empresas[5] = {"Microsoft", "Apple", "Google", "Warner", "Disney"};

    ifstream datos2023("input/ingresos-2023.csv");
    ifstream datos2024("input/ingresos-2024.csv");
    ifstream datos2025("input/ingresos-2025.csv");
    ofstream totales("output/totales.csv");

    int datos[3][5][12];
    
    string linea;
	string valor;

    int fila = 0;
    while (getline(datos2023, linea)) {
        stringstream ss2023(linea);
        int columna = 0;
        while (getline(ss2023, valor, ',')) {
            datos[0][fila][columna] = stoi(valor);
            columna++;
        }
        fila++;
    }

    fila = 0;
    while (getline(datos2024, linea)) {
        stringstream ss2024(linea);
        int columna = 0;
        while (getline(ss2024, valor, ',')) {
            datos[1][fila][columna] = stoi(valor);
            columna++;
        }
        fila++;
    }

    fila = 0;
    while (getline(datos2025, linea)) {
        stringstream ss2025(linea);
        int columna = 0;
        while (getline(ss2025, valor, ',')) {
            datos[2][fila][columna] = stoi(valor);
            columna++;
        }
        fila++;
    }

    totales << "Empresa,2023,2024,2025,Total" << endl;

    for (int empresa = 0; empresa < 5; empresa++) {
        int totalGeneral = 0;
        totales << empresas[empresa];

        for (int year = 0; year < 3; year++) {
            int totalYear = 0;
            for (int mes = 0; mes < 12; mes++) {
                totalYear += datos[year][empresa][mes];
            }
            totales << "," << totalYear;
            totalGeneral += totalYear;
        }
        totales << "," << totalGeneral << endl;
    }

    totales.close();
    cout << "Archivo totales.csv creado correctamente" << endl;
    return 0;
}
