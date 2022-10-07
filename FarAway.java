/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		
			Scanner sc=new Scanner(System.in);
		
		long t=sc.nextLong();
		
		while(t-->0) {
			
         long n=sc.nextLong();
         long m=sc.nextLong();
         
         long arr[]=new long[(int)n];
         
         for(int i=0;i<n;i++)
        	 arr[i]=sc.nextLong();
         
         long res=0;
         
         for(int i=0;i<n;i++) {
        	 if(Math.abs(arr[i]-1)>Math.abs(m-arr[i]))
        		 res+=Math.abs(arr[i]-1);
        	 else
        		 res+=Math.abs(m-arr[i]);
         }
         
         System.out.println(res);
       }
	}
}
