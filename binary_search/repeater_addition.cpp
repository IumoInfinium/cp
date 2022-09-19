// int solve(int n) {

//     while(n>=10){
//         int x=0;
//         while(n>0){
//             x+=(n%10);
//             n/=10;
//         }
//         n=x;
//     }
//     return n;
// }

int solve(int n){
    if(n<10)return n;
    if(n%9==0) return 9;
    return n%9;
}
