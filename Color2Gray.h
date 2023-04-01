

#ifndef COLOR2GRAY_COLOR2GRAY_H
#define COLOR2GRAY_COLOR2GRAY_H
#include<iostream>
#include <opencv/cv.hpp>
using namespace cv;
using namespace std;
inline float clamp(float x, float x_min, float x_max){
	 
	if (x < x_min) return(x_min);
	else if (x > x_max) return(x_max);
	else return(x);
}
void exec(const String& filename, const String& outFile, int u=1, int max_iter=5, float alpha=5, float theta=M_PI_4);
struct rgb{
    unsigned char r,g,b;
    float X,Y,Z;
    float l_,a_,b_;
    rgb(){}
    rgb(unsigned char r,unsigned char g,unsigned char b):r(r),g(g),b(b){}
    bool operator<(const rgb &c) const {
		if(r<c.r) return true;
		if(r>c.r) return false;
		if(g<c.g) return true;
		if(g>c.g) return false;		
		return b<c.b;
	}
    void rgb_to_xyz(){
        float B = b/255.;
		float G = g/255.;
		float R = r/255.;

		X = (0.412453f*R + 0.357580f*G + 0.180423f*B);
		Y = 0.212671f*R + 0.715160f*G + 0.072169f*B;
		Z = (0.019334f*R +  0.119193f*G + 0.950227f*B);

        const float Xn = 0.9513f;
		const float Yn = 1.000f;
		const float Zn = 1.0886f;

		X = X/Xn; Y = Y/Yn; Z = Z/Zn;       
        //count++;



    }
    void xyz_to_rgb(){

		
		float R = 3.240479f*X + -1.537150f*Y +  -0.498535f*Z;
		float G = -0.969256f*X +  1.875992f*Y +  0.041556f*Z;
		float B = 0.055648f*X +   -0.204043f*Y + 1.057311f*Z;

		r = clamp(R,0.0,1.0)*255.;
		g = clamp(G,0.0,1.0)*255.;
		b = clamp(B,0.0,1.0)*255.;

    }
    void xyz_to_lab() {

		float one_third=0.333333333333333333333333333333;

		float X_third = pow(X,(float)one_third);
		float Y_third = pow(Y,(float)one_third);
		float Z_third = pow(Z,(float)one_third);

		if (Y > 0.008856)
			l_ = (116.0f*(Y_third)) - 16.0f;
		else l_ = 903.3f*Y;

		a_= 500.0f * ((X_third) - (Y_third));
		b_= 200.0f * ((Y_third) - (Z_third));

	}
    void lab_to_xyz() {

		float P = (l_+16.0)/116.0;

		float Xn = 0.9513f;
		float Yn = 1.000f;
		float Zn = 1.0886f;

		 X = Xn * pow(P+ (a_/500.0f),3);
		 Y = Yn * pow(P,3);
		 Z = Zn * pow(P - (b_/200.0f),3);
	}



};


#endif //COLOR2GRAY_COLOR2GRAY_H
