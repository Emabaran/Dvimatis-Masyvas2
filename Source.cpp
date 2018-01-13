#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;
{

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
	return suma / n;
	return suma / m;
}

void Visu_Mokiniu_Vidurkiai(int n, double V[], int A[][Cn]) 

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
