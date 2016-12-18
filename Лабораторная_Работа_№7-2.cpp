// Лабораторная_Работа_№7-2.cpp: определяет точку входа для консольного приложения.
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
struct List
{
	struct List *next;
	struct Automobile aut;
};
void push(struct List **head, struct Automobile p) {
	struct List *tmp = (List*)malloc(sizeof(List));
	tmp->aut = p;
	tmp->next = (*head);
	*head = tmp;
}
void clear(List *head) {
	while (head != NULL) {
		List * t = head->next;
		free(head);
		head = t;
	}
}
int main() {
	FILE *pF;
	struct List *head = NULL;
	int n(0);
	fopen_s(&pF, "Automobile.dat", "rb");
	if (pF == 0)
	{
		printf("Error, file not found");
		return 1;
	}
	fread(&n, sizeof(int), 1, pF);
	for (int i = 0; i < n; i++) {
		struct Automobile *p = (Automobile *)malloc(sizeof(Automobile));
		fread(p, sizeof(Automobile), 1, pF);
		push(&head, *p);
	}
	fclose(pF);
	for (List *pi = head; pi; pi = pi->next) {
		printf("%s. %s. %s, %d, %d, %d \n",
			pi->aut.Model, pi->aut.Power, pi->aut.MaximumSpeed,
			pi->aut.FuelConsumption[0], pi->aut.FuelConsumption[1], pi->aut.FuelConsumption[2]);
	}
	clear(head);
	system("pause");
	return 0;
}

