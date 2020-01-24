int **read_file(char *fname){
	int size_map;
	int **map;
	int i,j;
	char k;
	FILE *fp=fopen(fname,"rb");
	fread(&size_map,sizeof(int),1,fp);
	map=(int **)malloc(size_map*sizeof(int*));
	for(i=0;i<size_map;i++){
		map[i]=(int *)malloc(size_map*sizeof(int));
		for(j=size_map-1;j>=0;j--){
			fread(&k,sizeof(char),1,fp);
			if(k=='1')map[i][j]=101;
			else map[i][j]=k-'1'+1;
		}
	}
	fclose(fp);
	return map;
}
void save_map(int **map,int size_map){
	FILE *fp=fopen("savemap.txt","a");
	int i,j;
	for(i=0;i<size_map;i++){
		for(j=0;j<size_map;j++){
			fprintf(fp,"%d ",map[i][j]);
		}
	}
	fclose(fp);
}






