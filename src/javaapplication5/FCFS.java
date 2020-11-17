/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication5;

/**
 *
 * @author sg
 */

/////////////////////////
public class FCFS {
   public int tracks=200;              //0 to 199
   // int head_pos=50;          //head position
     //int size = 8;       //size of the array
     //int []arr=new int[size];

   public void FCFS(int arr[], int curr_loc, int size) 
{ 
	int total = 0; 
	int curr_track;
        int distance_track;
       
	for (int i = 0; i < size; i++) 
	{ 
		curr_track = arr[i]; 

		// calculate absolute distance 
		distance_track = Math.abs(curr_track - curr_loc); 

		// increase the total count 
		total += distance_track; 

		// accessed track is now new head 
		curr_loc = curr_track; 
	}
        
        System.out.println("Seek=" + " " + total+" cylinders ");
}
}