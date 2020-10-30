/*���� �������������� ���������� ������� ������� n. ���������
������������������ �������������� ����� a1,...an �� �������: ���� � i-��
������ ������� �������, ������������� ������� ���������, �����������, �� ai
����� ����� ��������� i-�� ������, �������������� ������� ��������������
��������, ����� ai ����� ����� ��������� ��������� i-�� ������, ������� ��
������� ���������������� ��������. ������ ��� ������� ��������
�����������. ��������� ������� �� �������.*/

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
    int razmer;

    razmer = vv_razm();
    matrica = memory(razmer);
    vv_masiva(matrica, razmer);
    output(matrica, razmer);

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
    printf("������� ����������� �������: ");
    scanf_s("%d", &razmer);
    printf("\n");

    return razmer;
}

void vv_masiva(int** matrica, int razmer) {
    int i, j;
    printf("���� ������� :\n");
    for (i = 0; i < razmer; i++) {
        for (j = 0; j < razmer; j++) {
            printf("������� ������� a[%d][%d]: ", i + 1, j + 1);
            scanf_s("%d", &matrica[i][j]);
        }
        printf("\n");
    }
}
void output(int** matrica, int razmer) {
    int i, j;
    printf("���� �������:\n");
    for (i = 0; i < razmer; i++) {
        for (j = 0; j < razmer; j++) {
            printf("%4d", matrica[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}