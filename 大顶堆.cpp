//���룺int a[6] = {7, 3, 8, 5, 1, 2} 
#include <iostream>
using namespace std;
void Swap(int *heap, int len);//�������ڵ������ĩβԪ��
void BuildMaxHeap(int *heap, int len); //�����󶥶�
void BuildMaxHeap(int *heap, int len){
	int i;
	int temp;
	//len/2-1�����һ����Ҷ�ӽڵ� 
	for(i=len/2-1;i>=0;i--){
		//���ӽڵ�ʹ˽ڵ�ȴ�С 
		if((2*i+1)<len && heap[i] < heap[2*i+1]){
			temp = heap[i];
			heap[i] = heap[2*i+1];
			heap[2*i+1] = temp;
			//��齻������������Ƿ�����󶥶�����
			if((2*(2*i+1)+1<len && heap[2*i+1] < heap[2*(2*i+1)+1]) || (2*(2*i+1)+2 < len && heap[2*i+1] < heap[2*(2*i+1)+2])) 
			{
				//ֻ���ؽ�heap[2*i+1]��������
				BuildMaxHeap(heap,len);
			}
		}
		if((2*i+2) < len && heap[i] < heap[2*i+2]){
			temp = heap[i];
			heap[i] = heap[2*i+2];
			heap[2*i+2] = temp;
			//��齻������������Ƿ�����󶥶�����
			if((2*(2*i+2)+1<len && heap[2*i+2] < heap[2*(2*i+2)+1]) || (2*(2*i+2)+2 < len && heap[2*i+2] < heap[2*(2*i+2)+2])) 
			{
				//ֻ���ؽ�heap[2*i+2]�������� 
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
