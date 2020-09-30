// sem3lab2(structs).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <locale.h>
#include <stdlib.h>

#define clin while (getchar() != '\n')

typedef struct {
	char name[200];
	int grain;// граммов зерен кофе
	int milk;// мл молока в кофе (1мл = 1г)
	int sugar;// граммов сахара в кофе
	int size;// объем стакана кофе
} coffe;

char* String(int a) {
	char* intInString = (char*)calloc(200, sizeof(char));
	for (int i = 0; a > 0; i++, a/=10) {
		intInString[i] = a % 10 + '0';
	}
	return _strrev(intInString);
}

void strSum(char* str1, char* str2) {

	for (int i = 0; str1[i] != 0; i++) {
		if (str1[i + 1] == 0) {
			str1[i + 1] = '+';
			for (int j = 0; str2[j] != 0; j++) {
				str1[i + j + 2] = str2[j];
				str1[i + j + 2 + 1] = 0;
			}
			break;
		}
	}
}

void init(coffe* type) {
	type->name[0] = '\0';
	type->grain = 0;
	type->milk = 0;
	type->sugar = 0;
	type->size = 0;
}

void read(coffe* type) {
	printf("введите название кофе: "); scanf_s("%s", type->name, 20); clin;
	printf("введите колличество граммов кофе: "); scanf_s("%d", &type->grain); clin;
	printf("введите колличество мл молока: "); scanf_s("%d", &type->milk); clin;
	printf("введите колличество граммов сахара: "); scanf_s("%d", &type->sugar); clin;
	printf("введите объем стака кофе в мл: "); scanf_s("%d", &type->size); clin;
}
void display(coffe type) {
	if (type.name[0] != 0 && type.grain != 0 && type.milk != 0 && type.sugar != 0 && type.size != 0) {
		printf("%s:\nкрепкость: %d%%,%d мл молока, %d грамм сахара, общий объем: %d мл.\n", type.name, type.grain * 100 / type.size, type.milk, type.sugar, type.size);
	}
	else {
		printf("\nпроверьте правильность заполнения полей.\n");
	}
}

void add(coffe* first, coffe* second) {
	strSum(first->name, second->name);
	first->grain += second->grain;
	first->milk += second->milk;
	first->sugar += second->sugar;
	first->size += second->size;
}

void addSugar(coffe* type) {
	type->sugar += 10;
}
void compare(coffe first, coffe second) {
	printf("%-10s: %-10s %s\n", "название", first.name, second.name);
	printf("%-10s: %-10s %s\n", "крепкость", String(first.grain * 100 / first.size), String(second.grain * 100 / second.size));
	printf("%-10s: %-10s %s\n", "крепкость", String(first.size), String(second.size));
}

int main() {
	setlocale(LC_ALL, "rus");
	coffe* latte;
	latte = (coffe*)calloc(1, sizeof(coffe));
	init(latte);
	read(latte);
	display(*latte);

	coffe* americano;
	americano = (coffe*)calloc(1, sizeof(coffe));
	init(americano);
	read(americano);
	display(*americano);

	compare(*latte, *americano);

	addSugar(americano);

	add(latte, americano);

	display(*latte);
	printf("%s", String(120));

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
