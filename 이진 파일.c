#include<stdio.h>
#define SIZE 3

struct student {
	int number;	// �й�
	char name[20];	// �̸�
	double gpa;	// ����
};

int main(void)
{
	struct student table[SIZE] = {
		{ 1, "Kim", 3.99 },
		{ 2, "Min", 2.68 },
		{ 3, "Lee", 4.01 }
	};
	
	struct student sp;
	
	FILE *fp = NULL;
	int i;
	
	
	// ���� ������ ���� ���� ����.
	if( (fp = fopen("student.dat", "wb")) == NULL )
	{
		fprintf(stderr,"����� ���� ������ �� �� �����ϴ�.\n");
		exit(1);
	}
	
	
	// �迭�� ���Ͽ� �����Ѵ�.
	fwrite(table, sizeof(struct student), SIZE, fp);
	fclose(fp);
	
	
	// ���� ������ �б� ���� ����.
	if( (fp = fopen("student.dat", "rb")) == NULL )
	{
		fprintf(stderr,"�Է��� ���� ������ �� �� �����ϴ�.\n");
		exit(1);
	}
	
	for(i = 0;i < SIZE; i++)
	{	
		fread(&sp, sizeof(struct student), 1, fp);
		printf("�й� = %d, �̸� = %s, ���� = %f\n", sp.number, sp.name, sp.gpa);
	}
	
	fclose(fp);
	
	return 0;
}