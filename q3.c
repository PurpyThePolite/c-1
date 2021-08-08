#include<stdio.h>
#include<stdlib.h>

typedef struct {

	int subnum;
	char name[100];

}subfield;

typedef struct {

	int num;
	char name[100];
	subfield sublist[9];

}field;

void subread(field* p, int n, int subN) {
    //int n�� �����ڸ���(��з�), subN�� ������ ���� 
    for (int a = 0; a < 9; a++) {
        if (p[n].sublist[a].subnum == subN) {
            printf("++++++++++++++++++++++++++++++++++++\n");
            printf("%d, %s�� å�� ã���ô� ����!", subN, p[n].sublist[a].name);
            break;
        }
    }
}

void read(field* p) {

    int N = 0;
    int n = 0;
    int subN = 0;
    int temp = 0;
    int subsubN = 0;
    printf("��ȣ�� �Է����ּ���: \n");
    scanf("%d", &N);

    if (N == 0 || N % 100 < 10 || N % 100 == 0) {
        if (N % 100 == 0) {
            n = N / 100;
        }
        else
            n = N;
        printf("���� �߿��� � �Һо߷� ���� �����ʴϱ�?\n");
        printf("++++++++++++++++++++++++++++++++++++\n");
        for (int i = 0; i < 10; i++) {
            if (p[i].num / 100 == n) {
                for (int j = 0; j < 9; j++)
                    printf("%d  %s \n", p[i].sublist[j].subnum, p[i].sublist[j].name);
            }
        }
        scanf("%d", &subN);
        subread(p, n, subN);
    }
    else if (N>10&&N<90&&N%10==0) {

        printf("���� �߿��� � ��о߷� ���� �����ʴϱ�?\n");
        printf("++++++++++++++++++++++++++++++++++++\n");
        for (int b = 0; b < 10; b++) {
            printf("%d  %s \n", p[b].num, p[b].name);
        }
        n = N / 100;

        scanf("%d", &subsubN);
        if (subsubN >= 0 && subsubN <= 9) {
            subN = subsubN * 100 + N;
            temp = subsubN;
        }
        else {
            subN = subsubN + N;
            temp = subsubN / 100;
        }
        subread(p, temp, subN);
    }
    else {
        if (N < 100 && N > 10) {
            subN = N * 10;
            n = N / 10;
        }
        else {
            subN = N;
            n = N / 100; 
        }
        subread(p, n, subN);
    }
}

int main() {

    FILE* f;
    f = fopen("info.txt", "r");

    if (f == NULL) {
        puts("���� ���� ����");
        return -1;
    }

    field p[10];

    for (int j = 0; j < 10; j++) {
        fscanf(f, "%d %[^\n]", &p[j].num, p[j].name);
        for (int i = 0; i < 9; i++) {
            fscanf(f, "%d %[^\n]", &p[j].sublist[i].subnum, p[j].sublist[i].name);
        }
    }
    fclose(f);
    read(p);
}