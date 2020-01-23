#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "nodes.h"
void mitosis(struct node* head,int x,int y,char *celname){
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
void energy(struct node* head,char *celname,int energy){
	struct node* curr=head;
	while(strcmp(curr->info.name,celname)!=0)curr=curr->next;
	curr->info.energy+=energy;
	if(curr->info.energy>100)curr->info.energy=100;
}





