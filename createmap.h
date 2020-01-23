int create_map(int size_map){
	int i,j;
	char k;
	srand(time(NULL));
	FILE *fp=fopen("map.bin","wb");
	fwrite(&size,sizeof(int),1,fp);
	for(i=0;i<size;i++){
		for(j=size-1;j>=0;j--){
			k='1'+rand()%4;
			fwrite(&k,sizeof(char),1,fp);
		}
	}
	fclose(fp);
	return 0;
}

