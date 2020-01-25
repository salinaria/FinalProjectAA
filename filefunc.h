/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>*/
int **read_file(char *fname){
	int size_map;
	int **map;
	int i,j;
	char k;
	FILE *fp=fopen(fname,"rb");
	fread(&size_map,sizeof(int),1,fp);
	map=(int **)malloc(size_map*sizeof(int*));
	for(i=size_map-1;i>=0;i--){
		map[i]=(int *)malloc(size_map*sizeof(int));
		for(j=0;size_map>j;j++){
			fread(&k,sizeof(char),1,fp);
			if(k=='1')map[i][j]=101;
			else map[i][j]=k-'1'+1;
		}
	}
	fclose(fp);
	return map;
}
void save_map(int **map,int size_map){
	FILE *fp=fopen("savemap.txt","w");
	int i,j;
	for(i=0;i<size_map;i++){
		for(j=0;j<size_map;j++){
			fprintf(fp,"%d ",map[i][j]);
		}
	}
	fclose(fp);
}
/*void undo_map(int **map,int size_map){
	FILE *fp=fopen("savemap.txt","w");
	int i,j;
	for(i=0;i<size_map;i++){
		for(j=0;j<size_map;j++){
			fprintf(fp,"%d ",map[i][j]);
		}
	}
	fclose(fp);
}*/
void load_map(int **map,int size_map){
	FILE *fp=fopen("savemap.txt","r");
	int i,j;
	for(i=0;i<size_map;i++){
		for(j=0;j<size_map;j++){
			fscanf(fp,"%d",map[i][j]);
		}
	}
	fclose(fp);
}
void energy_map(int x,int y,int **map){
	map[x][y]=map[x][y]-15;
}
int check_map(int x,int y,int **map,int size_map){
	if(map[x][y]==3)return 0;
	if(x<0 || y<0 || x>=size_map || y>=size_map)return 0;
	return 1;
}



