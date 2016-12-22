// Labolatory_Number_7-2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
struct AUTOMOBILE
{
	char Model[64];
	char Power[32];
	char MaximumSpeed[32];
	int Track, City, Mixed;

};

int main(int argc, char* argv[])
{
	int n;
	AUTOMOBILE *pAutomobile;
	FILE *pF;
	fopen_s(&pF, "MyAutomobile.dat", "rb");

	if (pF == 0)
	{
		printf("Error,file not found");
		return 1;
	}
	fread(&n, sizeof(int), 1, pF);
	pAutomobile = new AUTOMOBILE[n];
	fread(pAutomobile, sizeof(AUTOMOBILE), n, pF);
	fclose(pF);
	for (int i = 0; i<n; ++i)
		printf("%s. %s. %s, %d. %d. %d.\n", pAutomobile[i].Model,
		pAutomobile[i].Power, pAutomobile[i].MaximumSpeed, pAutomobile[i].Track, pAutomobile[i].City, pAutomobile[i].Mixed);
	system("pause");
	return 0;
}

