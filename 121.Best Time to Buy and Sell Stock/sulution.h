int maxProfit(int* prices, int pricesSize) {
    int max = 0;
    int i,j;
    for(i=0; i<pricesSize; i++){
        int buyer = prices[i];
        for(j= i+1; j<pricesSize;j++){
            int seller = prices[j];
            int val = seller - buyer;
            if(val > max) max = val;
        }
    }
    return max;
}