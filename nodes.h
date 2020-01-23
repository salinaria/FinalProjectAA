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
int check_available(int x,int y,struct node *head){
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
