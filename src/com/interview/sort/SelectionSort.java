package sorting;


public class SelectionSort {

	public static void main(String[] args) {
		int arr[]={2,5,1,8,3,9,4};
		SelectionSort obj=new SelectionSort();
		//calling sort method
		obj.sort(arr);
		System.out.println("Sorted Array :");
		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i]+" ");
		}
	}

	
	private void sort(int arr[]) {

		int minimum;
		int n = arr.length;
		for (int i = 0; i < n; i++) {
			minimum = i;
			for (int j = i + 1; j < n; j++) {
				if (arr[j] < arr[minimum]) { 
					minimum = j;
				}
			}
			swap(arr, minimum, i);
		}
	}

	private void swap(int[] a, int minimum, int i) {
		int temp = a[minimum];
		a[minimum] = a[i];
		a[i] = temp;
	}
}
