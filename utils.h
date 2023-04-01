

#ifndef COLOR2GRAY_UTILS_H
#define COLOR2GRAY_UTILS_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <cmath>

using namespace cv;

float crunch(float x, float alpha);

float delta_count(float alpha, float theta, const float Li, const float Lj, const float Ci_a, const float Cj_a, const float Ci_b, const float Cj_b);


#endif //COLOR2GRAY_UTILS_H
