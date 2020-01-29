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
	}
	for(j=size_map-1;j>=0;j--){
		for(i=0;size_map>i;i++){
			fread(&k,sizeof(char),1,fp);
			if(k=='1')map[i][j]=101;
			else map[i][j]=k-'1'+1;
		}
	}
	fclose(fp);
	return map;
}
int map_size_bin(char *fname){
	int size_map;
	FILE *fp=fopen(fname,"rb");
	fread(&size_map,sizeof(int),1,fp);
	fclose(fp);
	return size_map;
}
int map_size_txt(char *fname){
	int size_map=0;
	int a;
	FILE *fp=fopen(fname,"r");
	while(feof(fp)==0){
		fscanf(fp,"%d",&a);
		size_map++;
	}
	size_map--;
	fclose(fp);
	return size_map;
}
void energy_map(int x,int y,int **map,int energy){
	map[x][y]=map[x][y]-energy;
}
int check_map(int x,int y,int **map,int size_map){
	if(map[x][y]==3)return 0;
	if(x<0 || y<0 || x>=size_map || y>=size_map)return 0;
	return 1;
}

