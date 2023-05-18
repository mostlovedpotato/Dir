

class Solution {
    public List<Integer> findSmallestSetOfVertices(int n, List<List<Integer>> edges) {
        List<Integer> ans = new ArrayList<>();
        int [] check = new int[n];
        for(int i = 0; i < n; i++){
            check[i]=0;
        }
        for(List<Integer> l : edges){
            check[l.get(1)]++;
        }
        for(int i = 0; i < n;i++){
            if(check[i]==0)
                ans.add(i);
        }
        return ans;
    }
}
