#include <stdio.h>

#define INT_MAX 2147483647 // ������ �ִ�
#define TRUE 1
#define FALSE 0
#define NODENUM 6  // ����� ��
#define INF 1000    // ������ ���°�� ���Ѵ�� ǥ���Ѵ�

int weight[NODENUM][NODENUM] = {
  {0  ,5  ,INF,2  ,4  ,INF},
  {5  ,0  ,3  ,3  ,INF,INF},
  {INF,3  ,0  ,3  ,4  ,2},
  {2  ,3  ,3  ,0  ,1  ,INF},
  {4  ,INF,4  ,1  ,0  ,2},
  {INF,INF,2  ,INF,2  ,0}, };
int distance[NODENUM]; // ���۳��κ����� �ִܰŸ��� �����ϴ� �迭
int visited[NODENUM];// �湮�� ��带 ����ϴ� �迭


int choose(int distance[], int num, int found[])
{
    // difstance  �迭���� ���� ����� ��ġ�� ��带 return�ϴ� �Լ�
    int i, min, index;
    min = INT_MAX;
    index = -1;
    // �ּҰ� min�� ã�� �ݺ���
    // �湮�� ���� ���� ��忡 ���� distance�迭�� ������ ���Ѵ�.
    for (i = 0; i < num; i++)
    {
        //found �迭�� ���� false�� distance�� �ּڰ����� �۴ٸ� �����ϴ� if��
        if (distance[i] < min && found[i] == FALSE)
        {
            min = distance[i];// min ������ ����  
            index = i; // �ش� ����� �ε����� ����.
            
        }
    }
    return index;//distance���� ���� ������������ index�� return
}

void shortestPath(int start, int num)//�������� ����� ������ input
// start ��忡�� ������ ������ �ִܰ�θ� ���ϴ� ���α׷�
{
    int i, u, w;
    u = 0;
    int n = num;
    //distnace�迭�� found �迭�� �ʱ�ȭ �ϴ� for��
    for (i = 0; i < n; i++)
    {
        distance[i] = weight[start][i];//start������ ����ġ�� distance�迭�� �ʱ�ȭ   
        visited[i] = FALSE;//visited ���� false�� �ʱ�ȭ ���� �ƹ� ��嵵 �湮���� �ʾұ� ����
        
    }
    visited[start] = TRUE;// ���۳���̱� ������ true
   
    for (i = 0; i < n - 1; i++) 
    {

            u = choose(distance, n, visited);// �ּҰ��� �ִ� �ε����� u�� ����
            visited[u] = TRUE;//u �ε����� ���� ���� �Ÿ��� ���� 
           //����� �ε��� ��ȣ�̱� ������ �湮
            
        for (w = 0; w < n; w++)
        {
            
            if (visited[w] == FALSE)// ���� ���õǾ� ���� ���� �����
            {
                // ���� �� �������� �Ÿ� (distance[u]) + ��� w������ �Ÿ���
                // ������ w�������� �Ÿ����� �����ٸ� �� ������ ����
                if (distance[u] + weight[u][w] < distance[w])
                {
                    distance[w] = distance[u] + weight[u][w];
               
                }
                
            }
           
        } 
        
    }
   
    printf(" %d�� ��忡�� ������ �������� �ִܰŸ�: %d",start ,distance[NODENUM - 1]);//������ �������� �ִܰŸ��� ���� print
}

void main()
{
    shortestPath(5, 6);
    
}
