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
	int FCTrack;
	int FCCity;
	int FCMixed;

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
		printf_s("Automobile N=%d:\n", i + 1);
		printf_s("Model : ");
		fflush(stdin); gets_s(pAutomobile[i].Model, 63);
		printf_s("Power : ");
		fflush(stdin); gets_s(pAutomobile[i].Power, 31);
		printf_s("MaximumSpeed : ");
		fflush(stdin); gets_s(pAutomobile[i].MaximumSpeed, 31);
		printf("FCTrack : ");
		scanf_s("%d", &pAutomobile[i].FCTrack);
		printf("FCCity : "); 
		scanf_s("%d", &pAutomobile[i].FCCity);
		printf("FCMixed : "); 
		scanf_s("%d", &pAutomobile[i].FCMixed);

	}
	FILE *pF;
	fopen_s(&pF, "Automobile.dat", "wb");
	fwrite(&n, sizeof(int), 1, pF);
	fwrite(pAutomobile, sizeof(AUTOMOBILE), n, pF);
	fclose(pF);
	system("pause");
	return 0;
}


