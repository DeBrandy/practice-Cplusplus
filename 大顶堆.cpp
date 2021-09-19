//输入：int a[6] = {7, 3, 8, 5, 1, 2} 
#include <iostream>
using namespace std;
void Swap(int *heap, int len);//交换根节点和数组末尾元素
void BuildMaxHeap(int *heap, int len); //构建大顶堆
void BuildMaxHeap(int *heap, int len){
	int i;
	int temp;
	//len/2-1是最后一个非叶子节点 
	for(i=len/2-1;i>=0;i--){
		//左孩子节点和此节点比大小 
		if((2*i+1)<len && heap[i] < heap[2*i+1]){
			temp = heap[i];
			heap[i] = heap[2*i+1];
			heap[2*i+1] = temp;
			//检查交换后的左子树是否满足大顶堆性质
			if((2*(2*i+1)+1<len && heap[2*i+1] < heap[2*(2*i+1)+1]) || (2*(2*i+1)+2 < len && heap[2*i+1] < heap[2*(2*i+1)+2])) 
			{
				//只是重建heap[2*i+1]的左子树
				BuildMaxHeap(heap,len);
			}
		}
		if((2*i+2) < len && heap[i] < heap[2*i+2]){
			temp = heap[i];
			heap[i] = heap[2*i+2];
			heap[2*i+2] = temp;
			//检查交换后的左子树是否满足大顶堆性质
			if((2*(2*i+2)+1<len && heap[2*i+2] < heap[2*(2*i+2)+1]) || (2*(2*i+2)+2 < len && heap[2*i+2] < heap[2*(2*i+2)+2])) 
			{
				//只是重建heap[2*i+2]的右子树 
				BuildMaxHeap(heap,len);
			}
		}
		
	}
} 
 
void Swap(int *heap, int len){
	int temp;
	temp = heap[0];
	heap[0] = heap[len-1];
	heap[len-1] = temp;
}
int main(){
	int a[6] = {7, 3, 8, 5, 1, 2};
	int len = 6;
	int i;
	
	for(i=len;i>0;i--){
		BuildMaxHeap(a,i);
		Swap(a,i);
	}
	for(i=0;i<len;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
