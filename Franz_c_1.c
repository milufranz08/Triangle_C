#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "math.h"
#include <stdbool.h>

static void spaceToStr(int num) {

	if (num > 0) {
		for (int i = 1; i <= num; i++) {
			printf(" ");
		}
	}
}

static void starToStr(int num) {
	if (num > 0) {
		for (int i = 1; i <= num; i++) {
			printf("*");
		}
		printf("\n");
	}
}

static void makeTriangle(int answer) {
	int mainRow = 0;
	int spacing = 0;
	int counter = 0;
	char star = '*';

	if (answer == 1) {
		printf("*\n");
		answer = 0;
	}
	else {
		mainRow = answer + (answer - 1);
		spacing = mainRow/2;
		spaceToStr(spacing);
		printf("%c\n", star);
		answer--;
		counter++;
	}

	while (answer != 0) {
		if (answer == 1) {
			starToStr(mainRow);
			answer--;
		}
		else {
			spacing--;
			spaceToStr(spacing);
			printf("%c", star);
			spaceToStr(counter);
			printf("%c\n", star);

			counter = counter + 2;
			answer--;
		}
	}
}

int main() {

	bool ask = true;

	while (ask == true) {
		int answer;
		printf("Enter number of rows (from 1 to 20):\n");
		scanf("%d", &answer);

		if (answer >= 1 && answer <= 20) {
			ask = false;
			makeTriangle(answer);
		}
	}

	return 0;
}