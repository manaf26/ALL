#include "helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0 ; i < height ; i++)
        {
            for(int j = 0 ; j < width ; j++)
            {
                int Blue = image[i][j].rgbtBlue;
                int Red = image[i][j].rgbtRed;
                int Green = image[i][j].rgbtGreen;
                int gray = (Blue + Green + Red)/3;
                image[i][j].rgbtGreen = gray;
                image[i][j].rgbtBlue = gray ;
                image[i][j].rgbtRed = gray;
            }

        }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp;
    for(int i = 0 ; i < height ; i++)
        {
            for(int j = 0 ; j < width/2 ; j++)
            {
                tmp = image[i][j];
                image[i][j] = image[i][width -1 -j ];
                image[i][width -1 -j ] = tmp;
            }
        }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int avgBlue;
    int avgRed ;
    int avgGreen;
    for(int i = 0 ; i < height ; i++)
        {
            for(int j = 0 ; j < width ; j++)
            {
                if (i > 0 && j > 0 && i < height -1  && j < width -1   )
                {//make black
                    avgBlue  = (image[i-1][j-1].rgbtBlue + image[i-1][j].rgbtBlue +image[i-1][j+1].rgbtBlue + image[i][j-1].rgbtBlue + image[i][j+1].rgbtBlue + image[i+1][j-1].rgbtBlue + image[i+1][j].rgbtBlue +image[i+1][j+1].rgbtBlue)/8;
                    avgRed   = (image[i-1][j-1].rgbtRed + image[i-1][j].rgbtRed +image[i-1][j+1].rgbtRed + image[i][j-1].rgbtRed + image[i][j+1].rgbtRed + image[i+1][j-1].rgbtRed + image[i+1][j].rgbtRed +image[i+1][j+1].rgbtRed)/8;
                    avgGreen = (image[i-1][j-1].rgbtGreen + image[i-1][j].rgbtGreen +image[i-1][j+1].rgbtGreen + image[i][j-1].rgbtGreen + image[i][j+1].rgbtGreen + image[i+1][j-1].rgbtGreen + image[i+1][j].rgbtGreen +image[i+1][j+1].rgbtGreen)/8;
                    image[i][j].rgbtBlue  = avgBlue;
                    image[i][j].rgbtRed   = avgRed;
                    image[i][j].rgbtGreen = avgGreen;
                }
            }
        }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int gx[3][3] = {
                    {-1,0,1},
                    {-2,0,2},
                    {-1,0,1}
                    };
    int gy[3][3] = {
                    {-1,-2,-1},
                    { 0, 0, 0},
                    { 1, 2, 1}
                    };
      //int newBlue  = sqrt(pow(gxb,2)+pow(gyb));
      //int newRed   = sqrt(pow(gxr,2)+pow(gyr));
      //int newGreen = sqrt(pow(gxg,2)+pow(gyg));
    int gxb = 0  ; int gxr = 0 ;int  gxg = 0; int gyb =0 ; int gyr = 0 ;int  gyg = 0;
    int gr = 0;
    int gc = 0;

    for(int i = 0 ; i < height ; i++)
        {
            for(int j = 0 ; j < width ; j++)
            {
                //loops to travel around all pixles in the picture
                if (i > 0 && j > 0 && i < height -1  && j < width -1   )
                {
                    gc = 0;
                    gr = 0;
                    for (int x = i-1 ; x < 3 ; x++) // loops to multiply pixle rgb channels with gx,gy
                        {
                            for (int y = j-1 ; y < 3 ; y++)
                                {
                                    //gxb   = (image[i-1][j-1].rgbtBlue * gx[0][0] + image[i-1][j].rgbtBlue * gx[0][1] + image[i-1][j+1].rgbtBlue * gx[0][1] + image[i][j-1].rgbtBlue * gx[x][y] + image[i][j+1].rgbtBlue * gx[x][y] + image[i+1][j-1].rgbtBlue * gx[x][y] + image[i+1][j].rgbtBlue * gx[x][y] +image[i+1][j+1].rgbtBlue* gx[x][y]);
                                    //gxr   = (image[i-1][j-1].rgbtRed * gx[x][y] + image[i-1][j].rgbtRed * gx[x][y] + image[i-1][j+1].rgbtRed * gx[x][y] + image[i][j-1].rgbtRed * gx[x][y] + image[i][j+1].rgbtRed * gx[x][y] + image[i+1][j-1].rgbtRed * gx[x][y] + image[i+1][j].rgbtRed * gx[x][y] + image[i+1][j+1].rgbtRed * gx[x][y]);
                                    //gxg   = (image[i-1][j-1].rgbtGreen * gx[x][y] + image[i-1][j].rgbtGreen * gx[x][y] +image[i-1][j+1].rgbtGreen * gx[x][y] + image[i][j-1].rgbtGreen * gx[x][y] + image[i][j+1].rgbtGreen * gx[x][y] + image[i+1][j-1].rgbtGreen * gx[x][y] + image[i+1][j].rgbtGreen * gx[x][y] +image[i+1][j+1].rgbtGreen * gx[x][y] );
                                    //gyb   = (image[i-1][j-1].rgbtBlue * gy[x][y] + image[i-1][j].rgbtBlue * gy[x][y] +image[i-1][j+1].rgbtBlue * gy[x][y] + image[i][j-1].rgbtBlue * gy[x][y] + image[i][j+1].rgbtBlue * gy[x][y]+ image[i+1][j-1].rgbtBlue * gy[x][y] + image[i+1][j].rgbtBlue * gy[x][y] +image[i+1][j+1].rgbtBlue* gy[x][y]);
                                    //gyr   = (image[i-1][j-1].rgbtRed * gy[x][y] + image[i-1][j].rgbtRed * gy[x][y] +image[i-1][j+1].rgbtRed * gy[x][y] + image[i][j-1].rgbtRed * gy[x][y] + image[i][j+1].rgbtRed * gy[x][y] + image[i+1][j-1].rgbtRed * gy[x][y] + image[i+1][j].rgbtRed * gy[x][y] +image[i+1][j+1].rgbtRed * gy[x][y]);
                                    //gyg   = (image[i-1][j-1].rgbtGreen * gy[x][y] + image[i-1][j].rgbtGreen * gy[x][y] + image[i-1][j+1].rgbtGreen * gy[x][y] + image[i][j-1].rgbtGreen * gy[x][y] + image[i][j+1].rgbtGreen * gy[x][y] + image[i+1][j-1].rgbtGreen * gy[x][y] + image[i+1][j].rgbtGreen * gy[x][y] +image[i+1][j+1].rgbtGreen * gy[x][y] );
                                    gxb   += image[x][y].rgbtBlue * gx[gr][gc];
                                    gxr   += image[x][y].rgbtRed * gx[gr][gc];
                                    gxg   += image[x][y].rgbtGreen * gx[gr][gc];
                                    gyb   += image[x][y].rgbtBlue * gy[gr][gc];
                                    gyr   += image[x][y].rgbtRed * gy[gr][gc];
                                    gyg   += image[x][y].rgbtGreen * gy[gr][gc];
                                    gc++;
                                }
                                gr++;


                        }
                }
            }
        }
    printf("%i",gxb);
    printf("%i",gxr);
    printf("%i",gxg);
    printf("%i",gyb);
    printf("%i",gyr);
    printf("%i",gyg);
    return;
}
