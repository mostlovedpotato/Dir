class Solution {
    List<Long> list;
    long mod = 1000000007;
    public int maxProduct(TreeNode root) {
        list = new ArrayList<>();
        long total = postOrder(root);
        long max = 0;
        long prod = 0;

        for(int i=0;i<list.size()-1;i++){
            prod = (list.get(i)*(total-list.get(i)));
            max = Math.max(prod,max);
        }
        return (int) (max%mod);
    }
    public long postOrder(TreeNode root){
        if(root==null){
            return 0;
        }
        long leftChild = postOrder(root.left);
        long rightChild = postOrder(root.right);
        long curSum = leftChild + rightChild + root.val;
        list.add(curSum);
        return curSum;
    }
}