
#include <iostream>
#include "Color2Gray.h"
#include "utils.h"
#include <math.h>


using namespace std;
Mat source, result;
int rows, cols, total_pixel;


void exec(const String &filename, const String& outFile, int u, int max_iter, float alpha, float theta) { 
    source = imread(filename,IMREAD_COLOR);
    cols = source.cols;
    rows=source.rows;
    total_pixel = rows * cols;
    rgb image[total_pixel];
    for(int i=0;i<total_pixel;i++){
        int r=i/cols;
        int c=i%cols;
        image[i]=rgb(source.at<Vec3b>(r,c)[0],source.at<Vec3b>(r,c)[1],source.at<Vec3b>(r,c)[2]);
        image[i].rgb_to_xyz();
        image[i].xyz_to_lab();
    }

    float * deltas = new float[total_pixel];
    float *gray=new float[total_pixel];
    for (int i=0; i<total_pixel; i++) {
        deltas[i] = 0;
        gray[i]=image[i].l_;
    }
    //cols=w
    for(int x=0;x<cols;x++){
        for(int y=0;y<rows;y++){
            int index1=x+y*cols;
            int left=u>0?((x-u)>0? (x-u): 0):0;
            int right=u>0?((u+x)<cols? (u+x):cols-1):cols-1;
            int up=u>0?((y-u)>0? (y-u):0):0;
            int down=u>0?((u+y)<rows? (u+y):rows-1):rows-1;
            for(int xx=left;xx<=right;xx++){
                for(int yy=up;yy<=down;yy++){
                    int index2=xx+yy*cols;
                    float temp=delta_count(alpha,theta,image[index1].l_,image[index2].l_,image[index1].a_,image[index1].b_,image[index2].a_,image[index2].b_);
                    deltas[index1]+=temp;
                }
            }
        }
    }

    for(int i=0;i<max_iter;i++){
        for(int x=0;x<cols;x++){
            for(int y=0;y<rows;y++){
                float sum=0,count=0;
                int index1=x+y*cols;
                int left=u>0?(x-u>0? x-u: 0):0;
                int right=u>0?(u+x<cols? u+x:cols-1):cols-1;
                int up=u>0?(y-u>0? y-u:0):0;
                int down=u>0?(u+y<rows? u+y:rows-1):rows-1;
                for(int xx=left;xx<=right;xx++){
                    for(int yy=up;yy<=down;yy++){
                        int index2=yy*cols+xx;
                        sum+=image[index2].l_;
                        count++;
                    }
                }
            image[index1].l_=(deltas[index1]+sum)/(float)count;
            }
        }
    }
    
    float error=0.0;
    for(int i=0;i<total_pixel;i++){
        error+=image[i].l_-gray[i];
    }
    error/=float(total_pixel);
    for(int i=0;i<total_pixel;i++){
        image[i].l_-=error;
    }

    for(int i=0;i<total_pixel;i++){
        int row=i/cols;
        int col=i%cols;
        image[i].a_=0.0;
        image[i].b_=0.0; 
        image[i].lab_to_xyz();
        image[i].xyz_to_rgb();
        source.at<Vec3b>(row,col)[0]=image[i].r;
        source.at<Vec3b>(row,col)[1]=image[i].g;
        source.at<Vec3b>(row,col)[2]=image[i].b;

    }

    Mat origin=imread(filename);
    Mat photoshop;
    cvtColor(origin,photoshop,COLOR_BGR2GRAY);
    imwrite("photoshop.ppm",photoshop);
    imwrite("result.ppm",source);

    imshow("origin",origin);
    imshow("photoshop",photoshop);
    //imshow("result",result);
    imshow("source",source);

    waitKey(0);
    
    delete [] deltas;

    delete [] gray;


}
