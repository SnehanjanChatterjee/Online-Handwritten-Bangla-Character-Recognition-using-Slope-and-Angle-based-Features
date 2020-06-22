#include<stdio.h>
#include<stdlib.h>
#include<cv.h>
#include<cxcore.h>
#include<highgui.h>
#include<math.h>
float x[1000],y[1000],z[1000];
char r[200];
int i,j,var=0;
float cg_x,cg_y,sum_x,sum_y;
void main()
    {
        FILE *fp;
        FILE *ptr;
        ptr=fopen("D:\\SLOPE_ANGEL CODES\\DAT FILES\\CG.DAT(10k)","a");
        for(var=0;var<200;var++)
        {sprintf(r,"D:\\Data set\\unit data\\YA\\normalized\\unit_scalled_coordinate%04d",var);
        puts(r);
        fp=fopen(r,"r");
        i=0;cg_x=0.0;cg_y=0.0;sum_x=0.0;sum_y=0.0;j=0;
        while(!feof(fp))
            {

              fscanf(fp,"%f %f %f\n",&x[i],&y[i],&z[i]);
              i++;
            }

            fclose(fp);
        for(j=0;j<i;j++)
           {
               sum_x=sum_x+x[j];
               //printf("%f\n",sum_x);
               sum_y=sum_y+y[j];
           }
          // printf("%f",sum_x);
           cg_x=(sum_x/j);
           cg_y=(sum_y/j);
              printf("CG_X=%f\n",cg_x);
              printf("CG_Y=%f\n",cg_y);
              //printf("ANGLE=%f\n\n\n",angle);
              fprintf(ptr,"%f,",cg_x);
              fprintf(ptr,"%f,",cg_y);
              //fprintf(ptr,"%f,",angle);
              //c++;

          fprintf(ptr,"YA\n");
         // printf("counter=%d",c);
          //getch();
        }
    }

