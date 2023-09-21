class ReverseArray{
  public static void main(String[] args){
    int arr[] = {5,2,1,7,8,10};
    int start = 0;
    int last = (arr.length)-1;
    while(start<=last){
      int temp = arr[start];
      arr[start] = arr[last];
      arr[last] = temp;
      start++;
      last--;
    }
    System.out.println("Revese array is ");
    for(int i =0;i<arr.length;i++){
      System.out.print(arr[i]+" ");
    }
    System.out.println(" ");
  }
}