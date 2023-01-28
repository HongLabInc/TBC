#include <stdio.h>
#include <conio.h>


int main() {

    char c;

    while ((c = _getch()) != '\n') {

        printf("%d ", (int)c);

    }

    printf("\n");

}