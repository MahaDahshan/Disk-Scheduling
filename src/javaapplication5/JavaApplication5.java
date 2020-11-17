/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication5;
import java.util.Scanner;
/**
 *
 * @author sg
 */
public class JavaApplication5 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
         
        int size=8;
        int []arr=new int[size];
        int Head_Position;
        FCFS F=new FCFS();
        Scanner sc=new Scanner (System.in);
        System.out.println("Please enter head position: ");
        Head_Position=sc.nextInt();
        
        System.out.println("Please fill the array: ");
        for(int i=0;i<size;i++)
        {
            arr[i]=sc.nextInt();
        }
        
        F.FCFS(arr, Head_Position, size);
    }
}
