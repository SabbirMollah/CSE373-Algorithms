#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 200

/*
    Sabbir Mollah
    - Assignment 3 (With Adjacency List)
*/


void enqueue(int);
int dequeue();
int isQueueEmpty();
int front =  - 1;
int rear =  - 1;
int queue[MAX_VERTICES];

struct Vertex{
    int index;
    struct Vertex* next;
};

void insertVertexAtoB(int, int);
int bfs(int);
struct Vertex* graph[MAX_VERTICES];
/*
    0 = Not visited
    1 = Red
    -1 = Green 
*/
int discovered[MAX_VERTICES];

int main(){
    int V, E;
    int i;

    scanf("%d%d",&V,&E);
    for(i=0; i<V; i++){
        graph[i] = NULL;
    }

    for(i=0; i<E; i++){
        int a, b;
        scanf("%d%d",&a,&b); 
        insertVertexAtoB(a,b);
        insertVertexAtoB(b,a);
    }
    for(i =0; i<V; i++){
        discovered[i] = 0;
    }

    int result = bfs(0);
    if(result ==1){
        printf("Yes");
    }
    else{
        printf("No");
    }
    return 0;
}

int bfs(int v)
{
    int currentColor = 1;
	discovered[v] = currentColor;
    enqueue(v);

	while (!isQueueEmpty()){

		v = dequeue();
        currentColor = discovered[v]*-1;
        struct Vertex* temp;
        temp = graph[v];
        while(temp!=NULL){
            
            if (discovered[temp->index] == 0){
				discovered[temp->index] = currentColor;
				enqueue(temp->index);
			}
            else if(discovered[temp->index] == currentColor){
            }
            else{
                return 0;
            }
            temp = temp->next;
        }	

	}
    return 1;
}

void enqueue(int item) {
    if (rear ==  - 1){
        rear++;
        front++;
    }
    else if (rear == MAX_VERTICES - 1 && front > 0){
        rear = 0;
    }
    else{
        rear++;
    }
    queue[rear] = item;
}

int dequeue() {
    int value;
    if (front == rear){
        value = queue[front];
        front =  - 1;
        rear =  - 1;
    }
    else{
        value = queue[front];
        front++;
    }
    return value;
}

int isQueueEmpty(){
    return (rear == -1 );
}

void insertVertexAtoB(int a, int b){
    struct Vertex *v = (struct Vertex*) malloc(sizeof(struct Vertex));
    v->index = a;
    v->next = NULL;

    if(graph[b] == NULL){
        graph[b] = v;
    }
    else{
        v->next = graph[b];
        graph[b] = v;
    }

}