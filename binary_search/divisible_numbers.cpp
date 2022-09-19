class Solution {
    public:
    int a,b,c;
    int lcm(int x,int y){
        return x*y/__gcd(x,y);
    }

    int lesser(int n){
        // how many elements less than it?
        return n/a + n/b + n/c - n/lcm(a,b) - n/lcm(b,c) - n/lcm(a,c) + n/lcm(a,lcm(b, c));
    }

    int solve(int n,int a,int b,int c){
        this->a=a,this->b=b, this->c=c;
        int l=1, r=INT_MAX;
        while(l<r){
            int guess=l+(r-l)/2;
            if (lesser(guess)>=n) r=guess;   // get first value with >=n elements lesser than it!
            else  l=guess+1;                 // guess is not the answer! +1 it
        }
        return l;
    }
};

int solve(int n, int a, int b, int c) {
    return (new Solution())->solve(n, a, b, c);
}
