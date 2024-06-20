#include "helpers.h"
#include <math.h>
#include<stdio.h>
#include<stdlib.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int avg_gray=0;
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            avg_gray = round(atof((image[i][j].rgbtRed+ image[i][j].rgbtBlue + image[i][j].rgbtGreen))/3);
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
    // Sobel kernel for Gx and Gy
    int Gx[3][3] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };
    int Gy[3][3] = {
        {-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1}
    };

    // Create a copy of the original image to avoid modifying it while processing
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // Apply Sobel operator
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sumXRed = 0, sumYRed = 0;
            int sumXGreen = 0, sumYGreen = 0;
            int sumXBlue = 0, sumYBlue = 0;

            // Apply the kernels to the current pixel's neighborhood
            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    int ni = i + di;
                    int nj = j + dj;

                    // Ensure the neighbor indices are within bounds
                    if (ni >= 0 && ni < height && nj >= 0 && nj < width)
                    {
                        sumXRed += copy[ni][nj].rgbtRed * Gx[di + 1][dj + 1];
                        sumYRed += copy[ni][nj].rgbtRed * Gy[di + 1][dj + 1];
                        sumXGreen += copy[ni][nj].rgbtGreen * Gx[di + 1][dj + 1];
                        sumYGreen += copy[ni][nj].rgbtGreen * Gy[di + 1][dj + 1];
                        sumXBlue += copy[ni][nj].rgbtBlue * Gx[di + 1][dj + 1];
                        sumYBlue += copy[ni][nj].rgbtBlue * Gy[di + 1][dj + 1];
                    }
                }
            }

            // Compute the gradient magnitude for each color channel
            int newRed = round(sqrt(sumXRed * sumXRed + sumYRed * sumYRed));
            int newGreen = round(sqrt(sumXGreen * sumXGreen + sumYGreen * sumYGreen));
            int newBlue = round(sqrt(sumXBlue * sumXBlue + sumYBlue * sumYBlue));

            // Clamp values to [0, 255]
            image[i][j].rgbtRed = (newRed > 255) ? 255 : newRed;
            image[i][j].rgbtGreen = (newGreen > 255) ? 255 : newGreen;
            image[i][j].rgbtBlue = (newBlue > 255) ? 255 : newBlue;
        }
    }
}




