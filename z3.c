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

        if (k == 0) {
            printf("Выход из программы. До свидания!\n");
            break;
        }

        if (k < 1 || k > 3) {
            printf("Ошибка: неверный пункт меню. Попробуйте снова.\n");
            continue;
        }

        printf("\nВведите символ для рисования: ");
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
            if (k == 1) {
                printf("\nПлощадь = %.2f\n", area_trap(d, b, a));
            }
            if (k == 2) {
                printf("\nПрямоугольная трапеция - трапеция с одной боковой стороной, перпендикулярной основаниям\n");
            }
            if (k == 3) {
                printf("\n");
                draw_trap(a, b, d, c);
            }
        }

        printf("\nПродолжить? (0 - вернуться в меню, другое число - выйти): ");
        scanf("%d", &n);
        if (n != 0) {
            break;
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
        if (i == a - 1) len = b;
        for (int j = 0; j < b; j++) {
            if (j == 0 || (i == 0 && j < c) || (i == a - 1) || (j < len)) {
                printf("%c", d);
            }
            else {
                printf(" ");
            }
        } printf("\n");
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
