#include <stdio.h>
#include <stdlib.h>

int numofdatas = 0;

typedef struct linkedlist
{
	int data;
	struct linkedlist* next;
} *ll;

ll createdata(ll haha)
{
	if(haha == NULL)
	{
		ll newone = (ll)malloc(sizeof(struct linkedlist));
		printf("값을 입력하세요. ");
		fflush(stdin);
		scanf_s("%d",&newone->data);
		newone->next = NULL;
		numofdatas++;
		return newone;
	}else{
		haha->next = createdata(haha->next);
	}
	return haha;
}

void cindexdata (ll haha,int index)
{
	int i;
	ll newtwo,newthree;
	if(index>numofdatas || index<=0)
	{
		printf("잘못된 값을 입력하셨습니다.\n");
		return;
	}else{
		for(i=1,newtwo = haha;i<index&&newtwo != NULL;i++,newtwo = newtwo->next);
		newthree = newtwo->next;
		newtwo->next = (ll)malloc(sizeof(struct linkedlist));
		newtwo = newtwo->next;
		printf("값을 입력해주십시오. ");
		scanf_s("%d",&newtwo->data);
		newtwo->next = newthree;
		numofdatas++;
	}
}

ll deletedata(ll hoho)
{
	ll i,j;
	i = hoho->next;
	j = hoho;
	if(i == NULL) {
		free(i);
		numofdatas--;
		return NULL;
	}
	while(i->next != NULL) {
		i = i->next;
		j = j->next;
	}
	free(i);
	j->next = NULL;
	numofdatas--;
	return hoho;
}

ll dindexdata(ll hoho,int index)
{
	int a;
	ll i,j;
	if(index>numofdatas || index<=0)
	{
		printf("잘못된 값을 입력하셨습니다.\n");
		return;
	}
	for(a = 1,i=hoho->next,j=hoho;a<index&&i!=NULL;a++,i=i->next,j=j->next);
	j->next = i->next;
	free(i);	
	numofdatas--;
	return hoho;
}

void display(ll hoho)
{
	ll i;
	for(i = hoho;i != NULL;i = i->next)
	{
		printf("%d  ",i->data);
	}
	putchar('\n');
}

ll searchdata(ll kaka,int a)
{
	ll i;
	for(i = kaka;i != NULL;i=i->next)
	{
		if(i->data == a)
			return i;
	}
	return NULL;
}

int main()
{
	ll head = NULL;
	ll l = NULL;
	int a,hihi;
	while(1)
	{
		printf("\t*원하는 번호를 선택해주십시오 *\n\t\t1.데이터 삽입\n\t\t2.데이터 인덱스 삽입\n\t\t3.데이터 삭제\n\t\t4.데이터 인덱스 삭제\n\t\t5.데이터 출력\n\t\t6.데이터 검색\n");
		scanf_s("%d",&a);
		switch(a)
		{
		case 1:
			head = createdata(head);
			break;
		case 2:
			printf("index를 입력하세요 ");
			scanf_s("%d",&hihi);
			cindexdata(head,hihi);
			break;
		case 3:
			head = deletedata(head);
			break;
		case 4:
			printf("index를 입력하세요 ");
			scanf_s("%d",&hihi);
			dindexdata(head,hihi);
			break;
		case 5:
			display(head);
			break;
		case 6:
			printf("찾을 값을 입력하세요 ");
			scanf_s("%d",&hihi);
			l = searchdata(head,hihi);
			if(l == NULL)
			{
				printf("값을 찾을 수 없습니다.\n");
				return;
			}else{
				printf("찾았습니다! \n값 : %d\n다음 헤드 : %p\n",l->data,l->next);
				break;
			}
		default:
			printf("정확한 번호를 입력하세요 ㅠ\n\n");
			return;
		}
	}
}