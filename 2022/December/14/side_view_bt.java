

class Solution {
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        if (root == null) return res;

        Deque<TreeNode> q = new LinkedList<>();
        q.offer(root);

        while (q.size() > 0) {
            int num = q.size();
            for (int i = 0; i < num; i++) {
                TreeNode temp = q.poll();
                if (i == 0) res.add(temp.val);
                if (temp.right != null) q.offer(temp.right);
                if (temp.left != null) q.offer(temp.left);
            }
        }
        return res;
    }
    public List<Integer> rightView(TreeNode root){
        List<Integer> res = new ArrayList<>();
        if(root==null) return res;
        HashSet<Integer> s = new HashSet<>();
        DFS(root,s,0,res);
        return res;
    }
    private void DFS(TreeNode root,HashSet<Integer> s, int level, List<Integer> res){
        if(root==null) return;
        if(!s.contains(level)){
            s.add(level);
            res.add(root.val);
        }
        DFS(root.right,s,level+1,res);
        DFS(root.left,s,level+1,res);
    }
}