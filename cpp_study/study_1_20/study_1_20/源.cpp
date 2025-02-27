#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include<string>
//#include<math.h>
//using namespace std;

//int main() {
//	int a = 0;
//	int &b = a;
//	b = 100;
//	cout << a<<endl;
//
//	return 0;
//}
//
//class stu {
//public:
//	string name;
//	int begin;
//	int end;
//
//	int time()
//	{
//		return end-begin;
//	}
//};
//class list {
//public:
//	string stu;
//	string num;
//	void list_all()
//	{
//		cout << "name=" << stu << "  num=" << num << endl;
//	}
//};
//
//int main()
//{
//	//stu stu1;
//	//stu1.name = "zhangsan";
//	//stu1.begin = 10;
//	//stu1.end = 50;
//	//cout << "worktime=" << stu1.time() << endl;
//	list stu;
//	stu.stu = "zhangsan";
//	stu.num = "23001010";
//	stu.list_all();
//	return 0;
//}


//class cercle
//{
//private:
//	double cercle_point_x=5.0;
//	double cercle_point_y=5.0;
//	double r = 5;
//public:
//	double cur_point_x;
//	double cur_point_y;
//	void calculate()
//	{
//		int x = pow(cur_point_x - cercle_point_x, 2) + pow(cur_point_y - cercle_point_y, 2);
//		if (x < pow(r, 2))
//			cout << "点在圆内" << endl;
//		else if (x == pow(r, 2))
//			cout << "点在圆上" << endl;
//		else
//			cout << "点在圆外" << endl;
//	}
//};
//int main()
//{
//	cercle c1;
//	while(1)
//	{
//		cin >> c1.cur_point_x >> c1.cur_point_y;
//		c1.calculate();
//	}
//	return 0;
//}


//class abstrackdrinking
//{
//public:
//	virtual void boil() = 0;
//	virtual void brew() = 0;
//	virtual void pour() = 0;
//	virtual void add() = 0;
//	void make()
//	{
//		boil();
//		brew();
//		pour();
//		add();
//	}
//};
//
//class tea : public abstrackdrinking
//{
//	virtual void boil()
//	{
//		cout << "水烧到100度" << endl;
//	}
//	virtual void brew()
//	{
//		cout << "冲泡茶叶" << endl;
//	}
//	virtual void pour()
//	{
//		cout << "倒入茶壶" << endl;
//	}
//	virtual void add()
//	{
//		cout << "加入枸杞" << endl;
//	}
//};
//
//class coffee : public abstrackdrinking
//{
//	virtual void boil()
//	{
//		cout << "水烧到120度" << endl;
//	}
//	virtual void brew()
//	{
//		cout << "冲泡咖啡" << endl;
//	}
//	virtual void pour()
//	{
//		cout << "倒入茶壶" << endl;
//	}
//	virtual void add()
//	{
//		cout << "加入糖" << endl;
//	}
//};
//
//void dowork(abstrackdrinking* abc)
//{
//	abc->make();
//	delete abc;
//}
//int main()
//{
//	//dowork(new tea);
//	//dowork(new coffee);
//	coffee myco;
//	myco.make();
//	tea myt;
//	myt.make();
//
//	return 0;
//}

//template<typename T>
//void my_swap(T &a, T &b)
//{
//	T temp = a;
//	a = b;
//	b = temp;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 100;
//	my_swap(a, b);
//	cout << "a=" << a << "b=" << b << endl;
//
//	return 0;
//}
//
//class person
//{
//public:
//	person(string name, int age)
//	{
//		this->name = name;
//		this->age = age;
//	}
//	string name;
//	int age;
//};
//
//int main()
//{
//	person tom("tom", 29);
//	return 0;
//}


//#include <stdio.h>

//int main()
//{
//    int i, j, num = 0, k = 0, flag = 0, two_num = 0;
//    int arr[2000] = { 0 };
//    scanf("%d", &num);
//    for (i = 1; i < num + 1; i++)
//    {
//        flag = 0;
//        for (j = 1; j < i + 1; j++)
//        {
//            if ((i % j == 0) || (j != 1) || (j != i))
//            {
//                flag = 1;
//            }
//        }
//        if (flag == 0)
//        {
//            arr[k] = i;
//            k++;
//        }
//    }
//    for (i = 0; i < num; i++)
//        printf("%d ", arr[i]);
//    for (i = 0; i < k + 1; i++)
//    {
//        if (arr[k + 1] - arr[k] == 2)
//            two_num++;
//    }
//    printf("%d", two_num);
//    return 0;
//}


