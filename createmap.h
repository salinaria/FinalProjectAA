int create_map(int size_map){
	int i,j;
	char k;
	srand(time(NULL));
	FILE *fp=fopen("map.bin","wb");
	fwrite(&size_map,sizeof(int),1,fp);
	for(i=size_map-1;i>=0;i--){
		for(j=0;size_map>j;j++){
			k='1'+rand()%4;
			fwrite(&k,sizeof(char),1,fp);
		}
	}
	fclose(fp);
	return 0;
}

