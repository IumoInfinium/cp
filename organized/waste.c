#include <stdio.h>
#define MAX 100001
int stack[MAX];
int top = -1;
int pop();
void push(int);

int pop(){
    if (top == -1) return -99999;
    return stack[top--];
}

void push(int i){
    stack[++top] = i;
}
int main(void){
    int t, n, k, count, i;
    scanf("%d", &t);
    while (t--){
        count = 0;
        scanf("%d%d", &n, &k);
        char str[n];
        scanf("%s", str);
        int sij, pij, x;
        for (i = 0; str[i] != '\0'; i++){
            if (str[i] == 'I' || str[i] == 'M'){
                if (top == -1) push(i);
                else{
                    sij = 0;
                    if (str[i] == 'I'){
                        while (str[stack[top]] != 'M'){
                            x = pop();
                            if (x == -999) sij++;
                            else if (x = -99999) break;
                        }
                        if (str[stack[top]] == 'M'){
                            if (i > stack[top])
                                pij = k + 1 - (i - stack[top]) - sij + 2;
                            else
                                pij = k + 1 - (stack[top] - i) - sij + 2;
                            if (pij > 0) count++;
                            // printf("pij= \n%d\n",pij);
                            pop();
                        }
                        else push(i);
                    }
                    else if (str[i] == 'M'){
                        while (str[stack[top]] != 'I'){
                            x = pop();
                            if (x == -999) sij++;
                            else if (x = -99999) break;
                        }
                        if (str[stack[top]] == 'I'){
                            if (i > stack[top])
                                pij = k + 1 - (i - stack[top]) - sij + 2;
                            else
                                pij = k + 1 - (stack[top] - i) - sij + 2;
                            if (pij > 0)
                                count++;
                            pop();
                            //                            printf("pij= \n%d\n",pij);
                        }
                        else push(i);
                    }
                }
            }
            else if (str[i] == ':') push(-999);
            else if (str[i] == 'X'){
                while (top != -1){
                    pop();
                }
            }
        }
        printf("%d\n", count);
    }
    return 0;
}