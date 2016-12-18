// Лабораторная_Работа_№7-1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
struct Automobile
{
	char Model[64];
	char Power[32];
	char MaximumSpeed[32];
	int FuelConsumption[3];
};

int main(int argc, char* argv[])
{
	int n;
	printf("Count of Automobile:\n");
	scanf_s("%d", &n);
	struct Automobile *p = (Automobile*)malloc(n * sizeof(Automobile));
	for (int i = 0; i<n; i++)
	{
		printf_s("Model ");
		scanf_s("%s", p[i].Model, 64);
		printf_s("Power ");
		scanf_s("%s", p[i].Power, 32);
		printf_s("MaximumSpeed ");
		scanf_s("%s", p[i].MaximumSpeed, 32);
		printf_s("FuelConsumption ");
		scanf_s("%d %d %d ", &p[i].FuelConsumption[0], &p[i].FuelConsumption[1], &p[i].FuelConsumption[2]);
	}
	FILE *pF;
	fopen_s(&pF, "Automobile.dat", "wb");
	fwrite(&n, sizeof(int), 1, pF);
	fwrite(p, sizeof(Automobile), n, pF);
	fclose(pF);
	system("pause");
	return 0;
}

