#include <math.h>
#include "./headers/utils.h"


void swap(Cheltuiala** this, Cheltuiala** other) {
	Cheltuiala* temp = *this;
	*this = *other;
	*other = temp;
}

int compareZi(Cheltuiala* this, Cheltuiala* other) {
	if (this->ziua > other->ziua)
		return 1;
	else if (this->ziua < other->ziua)
		return -1;
	return 0;
}

int compareTip(Cheltuiala* this, Cheltuiala* other) {
	if (strcmp(this->tip, other->tip) > 0)
		return 1;
	else if (strcmp(this->tip, other->tip) < 0)
		return -1;
	return 0;
}

int compareSuma(Cheltuiala* this, Cheltuiala* other) {
	if (abs(this->suma - other->suma) < EPSILON)
		return 0;
	if (this->suma - other->suma > 0)
		return 1;
	return -1;
}

void selectionSort(ListaCheltuieli* listaCheltuieli, bool reversed, compareMethod compare) {
	for (unsigned int i = 0; i < listaCheltuieli->lungime - 1; i++)
		for (unsigned int j = i + 1; j < listaCheltuieli->lungime; j++)
			if (reversed == true) {
				if (compare(listaCheltuieli->cheltuieli[i], listaCheltuieli->cheltuieli[j]) == -1)
					swap(&listaCheltuieli->cheltuieli[i], &listaCheltuieli->cheltuieli[j]);
			}
			else {
				if (compare(listaCheltuieli->cheltuieli[i], listaCheltuieli->cheltuieli[j]) == 1)
					swap(&listaCheltuieli->cheltuieli[i], &listaCheltuieli->cheltuieli[j]);
			}
}