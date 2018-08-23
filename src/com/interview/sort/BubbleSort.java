package sorting;


public class BubbleSort {


	public static void main(String[] args) {
		int arr[]={2,5,1,8,3,9,4};
		BubbleSort obj=new BubbleSort();
		
		//calling sort method
		obj.sort(arr);
		
		System.out.println("Sorted Array :");
		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i]+" ");
		}
	}



	private void sort(int[] arr) {
		for (int i = 0; i < arr.length - 1; i++) {
			for (int j = 0; j < arr.length - 1 - i; j++) {
				if (arr[j] > arr[j + 1]) {
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
	}
}
