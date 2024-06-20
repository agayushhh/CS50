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
            avg_gray = round((image[i][j].rgbtRed+ image[i][j].rgbtBlue + image[i][j].rgbtGreen)/3.0);
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
    int h = height;
    int w = width;

    // Create a temporary array to store the blurred values
    RGBTRIPLE temp[h][w];

    // Iterate over each pixel
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            int red = 0, green = 0, blue = 0;
            int count = 0;

            // Iterate over the surrounding pixels
            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    int ni = i + di;
                    int nj = j + dj;

                    // Check if the neighboring pixel is within bounds
                    if (ni >= 0 && ni < h && nj >= 0 && nj < w)
                    {
                        red += image[ni][nj].rgbtRed;
                        green += image[ni][nj].rgbtGreen;
                        blue += image[ni][nj].rgbtBlue;
                        count++;
                    }
                }
            }

            // Compute the average color values
            temp[i][j].rgbtRed = red / count;
            temp[i][j].rgbtGreen = green / count;
            temp[i][j].rgbtBlue = blue / count;
        }
    }

    // Copy the blurred values back to the original image
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            image[i][j] = temp[i][j];
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




