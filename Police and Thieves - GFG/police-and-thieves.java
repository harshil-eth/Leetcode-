//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*; 


// } Driver Code Ends
//User function Template for Java

class Solution 
{ 
    static int catchThieves(char arr[], int n, int k) 
	{ 
        // Code here
        Queue<Integer> tq = new ArrayDeque<>(); // queue to store index of thief
        Queue<Integer> pq = new ArrayDeque<>(); // queue to store index of police
        
        for (int i = 0; i < n; i++) { // loop through array to find index of thief/police
            if (arr[i] == 'T') {
                tq.offer(i);
            } else {
                pq.offer(i);
            }
        }
        
		int counter = 0;
        while (!tq.isEmpty() && !pq.isEmpty()) {
            if (Math.abs(tq.peek() - pq.peek()) <= k) { // thief is within the reach of the policeman
                counter++;
                pq.poll();
                tq.poll();
            } else if (tq.peek() > pq.peek()) { // thief lies beyond the reach of the current policeman
                pq.poll();
            } else { // thief is not reachable from any of the police
                tq.poll();   
            }
        }
        
        return counter;
	} 
} 



//{ Driver Code Starts.
class GFG{
    public static void main(String args[]) throws IOException {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while(t > 0)
        {
            int n = sc.nextInt();
            int k = sc.nextInt();
			char arr[] = new char[n];
			for(int i=0; i<n; i++)
         		arr[i] = sc.next().charAt(0);

			Solution ob = new Solution();
            System.out.println(ob.catchThieves(arr, n, k));
            t--;
        }
    }
}       
// } Driver Code Ends