class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        HashMap<Integer,Integer> mp = new HashMap<>();
        for(int num : nums){
            mp.put(num,mp.getOrDefault(num,0)+1);
        }
        PriorityQueue<Integer> minHeap = new PriorityQueue<>((a,b)->mp.get(a)-mp.get(b));
        for(int num : mp.keySet()){
            minHeap.offer(num);
            if(minHeap.size() > k){
                minHeap.poll();
            }
        }
        int[] res = new int[k];
        for(int i=k-1;i>=0;i--){
            result[i] = minHeap.poll();
        }
        return res;
    }
}