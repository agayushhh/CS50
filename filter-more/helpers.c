#include "helpers.h"

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
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int h= height;
    int w= width;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
         if((i==0 && j==0) ||(i== h-1 && j==0)||(i==h-1 && j==w-1)||(i==0 && j==w-1)
            {
                
            }
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
