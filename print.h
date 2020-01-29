void print_map_single(int **my_map,int size_map,struct node *head){
    int i,j;
    float x=600/(size_map);
    float y=600/(size_map+0.5);
    for(i=0;i<size_map;i++){
        for(j=0;j<size_map;j++){
            if(my_map[i][j]==2){
                setfillstyle(1,BLUE);
                if(i%2==0){
                    bar(i*x,(size_map-j-1)*y,(i+1)*x,(size_map-j)*y);
                    rectangle(i*x,(size_map-j-1)*y,(i+1)*x,(size_map-j)*y);
                }
                else{
                    bar(i*x,(size_map-j-1)*y+y/2,(i+1)*x,(size_map-j)*y+y/2);
                    rectangle(i*x,(size_map-j-1)*y+y/2,(i+1)*x,(size_map-j)*y+y/2);
                }
            }
            else if(my_map[i][j]==3){
                setfillstyle(2,RED);
                if(i%2==0){
                    bar(i*x,(size_map-j-1)*y,(i+1)*x,(size_map-j)*y);
                    rectangle(i*x,(size_map-j-1)*y,(i+1)*x,(size_map-j)*y);
                }
                else{
                    bar(i*x,(size_map-j-1)*y+y/2,(i+1)*x,(size_map-j)*y+y/2);
                    rectangle(i*x,(size_map-j-1)*y+y/2,(i+1)*x,(size_map-j)*y+y/2);
                }
            }
            else if(my_map[i][j]==4){
                setfillstyle(3,YELLOW);
                if(i%2==0){
                    bar(i*x,(size_map-j-1)*y,(i+1)*x,(size_map-j)*y);
                    rectangle(i*x,(size_map-j-1)*y,(i+1)*x,(size_map-j)*y);
                }
                else{
                    bar(i*x,(size_map-j-1)*y+y/2,(i+1)*x,(size_map-j)*y+y/2);
                    rectangle(i*x,(size_map-j-1)*y+y/2,(i+1)*x,(size_map-j)*y+y/2);
                }
            }
            else{
                setfillstyle(4,GREEN);
				if(i%2==0){
                    bar(i*x,(size_map-j-1)*y,(i+1)*x,(size_map-j)*y);
                    rectangle(i*x,(size_map-j-1)*y,(i+1)*x,(size_map-j)*y);
                }
                else{
                    bar(i*x,(size_map-j-1)*y+y/2,(i+1)*x,(size_map-j)*y+y/2);
                    rectangle(i*x,(size_map-j-1)*y+y/2,(i+1)*x,(size_map-j)*y+y/2);
                }
            }
        }
    }
    struct node *curr=head;
    while(curr!=NULL){
        setfillstyle(1,WHITE);
        if((curr->info.x)%2==0){
            fillellipse((curr->info.x)*x+x/2,y*(size_map-curr->info.y)-y/2,x/8,x/8);
        }
        else{
            fillellipse((curr->info.x)*x+x/2,y*(size_map-curr->info.y+1/2),x/8,x/8);
        }
        curr=curr->next;
    }
}
void print_map_multi(int **my_map,int size_map,struct node *head_1,struct node *head_2){
    int i,j;
    float x=600/(size_map);
    float y=600/(size_map+0.5);
    for(i=0;i<size_map;i++){
        for(j=0;j<size_map;j++){
            if(my_map[i][j]==2){
                setfillstyle(1,BLUE);
                if(i%2==0){
                    bar(i*x,(size_map-j-1)*y,(i+1)*x,(size_map-j)*y);
                    rectangle(i*x,(size_map-j-1)*y,(i+1)*x,(size_map-j)*y);
                }
                else{
                    bar(i*x,(size_map-j-1)*y+y/2,(i+1)*x,(size_map-j)*y+y/2);
                    rectangle(i*x,(size_map-j-1)*y+y/2,(i+1)*x,(size_map-j)*y+y/2);
                }
            }
            else if(my_map[i][j]==3){
                setfillstyle(2,RED);
                if(i%2==0){
                    bar(i*x,(size_map-j-1)*y,(i+1)*x,(size_map-j)*y);
                    rectangle(i*x,(size_map-j-1)*y,(i+1)*x,(size_map-j)*y);
                }
                else{
                    bar(i*x,(size_map-j-1)*y+y/2,(i+1)*x,(size_map-j)*y+y/2);
                    rectangle(i*x,(size_map-j-1)*y+y/2,(i+1)*x,(size_map-j)*y+y/2);
                }
            }
            else if(my_map[i][j]==4){
                setfillstyle(3,YELLOW);
                if(i%2==0){
                    bar(i*x,(size_map-j-1)*y,(i+1)*x,(size_map-j)*y);
                    rectangle(i*x,(size_map-j-1)*y,(i+1)*x,(size_map-j)*y);
                }
                else{
                    bar(i*x,(size_map-j-1)*y+y/2,(i+1)*x,(size_map-j)*y+y/2);
                    rectangle(i*x,(size_map-j-1)*y+y/2,(i+1)*x,(size_map-j)*y+y/2);
                }
            }
            else{
                setfillstyle(4,GREEN);
				if(i%2==0){
                    bar(i*x,(size_map-j-1)*y,(i+1)*x,(size_map-j)*y);
                    rectangle(i*x,(size_map-j-1)*y,(i+1)*x,(size_map-j)*y);
                }
                else{
                    bar(i*x,(size_map-j-1)*y+y/2,(i+1)*x,(size_map-j)*y+y/2);
                    rectangle(i*x,(size_map-j-1)*y+y/2,(i+1)*x,(size_map-j)*y+y/2);
                }
            }
        }
    }
    struct node *curr=head_1;
    while(curr!=NULL){
        setfillstyle(1,WHITE);
        if((curr->info.x)%2==0){
            fillellipse((curr->info.x)*x+x/2,y*(size_map-curr->info.y)-y/2,x/8,x/8);
        }
        else{
            fillellipse((curr->info.x)*x+x/2,y*(size_map-curr->info.y+1/2),x/8,x/8);
        }
        curr=curr->next;
    }
    curr=head_2;
    while(curr!=NULL){
        setfillstyle(1,BLACK);
        if((curr->info.x)%2==0){
            fillellipse((curr->info.x)*x+x/2,y*(size_map-curr->info.y)-y/2,x/8,x/8);
        }
        else{
            fillellipse((curr->info.x)*x+x/2,y*(size_map-curr->info.y+1/2),x/8,x/8);
        }
        curr=curr->next;
    }
}
