void infixtoPostfix(char *infix, char *postfix)
{
    Stack s;
    s.ll.head = NULL;
    s.ll.size = 0;
    while (*infix)
    {
        if (*infix == '(')
        {
            push(&s, *infix);
        }
        else if (isalnum(*infix))
        {
            *postfix = *infix;
            postfix++;
        }
        else if (*infix == ')')
        {
            while (1)
            {
                *postfix = pop(&s);
                postfix++;
                if (peek(&s) == '(')
                    break;
            }
            pop(&s);
        }
        else if (isEmptyStack(&s))
            push(&s, *infix);
        else
        {
            while ((precedence(*infix) <= precedence(peek(&s))) && peek(&s) != '(')
            {
                *postfix = pop(&s);
                postfix++;
                if (isEmptyStack(&s) || peek(&s) == '(')
                    break;
            }
            push(&s, *infix);
        }
        infix++;
    }
    while (!isEmptyStack(&s))
    {
        *postfix = pop(&s);
        postfix++;
    }
    *postfix = '\0';
}