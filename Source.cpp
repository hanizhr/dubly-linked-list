#include<stdio.h>
#include<conio.h>

int main() {
	int n;
	scanf_s("%d", &n);
	int c = 0,sw=0;
	for (int i = 2; i < 1000; i++) {
		for (int j = 2; j <= (i / 2); j++) {
			if (i%j == 0) {
				sw = 1;
			}
		}
		if (sw == 0) {
			c++;
		}
		sw = 0;
		if (c == n) {
			printf("%d", i);
			break;
		}

	}
	_getch();
	return 0;
}
