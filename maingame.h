void single_player(int **map,int size_map,struct node *head){
	while(1){
		printf("Please choose one of your cells:\n");
		struct node *curr=head;
		while(curr->next!=NULL){
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
		if(map[curr->info.x][curr->info.y]!=2 || curr->info.energy<80)printf("unavailable!");
		printf("\n");
		printf("[3]Boost energy");
		if(map[curr->info.x][curr->info.y]<=11)printf("unavailable!");
		printf("\n");
		printf("[4]Save\n[5]Exit\n");
		scanf("%d",&i);
		if(i==1){
			move(head,curr->info.name,map);
		}
		else if(i==2){
			if(map[curr->info.x][curr->info.y]==2 && curr->info.energy>=80){
					int availbale_x[6],availbale_y[6];
					int lenght=0;
					if(curr->info.x%2==0){
						if(check_cell(curr->info.x,curr->info.y+1,map,head)==1){
							availbale_x[lenght]=curr->info.x;
							availbale_y[lenght]=curr->info.y+1;
							lenght++;
						}
						if(check_cell(curr->info.x,curr->info.y-1,map,head)==1){
							availbale_x[lenght]=curr->info.x;
							availbale_y[lenght]=curr->info.y-1;
							lenght++;
						}
						if(check_cell(curr->info.x+1,curr->info.y+1,map,head)==1){
							availbale_x[lenght]=curr->info.x+1;
							availbale_y[lenght]=curr->info.y+1;
							lenght++;	
						}
						if(check_cell(curr->info.x-1,curr->info.y+1,map,head)==1){
							availbale_x[lenght]=curr->info.x-1;
							availbale_y[lenght]=curr->info.y+1;
							lenght++;
						}
						if(check_cell(curr->info.x-1,curr->info.y,map,head)==1){
							availbale_x[lenght]=curr->info.x-1;
							availbale_y[lenght]=curr->info.y;
							lenght++;
						}
						if(check_cell(curr->info.x+1,curr->info.y,map,head)==1){
							availbale_x[lenght]=curr->info.x+1;
							availbale_y[lenght]=curr->info.y;
							lenght++;	
						}	
					}
					if(curr->info.x%2==1){
						if(check_cell(curr->info.x,curr->info.y+1,map,head)==1){
							availbale_x[lenght]=curr->info.x;
							availbale_y[lenght]=curr->info.y+1;
							lenght++;
						}
						if(check_cell(curr->info.x,curr->info.y-1,map,head)==1){
							availbale_x[lenght]=curr->info.x;
							availbale_y[lenght]=curr->info.y-1;
							lenght++;
						}
						if(check_cell(curr->info.x+1,curr->info.y,map,head)==1){
							availbale_x[lenght]=curr->info.x+1;
							availbale_y[lenght]=curr->info.y;
							lenght++;	
						}
						if(check_cell(curr->info.x-1,curr->info.y,map,head)==1){
							availbale_x[lenght]=curr->info.x-1;
							availbale_y[lenght]=curr->info.y;
							lenght++;
						}
						if(check_cell(curr->info.x-1,curr->info.y-1,map,head)==1){
							availbale_x[lenght]=curr->info.x-1;
							availbale_y[lenght]=curr->info.y-1;
							lenght++;
						}
						if(check_cell(curr->info.x+1,curr->info.y-1,map,head)==1){
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
			save_cell(head);
		}
		else if(i==5)break;
	}
}
