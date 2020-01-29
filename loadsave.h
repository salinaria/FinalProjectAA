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
int **load_map(int **map,int size_map){
	FILE *fp=fopen("savemap.txt","r");
	int i,j;
	map=(int **)malloc(size_map*sizeof(int*));
	for(i=0;i<size_map;i++){
		map[i]=(int *)malloc(size_map*sizeof(int));
		for(j=0;j<size_map;j++){
			fscanf(fp,"%d",&map[i][j]);
		}
	}
	fclose(fp);
	return map;
}
void save_cell_single(struct node *head){
	FILE *fp=fopen("savecell1.txt","w");
	FILE *fpr=fopen("numplayer.txt","w");
	fprintf(fpr,"%d",1);
	struct node *curr=head;
	while(curr!=NULL){
		fprintf(fp,"%d %d %d %s ",curr->info.x,curr->info.y,curr->info.energy,curr->info.name);
		curr=curr->next;
	}
	fclose(fp);
	fclose(fpr);
}
void save_cell_multi(struct node *head_1,struct node *head_2){
	FILE *fp1=fopen("savecell1.txt","w");
	FILE *fp2=fopen("savecell2.txt","w");
	FILE *fpr=fopen("numplayer.txt","w");
	fprintf(fpr,"%d",2);
	struct node* curr=head_1;
	while(curr!=NULL){
		fprintf(fp1,"%d %d %d %s ",curr->info.x,curr->info.y,curr->info.energy,curr->info.name);
		curr=curr->next;
	}
	curr=head_2;
	while(curr!=NULL){
		fprintf(fp2,"%d %d %d %s ",curr->info.x,curr->info.y,curr->info.energy,curr->info.name);
		curr=curr->next;
	}
	fclose(fp1);
	fclose(fp2);
	fclose(fpr);
}
struct node* load_cell_1(struct node *head){
	FILE *fp=fopen("savecell1.txt","r");
	struct node* curr=head;
	fscanf(fp,"%d %d %d %s ",&curr->info.x,&curr->info.y,&curr->info.energy,&curr->info.name);
	curr->info.cellid=1;
	curr->next=NULL;
	int i=1;
	while(1){
        struct node *new_node=(struct node*)malloc(sizeof(struct node));
		fscanf(fp,"%d %d %d %s ",&new_node->info.x,&new_node->info.y,&new_node->info.energy,&new_node->info.name);
		new_node->info.cellid=i+1;
		i++;
		new_node->next=NULL;
        curr->next=new_node;
        curr=curr->next;
        if(feof(fp))break;
	}
	fclose(fp);
	return head;
}
struct node *load_cell_2(struct node *head){
	FILE *fp=fopen("savecell2.txt","r");
	struct node* curr=head;
	fscanf(fp,"%d %d %d %s ",&curr->info.x,&curr->info.y,&curr->info.energy,&curr->info.name);
	curr->info.cellid=1;
	curr->next=NULL;
	int i=1;
	while(1){
        struct node *new_node=(struct node*)malloc(sizeof(struct node));
		fscanf(fp,"%d %d %d %s ",&new_node->info.x,&new_node->info.y,&new_node->info.energy,&new_node->info.name);
		new_node->info.cellid=i+1;
		i++;
		new_node->next=NULL;
        curr->next=new_node;
        curr=curr->next;
        if(feof(fp))break;
	}
	fclose(fp);
	return head;
}

