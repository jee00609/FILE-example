#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct personscore
{
	int number;
	char name[40];
	int mid;
	int final;
	int quiz;
}pscore;

void printhead();

int main(void)
{
	char fname[100];
	char line[80];
	FILE *f;
	int cnt=0;
	pscore score;

	printf("파일 이름을 만드세요: ");
	gets(fname);


	if((f=fopen(fname,"wb"))==NULL)
	{
		printf("파일이 열리지 않습니다.\n");
		exit(1);
	}

	printf("이름과 성적(중간 기말 퀴즈)을 입력하세요.\n");
	fgets(line,80,stdin);


	while(!feof(stdin))
	{
		sscanf(line,"%s %d %d %d",&score.name,&score.mid,&score.final,&score.quiz);
		score.number=++cnt;

		fwrite(&score,sizeof(score),1,f);
		fgets(line,80,stdin);

	}
	fclose(f);

	if((f=fopen(fname,"rb"))==NULL)
	{
		printf("파일이 열리지 않습니다.\n");
		exit(1);
	}
	printhead();
	fread(&score,sizeof(score),1,f);
	
	while(!feof(f))
	{
		fprintf(stdout,"%6d%18s%8d%8d%8d\n",score.number,score.name,score.mid,score.final,score.quiz);
		fread(&score,sizeof(score),1,f);
	}
	printf("%s\n","------------------------------------------------");
	
	fclose(f);

	return 0;
}

void printhead()
{
	printf("%s\n","------------------------------------------------");
	printf("%8s%15s%10s%8s%8s\n","번호","이름","중간","기말","퀴즈");
	printf("%s\n","------------------------------------------------");
}