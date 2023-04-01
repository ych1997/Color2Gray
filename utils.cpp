

#include "utils.h"
#include <iostream>
float crunch(float x,float alpha){
    if(alpha>0){
        return alpha*tanh(x/alpha);
    }
    else{
        return 0.;
    }
}

float delta_count(float alpha, float theta,float Li,float Lj,float Ci_a,float Ci_b,float Cj_a,float Cj_b){
    float Lij=Li-Lj;
    float Cija=Ci_a-Cj_a;
    float Cijb=Ci_b-Cj_b;
    float c_dis=sqrt(Cija*Cija+Cijb*Cijb);
    float crunch_c=crunch(c_dis,alpha);
    float r;
    if(abs(Lij)>crunch_c){
        return Lij;
    }
    else if(Cija*cos(theta)+Cijb*sin(theta)>=0){
        return crunch_c;
    }
    else{
        return -crunch_c;
    }
}

