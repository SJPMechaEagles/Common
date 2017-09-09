/* 
* Vex Specific Math Functions, includes:
* Cartesian to polar cordinates
*/

#ifndef _VMATH_H_
#define _VMATH_H_

#include <math.h>

/*
* A struct that contains polar cordinates.
* Added by Chris Jerrett
*/
struct polar_cord {
  float angle;
  float magnitue;
};

/*
* Function to convert x and y 2 dimensional cartesian cordinated to Polar
* Cordinates. 
* 
* Added by Christian Desimone
*
* Returns a struct containing the angle and magnitude.
* x: float value of the x cartesian cordinate.
* y: float value of the y cartesian cordinate.
*/
struct polar_cord cartesian_to_polar(float x, float y) {
  float degree = 0;
  double magnitude = sqrt((fabs(x) * fabs(x)) + (fabs(y) * fabs(y)));

  if(x < 0){
    degree += 180.0;
  }
  else if(x > 0 && y < 0){
    degree += 360.0;
  }

  if(x != 0 && y != 0){
    degree += atan((float)y / (float)x);
  }
  else if(x == 0 && y > 0){
    degree = 90.0;
  }
  else if(y == 0 && x < 0){
    degree = 180.0;
  }
  else if(x == 0 && y < 0){
    degree = 270.0;
  }

  struct polar_cord p;
  p.angle = degree;
  p.magnitue = magnitude;
  return p;
}

#endif
