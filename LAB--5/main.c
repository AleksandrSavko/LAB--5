/*Дана действительная квадратная матрица порядка n. Построить
последовательность действительных чисел a1,...an по правилу: если в i-ой
строке матрицы элемент, принадлежащий главной диагонали, отрицателен, то ai
равно сумме элементов i-ой строки, предшествующих первому отрицательному
элементу, иначе ai равно сумме последних элементов i-ой строки, начиная по
порядку неотрицательного элемента. Память под массивы отводить
динамически. Программу разбить на функции.*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int** memory(int);
int vv_razm();
void vv_masiva(int**, int);
void output(int**, int);

int main() {
    setlocale(LC_ALL, "RUS");


	int** matrica;
    int* posled_a;
    int razmer;
    int i = 0;
    int j = 0;
    int otm = 0;

    razmer = vv_razm();
    matrica = memory(razmer);
    vv_masiva(matrica, razmer);
    output(matrica, razmer);
    
    posled_a = (int*)calloc(razmer, sizeof(int));

    for (i = 0; i < razmer; i++)
    {
        j = i;
        if (matrica[i][j] < 0)
        {
            for (int j = 0; j < razmer; j++)
            {
                if (matrica[i][j] > 0)
                {
                    posled_a[i] += matrica[i][j];
                }else break;
            }
        }
        j = i;
        if (matrica[i][j] > 0)
        {
            for (int j = 0; j < razmer; j++)
            {
                if (matrica[i][j] < 0)
                {
                    otm = j + 1;
                    break;
                }
                for (int k = otm; k < razmer; k++)
                {
                    posled_a[i] += matrica[i][j];
                }
            }
        }
        
    }
    for (int i = 0; i < razmer; i++) 
    {
        printf("Последовательность A[%d]=%d\n", i + 1, posled_a[i]);
    }

}

int ** memory(int razmer)
{
    int i;
    int** matrica = (int**)calloc(razmer, sizeof(int*));
    for (i = 0; i < razmer; i++) {
        matrica[i] = (int*)calloc(razmer, sizeof(int));
    }

    return matrica;
}

int vv_razm() {
    int razmer;
    printf("Введите размерность матрицы: ");
    scanf_s("%d", &razmer);
    printf("\n");

    return razmer;
}

void vv_masiva(int** matrica, int razmer) {
    int i, j;
    printf("Ввод массива :\n");
    for (i = 0; i < razmer; i++) {
        for (j = 0; j < razmer; j++) {
            printf("Введите элемент a[%d][%d]: ", i + 1, j + 1);
            scanf_s("%d", &matrica[i][j]);
        }
        printf("\n");
    }
}
void output(int** matrica, int razmer) {
    int i, j;
    printf("Ваша матрица:\n");
    for (i = 0; i < razmer; i++) {
        for (j = 0; j < razmer; j++) {
            printf("%4d", matrica[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}