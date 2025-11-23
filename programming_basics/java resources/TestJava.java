import java.io.*;

class TwoSum{

    private int number5 = 5;

    public int sumOfNumbers(int[] arr) {
        for(int i=0;i<arr.length;i++){
            System.out.println("ele: "+arr[i]);
        }
        return 0;
    }

    //use hashmap to store the elements of an array
    public int[] sumOfNumbersMethod2(int[] arr, int target){
        int res = new int[2];
        
        return res;
    }

    protected int getNumber(){
        return number5;
    }

    private void setNumber(int num){
        this.number5 = num;
    }
}

public class TestJava {
    public static void main(String[] args) {
        System.out.println("java version");
        int[] arr = {1,2,3,4,5,6};
        TwoSum twoSum = new TwoSum();
        int sum = twoSum.sumOfNumbers(arr);
        int num = 6;
        twoSum.setNumber(num);
        System.out.println("number is :"+twoSum.getNumber());
    }
}