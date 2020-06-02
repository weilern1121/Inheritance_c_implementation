#include "main.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>


typedef struct _Father Father;
typedef struct _Son Son;

//pointers to function
typedef void(*fptrPrint)(Father*);
typedef void(*fptrGetNumber)(Father*);
typedef void(*fptrDelete)(Father*);
typedef void(*fptrGetTimer)(Son*);

typedef struct _Father
{
	int				m_number;
	fptrPrint		print;
	fptrGetNumber	get_m_number;
	fptrDelete      delete;
}Father;

typedef struct _Son
{
	Father my_father;
	int				m_timer;
	fptrGetTimer	get_m_timer;
}Son;

Father* new_Father();    //constructor
void delete_father(Father* f);    //destructor
int get_m_number(Father* f);
void print_father();
void init_father(Father* f);

Son* new_Son();    //constructor
void delete_Son(Son*  s);    //destructor
int get_m_timer(Son*  s);
void print_son();


/*		Father funcs	*/
Father* new_Father() {    //constructor
	Father* output = (Father*)malloc(sizeof(Father));
	init_father(output);
	return output;
}

void init_father(Father*  f) {
	f->m_number = 3;
	f->get_m_number = get_m_number;
	f->print = print_father;
	f->delete = delete_father;
}

void delete_father(Father*  f) {
	free(f);
}

int get_m_number(Father*  f) {
	return f->m_number;
}

void print_father() {
	printf("hello father\n");
}


/*		Son funcs	*/

Son* new_Son() {    //constructor
	Son* output = (Son*)malloc(sizeof(Son));
	init_father(&output->my_father);
	output->my_father.delete = delete_Son;	//override
	output->my_father.print = print_son;	//override
	output->m_timer = 4;
	output->get_m_timer = get_m_timer;

	return output;
}

void delete_Son(Son* s) {    //destructor
	free(s);
}

int get_m_timer(Son* s) {
	return s->m_timer;
}

void print_son() {
	printf("hello son");
}


int main() {
	Father* f = new_Son();
	f->print(f);
	f->delete((Son*)f);
	return 0;

}
