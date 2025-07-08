    #include<stdio.h>
    #include<string.h>
    #include<ctype.h>
    #define max 100

    int top = -1;

    void push(int stack[], int value){
        if(top >= max -1) return;
        top++;
        stack[top] = value;
    }

    int pop(int stack[]){
        if(top == -1) return -1;
        int value = stack[top];
        top--; 
        return value;
    }

    int calculate(int stack[], char str[]){
        int length = strlen(str);
        for(int i = 0; i < length; i++){
            if(isdigit(str[i])){
                push(stack, str[i] - '0');
            }
            else if(str[i] == '+'){
                int a = pop(stack);
                int b = pop(stack);
                push(stack, a + b);
            }
            else if(str[i] == '-'){
                int a = pop(stack);
                int b = pop(stack);
                push(stack, b - a);
            }
            else if(str[i] == '*'){
                int a = pop(stack);
                int b = pop(stack);
                push(stack, a * b);
            }
            else if(str[i] == '/'){
                int a = pop(stack);
                int b = pop(stack);
                if(b == 0){
                    return -1;
                }
                push(stack, b / a);
            }
        }
        return stack[top];
    }

    int main(){
        int stack[max];
        char str[max];
        printf("Input: ");
        fgets(str, max, stdin);    
        str[strcspn(str, "\n")] = '\0';
        int result = calculate(stack, str);
        printf("%d", result);
        return 0;
    }