//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//    int n;
//    char arr[101][10] = { 0 };
//    int arr_up[101] = { 0 };
//    int arr_down[101] = { 0 };
//    scanf("%d", &n);
//    for (int i = 0; i < n; i++)
//    {
//        scanf("%s", arr[i]);
//    }
//    for (int i = 0; i < n; i++)
//    {
//        if (arr[i][0] == '-')
//        {
//            int j = 1;
//            while (arr[i][j] != '/')
//            {
//                arr_up[i] = arr_up[i] * 10 + arr[i][j] - '0';
//                j++;
//            }
//            arr_up[i] *= -1;
//            j++;
//            while (arr[i][j] != '\0')
//            {
//                arr_down[i] = arr_down[i] * 10 + arr[i][j] - '0';
//                j++;
//            }
//        }
//        else
//        {
//            int j = 0;
//            while (arr[i][j] != '/')
//            {
//                arr_up[i] = arr_up[i] * 10 + arr[i][j] - '0';
//                j++;
//            }
//            j++;
//            while (arr[i][j] != '\0')
//            {
//                arr_down[i] = arr_down[i] * 10 + arr[i][j] - '0';
//                j++;
//            }
//        }
//    }
//    int min_num,flag;
//    for (min_num = 1; ; min_num++)
//    {
//        int flag = 0;
//        for (int i = 0; i < n; i++)
//        {
//            if (min_num % arr_down[i] != 0)
//            {
//                flag = 1;
//                break;
//            }
//        }
//        if (flag == 0)
//            break;
//    }
//
//    for (int i = 0; i < n; i++)
//    {
//        arr_up[i] *= min_num / arr_down[i];
//    }
//
//    int sum = 0;
//    for (int i = 0; i < n; i++)
//    {
//        sum+=arr_up[i];
//    }
//    min_num *= n;
//    int dev = 0;
//    for (dev = min_num;; dev--)
//    {
//        if (sum % dev == 0 && min_num % dev == 0)
//        {
//            sum /= dev;
//            min_num /= dev;
//            break;
//        }
//    }
//    if (min_num == 1)
//    {
//        printf("%d", sum);
//    }
//    else
//    {
//        printf("%d/%d", sum, min_num);
//    }
//    return 0;
//}


#include <stdio.h>
#include <string.h>
#include <malloc.h>
//int main()
//{
//    int n, k;
//    scanf("%d %d", &n, &k);
//    char arr[102][11] = { 0 };
//    char temp[11] = { 0 };
//    for (int i = 0; i < n; i++)
//    {
//        scanf("%s", arr[i]);
//    }
//    if (n != 1)
//    {
//        for (int x = 0; x < k; x++)
//        {
//            ////////
//            for (int i = 0; i < n - 1; i++)
//            {
//                for (int j = 0; arr[i + 1][j] != '\0'; j++)
//                {
//                    if (arr[i][j] >= arr[i + 1][j])
//                    {
//                        strcpy(temp, arr[i]);
//                        strcpy(arr[i], arr[i + 1]);
//                        strcpy(arr[i + 1], temp);;
//                        break;
//                    }
//                    else if (arr[i][j] < arr[i + 1][j])
//                    {
//                        break;
//                    }
//                }
//            }
//        }
//        for (int i = 0; i < n; i++)
//        {
//            printf("%s\n", arr[i]);
//        }
//    }
//    else
//    {
//        printf("%s\n", arr[0]);
//    }
//    return 0;
//}
//typedef struct node
//{
//	int x;
//	struct node* next;
//}linklist;
//int main()
//{
//	int n, max, min;
//	scanf("%d", &n);
//
//	linklist *head,*s,*r;
//	head = NULL;
//	s = NULL;
//	r = NULL;
//	for (int i = 0; i < n; i++)
//	{
//		int mid = 0;
//		scanf("%d", &mid);
//		s = (linklist*)malloc(sizeof(linklist));
//		s->x = mid;
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
//	r = head;
//	//for (int i = 0; i < n; i++)
//	//{
//	//	printf("%d ", r->x);
//	//	r = r->next;
//	//}
//	scanf("%d %d", &min, &max);//输入数据
//	s = head;	
//	int flag = 1;
//	while(1)
//	{
//		if (s->x >= min && s->x <= max)
//		{
//			if (s->next == NULL)
//			{
//				break;
//			}
//			r = s->next;
//			s->x = r->x;
//			if(r->next!=NULL)
//			{
//				s->next = r->next;
//				free(r);
//			}
//			else
//			{
//				s->next = NULL;
//				free(r);
//			}
//
//		}
//		else if (s->x<min || s->x>max)
//		{
//
//			if (s->next != NULL)
//			{
//				if(flag)
//				{
//					printf("%d ", s->x);
//					s = s->next;
//					flag = 0;
//				}
//				else
//				{
//					printf(" %d ", s->x);
//					s = s->next;
//				}
//			}
//			else
//			{
//				printf(" %d", s->x);
//				break;
//			}
//		}
//	}
//
//	
//
//	return 0;
//}

