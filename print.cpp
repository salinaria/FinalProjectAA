#include <stdlib.h>
#include <stdio.h>
#include <graphics.h>
using namespace std;
void print_map(int **my_map,int size_map){
    int i,j;
    float x=600/(size_map+0.5);
    float y=600/size_map;
    for(i=0;i<size_map;i++){
        for(j=0;j<size_map;j++){
            if(my_map[i][j]==1){
                setfillstyle(1,3);
                if(j%2==0)
                    bar(y*j,(size_map-i)*x,y*j+y,(size_map-i-1)*x);
                else
                    bar(y*j,(size_map-i)*x+x/2,y*j+y,(size_map-i-1)*x+x/2);
            }
            if(my_map[i][j]==2){
                setfillstyle(1,4);
                if(j%2==0)
                    bar(y*j,(size_map-i)*x,y*j+y,(size_map-i-1)*x);
                else
                    bar(y*j,(size_map-i)*x+x/2,y*j+y,(size_map-i-1)*x+x/2);
            }
            if(my_map[i][j]==3){
                setfillstyle(1,5);
                if(j%2==0)
                    bar(y*j,(size_map-i)*x,y*j+y,(size_map-i-1)*x);
                else
                    bar(y*j,(size_map-i)*x+x/2,y*j+y,(size_map-i-1)*x+x/2);
            }
            if(my_map[i][j]==4){
                setfillstyle(1,7);
                if(j%2==0)
                    bar(y*j,(size_map-i)*x,y*j+y,(size_map-i-1)*x);
                else
                    bar(y*j,(size_map-i)*x+x/2,y*j+y,(size_map-i-1)*x+x/2);
            }
        }
    }
}
/*main()
{
    initwindow(600,600);
    int i,j,size_map=3;
    int **my_map;
    my_map=(int **)malloc(3*sizeof(int *));
    my_map[0]=(int *)malloc(3*sizeof(int));
    my_map[1]=(int *)malloc(3*sizeof(int));
    my_map[2]=(int *)malloc(3*sizeof(int));
    my_map[0][0]=1;
    my_map[0][1]=2;
    my_map[0][2]=3;
    my_map[1][0]=4;
    my_map[1][1]=1;
    my_map[1][2]=2;
    my_map[2][0]=3;
    my_map[2][1]=4;
    my_map[2][2]=1;
    print_map(my_map,3);
    getch();
}*/
