package programmers;	

import java.util.Arrays;

class Karray {

	public int[] solution(int[] array, int[][] commands) {

		int[] answer = {};
		answer = new int[commands.length];
		
		for (int i = 0; i < commands.length; i++) {

			int array2Length = commands[i][1] - commands[i][0] + 1;
			int[] array2 = new int[array2Length];
			
			System.arraycopy(array, commands[i][0] - 1, array2, 0 , array2Length);
			
			Arrays.sort(array2);
			
			int array2Index = commands[i][2] - 1;
			answer[i] = array2[array2Index];
			
		}
		
		return answer;
	}
}