//while (1)
//{
//	if (s->x >= min && s->x <= max)
//	{
//		if (s->next == NULL)
//		{
//			free(s);
//			break;
//		}
//		else
//		{
//			r = s->next;
//			s->x = r->x;
//			if (r->next == NULL)
//			{
//				break;
//			}
//			else
//			{
//				s = r->next;
//				free(r);
//			}
//		}
//	}
//	else if (s->x<min || s->x>max)
//	{
//		printf("%d ", s->x);
//		if (s->next == NULL)
//		{
//			break;
//		}
//		else
//		{
//			s = s->next;
//		}
//	}
//}


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
//	//while (1)
//	//{
//	//	printf("%c ", r->x);
//	//	if (r->next == NULL)
//	//	{
//	//		break;
//	//	}
//	//	r = r->next;
//	//}
//	int sum = 0, begin = 0, mid_sum = 0, abcd = 0,flag=0;
//	r = head;
//	s = head;
//	while (s != NULL)
//	{
//		abcd = 1;
//		if (s->x <= '9' && s->x >= '0')
//		{
//			mid_sum++;
//			if (mid_sum > sum)
//			{
//				sum = mid_sum;
//				begin = flag;
//			}
//			s = s->next;
//			flag++;
//		}
//		else
//		{
//			mid_sum = 0;
//			flag++;
//			s = s->next;
//		}
//	}
//	if(abcd==1)
//	{
//		printf("%d %d", begin - sum + 1, sum);
//	}
//	else
//	{
//		printf("NULL");
//	}
//
//
//	return 0;
//}

//typedef struct node
//{
//	int x;
//	struct node* next;
//}linklist;
//int main()
//{
//	int n,c;
//	scanf("%d", &n);
//	linklist* head1=NULL, *head2=NULL,*s=NULL,*r=NULL,*r1=NULL,*r2=NULL;
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &c);
//		s = (linklist*)malloc(sizeof(linklist));
//		s->x = c;
//		s->next = NULL;
//		if (head1 == NULL)
//		{
//			head1 = s;
//			r = head1;
//		}
//		else
//		{
//			r->next = s;
//			r = s;
//		}
//	}
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &c);
//		s = (linklist*)malloc(sizeof(linklist));
//		s->x = c;
//		s->next = NULL;
//		if (head2 == NULL)
//		{
//			head2 = s;
//			r = head2;
//		}
//		else
//		{
//			r->next = s;
//			r = s;
//		}
//	}
//	//r = head1;
//	//	while (1)
//	//{
//	//	printf("%d ", r->x);
//	//	if (r->next == NULL)
//	//	{
//	//		break;
//	//	}
//	//	r = r->next;
//	//}
//	r1 = head1;
//	r2 = head2;
//	int num;
//
//	if (head1->x > head2->x)
//	{
//		num = head2->x;
//	}
//	else
//	{
//		num=head1->x;
//	}
//	for (int i = 0; i < n-1; i++)
//	{
//		if (r1->x > r2->x)
//		{
//			r2 = r2->next;
//			num = r2->x;
//		}
//		else
//		{
//			r1 = r1->next;
//			num = r1->x;
//		}
//	}
//	printf("%d", num);
//
//	return 0;
//}

typedef struct node
{
	int x;
	struct node* next;
}linklist;
int main()
{
	linklist* head, * s, * r;
	int a = 0, n = 0;
	head = NULL;
	s = NULL;
	r = NULL;
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		scanf("%d", &a);
		s = (linklist*)malloc(sizeof(linklist));
		s->x = a;
		s->next = NULL;
		if (head == NULL)
		{
			head = s;
			r = s;
		}
		else
		{
			r->next = s;
			r = s;
		}
	}

	//r = head;
	//while (1)
	//{
	//	printf("%c ", r->x);
	//	if (r->next == NULL)
	//	{
	//		break;
	//	}
	//	r = r->next;
	//}
	int per_num=-11918,flag=0,len_num=0,len_num_mid=0,begin=0;
	s = head;
	while (s != NULL)
	{
		if (per_num == -11918)
		{
			per_num = s->x;
			flag++;
			len_num_mid++;
			s = s->next;
			continue;
		}
		else
		{
			if (s->x > per_num)
			{
				len_num_mid++;
				{
					if (len_num_mid > len_num)
					{
						len_num = len_num_mid;
						begin = flag;
					}
				}
			}
			else
			{
				len_num_mid = 1;
			}
			per_num = s->x;
			flag++;
		}
		s = s->next;
	}
	int y;
	s = head;
	for(int i=0;i<n;i++)
	{
		if (i > (begin - len_num)&&i<begin)
		{
			y = s->x;
			printf("%d ", y);
		}
		else if (i == begin)
		{
			y = s->x;
			printf("%d", y);
		}
		s = s->next;
	}

	return 0;
}