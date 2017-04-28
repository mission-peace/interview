package sorting;


public class InsertionSort {

	public static void main(String[] args) {
		int arr[] = { 2, 5, 1, 8, 3, 9, 4 };
		InsertionSort obj = new InsertionSort();

		// calling sort method
		obj.insertion_sort(arr);

		System.out.println("Sorted Array :");
		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i] + " ");
		}
	}

	private void insertion_sort(int[] arr) {
		int key = 0;
		int j = 0;
		for (int i = 2; i < arr.length; i++) {
			key = arr[i];
			j = i;
			while (j > 0&&key < arr[j - 1]) {
				arr[j] = arr[j-1];
				j = j - 1;
			}
			arr[j] = key;
		}
	}
}
