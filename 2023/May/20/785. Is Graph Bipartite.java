class Solution {
    int [] colors;
    public boolean isBipartite(int[][] graph) {
        int n = graph.length;
        int [] color = new int[n];
        for(int i = 0;i < n;i++){
            if(color[i] != 0 ){
                continue;
            }
            Queue<Integer> q = new LinkedList<>();
            q.add(i);
            color[i] = 1;
            while(!q.isEmpty()){
                int curr = q.peek();
                q.remove();
                for(int x : graph[curr]){
                    if(color[x] == 0){
                        color[x] -= color[curr];
                        q.add(x);
                    }else if(color[x] != -color[curr]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
}