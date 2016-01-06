/* This program is used to calculate the number of Island Present in the matrix *
 * It also incorporates the connected part as a one island and this approact    *
 * does not use queue or stack for implementation */

/* For example
        0  1  0  1  0
        0  0  1  1  1
        1  0  0  1  0
        0  1  1  0  0
        1  0  1  0  1
 has 6 islands in total where 1 or all connected 1s denote one island */

/* Credit for Question : https://www.pramp.com/ */

import java.util.Scanner;

public class IslandCount
{
	static int area[][];
	static int[] dirX = {1,0,-1,0};
	static int[] dirY = {0,1,0,-1};
	static int island_count = 0;
	static int n;
	
	public static void main(String[] arg)
	{
		Scanner cin = new Scanner(System.in);
		n = cin.nextInt();
		area = new int[n][n];
		
		for(int i = 0;i < n;i++)
		{
			for(int j = 0;j < n;j++)				
			{
				area[i][j] = cin.nextInt();
			}
		}
		
		for(int i = 0;i < n;i++)
		{
			for(int j = 0;j < n;j++)				
			{
				if(area[i][j] == 1)
				{
					/* Traverse its all neighbour */
					area[i][j] = 0;
					island_count++;
					markAllConnected(i,j);					
				}
			}
		}
		System.out.println(island_count);
		cin.close();
	}
	
	public static boolean isValidMove(int r,int c)
	{
		if(r < 0 || r >= n || c < 0 || c >= n)
			return false;
		return true;
	}
	
	public static void markAllConnected(int r,int c)
	{
		int ro = 0;
		int co = 0;
		
		for(int k = 0;k < 4;k++)
		{
			ro = dirX[k];
			co = dirY[k];
			if(isValidMove(r + ro,c + co) && area[r + ro][c + co] == 1)
			{
				area[r + ro][c + co] = 0;
				markAllConnected(r + dirX[k], c + dirY[k]);
			}
		}
	}
}
