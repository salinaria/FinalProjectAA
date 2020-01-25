struct information{
	int x;
	int y;
	int energy;
	char name[5];
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
int check_cell(int x,int y,struct node *head){
	struct node *curr=head;
	while(curr->next!=NULL){
		if(curr->info.x==x){
			if(curr->info.y==y)return 0;
		}
		curr=curr->next;
	}
	return 1;
}
void create_node(struct node* head,int celnum,int map_size){
	int i,x,y,check=0;
	head=(struct node*)malloc(celnum*sizeof(struct node));
	struct node *curr=head;
	for(i=0;i<celnum;i++){
		curr->info.energy=0;
		//random x and y for cel
		while(check==0){
			x=rand()%map_size;
			y=rand()%map_size;
			check=check_available(x,y,head);
		}
		curr->info.x=x;
		curr->info.y=y;
		check=0;
		rand_name(curr->info.name);
		curr=curr->next;
	}
	curr->next=NULL;
}
void split_cell(struct node* head,int x,int y,char *celname){
	struct node* curr=head;
	struct node* new_node;
	new_node=(struct node*)malloc((sizeof(struct node)));
	//edit the cel mitosised
	while(strcmp(curr->info.name,celname)!=0)curr=curr->next;
	rand_name(curr->info.name);
	curr->info.energy=40;
	//creat new cell
	while(curr->next!=NULL)curr=curr->next;
	new_node->next=NULL;
	rand_name(new_node->info.name);
	new_node->info.energy=40;
	new_node->info.x=x;
	new_node->info.y=y;
	new_node->next=NULL;
	curr->next=new_node;
}
void energy_cell(struct node* head,char *celname,int energy){
	struct node* curr=head;
	while(strcmp(curr->info.name,celname)!=0)curr=curr->next;
	curr->info.energy+=energy;
	if(curr->info.energy>100)curr->info.energy=100;
}
void move(struct node *head,char *celname,int direction){
	struct node* curr=head;
	while(strcmp(curr->info.name,celname)!=0)curr=curr->next;
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


