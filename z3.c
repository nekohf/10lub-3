#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

void print_title();
float area_trap(float a, float b, float c);
void draw_trap(int a, int b, int c, char d);
int get_top(int a, int b, double c);
int compare_trap(float a, float b);

int main() {
    setlocale(LC_CTYPE, "RUS");
    char c;
    int a, b, d, k, n;
    double g;

    print_title();

    do {
        printf("\n--- ГЛАВНОЕ МЕНЮ ---\n");
        printf("1. Вычислить площадь\n");
        printf("2. Показать определение\n");
        printf("3. Нарисовать фигуру\n");
        printf("0. Выйти из программы\n");
        printf("Выберите пункт меню: ");
        scanf("%d", &k);

        switch (k) {
        case 0:
            printf("Выход из программы. До свидания!\n");
            return 0;

        case 1:
        case 2:
        case 3:
            printf("\nВведите символ для рисования: ");
            scanf(" %c", &c);
            printf("Введите высоту: ");
            scanf("%d", &a);
            printf("Введите нижнее основание: ");
            scanf("%d", &b);
            printf("Введите угол (в градусах): ");
            scanf("%lf", &g);

            d = get_top(a, b, g);

            switch (d <= 0 || a <= 0) {
            case 1:
                printf("Ошибка: размеры слишком малы для заданного угла\n");
                break;
            case 0:
                switch (k) {
                case 1:
                    printf("\nПлощадь = %.2f\n", area_trap(d, b, a));
                    break;
                case 2:
                    printf("\nПрямоугольная трапеция - трапеция с одной боковой стороной, перпендикулярной основаниям\n");
                    break;
                case 3:
                    printf("\n");
                    draw_trap(a, b, d, c);
                    break;
                }
                break;
            }
            break;

        default:
            printf("Ошибка: неверный пункт меню. Попробуйте снова.\n");
            continue;
        }

        printf("\nПродолжить? (0 - вернуться в меню, другое число - выйти): ");
        scanf("%d", &n);
        
        switch (n) {
        case 0:
            break; 
        default:
            return 0; 
        }

    } while (1);

    return 0;
}

void print_title()
{
    printf("=====================================\n");
    printf(" ПРОГРАММА: ПРЯМОУГОЛЬНАЯ ТРАПЕЦИЯ\n");
    printf("=====================================\n");
}

float area_trap(float a, float b, float c) {
    return (a + b) / 2 * c;
}

void draw_trap(int a, int b, int c, char d)
{
    int s = b - c;
    for (int i = 0; i < a; i++) {
        int len = c + (a > 1 ? (i * s) / (a - 1) : 0);
        
        switch (i == a - 1) {
        case 1:
            len = b;
            break;
        case 0:
            break;
        }

        for (int j = 0; j < b; j++) {
            switch (j == 0 || (i == 0 && j < c) || (i == a - 1) || (j < len)) {
            case 1:
                printf("%c", d);
                break;
            case 0:
                printf(" ");
                break;
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
