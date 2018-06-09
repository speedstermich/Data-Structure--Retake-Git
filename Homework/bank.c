#include <stdio.h>
#include <stdlib.h>

//create customer class
struct Customer
{
	int num;
	int wait;
	struct Customer *next;
};
struct Customer *queue_front = NULL, *queue_rear = NULL;
int bank_window = 3;
int lenlist[1000];

//function for add queue
void Enter_queue(int seq)
{
	struct Customer *add_rear = (struct Customer *)malloc(sizeof(struct Customer));
	add_rear -> wait = 0;
	add_rear -> num = seq;
	add_rear -> next = NULL;
	if(queue_front == NULL)
	 	queue_front = add_rear;
	else
		queue_rear->next = add_rear;
	queue_rear = add_rear;
}

//function for get out from queue
void Out_queue()
{
	if (queue_front == NULL)
	{
		printf("ERROR: EMPTY QUEUE\n");
	}
	else
	{
		struct Customer *p = queue_front;
		queue_front = queue_front->next;
		free(p);
	}
}

//declare thread to start
void start(int new_customer, int *num_seq)
{
	int i, len_queue;
	for(i = 0; i < new_customer; i++)
	{
		Enter_queue(*num_seq);
		(*num_seq)++;
	}

	if(queue_front != NULL)
		len_queue = queue_rear->num - queue_front->num + 1;
	else
		len_queue = 0;
	if(len_queue / bank_window >= 7)
	{
		if(len_queue / (bank_window + 1) < 7)
		{
			if (bank_window <= 4)
				(bank_window)++;
		}
		else
		{
			bank_window = 5;
		}
	}
}

//declare thread to finish
void finish()
{
	int i, len_queue;
	struct Customer *current = queue_front;
	for(i = 0; i < bank_window; i++)
	{
		if(queue_front != NULL)
		{
			lenlist[queue_front->num - 1] = queue_front->wait;
			Out_queue();
		}
	}

	if(queue_front != NULL)
	{
		for(;;)
		{
			current->wait++;
			if(current == queue_rear)
				break;
			else
				current = current->next;
		}
		/*while(current != queue_rear)
		{
			current -> wait++;
			current = current -> next;
		}*/
	}

	if(queue_front != NULL)
		len_queue = queue_rear -> num - queue_front -> num + 1;
	else
		len_queue = 0;
	if(len_queue / (bank_window) < 7 && bank_window > 3)
		bank_window--;
}

int main(int argc, char const *argv[]) {
	int cycle, new_customer, num = 1, customer = 0;
	int i;
	scanf("%d", &cycle);
	for(;;)
	{
		scanf("%d", &new_customer);
		customer += new_customer;
		start(new_customer, &num);
		finish();
		cycle--;
		if(cycle == 0)
		{
			while(queue_front != NULL)
				finish();
			break;
		}
	}
	for(i = 0; i < customer; i++)
	  	printf("%d : %d\n", i+1, lenlist[i]);
	return 0;
}
