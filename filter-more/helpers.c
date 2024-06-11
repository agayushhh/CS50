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
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
