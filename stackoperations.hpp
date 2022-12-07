#include "stack.hpp"

void push(struct stack* p_stack, type value);

void pushr(struct stack* p_stack, int indeficator);

type pop (struct stack* p_stack);

type popr (struct stack* p_stack, int indeficator);

void add (struct stack* p_stack);

void sub (struct stack* p_stack);

void mul (struct stack* p_stack);

void div (struct stack* p_stack);

void out (struct stack* p_stack);

void print (struct stack stack);

void dump (struct stack stack);

void jump (struct stack* p_stack, int i);

void jb (struct stack* p_stack, int i);

void jbe (struct stack* p_stack, int i);

void ja (struct stack* p_stack, int i);

void jae (struct stack* p_stack, int i);

void je (struct stack* p_stack, int i);

void jne (struct stack* p_stack, int i);

void hlt (struct stack* p_stack);
