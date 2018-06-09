#include <stdio.h>

//int MAX_Value (int coordinate1, int coordinate2);
//int MIN_Value (int coordinate1, int coordinate2);
int MAX_Value (int coordinate1, int coordinate2)
{
	//int max;
	if (coordinate1 > coordinate2)
		return coordinate1;
	else
		return coordinate2;
}

int MIN_Value (int coordinate1, int coordinate2)
{
	//int min;
	if (coordinate1 < coordinate2)
		return coordinate1;
	else
		return coordinate2;
}


int main()
{
	int Ax1, Ay1, Ax2, Ay2; // A coordinate
	int Bx1, By1, Bx2, By2; // B coordinate
	int Max_Ax, Min_Ax, Max_Bx, Min_Bx, Max_Ay, Min_Ay, Max_By, Min_By ;
	int temp_x, temp_x1, res_X, temp_y, temp_y1, res_Y, area;

	scanf( "%d  %d %d  %d", &Ax1, &Ay1, &Ax2, &Ay2 );
	scanf( "%d  %d %d  %d", &Bx1, &By1, &Bx2, &By2 );
//X Coordinate
	Max_Ax = MAX_Value (Ax1, Ax2);
	Min_Ax = MIN_Value (Ax1, Ax2);
	Max_Bx = MAX_Value (Bx1, Bx2);
	Min_Bx =  MIN_Value (Bx1, Bx2);
// Y Coordinate
	Max_Ay = MAX_Value (Ay1, Ay2);
	Min_Ay = MIN_Value (Ay1, Ay2);
	Max_By = MAX_Value (By1, By2);
	Min_By =  MIN_Value (By1, By2);

	if (Max_Ax < Max_Bx)
	{
		temp_x = Max_Ax;
	}
	else
	{
		temp_x = Max_Bx;
	}

	if (Min_Ax > Min_Bx)
	{
		temp_x1 = Min_Ax;
	}
	else
	{
		temp_x1 = Min_Bx;
	}

	res_X = temp_x - temp_x1;

	if (Max_Ay < Max_By)
	{
		temp_y = Max_Ay;
	}
	else
	{
		temp_y = Max_By;
	}

	if (Min_Ay > Min_By)
	{
		temp_y1 = Min_Ay;
	}
	else
	{
		temp_y1 = Min_By;
	}

	res_Y = temp_y - temp_y1;
	//calculate area
	if (res_X < 0 || res_Y < 0)
	{
		 area = 0;
	}
	else
	{
		area = res_X * res_Y;
	}

printf("%d\n", area );
	return 0;
}

//X and Ycoordinate Compare
