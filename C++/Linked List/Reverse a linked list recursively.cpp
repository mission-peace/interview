list_node* reverse_list(list_node *head){
    if(head == NULL || head->next == NULL)
        return head;
    list_node* temp = reverse_list(head->next);
    head->next->next = head;
    head->next = NULL;
    return temp;
}
