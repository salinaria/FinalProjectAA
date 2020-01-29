void single_player(int **map,int size_map,struct node *head){
	while(1){
        print_map_single(map,size_map,head);
		printf("Please choose one of your cells:\n");
		struct node *curr=head;
		while(curr!=NULL){
			printf("[%d] %s (%d,%d)\n",curr->info.cellid,curr->info.name,curr->info.x,curr->info.y);
			curr=curr->next;
		}
		int cellnum;
		scanf("%d",&cellnum);
		curr=head;
		while(curr->info.cellid!=cellnum)curr=curr->next;
		int i;
		printf("[1]Move\n");
		printf("[2]Split a cell ");
		if(map[curr->info.x][curr->info.y]!=2 || curr->info.energy<80)printf("               unavailable!");
		printf("\n");
		printf("[3]Boost energy");
		if(map[curr->info.x][curr->info.y]<=11)printf("               unavailable!");
		printf("\n");
		printf("[4]Save\n[5]Exit\n");
		scanf("%d",&i);
		if(i==1){
			move(head,curr->info.name,map,size_map);
		}
		else if(i==2){
			if(map[curr->info.x][curr->info.y]==2 && curr->info.energy>=80){
					int availbale_x[6],availbale_y[6];
					int lenght=0;
					if(curr->info.x%2==0){
						if(check_cell(curr->info.x,curr->info.y+1,map,size_map,head)==1){
							availbale_x[lenght]=curr->info.x;
							availbale_y[lenght]=curr->info.y+1;
							lenght++;
						}
						if(check_cell(curr->info.x,curr->info.y-1,map,size_map,head)==1){
							availbale_x[lenght]=curr->info.x;
							availbale_y[lenght]=curr->info.y-1;
							lenght++;
						}
						if(check_cell(curr->info.x+1,curr->info.y+1,map,size_map,head)==1){
							availbale_x[lenght]=curr->info.x+1;
							availbale_y[lenght]=curr->info.y+1;
							lenght++;
						}
						if(check_cell(curr->info.x-1,curr->info.y+1,map,size_map,head)==1){
							availbale_x[lenght]=curr->info.x-1;
							availbale_y[lenght]=curr->info.y+1;
							lenght++;
						}
						if(check_cell(curr->info.x-1,curr->info.y,map,size_map,head)==1){
							availbale_x[lenght]=curr->info.x-1;
							availbale_y[lenght]=curr->info.y;
							lenght++;
						}
						if(check_cell(curr->info.x+1,curr->info.y,map,size_map,head)==1){
							availbale_x[lenght]=curr->info.x+1;
							availbale_y[lenght]=curr->info.y;
							lenght++;
						}
					}
					if(curr->info.x%2==1){
						if(check_cell(curr->info.x,curr->info.y+1,map,size_map,head)==1){
							availbale_x[lenght]=curr->info.x;
							availbale_y[lenght]=curr->info.y+1;
							lenght++;
						}
						if(check_cell(curr->info.x,curr->info.y-1,map,size_map,head)==1){
							availbale_x[lenght]=curr->info.x;
							availbale_y[lenght]=curr->info.y-1;
							lenght++;
						}
						if(check_cell(curr->info.x+1,curr->info.y,map,size_map,head)==1){
							availbale_x[lenght]=curr->info.x+1;
							availbale_y[lenght]=curr->info.y;
							lenght++;
						}
						if(check_cell(curr->info.x-1,curr->info.y,map,size_map,head)==1){
							availbale_x[lenght]=curr->info.x-1;
							availbale_y[lenght]=curr->info.y;
							lenght++;
						}
						if(check_cell(curr->info.x-1,curr->info.y-1,map,size_map,head)==1){
							availbale_x[lenght]=curr->info.x-1;
							availbale_y[lenght]=curr->info.y-1;
							lenght++;
						}
						if(check_cell(curr->info.x+1,curr->info.y-1,map,size_map,head)==1){
							availbale_x[lenght]=curr->info.x+1;
							availbale_y[lenght]=curr->info.y-1;
							lenght++;
						}
					}
				int x=rand()%lenght;
				split_cell(head,availbale_x[x],availbale_y[x],curr->info.name);
			}
		}
		else if(i==3){
			if(map[curr->info.x][curr->info.y]>=11){
				if(map[curr->info.x][curr->info.y]>=16){
					energy_cell(head,curr->info.name,15);
					energy_map(curr->info.x,curr->info.y,map,15);
				}
				else {
					energy_cell(head,curr->info.name,map[curr->info.x][curr->info.y]-1);
					energy_map(curr->info.x,curr->info.y,map,map[curr->info.x][curr->info.y]-1);
				}
			}
		}
		else if(i==4){
			save_map(map,size_map);
			save_cell_single(head);
		}
		else if(i==5)break;
	}
}
void multi_player(int **map,int size_map,struct node *head_1,struct node *head_2){
	print_map_multi(map,size_map,head_1,head_2);
	int j=1;
	while(1){
		if(j%2==1){
			printf("Please choose one of your cells(Player 1):\n");
			struct node *curr=head_1;
			while(curr!=NULL){
				printf("[%d] %s (%d,%d)\n",curr->info.cellid,curr->info.name,curr->info.x,curr->info.y);
				curr=curr->next;
			}
			int cellnum;
			scanf("%d",&cellnum);
			curr=head_1;
			while(curr->info.cellid!=cellnum)curr=curr->next;
			int i;
			printf("[1]Move\n");
			printf("[2]Split a cell ");
			if(map[curr->info.x][curr->info.y]!=2 || curr->info.energy<80)printf("               unavailable!");
			printf("\n");
			printf("[3]Boost energy");
			if(map[curr->info.x][curr->info.y]<=11)printf("               unavailable!");
			printf("\n");
			printf("[4]Save\n[5]Exit\n");
			scanf("%d",&i);
			if(i==1){
				move(head_1,curr->info.name,map,size_map);
			}
			else if(i==2){
				if(map[curr->info.x][curr->info.y]==2 && curr->info.energy>=80){
						int availbale_x[6],availbale_y[6];
						int lenght=0;
						if(curr->info.x%2==0){
							if(check_cell(curr->info.x,curr->info.y+1,map,size_map,head_1)==1){
								availbale_x[lenght]=curr->info.x;
								availbale_y[lenght]=curr->info.y+1;
								lenght++;
							}
							if(check_cell(curr->info.x,curr->info.y-1,map,size_map,head_1)==1){
								availbale_x[lenght]=curr->info.x;
								availbale_y[lenght]=curr->info.y-1;
								lenght++;
							}
							if(check_cell(curr->info.x+1,curr->info.y+1,map,size_map,head_1)==1){
								availbale_x[lenght]=curr->info.x+1;
								availbale_y[lenght]=curr->info.y+1;
								lenght++;
							}
							if(check_cell(curr->info.x-1,curr->info.y+1,map,size_map,head_1)==1){
								availbale_x[lenght]=curr->info.x-1;
								availbale_y[lenght]=curr->info.y+1;
								lenght++;
							}
							if(check_cell(curr->info.x-1,curr->info.y,map,size_map,head_1)==1){
								availbale_x[lenght]=curr->info.x-1;
								availbale_y[lenght]=curr->info.y;
								lenght++;
							}
							if(check_cell(curr->info.x+1,curr->info.y,map,size_map,head_1)==1){
								availbale_x[lenght]=curr->info.x+1;
								availbale_y[lenght]=curr->info.y;
								lenght++;
							}
						}
						if(curr->info.x%2==1){
							if(check_cell(curr->info.x,curr->info.y+1,map,size_map,head_1)==1){
								availbale_x[lenght]=curr->info.x;
								availbale_y[lenght]=curr->info.y+1;
								lenght++;
							}
							if(check_cell(curr->info.x,curr->info.y-1,map,size_map,head_1)==1){
								availbale_x[lenght]=curr->info.x;
								availbale_y[lenght]=curr->info.y-1;
								lenght++;
							}
							if(check_cell(curr->info.x+1,curr->info.y,map,size_map,head_1)==1){
								availbale_x[lenght]=curr->info.x+1;
								availbale_y[lenght]=curr->info.y;
								lenght++;
							}
							if(check_cell(curr->info.x-1,curr->info.y,map,size_map,head_1)==1){
								availbale_x[lenght]=curr->info.x-1;
								availbale_y[lenght]=curr->info.y;
								lenght++;
							}
							if(check_cell(curr->info.x-1,curr->info.y-1,map,size_map,head_1)==1){
								availbale_x[lenght]=curr->info.x-1;
								availbale_y[lenght]=curr->info.y-1;
								lenght++;
							}
							if(check_cell(curr->info.x+1,curr->info.y-1,map,size_map,head_1)==1){
								availbale_x[lenght]=curr->info.x+1;
								availbale_y[lenght]=curr->info.y-1;
								lenght++;
							}
						}
					int x=rand()%lenght;
					split_cell(head_1,availbale_x[x],availbale_y[x],curr->info.name);
				}
			}
			else if(i==3){
				if(map[curr->info.x][curr->info.y]>=11){
					if(map[curr->info.x][curr->info.y]>=16){
						energy_cell(head_1,curr->info.name,15);
						energy_map(curr->info.x,curr->info.y,map,15);
					}
					else {
						energy_cell(head_1,curr->info.name,map[curr->info.x][curr->info.y]-1);
						energy_map(curr->info.x,curr->info.y,map,map[curr->info.x][curr->info.y]-1);
					}
				}
			}
			else if(i==4){
				save_map(map,size_map);
				save_cell_multi(head_1,head_2);
			}
			else if(i==5)break;
		}
		if(j%2==0){
			printf("Please choose one of your cells:(Player 2)\n");
			struct node *curr=head_2;
			while(curr!=NULL){
				printf("[%d] %s (%d,%d)\n",curr->info.cellid,curr->info.name,curr->info.x,curr->info.y);
				curr=curr->next;
			}
			int cellnum;
			scanf("%d",&cellnum);
			curr=head_2;
			while(curr->info.cellid!=cellnum)curr=curr->next;
			int i;
			printf("[1]Move\n");
			printf("[2]Split a cell ");
			if(map[curr->info.x][curr->info.y]!=2 || curr->info.energy<80)printf("              unavailable!");
			printf("\n");
			printf("[3]Boost energy");
			if(map[curr->info.x][curr->info.y]<=11)printf("               unavailable!");
			printf("\n");
			printf("[4]Save\n[5]Exit\n");
			scanf("%d",&i);
			if(i==1){
				move(head_2,curr->info.name,map,size_map);
			}
			else if(i==2){
				if(map[curr->info.x][curr->info.y]==2 && curr->info.energy>=80){
						int availbale_x[6],availbale_y[6];
						int lenght=0;
						if(curr->info.x%2==0){
							if(check_cell(curr->info.x,curr->info.y+1,map,size_map,head_2)==1){
								availbale_x[lenght]=curr->info.x;
								availbale_y[lenght]=curr->info.y+1;
								lenght++;
							}
							if(check_cell(curr->info.x,curr->info.y-1,map,size_map,head_2)==1){
								availbale_x[lenght]=curr->info.x;
								availbale_y[lenght]=curr->info.y-1;
								lenght++;
							}
							if(check_cell(curr->info.x+1,curr->info.y+1,map,size_map,head_2)==1){
								availbale_x[lenght]=curr->info.x+1;
								availbale_y[lenght]=curr->info.y+1;
								lenght++;
							}
							if(check_cell(curr->info.x-1,curr->info.y+1,map,size_map,head_2)==1){
								availbale_x[lenght]=curr->info.x-1;
								availbale_y[lenght]=curr->info.y+1;
								lenght++;
							}
							if(check_cell(curr->info.x-1,curr->info.y,map,size_map,head_2)==1){
								availbale_x[lenght]=curr->info.x-1;
								availbale_y[lenght]=curr->info.y;
								lenght++;
							}
							if(check_cell(curr->info.x+1,curr->info.y,map,size_map,head_2)==1){
								availbale_x[lenght]=curr->info.x+1;
								availbale_y[lenght]=curr->info.y;
								lenght++;
							}
						}
						if(curr->info.x%2==1){
							if(check_cell(curr->info.x,curr->info.y+1,map,size_map,head_2)==1){
								availbale_x[lenght]=curr->info.x;
								availbale_y[lenght]=curr->info.y+1;
								lenght++;
							}
							if(check_cell(curr->info.x,curr->info.y-1,map,size_map,head_2)==1){
								availbale_x[lenght]=curr->info.x;
								availbale_y[lenght]=curr->info.y-1;
								lenght++;
							}
							if(check_cell(curr->info.x+1,curr->info.y,map,size_map,head_2)==1){
								availbale_x[lenght]=curr->info.x+1;
								availbale_y[lenght]=curr->info.y;
								lenght++;
							}
							if(check_cell(curr->info.x-1,curr->info.y,map,size_map,head_2)==1){
								availbale_x[lenght]=curr->info.x-1;
								availbale_y[lenght]=curr->info.y;
								lenght++;
							}
							if(check_cell(curr->info.x-1,curr->info.y-1,map,size_map,head_2)==1){
								availbale_x[lenght]=curr->info.x-1;
								availbale_y[lenght]=curr->info.y-1;
								lenght++;
							}
							if(check_cell(curr->info.x+1,curr->info.y-1,map,size_map,head_2)==1){
								availbale_x[lenght]=curr->info.x+1;
								availbale_y[lenght]=curr->info.y-1;
								lenght++;
							}
						}
					int x=rand()%lenght;
					split_cell(head_2,availbale_x[x],availbale_y[x],curr->info.name);
				}
			}
			else if(i==3){
				if(map[curr->info.x][curr->info.y]>=11){
					if(map[curr->info.x][curr->info.y]>=16){
						energy_cell(head_2,curr->info.name,15);
						energy_map(curr->info.x,curr->info.y,map,15);
					}
					else {
						energy_cell(head_2,curr->info.name,map[curr->info.x][curr->info.y]-1);
						energy_map(curr->info.x,curr->info.y,map,map[curr->info.x][curr->info.y]-1);
					}
				}
			}
			else if(i==4){
				save_map(map,size_map);
				save_cell_multi(head_1,head_2);
			}
			else if(i==5)break;
		}
		j++;
	}
}
