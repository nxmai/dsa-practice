class Solution {
    public int kthSmallest(int[][] matrix, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        int n = matrix.length;
        int i = 0, j = 0;
        
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                if(pq.size() == k){
                    if(matrix[i][j] < pq.peek()){
                        pq.poll();
                        pq.add(matrix[i][j]);
                    }
                } else {
                    pq.add(matrix[i][j]);
                }
               
            }
        }
        
        
        return pq.peek();
    }
}