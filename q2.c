#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct heart{

	char arr[100001];
	int x;
	int y;

}heart;

typedef struct realxy {

	int x;
	int y;

}realxy;

void read(heart* list, int N) {

	realxy* real_list = (realxy*)malloc(sizeof(realxy) * N);
	for (int a = 0; a < N; a++) {
		real_list[a].x = 0;
		real_list[a].y = 0;
	}

	int sum_x = 0;
	int sum_y = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < strlen(list[i].arr) - 1; j ++) {
			if (list[i].arr[j] == 53) {
				if (list[i].arr[j + 1] == 50)
					real_list[i].x++;
			}
			if (list[i].arr[j] == 60) {
				if (list[i].arr[j + 1] == 51)
					real_list[i].y++;
			}
		}
	}

	for (int a = 0; a < N; a++) {
		if (real_list[a].x == list[a].x)
			sum_x += list[a].x;
		else if (real_list[a].x != list[a].x)
			sum_x -= list[a].x;
		if (real_list[a].y == list[a].y)
			sum_y += list[a].y;
		else if (real_list[a].y != list[a].y)
			sum_y -= list[a].y;
	}

	printf("\n52의 하트 점수는 %d입니다.", sum_x);
	printf("\n<3의 하트 점수는 %d입니다.", sum_y);
	free(real_list);
}

int main() {
	
	int N = 0;
	scanf("%d", &N);
	heart* list = (heart*)malloc(sizeof(heart) * N);

	for (int i = 0; i < N; i++) {
		scanf("%s ", list[i].arr);
		scanf("%d ", &list[i].x);
		scanf("%d", &list[i].y);
	}

	read(list, N);
	free(list);
	return 0;
}