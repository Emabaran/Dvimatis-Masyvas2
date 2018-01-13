#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;
const int Cn = 100;
const int Cm = 100;
const string CDfv = "Duomenys.txt";
const string CFrez = "Rezultatai.txt";

void Skaitymas(int P[][Cn], int & n, int & m);
double Mokinio_Vidurkis(int n, int eil, int A[][Cn]);
void Visu_Mokiniu_Vidurkiai(int n, double V[], int A[][Cn]);
double Testo_Vidurkis(int m, int eil, int A[][Cn]);
void Visu_Testu_Vidurkiai(int m, double T[], int A[][Cn]);
void Spausdinimas(int k, string antraste, double M[]);

int main() 
{
	int n, m;
	int A[Cn][Cm];
	double V[Cn], T[Cn];

	ofstream fr(CFrez);
	fr.close();

	Skaitymas( A,  n,   m) ;
	Visu_Mokiniu_Vidurkiai(m, V, A);
	Visu_Testu_Vidurkiai(n, T, A);

	Spausdinimas(n, "Mokiniu vidurkiai", V);
	Spausdinimas(m, "Testu vidurkiai", T);

	return 0;
}

void Skaitymas(int A[][Cn], int & n, int & m) 
{
	ifstream fd(CDfv);
	fd >> n >> m;
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++)
			fd >> A[i][j];
	}
}

double Mokinio_Vidurkis(int n, int eil, int A[][Cn])
{
	double suma = 0;
	for (int i = 0; i < n; i++) 
	{
		suma += A[eil][i];
	}
	return suma / n;
}

double Testo_Vidurkis(int m, int eil, int A[][Cn])
{
	double suma = 0;
	for (int i = 0; i < m; i++) 
	{
		suma += A[i][eil];
	}
	return suma / m;
}

void Visu_Mokiniu_Vidurkiai(int n, double V[], int A[][Cn]) 
{
	for (int i = 0; i < n; i++) 
		V[i] = Mokinio_Vidurkis(n, i, A);
}

void Visu_Testu_Vidurkiai(int m, double T[], int A[][Cn]) 
{
	for (int i = 0; i < m; i++) 
		T[i] = Mokinio_Vidurkis(m, i, A);
}

void Spausdinimas(int k, string antraste, double M[])
{
	ofstream fr(CFrez, ios::app);

	fr << antraste << endl;
	fr << "---------------------" << endl;
	fr << "Eil nr.      Vidurkis" << endl;
	fr << "-------------------" << endl;

	for (int i = 0; i < k; i++) 
	{
		fr << setw(4) << i+1 << setw(14) << M[i] << endl;
	}
	fr << "-------------------" << endl << endl;

	fr.close();
}
