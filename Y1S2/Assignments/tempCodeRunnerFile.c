int insertSortedLL(LinkedList *ll, int item)
{
    ListNode *ptr = ll->head;
    int index = 0;
    if ((ll->size) == 0)
    {
        insertNode(ll, 0, item);
        return 1;
    }
    for (index; index < (ll->size); index++)
    {
        if (item < ptr->item)
            break;
        ptr = ptr->next;
        index++;
    }
    printf("%d", index);
    insertNode(ll, index, item);
}