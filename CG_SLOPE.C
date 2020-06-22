#include<stdio.h>
#include<stdlib.h>
#include<cv.h>
#include<cxcore.h>
#include<highgui.h>
#include<math.h>
float x[1000],y[1000],z[1000];
char r[200];
int i,j,var=0,n;
float cg_x,cg_y,sum_x,sum_y,slope1,slope2,angle1,angle2;
void main()
    {
        FILE *fp;
        FILE *ptr;
        ptr=fopen("D:\\SLOPE_ANGEL CODES\\DAT FILES\\CG_SLOPE(2).DAT(10k)","a");
        printf("enter no of segments");
        scanf("%d",&n);
        for(var=0;var<200;var++)
        {sprintf(r,"D:\\Data set\\unit data\\YA\\normalized\\unit_scalled_coordinate%04d",var);
        puts(r);
        fp=fopen(r,"r");
        i=0;cg_x=0.0;cg_y=0.0;sum_x=0.0;sum_y=0.0;j=0;slope1=0.0;
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
           //printf("%f\n",cg_x);
            //printf("%f\n",cg_y);
           for(j=0;j<i;j++)
           {
             if(j==0 || ((j+1)%n)==0)
             {
                 if(cg_x==x[j])
                 slope1=2.0;
                 else
                {slope1=((cg_y-y[j])/(cg_x-x[j]));
                 if(slope1>0)
                    slope1=1;
                 else if(slope1<0)
                    slope1=-1;
                 else
                    slope1=0;}
                //angle1=atan(slope1);}
                //slope2=((cg_y-y[j-1])/(cg_x-x[j-1]));
                //angle2=atan(slope2);
                printf("SLOPE1=%f\n",slope1);
                //printf("ANGLE1=%f\n",angle2);
              //printf("ANGLE=%f\n\n\n",angle);
                fprintf(ptr,"%f,",slope1);
                //fprintf(ptr,"%f,",angle2);
              //fprintf(ptr,"%f,",angle);
              //c++;
             }
           }
          fprintf(ptr,"YA\n");
         // printf("counter=%d",c);
          //getch();
        }
    }

