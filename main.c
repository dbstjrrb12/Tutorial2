#include<stdio.h>
#include<string.h>

int sum(int, int);
int sub(int, int);

int main() {
	
	int maxsize = 255;
	char buff[255];

	FILE *fp = fopen("yoontext.txt","w"); 
	fputs("why not change the world?\n", fp);
	fputs("why not change ther world, agai\n",fp);
       	fclose(fp);

	fp = fopen("yoontext.txt","r");
	char data[500];
	int length = 0;

	while((buff[0] = fgetc(fp))>0){
		length++;
		data[length-1] = buff[0];
		if(length >=  sizeof(data)- 1) break;
	}
	data[length] = 0x00;
	printf("%s",data);

	rewind(fp);
	char data2[500];

	length = 0;
	while(fgets(buff,maxsize,fp) != 0x00){
		if((length + strlen(buff))>=sizeof(data2)) break;
		strncpy(&data2[length], buff, strlen(buff));
		length += strlen(buff);
	}
	data2[length] = 0x00;
       	printf("%s",data2);	

	fclose(fp);

	return 0;
}

