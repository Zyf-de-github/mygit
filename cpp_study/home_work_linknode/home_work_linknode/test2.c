
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <malloc.h>


typedef struct node
{
	int x;
	struct node* next;
}linklist;
int main()
{
	int n, max, min;
	scanf("%d", &n);

	linklist* head, * s, * r;
	head = NULL;
	s = NULL;
	r = NULL;
	for (int i = 0; i < n; i++)
	{
		int mid = 0;
		scanf("%d", &mid);
		s = (linklist*)malloc(sizeof(linklist));
		s->x = mid;
		s->next = NULL;
		if (head == NULL)
		{
			head = s;
			r = head;
		}
		else
		{
			r->next = s;
		}
		r = s;
	}
	r = head;
	//for (int i = 0; i < n; i++)
	//{
	//	printf("%d ", r->x);
	//	r = r->next;
	//}
	scanf("%d %d", &min, &max);//ÊäÈëÊý¾Ý
	s = head;
	int mid_sum = 1;
	while (1)
	{
		if (s->x >= min && s->x <= max)
		{
			if (s->next == NULL)
			{
				break;
			}
			r = s->next;
			s->x = r->x;
			if (r->next != NULL)
			{
				s->next = r->next;
				free(r);
			}
			else
			{
				s->next = NULL;
				free(r);
			}

		}
		else if (s->x<min || s->x>max)
		{

			if (s->next != NULL)
			{
				if (mid_sum)
				{
					printf("%d ", s->x);
					s = s->next;
					mid_sum = 0;
				}
				else
				{
					printf(" %d ", s->x);
					s = s->next;
				}
			}
			else
			{
				printf(" %d", s->x);
				break;
			}
		}
	}



	return 0;
}


//typedef struct node
//{
//	char x;
//	struct node* next;
//}linklist;
//int main()
//{
//	linklist* head, * s, * r;
//	head = NULL;
//	s = NULL;
//	r = NULL;
//	char c;
//	while ((c = getchar()) != '\n')
//	{
//		s = (linklist*)malloc(sizeof(linklist));
//		s->x=c;
//		s->next = NULL;
//		if (head == NULL)
//		{
//			head = s;
//			r = head;
//		}
//		else
//		{
//			r->next = s;
//		}
//		r = s;
//	}
//	s = head;
//
//	//int sum = 0, begin = 0, mid_sum = 0, flag = 1, mid_begin = 1;
//	//while (s->next != NULL)
//	//{
//	//	if (s->x <= '9' && s->x >= '0')
//	//	{
//	//		mid_sum++;
//	//		if (mid_sum > sum)
//	//		{
//	//			sum = mid_sum;
//	//			if (flag)
//	//			{
//	//				begin = mid_begin;
//	//			}
//	//		}
//	//		mid_begin++;
//	//		s = s->next;
//	//	}
//	//	else
//	//	{
//	//		mid_sum = 0;
//	//		flag = 0;
//	//		mid_begin++;
//	//		flag = 0;
//	//		s = s->next;
//	//	}
//	//}
//	//printf("%d %d", begin, sum);
//
//
//	return 0;
//}
