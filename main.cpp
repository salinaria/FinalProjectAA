#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "createmap.h"
#include "cellfunc.h"
#include "filefunc.h"
#include "loadsave.h"
#include <math.h>
#include <graphics.h>
#include "print.h"
#include "maingame.h"
using namespace std;
main(){
    initwindow(600,600);
    srand(time(NULL));
	int i,j,k;
	int **my_map;
	printf("[1]Load\n[2]New single player game\n[3]New Multiplayer game\n[4]Exit\n");
	scanf("%d",&i);
	if(i==1){
		int size=map_size_txt("savemap.txt");
		size=(int)sqrt(size);
		my_map=load_map(my_map,size);
		int cellnum;
		int numplayer;
		FILE *fp=fopen("numplayer.txt","r");
		fscanf(fp,"%d",&numplayer);
		if(numplayer==1){
			struct node *head=(struct node*)malloc(sizeof(struct node));
			head=load_cell_1(head);
			single_player(my_map,size,head);
		}
		if(numplayer==2){
			struct node *head_1=(struct node*)malloc(sizeof(struct node));
			struct node *head_2=(struct node*)malloc(sizeof(struct node));
			head_1=load_cell_1(head_1);
			head_2=load_cell_2(head_2);
			multi_player(my_map,size,head_1,head_2);
		}
	}
	else if(i==2){
		my_map=read_file("map.bin");
		int size=map_size_bin("map.bin");
		int cellnum;
		printf("How many cells do you want?");
		scanf("%d",&cellnum);
		struct node *head=(struct node*)malloc(sizeof(struct node));
		head=create_node(head,cellnum,size,my_map);
		print_map_single(my_map,size,head);
		single_player(my_map,size,head);
	}
	else if(i==3){
		my_map=read_file("map.bin");
		int size=map_size_bin("map.bin");
		int celnum_1;
		printf("How many cells do you want(Player1)?");
		scanf("%d",&celnum_1);
		struct node *head_1=(struct node*)malloc(sizeof(struct node));
		head_1=create_node(head_1,celnum_1,size,my_map);
		int celnum_2;
		printf("How many cells do you want(Player2)?");
		scanf("%d",&celnum_2);
		struct node *head_2=(struct node*)malloc(sizeof(struct node));
		head_2=create_node(head_2,celnum_2,size,my_map);
		print_map_multi(my_map,size,head_1,head_2);
		multi_player(my_map,size,head_1,head_2);
	}
	//else
	return 0;
}

