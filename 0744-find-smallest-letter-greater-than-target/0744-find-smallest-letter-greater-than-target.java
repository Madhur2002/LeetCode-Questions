class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        int n = letters.length;
        int start = 0, end = n - 1;

        char nextLetter = letters[start];

        while (start <= end) {
            int mid = (start + end) / 2;

            if (target < letters[mid]) {
                /*
                 * letters[mid] is the smallest letter found so far that is greater than target.
                 * So update nextLetter to this value and keep checking in the left side of the
                 * array to find an even smaller letter that is greater than target
                 */
                nextLetter = letters[mid];
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return nextLetter;
    }
}