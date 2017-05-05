/*
Assignment 4

Student name: Galdan MOULINNEUF
Student number: 2927686
===========================================================================

Your task this week is to benchmark three fast sorting algorithms Mergesort,
Quicksort and Arrays.sort (that uses the dual-pivot quicksort described in Yaroslavskiy 2009)


Please note that marks will be awarded based on the quality of the report written by you
in the sections provided below.

When preparing your report, you should take note of the comments provided for Assignment 3
that involved a simple benchmark report.

*/

/*=======================================================================================
*  Benchmarking Report for each of the sorting algorithms
=========================================================================================
*   MergeSort


*  =======================================================================================
*   QuickSort
*
*
*
* ========================================================================================
*  Arrays.sort
*
*
*
* ========================================================================================
*  Comparison based on your test results
*
*
*
*/
//=====================================================================================

import java.lang.reflect.Array;
import java.util.*;
class Benchmark {
    static final int N = (int)Math.pow(10, 6);

    static int same[] = new int[N];
    static int ordered[] = new int[N];
    static int reversed[] = new int[N];
    static int sameFirstSameLast[] = new int[N];
    static int allRandom[] = new int[N];


    public static void main(String args[]) {
        int randomNum = (int)(Math.random() * N);
        for (int i = 0; i < N; ++i) {
            same[i] = 2;
            ordered[i] = i;
            reversed[i] = N - i;
            if (i > 10000 && i < N - 10000)
                sameFirstSameLast[i] = (int)(Math.random() * N);
            else
                sameFirstSameLast[i] = randomNum;
            allRandom[i] = (int)(Math.random() * N);
        }

        //==========================================================
        //Benchmarking MergeSort code

        //long startMerge = System.nanoTime();
        //mergeSort(same, 0, N);
        //mergeSort(ordered, 0, N);
        //mergeSort(reversed, 0, N);
        //mergeSort(sameFirstSameLast, 0, N);
        //mergeSort(allRandom, 0, N);
        //long endMerge = System.nanoTime();

        //System.out.println("Time : " + ((endMerge - startMerge) * Math.pow(10, -9)));
        //==========================================================
        // Benchmarking QuickSort code

        //long startQuick = System.nanoTime();
        //quickSort(same, 0, N);
        //quickSort(ordered, 0, N);
        //quickSort(reversed, 0, N);
        //quickSort(sameFirstSameLast, 0, N);
        //quickSort(allRandom, 0, N);
        //long endQuick = System.nanoTime();

        //System.out.println("Time : " + ((endQuick - startQuick) * Math.pow(10, -9)));

        //==========================================================
        //Benchmarking Arrays.sort

        //long startArrSort = System.nanoTime();
        //Arrays.sort(same);
        //Arrays.sort(ordered);
        //Arrays.sort(reversed);
        //Arrays.sort(sameFirstSameLast);
        //Arrays.sort(allRandom);
        //long endArrSort = System.nanoTime();

        //System.out.println("Time : " + ((endArrSort - startArrSort) * Math.pow(10, -9)));
        //==========================================================
    }


    static void quickSort(int f[], int p, int q){
        if(q-p <= 1)
            ; //skip
        else{
            int x;
            int i, j, k;
            // let x = middle element in f[p..q-1]
            x = f[(p+q)/2];
            //x = f[p];
            i = p; j = p; k = q;
            while(j != k){
                if(f[j] == x)
                    j = j + 1;
                else if(f[j] < x){ //swap f[j] with f[i]
                    int temp;
                    temp = f[j];
                    f[j] = f[i];
                    f[i] = temp;
                    j = j + 1;
                    i = i + 1;
                }
                else{ // f[j] > x
                    // swap f[j] with f[k-1]
                    int temp;
                    temp = f[j];
                    f[j] = f[k-1];
                    f[k-1] = temp;
                    k = k - 1;
                }
            }
            quickSort(f,p,i);
            quickSort(f,j,q);
        }
    }

    static void mergeSort(int f[], int lb, int ub){
        //termination reached when a segment of size 1 reached - lb+1 = ub
        if(lb+1 < ub){
            int mid = (lb+ub)/2;
            mergeSort(f,lb,mid);
            mergeSort(f,mid,ub);
            merge(f,lb,mid,ub);
        }
    }
    static void merge(int f[], int p, int q, int r){
        //p<=q<=r
        int i = p; int j = q;
        //use temp array to store merged sub-sequence
        int temp[] = new int[r-p]; int t = 0;
        while(i < q && j < r){
            if(f[i] <= f[j]){
                temp[t]=f[i];i++;t++;
            }
            else{
                temp[t] = f[j]; j++; t++;
            }
        }
        //tag on remaining sequence
        while(i < q){
            temp[t]=f[i];i++;t++;
        }
        while(j < r){
            temp[t] = f[j]; j++; t++;
        }
        //copy temp back to f
        i = p; t = 0;
        while(t < temp.length){
            f[i] = temp[t];
            i++; t++;
        }
    }

    static void insertionSort(int k[], int a, int b){
        int j = a+1;
        while(j < b){
            int i = j;
            while(i > a && k[i] < k[i-1]){ //swap k[i], k[i-1]
                int temp = k[i];
                k[i] = k[i-1]; k[i-1] = temp;
                i = i - 1;
            }
            j = j + 1;
        }
    }
}

