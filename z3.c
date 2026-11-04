#define M_PI 3.14159265358979323846
#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

float area_trap(float a, float b, float c)
{
    return (a + b) / 2 * c;
}

void draw_trap(int a, int b, int c, char d)
{
    int s = b - c;
    for (int i = 0; i < a; i++) {
        int len = c + (a > 1 ? (i * s) / (a - 1) : 0);
        if (i == a - 1) len = b;
        for (int j = 0; j < b; j++) {
            if (j == 0 || (i == 0 && j < c) || (i == a - 1) || (j == len - 1)) {
                printf("%c", d);
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int get_top(int a, int b, double c)
{
    return b - (int)(a / tan(c * M_PI / 180.0));
}

int compare_trap(float a, float b)
{
    return (int)(a - b);
}

int main()
{
    setlocale(LC_CTYPE, "RUS");
    char c;
    int a, b, d, k, n;
    double g;

    do {
        printf("Введите символ для рисования: ");
        scanf(" %c", &c);
        printf("Введите высоту: ");
        scanf("%d", &a);
        printf("Введите нижнее основание: ");
        scanf("%d", &b);
        printf("Введите угол (в градусах): ");
        scanf("%lf", &g);
        d = get_top(a, b, g);
        if (d <= 0 || a <= 0) {
            printf("Ошибка: размеры слишком малы для заданного угла\n");
        }
        else {
            printf("1 - площадь\n2 - определение\n3 - рисунок\n");
            scanf("%d", &k);
            if (k == 1) {
                printf("Площадь = %.2f\n", area_trap(d, b, a));
            }
            if (k == 2) {
                printf("Прямоугольная трапеция - трапеция с одной боковой стороной, перпендикулярной основаниям\n");
            }
            if (k == 3) {
                draw_trap(a, b, d, c);
            }
        }
        printf("Продолжить? (0 - нет, другое число - да): ");
        scanf("%d", &n);
    } while (n != 0);

    return 0;
}
