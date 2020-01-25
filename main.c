#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "createmap.h"
#include "cellfunc.h"
#include "filefunc.h"
#include "maingame.h"
int main() {
	int i;
	int **map;
	create_map(3);
	printf("[1]Load\n[2]New single player game\n[3]New Multiplayer game\n[4]Exit\n");
	scanf("%d",&i);
	if(i==1){
		load_map(map,map_size("savemap.h"));
	}
	else if(i==2){
		map=read_file("map.bin");
		int size=map_size("map.bin");
		int cellnum;
		printf("How many cells do you want?");
		scanf("%d",&cellnum);
		struct node *head=(struct node*)malloc(cellnum*sizeof(struct node));
		create_node(head,cellnum,size,map);
		printf("%d",map[0][0]);
		single_player(map,size,head);
		
	}
	else if(i==3){
		char *fname=malloc(10);
		printf("Please text name of file:");
		gets(fname);
		read_file(fname);
		int size=map_size(fname);
		int celnum_1;
		printf("Howmany cells do you want(Player1)?");
		scanf("%d",&celnum_1);
		struct node *head_1;
		create_node(head_1,celnum_1,size,map);
		int celnum_2;
		printf("Howmany cells do you want(Player2)?");
		scanf("%d",&celnum_2);
		struct node *head_2;
		create_node(head_2,celnum_2,size,map);
	}
	else return 0;
}
