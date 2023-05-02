# include <stdio.h>
# define LEN 5
void insertionSort(int* arr){
	int i, j, key;
	for(i=1; i< LEN; i++){
		key = arr[i]; // 현재 삽입될 숫자인 i번째 정수를 key 변수로 복사
		for(j=i-1; j>=0 && arr[j]>key; j--){ // key가 더 큰 값일 때까지
			arr[j+1] = arr[j]; // 한 칸 뒤로 이동
		}
		arr[j+1] = key; // 알맞은 위치에 key 삽입
	}
}
int main(){
	int arr[LEN] = {7,5,1,4,3};
	int i;
	printf("정렬 전 : ");
	for(i=0; i<5; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	insertionSort(arr);
	printf("정렬 후 : ");
	for(i=0; i<5; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
