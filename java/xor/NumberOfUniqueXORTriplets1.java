public class NumberOfUniqueXORTriplets1 {
    public int uniqueXorTriplets(int[] nums) {
        int n=nums.length;

        if(n < 3){
            return n;
        }

        int x = (int)(Math.log(n)/Math.log(2));

        return (int) Math.pow(2,x+1);
    }

    public static void main(String[] args) {
        int[] nums={3,1,2};
        NumberOfUniqueXORTriplets1 solution = new NumberOfUniqueXORTriplets1();
        System.out.println(solution.uniqueXorTriplets(nums));
    }
}
