#include <stdio.h>
#define SIZE 5

int main(void)
{
	float buffer[SIZE];
	int i=0;
	FILE *fp = NULL;
	size_t size;

	fp = fopen("binary.txt", "rb");
	if( fp == NULL ) 
	{
		fprintf(stderr, "binary.txt ������ �� �� �����ϴ�.");
		exit(1);
	}
	size = fread( &buffer, sizeof(float), SIZE, fp);
	
	if( size != SIZE )
		fprintf(stderr, "�б� ���� �� ������ �߻��߽��ϴ�.\n");

	for(i=0;i<SIZE;i++)
	{
		printf("%s",&buffer[i]);
	}

	fclose(fp);
	return 0;
}