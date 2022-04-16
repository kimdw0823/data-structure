#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef char element;		
#define MAX_STACK_SIZE 100


typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;


void init_stack(StackType *s)
{
	s->top = -1;
}


int is_empty(StackType *s)
{
	return (s->top == -1);
}

int is_full(StackType *s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType *s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else s->data[++(s->top)] = item;
}

element pop(StackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

element peek(StackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[s->top];
}


// 연산자의 우선순위를 반환한다.
int prec(char op)
{
	switch (op) {
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	}
	return -1;
}
// 중위 표기 수식 -> 후위 표기 수식
void infix_to_postfix(char exp[])
{
	int i = 0;
	char ch, top_op;
	int len = strlen(exp);
	StackType s;

	init_stack(&s);					// 스택 초기화
	for (i = 0; i<len; i++) {
		ch = exp[i];
		switch (ch) {
		case '+': case '-': case '*': case '/': // 연산자
											// 스택에 있는 연산자의 우선 순위가 더 크거나 같으면 출력
			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))
				printf("%c", pop(&s));
			push(&s, ch);
			break;
		case '(':	// 왼쪽 괄호
			push(&s, ch);
			break;
		case ')':	//오른쪽 과로
			top_op = pop(&s);
			// 왼쪽 괄호를 만날때까지 출력
			while (top_op != '(') {
				printf("%c", top_op);
				top_op = pop(&s);
			}
			break;
		default:		// 피연산자
			printf("%c", ch);
			break;
		}
	}
	while (!is_empty(&s))	// 스택에 저장된 연산자를 출력
		printf("%c", pop(&s));
}
// 
int main(void)
{
	char *s = "(2+3)*4+9";
	printf("중위표기수식 %s \n", s);
	printf("후위표기수식");
	infix_to_postfix(s);
	printf("\n");
	return 0;
}