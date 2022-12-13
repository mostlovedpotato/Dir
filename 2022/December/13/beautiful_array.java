
//A1 = A * 2 - 1 is beautiful with only odds from 1 to N * 2 -1
//A2 = A * 2 is beautiful with only even from 2 to N * 2
//B = A1 + A2 beautiful array with length N * 2

// we can obtain the new array by multiplying previous array by 2 and then for odds subtracting one form each element.

class Solution {
    public int[] beautifulArray(int n) {
        ArrayList<Integer> res = new ArrayList<>();
        res.add(1);
        while(res.size()<n){
            ArrayList<Integer> tmp = new ArrayList<>();
            for(int i : res ) if(i*2-1 <= n) tmp.add(i*2-1);
            for(int i : res) if(i*2 <= n) tmp.add(2*i);
            res = tmp;
        }
        return res.stream().mapToInt(i->i).toArray();
    }
}