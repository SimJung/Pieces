#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
	double x1, x2, x3, y1, y2, y3, d1, d2, cntx, cnty, rad, ppi = 3.141592653589793;
	cout<<fixed;
	cout.precision(2);
	
	while(1) {
		cin>>x1>>y1>>x2>>y2>>x3>>y3; 

		//두 수직 이등분선의 기울기를 입력

		d1=(x2-x1)/(y2-y1);

		d2=(x3-x2)/(y3-y2);

 

		//원의 중점을 구함

		cx=((y3-y1)+(x2+x3)*d2-(x1+x2)*d1)/(2*(d2-d1))

		cy=-d1*(cx-(x1+x2)/2)+(y1+y2)/2

 

		//원의 반지름을 구함

		r=sqrt((x1-cx)^2+(y1-cy)^2)

 

		//임의의 x좌표에서 원의 y값을 구함

		x=22500;

		y1=sqrt(r^2-(x-cx)^2)+cy
	}
	
	return 0;
}
