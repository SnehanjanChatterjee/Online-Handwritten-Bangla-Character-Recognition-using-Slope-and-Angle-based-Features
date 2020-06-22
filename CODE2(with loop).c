#include<stdio.h>
#include<stdlib.h>
#include<cv.h>
#include<cxcore.h>
#include<highgui.h>
#include<math.h>
char r[200];
int i,p,c,j,n,var=0;
float slope1,slope2,angle1,angle2,sum_x,sum_y,cg_x,cg_y,a;
void main()
   {
       printf("enter no of segments");
        scanf("%d",&n);
       for(var=0;var<5;var++)
        {
            sprintf(r,"D:\\DATA SET\\unit data\\A\\normalized\\unit_scalled_coordinate%04d",var);
            saf(r,n);
            printf("END OF 1ST ITERATION\n\n\n");
        }
   }
void saf(char *r,int n)
   {
       FILE *fp;
       FILE *ptr;
       float x[1000],y[1000],z[1000];

       //int i,j,p,c,var=0;
       //oat slope,angle1,a,sum;
        ptr=fopen("D:\\SLOPE_ANGEL CODES\\MERGED CODE\\NEW1.dat","a");
       fp=fopen(r,"r");
        i=0;p=0;c=1;j=0;slope1=0.0;angle1=0.0;slope2=0.0;angle2=0.0;a=0;sum_x=0.0;sum_y=0.0;cg_x=0.0;cg_y=0.0;
        while(!feof(fp))
            {

              fscanf(fp,"%f %f %f\n",&x[i],&y[i],&z[i]);
              i++;
            }

        fclose(fp);
        for(j=0;j<(i-1);j++)
           {
              if(x[j+1]==x[j])
              {
                  slope1=0.0;
                  angle1=0.0;

              }
              else
              {
              slope1=((y[j+1]-y[j])/(x[j+1]-x[j]));

              angle1=atan(slope1);
              if(slope1>=0)
                slope1=1;
              else if(slope1<0)
                slope1=-1;
           }

             // printf("ANGLE1=%f\n",angle1);
              //printf("SLOPE=%f\n",slope);
              fprintf(ptr,"%f,",angle1);
              fprintf(ptr,"%f,",slope1);


           }
            for(j=0;j<i;j++)
           {
               sum_x=sum_x+x[j];
               //printf("%f\n",sum_x);
               sum_y=sum_y+y[j];
           }
          // printf("%f",sum_x);
           cg_x=(sum_x/j);
           cg_y=(sum_y/j);
           fprintf(ptr,"%f,",cg_x);
           fprintf(ptr,"%f,",cg_y);
            //printf("%f\n",cg_x);
            //printf("%f\n",cg_y);
           for(j=0;j<i;j++)
           {
             if(j==0 || ((j+1)%n)==0)
             {
                 if(cg_x==x[j])
                 {angle2=0.0;
                  slope2=0.0;}
                 else
                {slope2=((cg_y-y[j])/(cg_x-x[j]));
                //printf("SLOPE2=%f\n",slope2);
                angle2=atan(slope2);
                if(slope2>=0)
                    slope2=2;
                else if(slope2<0)
                    slope2=-2;


                }
                fprintf(ptr,"%f,",angle2);
                fprintf(ptr,"%f,",slope2);

                //printf("ANGLE=%f\n",angle2);
                //printf("SLOPE=%f\n\n\n",slope2);

             }
           }
            fprintf(ptr,"A\n");


   }
