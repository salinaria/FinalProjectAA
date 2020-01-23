#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int create_map(int n){
	int i,j;
	char k;
	srand(time(NULL));
	FILE *fp=fopen("map.bin","wb");
	fwrite(&n,sizeof(int),1,fp);
	for(i=0;i<n;i++){
		for(j=n-1;j>=0;j--){
			k='1'+rand()%4;
			fwrite(&k,sizeof(char),1,fp);
		}
	}
	fclose(fp);
	return 0;
}

