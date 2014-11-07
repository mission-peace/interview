
/**
 * https://oj.leetcode.com/problems/trapping-rain-water/
 */
public class TrappingWater {

	public int trapWater(int input[]){
		if(input.length < 2){
			return 0;
		}
		
		int maxFoundSoFar = 0;
		int result = 0;
		for(int i = 1; i < input.length; i++){
			if(input[i] < input[maxFoundSoFar]){
				continue;
			}
			else{
				int minOfTwo = Math.min(input[maxFoundSoFar], input[i]);
				for(int j = i-1; j > maxFoundSoFar; j--){
					if(minOfTwo > input[j]){
						result += minOfTwo - input[j];
					}else{
						minOfTwo = input[j];
					}
				}
				maxFoundSoFar = i;
			}
		}
		
		int minOfTwo = input[input.length-1];
		for(int j = input.length-2; j > maxFoundSoFar; j--){
			if(minOfTwo > input[j]){
				result += minOfTwo - input[j];
			}else{
				minOfTwo = input[j];
			}
		}
		return result;
	}
	
	public static void main(String args[]){
		int input[] = {0,1,0,2,1,0,1,3,2,1,2,1};
		TrappingWater tw = new TrappingWater();
		System.out.println(tw.trapWater(input));
	}
}
