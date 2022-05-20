#include <stdio.h>

#define INT_MAX 2147483647 // 정수의 최댓값
#define TRUE 1
#define FALSE 0
#define NODENUM 6  // 노드의 수
#define INF 1000    // 연결이 없는경우 무한대로 표시한다

int weight[NODENUM][NODENUM] = {
  {0  ,5  ,INF,2  ,4  ,INF},
  {5  ,0  ,3  ,3  ,INF,INF},
  {INF,3  ,0  ,3  ,4  ,2},
  {2  ,3  ,3  ,0  ,1  ,INF},
  {4  ,INF,4  ,1  ,0  ,2},
  {INF,INF,2  ,INF,2  ,0}, };
int distance[NODENUM]; // 시작노드로부터의 최단거리를 저장하는 배열
int visited[NODENUM];// 방문한 노드를 기록하는 배열


int choose(int distance[], int num, int found[])
{
    // difstance  배열에서 가장 가까운 위치의 노드를 return하는 함수
    int i, min, index;
    min = INT_MAX;
    index = -1;
    // 최소값 min을 찾는 반복문
    // 방문한 적이 없는 노드에 대해 distance배열의 값들을 비교한다.
    for (i = 0; i < num; i++)
    {
        //found 배열의 값이 false고 distance가 최솟값보다 작다면 갱신하는 if문
        if (distance[i] < min && found[i] == FALSE)
        {
            min = distance[i];// min 정보를 갱신  
            index = i; // 해당 노드의 인덱스를 저장.
            
        }
    }
    return index;//distance에서 제일 작은값을가진 index를 return
}

void shortestPath(int start, int num)//시작점과 노드의 개수를 input
// start 노드에서 마지막 노드까지 최단경로를 구하는 프로그램
{
    int i, u, w;
    u = 0;
    int n = num;
    //distnace배열과 found 배열을 초기화 하는 for문
    for (i = 0; i < n; i++)
    {
        distance[i] = weight[start][i];//start기준의 가중치로 distance배열을 초기화   
        visited[i] = FALSE;//visited 값을 false로 초기화 아직 아무 노드도 방문하지 않았기 떄문
        
    }
    visited[start] = TRUE;// 시작노드이기 때문에 true
   
    for (i = 0; i < n - 1; i++) 
    {

            u = choose(distance, n, visited);// 최소값이 있는 인덱스를 u에 저장
            visited[u] = TRUE;//u 인덱스가 가장 작은 거리를 가진 
           //노드의 인덱스 번호이기 때문에 방문
            
        for (w = 0; w < n; w++)
        {
            
            if (visited[w] == FALSE)// 아직 선택되어 지지 않은 노드라면
            {
                // 현재 그 노드까지의 거리 (distance[u]) + 노드 w까지의 거리가
                // 기존의 w노드까지의 거리보다 가깝다면 그 정보를 갱신
                if (distance[u] + weight[u][w] < distance[w])
                {
                    distance[w] = distance[u] + weight[u][w];
               
                }
                
            }
           
        } 
        
    }
   
    printf(" %d번 노드에서 마지막 노드까지의 최단거리: %d",start ,distance[NODENUM - 1]);//마지막 노드까지의 최단거리의 값을 print
}

void main()
{
    shortestPath(5, 6);
    
}
