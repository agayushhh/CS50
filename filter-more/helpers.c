#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int avg_gray=0;
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            avg_gray=(image[i][j].rgbtRed+image[i][j].rgbtBlue+image[i][j].rgbtGreen)/3;
            image[i][j].rgbtRed = avg_gray;
            image[i][j].rgbtGreen = avg_gray;
            image[i][j].rgbtBlue = avg_gray;

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int temp;
    int h= height;
    int w= width;
     for(int i=0;i<height;i++)
    {
        for(int j=0;j<width/2;j++)
        {

            temp = image[i][j].rgbtRed;
            image[i][j].rgbtRed = image[i][w-1-j].rgbtRed;
            image[i][w-1-j].rgbtRed =  temp;
            temp = image[i][j].rgbtGreen;
            image[i][j].rgbtGreen = image[i][w-1-j].rgbtGreen;
            image[i][w-1-j].rgbtGreen =  temp;
            temp = image[i][j].rgbtBlue;
            image[i][j].rgbtBlue = image[i][w-1-j].rgbtBlue;
            image[i][w-1-j].rgbtBlue =  temp;

        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int h= height;
    int w= width;
    int red,Green,Blue;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            if(i==0 && j==0)
             {
                red=(image[i][j].rgbtRed+image[i+1][j].rgbtRed+image[i][j+1].rgbtRed+image[i+1][j+1].rgbtRed)/4;
                Green=(image[i][j].rgbtGreen + image[i+1][j].rgbtGreen +image[i][j+1].rgbtGreen +image[i+1][j+1].rgbtGreen)/4;
                Blue =(image[i][j].rgbtBlue+image[i+1][j].rgbtBlue+image[i][j+1].rgbtBlue+image[i+1][j+1].rgbtBlue)/4;
                image[i][j].rgbtRed = red;
                image[i][j].rgbtGreen = Green;
                image[i][j].rgbtBlue = Blue;


             }
          else if(i==0 && j!=w-1)
             {
                red=(image[i][j].rgbtRed+image[i+1][j].rgbtRed+image[i][j+1].rgbtRed+image[i+1][j+1].rgbtRed + image[i][j-1].rgbtRed+image[i+1][j-1].rgbtRed)/6;
                Green=(image[i][j].rgbtGreen + image[i+1][j].rgbtGreen +image[i][j+1].rgbtGreen +image[i+1][j+1].rgbtGreen +image[i+1][j-1].rgbtGreen +image[i][j-1].rgbtGreen)/6;
                Blue =(image[i][j].rgbtBlue+image[i+1][j].rgbtBlue+image[i][j+1].rgbtBlue+image[i+1][j+1].rgbtBlue + image[i][j-1].rgbtBlue +image[i+1][j-1].rgbtBlue)/6;
                image[i][j].rgbtRed = red;
                image[i][j].rgbtGreen = Green;
                image[i][j].rgbtBlue = Blue;
             }
        else if (i==0 && j== w-1)
           {
                red=(image[i][j].rgbtRed+image[i][j-1].rgbtRed+image[i+1][j].rgbtRed+image[i+1][j-1].rgbtRed)/4;
                Green=(image[i][j].rgbtGreen + image[i+1][j].rgbtGreen +image[i][j-1].rgbtGreen +image[i+1][j-1].rgbtGreen)/4;
                Blue =(image[i][j].rgbtBlue+image[i+1][j].rgbtBlue+image[i][j-1].rgbtBlue+image[i+1][j-1].rgbtBlue)/4;
                image[i][j].rgbtRed = red;
                image[i][j].rgbtGreen = Green;
                image[i][j].rgbtBlue = Blue;
           }
         else if(i!=h-1 && j==w-1)
             {
                red=(image[i][j].rgbtRed+image[i+1][j].rgbtRed+image[i-1][j].rgbtRed+image[i+1][j-1].rgbtRed + image[i][j-1].rgbtRed+image[i-1][j-1].rgbtRed)/6;
                Green=(image[i][j].rgbtGreen + image[i+1][j].rgbtGreen +image[i-1][j].rgbtGreen +image[i+1][j-1].rgbtGreen +image[i-1][j-1].rgbtGreen +image[i][j-1].rgbtGreen)/6;
                Blue =(image[i][j].rgbtBlue+image[i+1][j].rgbtBlue+image[i-1][j].rgbtBlue+image[i+1][j-1].rgbtBlue + image[i-1][j-1].rgbtBlue +image[i][j-1].rgbtBlue)/6;
                image[i][j].rgbtRed = red;
                image[i][j].rgbtGreen = Green;
                image[i][j].rgbtBlue = Blue;
             }

         else if (i== h-1 && j== w-1)
           {
                red=(image[i][j].rgbtRed+image[i][j-1].rgbtRed+image[i-1][j].rgbtRed+image[i-1][j-1].rgbtRed)/4;
                Green=(image[i][j].rgbtGreen + image[i-1][j].rgbtGreen +image[i][j-1].rgbtGreen +image[i-1][j-1].rgbtGreen)/4;
                Blue =(image[i][j].rgbtBlue+image[i-1][j].rgbtBlue+image[i][j-1].rgbtBlue+image[i-1][j-1].rgbtBlue)/4;
                image[i][j].rgbtRed = red;
                image[i][j].rgbtGreen = Green;
                image[i][j].rgbtBlue = Blue;
           }

         else if(i==h-1 && j!=0)
             {
                red=(image[i][j].rgbtRed+image[i-1][j].rgbtRed+image[i][j-1].rgbtRed+image[i][j+1].rgbtRed + image[i-1][j-1].rgbtRed+image[i-1][j+1].rgbtRed)/6;
                Green=(image[i][j].rgbtGreen + image[i-1][j].rgbtGreen +image[i][j-1].rgbtGreen +image[i][j+1].rgbtGreen +image[i-1][j+1].rgbtGreen +image[i-1][j-1].rgbtGreen)/6;
                Blue =(image[i][j].rgbtBlue+image[i-1][j].rgbtBlue+image[i][j-1].rgbtBlue+image[i][j+1].rgbtBlue + image[i-1][j+1].rgbtBlue +image[i-1][j-1].rgbtBlue)/6;
                image[i][j].rgbtRed = red;
                image[i][j].rgbtGreen = Green;
                image[i][j].rgbtBlue = Blue;
             }

         else if (i== h-1 && j== 0) //lower left coorner.
           {
                red=(image[i][j].rgbtRed+image[i][j+1].rgbtRed+image[i-1][j].rgbtRed+image[i-1][j+1].rgbtRed)/4;
                Green=(image[i][j].rgbtGreen + image[i-1][j].rgbtGreen +image[i][j+1].rgbtGreen +image[i-1][j+1].rgbtGreen)/4;
                Blue =(image[i][j].rgbtBlue+image[i-1][j].rgbtBlue+image[i][j+1].rgbtBlue+image[i-1][j+1].rgbtBlue)/4;
                image[i][j].rgbtRed = red;
                image[i][j].rgbtGreen = Green;
                image[i][j].rgbtBlue = Blue;
           }
         else if(i!=0 && j==0)
             {
                red=(image[i][j].rgbtRed+image[i-1][j].rgbtRed+image[i+1][j].rgbtRed+image[i][j+1].rgbtRed + image[i-1][j+1].rgbtRed+image[i+1][j+1].rgbtRed)/6;
                Green=(image[i][j].rgbtGreen + image[i-1][j].rgbtGreen +image[i+1][j].rgbtGreen +image[i][j+1].rgbtGreen +image[i-1][j+1].rgbtGreen +image[i+1][j+1].rgbtGreen)/6;
                Blue =(image[i][j].rgbtBlue+image[i-1][j].rgbtBlue+image[i+1][j].rgbtBlue+image[i][j+1].rgbtBlue + image[i-1][j+1].rgbtBlue +image[i+1][j+1].rgbtBlue)/6;
                image[i][j].rgbtRed = red;
                image[i][j].rgbtGreen = Green;
                image[i][j].rgbtBlue = Blue;
             }
        else
        {
                red=(image[i][j].rgbtRed+image[i-1][j].rgbtRed+image[i+1][j].rgbtRed+image[i][j+1].rgbtRed + image[i-1][j+1].rgbtRed+image[i+1][j+1].rgbtRed + image[i][j-1].rgbtRed + image[i-1][j-1].rgbtRed+image[i+1][j-1].rgbtRed)/9;
                Green=(image[i][j].rgbtGreen + image[i-1][j].rgbtGreen +image[i+1][j].rgbtGreen +image[i][j+1].rgbtGreen +image[i-1][j+1].rgbtGreen +image[i+1][j+1].rgbtGreen+ image[i][j-1].rgbtGreen + image[i-1][j-1].rgbtGreen+image[i+1][j-1].rgbtGreen)/9;
                Blue =(image[i][j].rgbtBlue + image[i-1][j].rgbtBlue+image[i+1][j].rgbtBlue+image[i][j+1].rgbtBlue + image[i-1][j+1].rgbtBlue +image[i+1][j+1].rgbtBlue + image[i][j-1].rgbtBlue + image[i-1][j-1].rgbtBlue +image[i+1][j-1].rgbtBlue)/9;
                image[i][j].rgbtRed = red;
                image[i][j].rgbtGreen = Green;
                image[i][j].rgbtBlue = Blue;
        }



        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int h= height;
    int w= width;
    int gx,gy;

    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            if(i==0 && j==0)
             {
                gx=((image[i][j].rgbtRed * 0) + (image[i+1][j].rgbtRed*0) +(image[i][j+1].rgbtRed*2) + (image[i+1][j+1].rgbtRed *1));
                gy=((image[i][j].rgbtRed * 0) + (image[i+1][j].rgbtRed*2) +(image[i][j+1].rgbtRed*0) + (image[i+1][j+1].rgbtRed *1));
                image[i][j].rgbtRed = sqrt(((gx*gx)+(gy*gy)));
                gx=((image[i][j].rgbtGreen * 0) + (image[i+1][j].rgbtGreen*0) +(image[i][j+1].rgbtGreen*2) + (image[i+1][j+1].rgbtGreen *1));
                gy=((image[i][j].rgbtGreen * 0) + (image[i+1][j].rgbtGreen*2) +(image[i][j+1].rgbtGreen*0) + (image[i+1][j+1].rgbtGreen *1));
                image[i][j].rgbtGreen = sqrt(((gx*gx)+(gy*gy)));
                gx=((image[i][j].rgbtBlue * 0) + (image[i+1][j].rgbtBlue*0) +(image[i][j+1].rgbtBlue*2) + (image[i+1][j+1].rgbtBlue*1));
                gy=((image[i][j].rgbtBlue * 0) + (image[i+1][j].rgbtBlue*2) +(image[i][j+1].rgbtBlue*0) + (image[i+1][j+1].rgbtBlue *1));
                image[i][j].rgbtBlue = sqrt(((gx*gx)+(gy*gy)));


             }
          else if(i==0 && j!=w-1)
             {
                gx=((image[i][j].rgbtRed * 0) + (image[i+1][j].rgbtRed*0) +(image[i][j+1].rgbtRed*2) + (image[i+1][j+1].rgbtRed * 1) + (image[i][j-1].rgbtRed*(-2) ) + (image[i+1][j-1].rgbtRed * (-1)));
                gy= ((image[i][j].rgbtRed * 0) + (image[i+1][j].rgbtRed*2) +(image[i][j+1].rgbtRed*0) + (image[i+1][j+1].rgbtRed *1) + (image[i][j-1].rgbtRed*(0) ) + (image[i+1][j-1].rgbtRed * (1)));
                image[i][j].rgbtRed = sqrt(((gx*gx)+(gy*gy)));
                gx=((image[i][j].rgbtGreen * 0) + (image[i+1][j].rgbtGreen*0) +(image[i][j+1].rgbtGreen*2) + (image[i+1][j+1].rgbtGreen* 1) + (image[i][j-1].rgbtGreen*(-2) ) + (image[i+1][j-1].rgbtGreen* (-1)));
                gy= ((image[i][j].rgbtGreen * 0) + (image[i+1][j].rgbtGreen*2) +(image[i][j+1].rgbtGreen*0) + (image[i+1][j+1].rgbtGreen *1) + (image[i][j-1].rgbtGreen*(0) ) + (image[i+1][j-1].rgbtGreen * (1)));
                image[i][j].rgbtGreen = sqrt(((gx*gx)+(gy*gy)));
                gx=((image[i][j].rgbtBlue * 0) + (image[i+1][j].rgbtBlue*0) +(image[i][j+1].rgbtBlue*2) + (image[i+1][j+1].rgbtBlue * 1) + (image[i][j-1].rgbtBlue*(-2) ) + (image[i+1][j-1].rgbtBlue * (-1)));
                gy= ((image[i][j].rgbtBlue * 0) + (image[i+1][j].rgbtBlue*2) +(image[i][j+1].rgbtBlue*0) + (image[i+1][j+1].rgbtBlue*1) + (image[i][j-1].rgbtBlue*(0) ) + (image[i+1][j-1].rgbtBlue * (1)));
                image[i][j].rgbtBlue = sqrt(((gx*gx)+(gy*gy)));
             }
        else if (i==0 && j== w-1)
           {
                gx =((image[i][j].rgbtRed*0)+ (image[i][j-1].rgbtRed * (-1)) + (image[i+1][j].rgbtRed*0)+ (image[i+1][j-1].rgbtRed*(-1)));
                gy = ((image[i][j].rgbtRed*0)+ (image[i][j-1].rgbtRed * (0)) + (image[i+1][j].rgbtRed*2)+ (image[i+1][j-1].rgbtRed*(1)));
                image[i][j].rgbtRed = sqrt(((gx*gx)+(gy*gy)));
                gx =((image[i][j].rgbtGreen*0)+ (image[i][j-1].rgbtGreen * (-1)) + (image[i+1][j].rgbtGreen*0)+ (image[i+1][j-1].rgbtGreen*(-1)));
                gy = ((image[i][j].rgbtGreen*0)+ (image[i][j-1].rgbtGreen * (0)) + (image[i+1][j].rgbtGreen*2)+ (image[i+1][j-1].rgbtGreen*(1)));
                image[i][j].rgbtGreen = sqrt(((gx*gx)+(gy*gy)));
                gx =((image[i][j].rgbtBlue*0)+ (image[i][j-1].rgbtBlue * (-1)) + (image[i+1][j].rgbtBlue*0)+ (image[i+1][j-1].rgbtBlue*(-1)));
                gy = ((image[i][j].rgbtBlue*0)+ (image[i][j-1].rgbtBlue * (0)) + (image[i+1][j].rgbtBlue*2)+ (image[i+1][j-1].rgbtBlue*(1)));
                image[i][j].rgbtBlue = sqrt(((gx*gx)+(gy*gy)));
           }
         else if(i!=h-1 && j==w-1)
             {
                gx=((image[i][j].rgbtRed * 0) + (image[i+1][j].rgbtRed*0)+(image[i-1][j].rgbtRed*0)+(image[i+1][j-1].rgbtRed*(-1)) + (image[i][j-1].rgbtRed * (-2))+(image[i-1][j-1].rgbtRed * (-1)));
                gy=((image[i][j].rgbtRed * 0) + (image[i+1][j].rgbtRed*(-2))+(image[i-1][j].rgbtRed*(-2))+(image[i+1][j-1].rgbtRed*(1)) + (image[i][j-1].rgbtRed * (0))+(image[i-1][j-1].rgbtRed * (-1)));
                image[i][j].rgbtRed = sqrt(((gx*gx)+(gy*gy)));
                gx=((image[i][j].rgbtBlue * 0) + (image[i+1][j].rgbtBlue*0)+(image[i-1][j].rgbtBlue*0)+(image[i+1][j-1].rgbtBlue*(-1)) + (image[i][j-1].rgbtBlue * (-2))+(image[i-1][j-1].rgbtBlue * (-1)));
                gy=((image[i][j].rgbtBlue * 0) + (image[i+1][j].rgbtBlue*(-2))+(image[i-1][j].rgbtBlue*(-2))+(image[i+1][j-1].rgbtBlue*(1)) + (image[i][j-1].rgbtBlue * (0))+(image[i-1][j-1].rgbtBlue * (-1)));
                image[i][j].rgbtBlue = sqrt(((gx*gx)+(gy*gy)));
                gx=((image[i][j].rgbtGreen * 0) + (image[i+1][j].rgbtGreen*0)+(image[i-1][j].rgbtGreen*0)+(image[i+1][j-1].rgbtGreen*(-1)) + (image[i][j-1].rgbtGreen * (-2))+(image[i-1][j-1].rgbtGreen* (-1)));
                gy=((image[i][j].rgbtGreen * 0) + (image[i+1][j].rgbtGreen*(-2))+(image[i-1][j].rgbtGreen*(-2))+(image[i+1][j-1].rgbtGreen*(1)) + (image[i][j-1].rgbtGreen * (0))+(image[i-1][j-1].rgbtGreen * (-1)));
                image[i][j].rgbtGreen = sqrt(((gx*gx)+(gy*gy)));
             }

         else if (i== h-1 && j== w-1)
           {
                gx = ((image[i][j].rgbtRed*0) + (image[i][j-1].rgbtRed*(-2))+(image[i-1][j].rgbtRed*0)+(image[i-1][j-1].rgbtRed*(-1)));
                gy = ((image[i][j].rgbtRed*0) + (image[i][j-1].rgbtRed*(0))+(image[i-1][j].rgbtRed* (-2))+(image[i-1][j-1].rgbtRed*(-1)));
                image[i][j].rgbtRed = sqrt(((gx*gx)+(gy*gy)));
                gx = ((image[i][j].rgbtGreen*0) + (image[i][j-1].rgbtGreen*(-2))+(image[i-1][j].rgbtGreen*0)+(image[i-1][j-1].rgbtGreen*(-1)));
                gy = ((image[i][j].rgbtGreen*0) + (image[i][j-1].rgbtGreen*(0))+(image[i-1][j].rgbtGreen* (-2))+(image[i-1][j-1].rgbtGreen*(-1)));
                image[i][j].rgbtGreen = sqrt(((gx*gx)+(gy*gy)));
                gx = ((image[i][j].rgbtBlue*0) + (image[i][j-1].rgbtBlue*(-2))+(image[i-1][j].rgbtBlue*0)+(image[i-1][j-1].rgbtBlue*(-1)));
                gy = ((image[i][j].rgbtBlue*0) + (image[i][j-1].rgbtBlue*(0))+(image[i-1][j].rgbtBlue* (-2))+(image[i-1][j-1].rgbtBlue*(-1)));
                image[i][j].rgbtBlue = sqrt(((gx*gx)+(gy*gy)));

           }

         else if(i==h-1 && j!=0)
             {
                red=(image[i][j].rgbtRed+image[i-1][j].rgbtRed+image[i][j-1].rgbtRed+image[i][j+1].rgbtRed + image[i-1][j-1].rgbtRed+image[i-1][j+1].rgbtRed)/6;
                Green=(image[i][j].rgbtGreen + image[i-1][j].rgbtGreen +image[i][j-1].rgbtGreen +image[i][j+1].rgbtGreen +image[i-1][j+1].rgbtGreen +image[i-1][j-1].rgbtGreen)/6;
                Blue =(image[i][j].rgbtBlue+image[i-1][j].rgbtBlue+image[i][j-1].rgbtBlue+image[i][j+1].rgbtBlue + image[i-1][j+1].rgbtBlue +image[i-1][j-1].rgbtBlue)/6;
                image[i][j].rgbtRed = red;
                image[i][j].rgbtGreen = Green;
                image[i][j].rgbtBlue = Blue;
             }

         else if (i== h-1 && j== 0) //lower left coorner.
           {
                gx=((image[i][j].rgbtRed * 0)+(image[i-1][j].rgbtRed*0)+(image[i+1][j].rgbtRed*0)+(image[i][j+1].rgbtRed*2) + (image[i-1][j+1].rgbtRed*1)+(image[i+1][j+1].rgbtRed*0) + (image[i][j-1].rgbtRed*(0)) + (image[i-1][j-1].rgbtRed*(0))+(image[i+1][j-1].rgbtRed*(0)));
                gy=((image[i][j].rgbtRed * 0)+(image[i-1][j].rgbtRed*(-2))+(image[i+1][j].rgbtRed*(0))+(image[i][j+1].rgbtRed*0) + (image[i-1][j+1].rgbtRed*(-1))+(image[i+1][j+1].rgbtRed*0) + (image[i][j-1].rgbtRed*(0)) + (image[i-1][j-1].rgbtRed*(0))+(image[i+1][j-1].rgbtRed*(0)));
                image[i][j].rgbtRed = sqrt(((gx*gx)+(gy*gy)));
                gx=((image[i][j].rgbtGreen * 0)+(image[i-1][j].rgbtGreen*0)+(image[i+1][j].rgbtGreen*0)+(image[i][j+1].rgbtGreen*2) + (image[i-1][j+1].rgbtGreen*1)+(image[i+1][j+1].rgbtGreen*1) + (image[i][j-1].rgbtGreen*(-2)) + (image[i-1][j-1].rgbtGreen*(-1))+(image[i+1][j-1].rgbtGreen*(-1)));
                gy=((image[i][j].rgbtGreen * 0)+(image[i-1][j].rgbtGreen*(-2))+(image[i+1][j].rgbtGreen*(2))+(image[i][j+1].rgbtGreen*0) + (image[i-1][j+1].rgbtGreen*(-1))+(image[i+1][j+1].rgbtGreen*1) + (image[i][j-1].rgbtGreen*(0)) + (image[i-1][j-1].rgbtGreen*(-1))+(image[i+1][j-1].rgbtGreen*(1)));
                image[i][j].rgbtGreen = sqrt(((gx*gx)+(gy*gy)));
                gx=((image[i][j].rgbtBlue * 0)+(image[i-1][j].rgbtBlue*0)+(image[i+1][j].rgbtBlue*0)+(image[i][j+1].rgbtBlue*2) + (image[i-1][j+1].rgbtBlue*1)+(image[i+1][j+1].rgbtBlue*1) + (image[i][j-1].rgbtBlue*(-2)) + (image[i-1][j-1].rgbtBlue*(-1))+(image[i+1][j-1].rgbtBlue*(-1)));
                gy=((image[i][j].rgbtBlue * 0)+(image[i-1][j].rgbtBlue*(-2))+(image[i+1][j].rgbtBlue*(2))+(image[i][j+1].rgbtBlue*0) + (image[i-1][j+1].rgbtBlue*(-1))+(image[i+1][j+1].rgbtBlue*1) + (image[i][j-1].rgbtBlue*(0)) + (image[i-1][j-1].rgbtBlue*(-1))+(image[i+1][j-1].rgbtBlue*(1)));
                image[i][j].rgbtBlue = sqrt(((gx*gx)+(gy*gy)));

           }
         else if(i!=0 && j==0)
             {
                gx=(image[i][j].rgbtRed*-2+image[i-1][j].rgbtRed*-1+image[i+1][j].rgbtRed*-1+image[i][j+1].rgbtRed*0 + image[i-1][j+1].rgbtRed*0+image[i+1][j+1].rgbtRed*0);
                gy=(image[i][j].rgbtRed*0+image[i-1][j].rgbtRed*-1+image[i+1][j].rgbtRed*1+image[i][j+1].rgbtRed*0 + image[i-1][j+1].rgbtRed*-2+image[i+1][j+1].rgbtRed*2);
                image[i][j].rgbtRed = sqrt(((gx*gx)+(gy*gy)));
                gx=(image[i][j].rgbtGreen*-2+image[i-1][j].rgbtGreen*-1+image[i+1][j].rgbtGreen*-1+image[i][j+1].rgbtGreen*0 + image[i-1][j+1].rgbtGreen*0+image[i+1][j+1].rgbtGreen*0);
                gy=(image[i][j].rgbtGreen*0+image[i-1][j].rgbtGreen*-1+image[i+1][j].rgbtGreen*1+image[i][j+1].rgbtGreen*0 + image[i-1][j+1].rgbtGreen*-2+image[i+1][j+1].rgbtGreen*2);
                image[i][j].rgbtGreen = sqrt(((gx*gx)+(gy*gy)));
                gx=(image[i][j].rgbtBlue*-2+image[i-1][j].rgbtBlue*-1+image[i+1][j].rgbtBlue*-1+image[i][j+1].rgbtBlue*0 + image[i-1][j+1].rgbtBlue*0+image[i+1][j+1].rgbtBlue*0);
                gy=(image[i][j].rgbtBlue*0+image[i-1][j].rgbtBlue*-1+image[i+1][j].rgbtBlue*1+image[i][j+1].rgbtBlue*0 + image[i-1][j+1].rgbtBlue*-2+image[i+1][j+1].rgbtBlue*2);
                image[i][j].rgbtBlue = sqrt(((gx*gx)+(gy*gy)))

             }
        else
        {
                gx=((image[i][j].rgbtRed * 0)+(image[i-1][j].rgbtRed*0)+(image[i+1][j].rgbtRed*0)+(image[i][j+1].rgbtRed*2) + (image[i-1][j+1].rgbtRed*1)+(image[i+1][j+1].rgbtRed*1) + (image[i][j-1].rgbtRed*(-2)) + (image[i-1][j-1].rgbtRed*(-1))+(image[i+1][j-1].rgbtRed*(-1)));
                gy=((image[i][j].rgbtRed * 0)+(image[i-1][j].rgbtRed*(-2))+(image[i+1][j].rgbtRed*(2))+(image[i][j+1].rgbtRed*0) + (image[i-1][j+1].rgbtRed*(-1))+(image[i+1][j+1].rgbtRed*1) + (image[i][j-1].rgbtRed*(0)) + (image[i-1][j-1].rgbtRed*(-1))+(image[i+1][j-1].rgbtRed*(1)));
                image[i][j].rgbtRed = sqrt(((gx*gx)+(gy*gy)));
                gx=((image[i][j].rgbtGreen * 0)+(image[i-1][j].rgbtGreen*0)+(image[i+1][j].rgbtGreen*0)+(image[i][j+1].rgbtGreen*2) + (image[i-1][j+1].rgbtGreen*1)+(image[i+1][j+1].rgbtGreen*1) + (image[i][j-1].rgbtGreen*(-2)) + (image[i-1][j-1].rgbtGreen*(-1))+(image[i+1][j-1].rgbtGreen*(-1)));
                gy=((image[i][j].rgbtGreen * 0)+(image[i-1][j].rgbtGreen*(-2))+(image[i+1][j].rgbtGreen*(2))+(image[i][j+1].rgbtGreen*0) + (image[i-1][j+1].rgbtGreen*(-1))+(image[i+1][j+1].rgbtGreen*1) + (image[i][j-1].rgbtGreen*(0)) + (image[i-1][j-1].rgbtGreen*(-1))+(image[i+1][j-1].rgbtGreen*(1)));
                image[i][j].rgbtGreen = sqrt(((gx*gx)+(gy*gy)));
                gx=((image[i][j].rgbtBlue * 0)+(image[i-1][j].rgbtBlue*0)+(image[i+1][j].rgbtBlue*0)+(image[i][j+1].rgbtBlue*2) + (image[i-1][j+1].rgbtBlue*1)+(image[i+1][j+1].rgbtBlue*1) + (image[i][j-1].rgbtBlue*(-2)) + (image[i-1][j-1].rgbtBlue*(-1))+(image[i+1][j-1].rgbtBlue*(-1)));
                gy=((image[i][j].rgbtBlue * 0)+(image[i-1][j].rgbtBlue*(-2))+(image[i+1][j].rgbtBlue*(2))+(image[i][j+1].rgbtBlue*0) + (image[i-1][j+1].rgbtBlue*(-1))+(image[i+1][j+1].rgbtBlue*1) + (image[i][j-1].rgbtBlue*(0)) + (image[i-1][j-1].rgbtBlue*(-1))+(image[i+1][j-1].rgbtBlue*(1)));
                image[i][j].rgbtBlue = sqrt(((gx*gx)+(gy*gy)));
        }



        }
    }

    return;
}
