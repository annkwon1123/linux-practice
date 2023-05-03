int recur(int v){
        if(v <= 1) return 1;
        else return v * recur(v-1);
}

int main(int argc, char* argv[]){
        int N = atoi(argv[1]);

        int pid, result = 0;
        pid = fork();
        if (pid == 0){
                for(int i=0; i<=N; i++) result += i;
                printf("sum: %d\n", result);
        }
        else{
                result = recur(N);
                printf("factorial: %d\n", result);
        }

        return 0;
}
