#include <stdio.h>
#include <math.h>

struct point{       //Stores the  x's and y's
    float x;    //Access to x values
    float y;    //Access to y values
};

struct line{         //Stores the coordinates of the both starting and ending points
    struct point start;     //Access to starting point x,y
    struct point end;       //Access to ending point x,y
};


struct point whereMidpoint(struct line);     //Structure declaration for finding the midpoint
float goDistance(struct line);        //for finding the distance between the two points given by the user
float goSlope(struct line);             //for finding the slope given by the starting x and y and ending x and y

int main(){
    struct point mid;
    struct line lineStruct;
    float distance;
    float m;
    float b;
    

    /* Asks the user for the x,y coords of starting point */
    printf("Enter x and y coordinates of starting point: ");
    scanf("%f %f", &lineStruct.start.x, &lineStruct.start.y);
    
    /* Asks the user for the x,y coords of ending point */
    printf("Enter x and y coordinate of ending point: ");
    scanf("%f %f", &lineStruct.end.x, &lineStruct.end.y);
    
    /* Displays here the Results */
    m = goSlope(lineStruct);    //Calls the function and returns with the value of Slope
    printf("\nSlope is (%.1f)\n", m);

    mid = whereMidpoint(lineStruct);   //Calls the function and returns with the value of midpoint with the x coordinate, and y coordinate 
    printf("Midpoint is (%.1f, %.1f)\n",
        mid.x, mid.y);

    distance = goDistance(lineStruct);    //Calls the function and returns with the value of the distance
    printf("Distance between (%.1f, %.1f) & (%.1f, %.1f) is %.1f\n",
        lineStruct.start.x, lineStruct.start.y, lineStruct.end.x, lineStruct.end.y, distance);
    
    /* Gets the value from the Slope and displays the Slope-Intercept Form */
    b = lineStruct.start.y - (m * lineStruct.start.x);  //Same as lineStruct.end.y - (m * lineStruct.end.x);
    printf("Slope-Intercept Form / Equation of the line is y = %.1fx + %.1f", m, b);
    return 0;   
} 

/* Definition and Calculates here the slope but uses if-statement in case dividing by 0 */
float goSlope(struct line lineStruct){
    float m;
    if (lineStruct.end.x - lineStruct.start.x != 0){
        m = (lineStruct.end.y - lineStruct.start.y) / (lineStruct.end.x - lineStruct.start.x);
        return m;   //Returns the value of the Slope
    }else{
        return __INT_MAX__; //Returns maximum integer value (if it divides by 0) to the main
    }
    
}

/* Calculates here the wheremidpoint x,y values */
struct point whereMidpoint(struct line lineStruct){
    struct point temp;  //Temporary variable for storing the wheremidpoint x,y values
    temp.x = (lineStruct.start.x + lineStruct.end.x) / 2.0;
    temp.y = (lineStruct.start.y + lineStruct.end.y) / 2.0;
    return temp;    //Returns the value of wheremidpoint to the main from temp x,y values
} 

/* Calculates here the value of the distance between two points */
float goDistance(struct line lineStruct){
    float distance;
    distance = sqrt((lineStruct.start.x - lineStruct.end.x) * (lineStruct.start.x -
        lineStruct.end.x) + (lineStruct.start.y - lineStruct.end.y) * (lineStruct.start.y -
        lineStruct.end.y));

    return distance; //Returns the value of distance to the main
}

