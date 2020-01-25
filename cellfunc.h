struct information{
	int x;
	int y;
	int energy;
	char name[5];
	int cellid;
};
struct node{
	struct information info;
	struct node *next;
};
void rand_name(char *name){
	int i;
	for(i=0;i<5;i++){
		name[i]='a'+rand()%26;
	}
}
int check_cell(int x,int y,int **map,struct node *head){
	struct node *curr=head;
	while(curr->next!=NULL){
		if(curr->info.x==x){
			if(curr->info.y==y)return 0;
		}
		curr=curr->next;
	}
	if(map[x][y]==3)return 0;
	return 1;
}
struct node *create_node(struct node *head,int cellnum,int map_size,int **map){
	int i,x,y,check=0;
	head=(struct node*)malloc(cellnum*sizeof(struct node));
	struct node *curr=head;
	for(i=0;i<cellnum;i++){
		curr->info.energy=0;
		//random x and y for cell
		while(check==0){
			x=rand()%map_size;
			y=rand()%map_size;
			check=check_cell(x,y,map,head);
		}
		curr->info.x=x;
		curr->info.y=y;
		curr->info.cellid=i;
		check=0;
		rand_name(curr->info.name);
		curr=curr->next;
	}
	curr->next=NULL;
	return head;
}
void split_cell(struct node* head,int x,int y,char *cellname){
	struct node* curr=head;
	struct node* new_node;
	int count=0;
	new_node=(struct node*)malloc((sizeof(struct node)));
	//edit the cell mitosised
	while(strcmp(curr->info.name,cellname)!=0){
		curr=curr->next;
		count++;	
	}
	rand_name(curr->info.name);
	curr->info.energy=40;
	//creat new cell
	while(curr->next!=NULL){
		curr=curr->next;
		count++;	
	}
	new_node->next=NULL;
	rand_name(new_node->info.name);
	new_node->info.energy=40;
	new_node->info.x=x;
	new_node->info.y=y;
	new_node->info.cellid=count+1;
	new_node->next=NULL;
	curr->next=new_node;
}
void energy_cell(struct node* head,char *cellname,int energy){
	struct node* curr=head;
	while(strcmp(curr->info.name,cellname)!=0)curr=curr->next;
	curr->info.energy+=energy;
	if(curr->info.energy>100)curr->info.energy=100;
}
void move(struct node *head,char *cellname,int **map){
	struct node* curr=head;
	while(strcmp(curr->info.name,cellname)!=0)curr=curr->next;
	printf("[1]North ");
	if(check_cell(curr->info.x,curr->info.y+1,map,head)==0)printf("unavailable");
	printf("\n");
	
	printf("[2]South ");
	if(check_cell(curr->info.x,curr->info.y-1,map,head)==0)printf("unavailable");
	printf("\n");
	
	printf("[3]Northeast ");
	if(curr->info.x%2==0){
		if(check_cell(curr->info.x+1,curr->info.y+1,map,head)==0)printf("unavailable");	
	}
	else{
		if(check_cell(curr->info.x+1,curr->info.y,map,head)==0)printf("unavailable");
	}
	printf("\n");
	
	printf("[4]Northwest ");
	if(curr->info.x%2==0){
		if(check_cell(curr->info.x-1,curr->info.y+1,map,head)==0)printf("unavailable");	
	}
	else{
		if(check_cell(curr->info.x-1,curr->info.y,map,head)==0)printf("unavailable");
	}
	printf("\n");
	
	printf("[5]Southeast ");
	if(curr->info.x%2==0){
		if(check_cell(curr->info.x+1,curr->info.y,map,head)==0)printf("unavailable");	
	}
	else{
		if(check_cell(curr->info.x-1,curr->info.y-1,map,head)==0)printf("unavailable");
	}
	printf("\n");
	
	printf("[6]Southwest ");
	if(curr->info.x%2==0){
		if(check_cell(curr->info.x+1,curr->info.y,map,head)==0)printf("unavailable");	
	}
	else{
		if(check_cell(curr->info.x-1,curr->info.y-1,map,head)==0)printf("unavailable");
	}
	printf("\n");
	
	int direction;
	scanf("%d",&direction);
	//1 north
	if(direction==1)curr->info.y++;
	//2 south
	else if(direction==2)curr->info.y--;
	//3 northeast
	else if(direction==3){
		if((curr->info.x)%2==0)curr->info.y++;
		curr->info.x++;
	}
	//4 northwest
	else if(direction==4){
		if((curr->info.x)%2==0)curr->info.y++;
		curr->info.x--;
	}
	//5 southeast
	else if(direction==5){
		if((curr->info.x)%2==1)curr->info.y--;
		curr->info.x++;
	}
	//6 southwest
	else if(direction==6){
		if((curr->info.x)%2==1)curr->info.y--;
		curr->info.x--;
	}
}
void save_cell(struct node *head){
	FILE *fp=fopen("savecell.txt","w");
	struct node* curr=head;
	while(curr->next!=NULL){
		fprintf(fp,"%d %d %d %s",curr->info.x,curr->info.y,curr->info.energy,curr->info.name);
		curr=curr->next;
	}
	fclose(fp);
}
void load_cell(struct node *head){
	FILE *fp=fopen("savecell.txt","r");
	struct node* curr=head;
	int i=0;
	while(curr->next!=NULL){
		fscanf(fp,"%d %d %d %s",curr->info.x,curr->info.y,curr->info.energy,curr->info.name);
		curr->info.cellid=i;
		i++;
		curr=curr->next;
	}
	fclose(fp);
}
