#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>

int fileIO(char place[], char result[]);
int i;	//for���p

int main(void)
{
	printf("�Ώۃf�B���N�g���̒�����A�v�����N�����Ă��܂����B\n");

	char a[10] = "";
	printf("-->[Y/n]\n");
	scanf("%s", a);

	if (a[0] == 'Y' || a[0] == 'y') {
		;
	}
	else {
		printf("�t�@�C���̐����Ɏ��s���܂����B\n");
		return -1;
	}

	char *filename = "2017_CDCL_2017_";		//���ʃt�@�C����
	char *extension = ".csv";				//�g���q

	char output[256];						//�o�̓t�@�C����
	int num;								//�o�̓t�@�C����

	printf("�o�̓t�@�C����\n");
	scanf("%s", output);

	printf("�ǂݍ��ރt�@�C����\n");
	scanf("%d", &num);

	for (i = 0; i < num; i++) {
		//������
		char name[256] = "";
		char str[256] = "";

		//�t�@�C�����̐���
		strcpy(name, filename);
		sprintf(str, "%d", i + 1);
		strcat(name, str);
		strcat(name, extension);

		//���l�f�[�^�̓ǂݍ���
		fileIO(name, output);
	}

	char fin[10];
	printf("�������L�[����͂��Ă�������\n");
	scanf("%s", fin);

	return 0;
}

int fileIO(char place[], char result[])
{
	FILE *fpi;
	fpi = fopen(place, "r");

	FILE *fpo;
	fpo = fopen(result, "a");

	char data[256];

	fgets(data, 256, fpi);
	fgets(data, 256, fpi);
	fgets(data, 256, fpi);

	fprintf(fpo, data);

	fclose(fpi);
	fclose(fpo);
}