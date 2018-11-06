import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> res = new ArrayList<>();
        int n = nums.length;
        if (n < 4) {
            return res;
        }

        Arrays.sort(nums);

        for (int i = 0; i < n-3; i++) {
            int a = nums[i];
            if (i > 0 && a == nums[i-1]) {
                continue;
            }

            for (int j = i+1; j < n-2; j++) {
                int b = nums[j];
                if (j > 1 && b == nums[j-1]) {
                    continue;
                }

                int start = j+1;
                int end = n-1;
                while (start < end) {
                    int c = nums[start];
                    int d = nums[end];
                    int total = a + b + c + d;
                    if (total == target) {
                        res.add(new ArrayList<>(Arrays.asList(a, b, c, d)));

                        while (start < end && c == nums[start]) {
                            start++;
                        }
                        while (start < end && d == nums[end]) {
                            end--;
                        }
                    } else if (total < target) {
                        start++;
                    } else {
                        end--;
                    }
                }
            }
        }

        return res;
    }
}

public class MainClass {
    public static int[] stringToIntegerArray(String input) {
        input = input.trim();
        input = input.substring(1, input.length() - 1);
        if (input.length() == 0) {
            return new int[0];
        }

        String[] parts = input.split(",");
        int[] output = new int[parts.length];
        for(int index = 0; index < parts.length; index++) {
            String part = parts[index].trim();
            output[index] = Integer.parseInt(part);
        }
        return output;
    }

    public static String integerArrayListToString(List<Integer> nums, int length) {
        if (length == 0) {
            return "[]";
        }

        String result = "";
        for(int index = 0; index < length; index++) {
            Integer number = nums.get(index);
            result += Integer.toString(number) + ", ";
        }
        return "[" + result.substring(0, result.length() - 2) + "]";
    }

    public static String integerArrayListToString(List<Integer> nums) {
        return integerArrayListToString(nums, nums.size());
    }

    public static String int2dListToString(List<List<Integer>> nums) {
        StringBuilder sb = new StringBuilder("[");
        for (List<Integer> list: nums) {
            sb.append(integerArrayListToString(list));
            sb.append(",");
        }

        sb.setCharAt(sb.length() - 1, ']');
        return sb.toString();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String line;
        while ((line = in.readLine()) != null) {
            int[] nums = stringToIntegerArray(line);
            line = in.readLine();
            int target = Integer.parseInt(line);

            List<List<Integer>> ret = new Solution().fourSum(nums, target);

            String out = int2dListToString(ret);

            System.out.print(out);
        }
    }
}