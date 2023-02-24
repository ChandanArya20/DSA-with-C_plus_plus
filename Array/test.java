public class InsertionSort {

	public static void main(String[] args) {
		
		int[] arr= {2,4,8,12,5,1,2,3,4,5,2,9,23,22};
		
		
		int i,j;
		for(i=1;i<arr.length;i++) {
			int temp=arr[i];
			for(j=i-1;arr[j]>temp && j>=0 ;j--) {
				int tmp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=tmp;
			}
			arr[j+1]=temp;
		}
		for(int x:arr) {
			System.out.print(x+" ");
		}

	}

}
