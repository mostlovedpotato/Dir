class Solution {
     public int longestDecomposition(String S) {
        int res = 0, n = S.length();
        String l = "", r = "";
        for (int i = 0; i < n/2; ++i) {
            l = l + S.charAt(i);
            r = S.charAt(n - i - 1) + r;
            if (l.equals(r)) {
                res+=2;
                l = "";
                r = "";
            }
        }
        if(n%2==0 && l =="" && r == "") return res;
        return res+1;
    }
}