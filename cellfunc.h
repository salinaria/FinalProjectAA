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
	for(i=0;i<4;i++){
		name[i]='a'+rand()%26;
	}
	name[4]='\0';
}
int check_cell(int x,int y,int **map,int size_map,struct node *head){
	struct node *curr=head;
	if(x<0 || y<0 || x>=size_map || y>=size_map){
		return 0;
	}
	while(curr!=NULL){
		if(curr->info.x==x){
			if(curr->info.y==y){
				return 0;	
			}
		}
		curr=curr->next;
	}
	
	if(map[x][y]==3){
		return 0;
	}
	return 1;
}
struct node *create_node(struct node *head,int cellnum,int map_size,int **map){
	int i,x,y,check=0;
	struct node *curr=head;
    check=0;
    x=rand()%map_size;
    y=rand()%map_size;
	while(map[x][y]==3){
    	x=rand()%map_size;
    	y=rand()%map_size;
	}
    curr->info.x=x;
    curr->info.y=y;
    curr->info.cellid=1;
    curr->info.energy=0;
    rand_name(curr->info.name);
    curr->next=NULL;
	for(i=1;i<cellnum;i++){
		struct node *new_node=(struct node*)malloc(sizeof(struct node));
		new_node->info.energy=0;
		//random x and y for cell
		while(check==0){
			x=rand()%map_size;
			y=rand()%map_size;
			check=check_cell(x,y,map,map_size,head);
		}
		check=0;
		new_node->info.x=x;
		new_node->info.y=y;
		new_node->info.cellid=i+1;
		new_node->info.energy=0;
		rand_name(new_node->info.name);
		new_node->next=NULL;
		curr->next=new_node;
		curr=curr->next;
	}
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
void move(struct node *head,char *cellname,int **map,int size_map){
	struct node* curr=head;
	while(strcmp(curr->info.name,cellname)!=0)curr=curr->next;
	printf("[1]North ");
	if(check_cell(curr->info.x,(curr->info.y)+1,map,size_map,head)==0)printf("               unavailable!");
	printf("\n");

	printf("[2]South ");
	if(check_cell(curr->info.x,(curr->info.y)-1,map,size_map,head)==0)printf("               unavailable!");
	printf("\n");

	printf("[3]Northeast ");
	if(curr->info.x%2==0){
		if(check_cell((curr->info.x)+1,(curr->info.y)+1,map,size_map,head)==0)printf("               unavailable!");
	}
	else{
		if(check_cell((curr->info.x)+1,curr->info.y,map,size_map,head)==0)printf("               unavailable!");
	}
	printf("\n");

	printf("[4]Northwest ");
	if(curr->info.x%2==0){
		if(check_cell((curr->info.x)-1,(curr->info.y)+1,map,size_map,head)==0)printf("               unavailable!");
	}
	else{
		if(check_cell((curr->info.x)-1,curr->info.y,map,size_map,head)==0)printf("               unavailable!");
	}
	printf("\n");

	printf("[5]Southeast ");
	if(curr->info.x%2==0){
		if(check_cell((curr->info.x)+1,curr->info.y,map,size_map,head)==0)printf("               unavailable!");
	}
	else{
		if(check_cell((curr->info.x)+1,(curr->info.y)-1,map,size_map,head)==0)printf("                unavailable!");
	}
	printf("\n");

	printf("[6]Southwest ");
	if(curr->info.x%2==0){
		if(check_cell((curr->info.x)-1,curr->info.y,map,size_map,head)==0)printf("                 unavailable!");
	}
	else{
		if(check_cell((curr->info.x)-1,(curr->info.y)-1,map,size_map,head)==0)printf("               unavailable!");
	}
	printf("\n");

	int direction;
	scanf("%d",&direction);
	//1 north
	if(direction==1 && check_cell(curr->info.x,(curr->info.y)+1,map,size_map,head)==1)curr->info.y++;
	//2 south
	else if(direction==2 && check_cell(curr->info.x,(curr->info.y)-1,map,size_map,head)==1)curr->info.y--;
	//3 northeast
	else if(direction==3){
		if((curr->info.x)%2==0 && check_cell((curr->info.x)+1,(curr->info.y)+1,map,size_map,head)==1)curr->info.y++;
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
