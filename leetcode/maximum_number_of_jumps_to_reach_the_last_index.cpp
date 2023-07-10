class Solution {
public:
    // int largestVariance(string s) {
    //     int freq[26];
    //     int n = s.size();

    //     for(int i=0; i<n; i++) freq[s[i]-'a']++;

    //     int maxVariance = 0;

    //     for(int i=0; i<26; i++){
    //         for(int j=0; j<26; j++){
    //             int remainA = freq[i];
    //             int remainB = freq[j];
    //             if(i == j || remainA == 0 || remainB == 0) continue;

    //             int currAFreq = 0, currBFreq = 0;

    //             for(int k=0; k<n; k++){
    //                 int c = s[k]-'a';
    //                 if(c == j) currBFreq++;
    //                 if(c == i){
    //                     currAFreq++;
    //                     remainA--;
    //                 }
    //                 if(currAFreq > 0) maxVariance = max(maxVariance, currBFreq - currAFreq);

    //                 if(currBFreq < currAFreq && remainA >= 1) currBFreq = currAFreq = 0;
    //             }
    //         }
    //     }
    //     return maxVariance;
    // }
    int largestVariance(string s){
        int maxVariance = 0;

        for(char c1 = 'a'; c1<= 'z'; c1++){
            for(char c2 = 'a'; c2<='z'; c2++){
                if(c1 == c2) continue;

                int freqA = 0;
                int freqB = 0;
                bool lowFreqLeft = false;

                for(char &c : s){
                    if(c == c1) freqA++;
                    if(c == c2) freqB++;
                    if(freqB > 0) maxVariance = max(maxVariance, freqA - freqB);
                    else{
                        if(lowFreqLeft) maxVariance = max(maxVariance, freqA - 1);
                    }

                    if(freqB > freqA){
                        freqB = freqA = 0;
                        lowFreqLeft = true;
                    }
                }
            }
        }
        return maxVariance;
    }
};
