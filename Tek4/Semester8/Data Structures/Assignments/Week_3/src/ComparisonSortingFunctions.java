public class ComparisonSortingFunctions {
    private static final int N = 1000; //Set the number of elements to sort here
    public static void main(String[] args) {
        // ====================================================
        // Creates two identical arrays for sorting purposes
        int f[] = new int[N];
        int g[] = new int[N];
        for(int j = 0; j < f.length;j++){
            f[j] = (int)(Math.random()*N);
            g[j] = f[j];
        }
        // ====================================================
        // Benchmark both algorithms separately here
        // See book page 48

        long start = System.nanoTime();
        insertionSort(f,0,f.length);

        long mid = System.nanoTime();

        mergeSort(g,0,g.length);

        long end = System.nanoTime();

        long t1 = mid - start;
        long t2 = end - mid;

        System.out.println("Insertion : " + t1 + "\nSort : " + t2);

        //======================================================

    }
    //========================================================
    // Do not change any code here
    private static void insertionSort(int k[], int a, int b){
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
    private static void mergeSort(int f[], int lb, int ub){
        //termination reached when a segment of size 1 reached - lb+1 = ub
        if(lb+1 < ub){
            int mid = (lb+ub)/2;
            mergeSort(f,lb,mid);
            mergeSort(f,mid,ub);
            merge(f,lb,mid,ub);
        }
    }
    private static void merge(int f[], int p, int q, int r){
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
}