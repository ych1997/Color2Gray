#include <iostream>
#include <opencv/cv.h>
#include "Color2Gray.h"

using namespace cv;
using namespace std;

int main(int argc, const char** argv) {
    if (argc > 1) {
        int u = 5, max_iter = 30;
        float alpha = 5, theta =M_PI/4;
        char outFile[100];
        //cout<<M_PI<<endl;
        strcpy(outFile, "result.ppm");
        
        for (int i = 2; i < argc - 1; ++i) {
            if (strcmp(argv[i], "-u") == 0) {
                u = atoi(argv[i+1]);
                //printf("u:%d\n",u);
                ++i;
            } else if (strcmp(argv[i], "-iter") == 0) {
                max_iter = atoi(argv[i+1]);
                //printf("iter:%d\n",max_iter);
            } else if (strcmp(argv[i], "-alpha") == 0) {
                alpha = atof(argv[i+1]);
                ++i;
            } else if (strcmp(argv[i], "-theta") == 0) {

                theta = atof(argv[i+1]);
                theta*=  M_PI/180.0;
                ++i;
            } else if (strcmp(argv[i], "-o") == 0) {
                strcpy(outFile, argv[i+1]);
                //cout<<"argv[i+1]"<<argv[i+1]<<endl;
                ++i;
            }
            
        }
        
        printf("out=%s, u=%i, iter=%i, alpha=%.2f, theta=%.2f\n", outFile, u, max_iter, alpha, theta*180/M_PI );
        exec(argv[1],outFile, u, max_iter, alpha,theta);
    } 
    else {
        cout << "Instruction: <filename> [-u region size] [-iter iteration size] [-alpha alpha] [-theta theta*4/PI]" << endl;
    }
    return 0;
}