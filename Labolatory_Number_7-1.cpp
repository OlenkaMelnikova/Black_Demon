// Labolatory_Number_7-1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
struct AUTOMOBILE
{
	char Model[64];
	char Power[32];
	char MaximumSpeed[32];
	int Track,City,Mixed;

};

int main(int argc, char* argv[])
{
	int n;
	AUTOMOBILE *pAutomobile;
	printf("Count of Automobile:\n");
	scanf_s("%d", &n);
	pAutomobile = new AUTOMOBILE[n];
	for (int i = 0; i<n; ++i)
	{
		printf("Automobile N=%d:\n",i+1);
		printf("Model : ");
		fflush(stdin); gets_s(pAutomobile[i].Model, 63);
		printf("Power : ");
		fflush(stdin); gets_s(pAutomobile[i].Power, 31);
		printf("MaximumSpeed : ");
		fflush(stdin); gets_s(pAutomobile[i].MaximumSpeed, 31);
		printf("Track : ");
		scanf_s("%d", &pAutomobile[i].Track);
		printf("City : "); 
		scanf_s("%d", &pAutomobile[i].City);
		printf("Mixed : "); 
		scanf_s("%d", &pAutomobile[i].Mixed);

	}
	FILE *pF;
	fopen_s(&pF, "MyAutomobile.dat", "wb");
	fwrite(&n, sizeof(int), 1, pF);
	fwrite(pAutomobile, sizeof(AUTOMOBILE), n, pF);
	fclose(pF);
	system("pause");
	return 0;
}


