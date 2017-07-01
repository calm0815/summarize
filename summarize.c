#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>

int fileIO(char place[], char result[]);
int i;	//for文用

int main(void)
{
	printf("対象ディレクトリの中からアプリを起動していますか。\n");

	char a[10] = "";
	printf("-->[Y/n]\n");
	scanf("%s", a);

	if (a[0] == 'Y' || a[0] == 'y') {
		;
	}
	else {
		printf("ファイルの生成に失敗しました。\n");
		return -1;
	}

	char *filename = "2017_CDCL_2017_";		//共通ファイル名
	char *extension = ".csv";				//拡張子

	char output[256];						//出力ファイル名
	int num;								//出力ファイル数

	printf("出力ファイル名\n");
	scanf("%s", output);

	printf("読み込むファイル数\n");
	scanf("%d", &num);

	for (i = 0; i < num; i++) {
		//初期化
		char name[256] = "";
		char str[256] = "";

		//ファイル名の生成
		strcpy(name, filename);
		sprintf(str, "%d", i + 1);
		strcat(name, str);
		strcat(name, extension);

		//数値データの読み込み
		fileIO(name, output);
	}

	char fin[10];
	printf("何かをキーを入力してください\n");
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