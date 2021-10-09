#include<stdio.h>

struct queue 
{
    int arr[50];
    int FRONT;
    int REAR;
    int size;
}p;

void inqueue(struct queue *s)
{
    if ((s->REAR + 1) % s->size == s->FRONT)
        printf("Queue OverFlow.\n");
    else
    {
        int item;
        printf("Enter item: ");
        scanf("%d", &item);
        
        if (s->FRONT == -1)
        {
            s->FRONT +=1;
            s->REAR +=1;
            s->arr[s->REAR] = item;
        }
        else
        {
            s->REAR = (s->REAR + 1) % s->size;
            s->arr[s->REAR] = item;
        }
    }
}

void dequeue(struct queue *s)
{
    if (s->FRONT == -1)
        printf("Queue Empty.\n");
    else
    {
        int item;
        item = s->arr[s->FRONT];
        printf("Item %d dequeued.\n", item);
        if (s->FRONT == s->REAR)
        {
            s->FRONT = -1;
            s->REAR = -1;
        }
        else
            s->FRONT = (s->FRONT + 1) % s->size;
    }
}

void display(struct queue *s)
{
    if (s->FRONT == -1)
        printf("Queue Empty.\n");
    else
    {
        int i,j;
        printf("\nQueue\n");
        
        for(i = s->FRONT; i != s->REAR; i = (i+1)%s->size)
            printf("%d\n", s->arr[i]);
            
        if(i == s->REAR)
            printf("%d\n", s->arr[i]);
            
        printf("\n");
                   
    }
}

void main()
{
    struct queue p;
    printf("Enter size of Queue(Max 50): ");
    scanf("%d", &p.size);
    p.FRONT = -1;
    p.REAR = -1;
    
    int ch;
    while(1)
    {
        printf("Menu\n1.Inqueue\n2.Dequeue\n3.Display\nEnter Choice: ");
        scanf("%d", &ch);
        
        switch(ch)
        {
            case 1: inqueue(&p); break;
            case 2: dequeue(&p); break;
            case 3: display(&p); break;
            case 4: exit(1); break;
        }
        
    }
}
